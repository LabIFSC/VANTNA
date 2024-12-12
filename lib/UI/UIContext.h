#pragma once

#include "UISettings.h"
#include "Display.h"
#include "LCD.h"
#include "Menu/MainMenu.h"
#include "Menu/ConfigMenu.h"
#include "SimpleMath.h"
#include "LCDKeyboard.h"

struct CustomCursor
{
    uint8_t id_;
    uint8_t data[8] = {
        B00000,
        B01000,
        B01100,
        B01110,
        B01100,
        B01000,
        B00000,
    };

    uint8_t pos_col = 0;
    uint8_t pos_row = 0;
};

struct UIState
{
    uint8_t frame_counter = 0;
    bool is_draw_frame = false; // Used to animate blinking cursor

    uint8_t offset;             // TODO: Manipular offset baseado em inputs do teclado
    uint8_t max_offset;         // Prevent overflows
    uint8_t per_page;           // Bound max rows either by LCD_HEIGHT or number of items to display (as long as they are < LCD_HEIGHT)
};

/**
 * TODO: Adicionar documentação de uso
 * - Inicializar um tipo de display (No caso, o LCD)
 * - Passar esse display para o UIContext conseguir desenhar coisas nele
 * - Criar instância com 'UIContext* UI = UIContext::GetInstance()'
 */
class UIContext
{
    private:
        LCD* display_;
        LCDKeyboard* keyboard_;

        MID menu_idx;
        unsigned char menu_counter;
        Menu menus[UI_CTX_MAX_MENU];

        // [ MENU_INICIAL, MENU_CONFIG, MENU_DISPOSITIVO, MENU_CONFIG_NOVA_MISSAO ]

        UIState ui_state;
        CustomCursor CCursor;

        void InitMenus()
        {
            MainMenu main;          // TODO: Testar se não causa SegFault;
            ConfigMenu config;      // TODO: Testar se não causa SegFault;

            RegistrarMenu(main);
            RegistrarMenu(config);

            this->menu_idx = 0;
        }

    protected:
        static UIContext& self_;

    public:

        UIContext(LCDSettings lcd_settings, uint8_t keyboard_pin)
        {
            display_ = new LCD(lcd_settings);
            keyboard_ = new LCDKeyboard(keyboard_pin);

            InitMenus();
            CreateCustomCursor();
        }


        void CreateCustomCursor()
        {
            CCursor.id_ = 0;
            display_->createChar(byte(0), CCursor.data);
        }

        //#region Drawing

        void Update()
        {
            keyboard_->PoolEvents();

            // Process how current menu should be drawn
            Menu m = MenuAtual();

            uint8_t bound = m.GetNumOptions();

            ui_state.per_page = (bound < LCD_HEIGHT) ? bound : LCD_HEIGHT;
            ui_state.max_offset = RoundIntDiv(bound, LCD_HEIGHT) - 1;

            if(keyboard_->IsBtnDown(BTN_DOWN))
            {
                ui_state.offset++;
            }

            if(keyboard_->IsBtnDown(BTN_SELECT))
            {
                // TODO: Executa callback do indice atual selecionado do menu
                MenuAtual().GetOptions()[ui_state.offset + CCursor.pos_row].callback();
            }

            // ...
            if((ui_state.offset > (ui_state.max_offset + 1))) // Overflow pro começo da lista
            {
                ui_state.offset = 0;
                CCursor.pos_row = 0;

                // TODO: Limpar buffer
            }
        }

        void UpdateFrameCounter()
        {
            if(ui_state.frame_counter > 60)
            {
                ui_state.frame_counter = 0;
                ui_state.is_draw_frame = !ui_state.is_draw_frame;
                return;
            }

            ui_state.frame_counter++;
        }

        void Draw()
        {

            // ... for each menu

            // Draw Custom Cursor
            display_->setCursor(CCursor.pos_col, CCursor.pos_row);

            if(ui_state.is_draw_frame)
                display_->write(byte(CCursor.id_));
            else
            {
                // Clear both cells from cursor column
                display_->setCursor(0, 0);
                display_->print(" ");
                display_->setCursor(0, 1);
                display_->print(" ");
            }

            const Option* opts = MenuAtual().GetOptions();
            uint8_t n_options = MenuAtual().GetNumOptions() - 1;

            for(uint8_t i = 0; i < ui_state.per_page; i++)
            {
                display_->setCursor(1, i);

                if((i + ui_state.offset) > n_options)
                {
                    display_->print("                    ");
                    continue;
                }

                display_->print(opts[i + ui_state.offset].nome);
            }

            // Toggles flag to draw animated cursor every other refresh window
            UpdateFrameCounter();

            display_->Refresh();
        }

        //#endregion

        const Menu& MenuAtual()
        {
            return menus[menu_idx];
        }

        void SetMenuAtual(MID menu_id)
        {
            if(menu_id > UI_CTX_MAX_MENU) /* Segfault: Out of bounds */
                return;

            menu_idx = menu_id;
        }

        void Voltar()
        {
            const Menu& atual = MenuAtual();

            /** Navegacao redudante */
            if(atual.GetID() == atual.GetAnterior()) 
                return;

            SetMenuAtual(atual.GetAnterior());
        }

        /**
         * Usada para registrar os menus durante runtime.
         * 
         * Incrementa `menu_counter`
         * Para a plataforma de protótipo, esse caso é efetivo o suficiente
         * pois permite adicionar novas telas sem ter que lidar com o controle
         * da posição da memória do Menu em relação ao seu MID.
         */
        bool RegistrarMenu(const Menu menu)
        {
            MID menu_id = menu.GetID();

            if(menu_counter + 1 > UI_CTX_MAX_MENU || menu.GetID() > UI_CTX_MAX_MENU)
                return false;

            menus[menu_id] = menu;
            menu_counter++;

            return true;
        }
};
