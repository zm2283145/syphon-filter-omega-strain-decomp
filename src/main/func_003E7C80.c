/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char* D_00493970;          /* cursor character */
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

    *D_00493970 = c;
}

void func_003E7CD0(Unk3E7CD0* self) {
    self->unk01 = 0;
    self->unk02 = 1;
    self->unk04 = -7;
}
