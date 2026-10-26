/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

/* cursor character */
extern char D_004BDF20[];
static void * const dat_00493970[2] = { (void*)D_004BDF20, (void*)0x0 };
extern void Global_SetCursorChar(char* str);

/* Script native: SetCursorChar(string). */
int Script_SetCursorChar(L4ScriptArg* args) {
    int part[1];

    part[0] = args[0].i;
    Global_SetCursorChar(*(char**)part);
    return 0;
}

/* Stores the first character of str as the cursor character. */
void Global_SetCursorChar(char* str) {
    char c = *str;

    *(*(char**)dat_00493970) = c;
}

void cConsole_Deactivate(Unk3E7CD0* self) {
    self->unk01 = 0;
    self->unk02 = 1;
    self->unk04 = -7;
}
