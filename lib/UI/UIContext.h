#pragma once

#include "UISettings.h"
#include "Display.h"
#include "LCD.h"
#include "Menu/MainMenu.h"
#include "Menu/ConfigMenu.h"
#include "SimpleMath.h"

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

    uint8_t pos_col;
    uint8_t pos_row;
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
        DisplayDevice* display_;

        MID menu_idx;
        unsigned char menu_counter;
        Menu menus[UI_CTX_MAX_MENU];

        // [ MENU_INICIAL, MENU_CONFIG, MENU_DISPOSITIVO, MENU_CONFIG_NOVA_MISSAO ]

        CustomCursor CCursor;
        bool is_draw_frame = false; // Used to animate UI

        void InitMenus()
        {
            MainMenu main; // TODO: Testar se não causa SegFault;
            ConfigMenu config; // TODO: Testar se não causa SegFault;

            RegistrarMenu(main);
            RegistrarMenu(config);

            this->menu_idx = 0;
        }

    protected:
        static UIContext& self_;

    public:

        UIContext()
        {
            // Hardcoded display device to LCD
            display_ = new LCD();

            InitMenus();
            CreateCustomCursor();

        }

        void CreateCustomCursor()
        {
            CCursor.id_ = 0;
            GetRawDisplay()->createChar(byte(0), CCursor.data);
        }

        LiquidCrystal* GetRawDisplay()
        {
            return display_->GetRawDevice();
        }

        //#region Drawing

        void Draw()
        {
            Menu m = MenuAtual();

            // ... for each menu

            LiquidCrystal* rawDevice = display_->GetRawDevice();

            uint8_t bound = m.GetNumOptions();
            const Option* opts = m.GetOptions();

            uint8_t max_offset = RoundIntDiv(bound, LCD_HEIGHT) - 1;
            uint8_t per_page = (bound < LCD_HEIGHT) ? bound : LCD_HEIGHT;

            uint8_t offset = 0; // TODO: Manipular offset baseado em inputs do teclado

            if(offset > max_offset) // Overflow pro começo da lista
                offset = 1;

            for(uint8_t i = 0; i < per_page; i++)
            {
                rawDevice->setCursor(1, i);
                rawDevice->print(opts[i + offset].nome);
            }

            // Draw Custom Cursor
            rawDevice->setCursor(0, 0);

            is_draw_frame = !is_draw_frame;

            if(is_draw_frame)
                rawDevice->write(byte(CCursor.id_));
            else
                rawDevice->print(" ");

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
