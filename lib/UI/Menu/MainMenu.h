#include "Menu.h"
#include "UISettings.h"

// TODO: Implementar

class MainMenu : public Menu
{
  public:
    MainMenu() : Menu(MID_MAIN)
    {
      opcoes[0] = { "Executar       ", ExecMission };
      opcoes[1] = { "Configurar     ", OpenSettings };
      opcoes[2] = { "Dispositivo    ", NOT_IMPLEMENTED };

      this->n_opts = 3;
    }

    static void ExecMission(void)
    {
      //
    };

    static void OpenSettings(void)
    {
      // Abrir novo menu
      // UI.SetManuAtual(Config)
      // ......
    };

    static void NOT_IMPLEMENTED(void) {};
};