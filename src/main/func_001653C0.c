/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int D_0055A278; /* current interface font */
extern int Global_SetInterfaceFont(int font);
extern FontOwner* func_001698C0(void);

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

    owner = func_001698C0();
    handle = owner->fonts[font & 255];
    D_0055A278 = handle;
    return (int)owner;
}
