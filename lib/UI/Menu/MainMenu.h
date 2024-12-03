#include "Menu.h"
#include "UISettings.h"

class MainMenu : public Menu
{
  public:
    MainMenu() : Menu(MID_MAIN)
    {
      opcoes[0].nome = "Executar";
      opcoes[0].acao = (void*)0;

      opcoes[1].nome = "Configurar";
      opcoes[1].acao = (void*)0;

      this->n_opts = 2;
    }
};