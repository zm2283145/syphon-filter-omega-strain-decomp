/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int g_InterfaceFont; /* current interface font */
extern int Global_SetInterfaceFont(int font);
extern FontOwner* App_GetInstance(void);

/* Script native: SetInterfaceFont(byte index). */
int Script_SetInterfaceFont(unsigned char* args) {
    unsigned char font;

    font = args[0];
    Global_SetInterfaceFont(font);
    return 0;
}

int Global_SetInterfaceFont(int font) {
    FontOwner* owner;
    int handle;

    owner = App_GetInstance();
    handle = owner->fonts[font & 255];
    g_InterfaceFont = handle;
    return (int)owner;
}
