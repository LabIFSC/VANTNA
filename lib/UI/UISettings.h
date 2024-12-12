#define UI_CTX_MAX_MENU 15              // Limite do buffer de menus. Padrao: 15 

/**
 * Incrementar ID nessa lista sempre que um novo menu for implementado
 * i.e:
 * 
 * #define MID_CONFIG_EDIT 0x04       0 + 4
 * #define MID_MENU_NOVO 0x05         0 + 5
*/
#define MID_MAIN 0x00
#define MID_EXEC 0X01
#define MID_CONFIG 0X02
#define MID_CONFIG_NEW 0x03
#define MID_CONFIG_EDIT 0x04