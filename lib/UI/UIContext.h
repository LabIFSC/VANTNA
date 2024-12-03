#pragma once

#include "UISettings.h"
#include "Display.h"
#include "LCD.h"
#include "Menu/Menu.h"
#include "Menu/MainMenu.h"

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

        void InitMenus()
        {
            MainMenu main; // TODO: Testar se não causa SegFault;

            RegistrarMenu(main);
        }

    protected:
        static UIContext& self_;

    public:

        UIContext()
        {
            // Hardcoded display device to LCD
            display_ = new LCD();
        };

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
         * Usada para registrar os menus durante runtime.
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

            return true;
        }
};
