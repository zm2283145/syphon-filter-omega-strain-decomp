/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after SFOLobby_Main.cc (ends 0x004534A0); probably part of it.
 */

#include "loose05_types.h"

extern int memset(void* dst, int value, int size); /* memset */
extern void func_0042B420(void* obj);
extern int func_00438A70(int handle, int arg);

/* Clears an 84-byte record and hands it to func_0042B420. */
void func_00454010(void* rec) {
    memset(rec, 0, 84);
    func_0042B420(rec);
}

void func_00454050(SFOLobby* self) {
    if (self->unk23D5 == 0) {
        func_00438A70(self->unk180, 0);
    }
}
