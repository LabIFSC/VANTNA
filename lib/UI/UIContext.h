#include "Menu/Menu.h"

/** UI Config */
#define UI_CTX_MAX_MENU 15              // Limite do buffer de menus. Padrao: 15 

#define MID_MAIN 0x00
#define MID_EXEC 0X01
#define MID_CONFIG 0X02
#define MID_CONFIG_NEW 0x03
#define MID_CONFIG_EDIT 0x04


/**
 * TODO: Adicionar documentação de uso
 * - Criar instância com 'UIContext* UI = UIContext::GetInstance()'
 */
class UIContext
{
    private:
        UIContext() {};

        MID menu_idx;
        unsigned char menu_counter;
        Menu menus[UI_CTX_MAX_MENU];

    protected:
        static UIContext* self_;

    public:

        /**
         * Singletons should not be cloneable.
         */
        UIContext(UIContext &other) = delete;

        /**
         * Singletons should not be assignable.
         */
        void operator=(const UIContext &) = delete;

        static UIContext* GetInstance()
        {
            if(self_ == nullptr)
            {
                return new UIContext();
            }

            return self_;
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
