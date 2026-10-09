/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern void func_003CE7D0(cGOBJ* obj);
extern void func_003CE810(cGOBJ* obj);

void func_00173640(void) {
}

void func_00173650(void) {
}

void* func_00173660(char* self) {
    return self + 112;
}

/* Set the object's +0x2C flag. */
void func_00173670(cGOBJ* obj) {
    obj->unk2C = 1;
}

/* Clear the object's +0x2C flag. */
void func_00173680(cGOBJ* obj) {
    obj->unk2C = 0;
}

void func_00173690(cGOBJ* obj) {
    obj->unk2C = 1;
    func_003CE810(obj);
}

void func_001736A0(cGOBJ* obj) {
    obj->unk2C = 0;
    func_003CE7D0(obj);
}

int func_001736B0(void) {
    return 1;
}
