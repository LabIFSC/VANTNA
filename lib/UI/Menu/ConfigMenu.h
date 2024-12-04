#include "Menu.h"
#include "UISettings.h"

// TODO: Implementar
void ExibirMissao();
void AddCoords();

class ConfigMenu : public Menu
{
  public:
    ConfigMenu() : Menu(MID_CONFIG)
    {
      opcoes[0] = { "Exibir", ExibirMissao };
      opcoes[1] = { "Add. Coord.", AddCoords };

      this->n_opts = 2;
    }
};