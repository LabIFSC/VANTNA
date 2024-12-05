#include "Menu.h"
#include "UISettings.h"

// TODO: Implementar

class MainMenu : public Menu
{
  public:
    MainMenu() : Menu(MID_MAIN)
    {
      opcoes[0] = { "Executar", ExecMission };
      opcoes[1] = { "Configurar", OpenSettings };

      this->n_opts = 2;
    }

    static void ExecMission(void)
    {
      //
    };

    static void OpenSettings(void)
    {
      //
    };
};