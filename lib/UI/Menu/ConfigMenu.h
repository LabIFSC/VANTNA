#include "Menu.h"
#include "UISettings.h"

class ConfigMenu : public Menu
{
  public:
    ConfigMenu() : Menu(MID_CONFIG)
    {
      opcoes[0] = { "Exibir", ExibirMissao };
      opcoes[1] = { "Add. Coord.", AddCoords };

      this->n_opts = 2;
    }

    static void ExibirMissao() {};

    static void AddCoords() {};
};