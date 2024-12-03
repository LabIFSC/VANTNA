#pragma once

#include "Display.h"
#include "LCD.h"
#include "Menu/Menu.h"

/** UI Config */
#define UI_CTX_MAX_MENU 15              // Limite do buffer de menus. Padrao: 15 

#define MID_MAIN 0x00
#define MID_EXEC 0X01
#define MID_CONFIG 0X02
#define MID_CONFIG_NEW 0x03
#define MID_CONFIG_EDIT 0x04
#define MID_MENU_NOVO 0x05

/**
 * TODO: Adicionar documentação de uso
 * - Inicializar um tipo de display (No caso, o LCD)
 * - Passar esse display para o UIContext conseguir desenhar coisas nele
 * - Criar instância com 'UIContext* UI = UIContext::GetInstance()'
 */
class UIContext
{
    private:
        UIContext()
        {
            // Hardcoded display device to LCD
            display_ = new LCD();
        };

        DisplayDevice* display_;

        MID menu_idx;
        unsigned char menu_counter;
        Menu menus[UI_CTX_MAX_MENU];

        // [ MENU_INICIAL, MENU_CONFIG, MENU_DISPOSITIVO, MENU_CONFIG_NOVA_MISSAO ]

    protected:
        static UIContext& self_;

    public:
        /**
         * Singletons should not be cloneable.
         */
        UIContext(UIContext &other) = delete;

        /**
         * Singletons should not be assignable.
         */
        void operator=(const UIContext &) = delete;

        static UIContext& GetInstance();

        DisplayDevice* GetRawDisplay()
        {
            return display_;
        }

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
         * TODO: Definir como função de utilidade, já que os menus não precisam ser definidos em runtime
         */
        bool RegistrarMenu(Menu menu)
        {
            if(menu_counter + 1 > UI_CTX_MAX_MENU)
                return;

            menu_counter++;
            menus[menu_counter] = menu;
        }
};
