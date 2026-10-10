#include "types.h"

typedef struct GuiState {
    char pad[0x1C4];
    int dirty;
    char pad2[0xA68 - 0x1C8];
    char buf[0x20];
} GuiState;

extern GuiState* D_00585E60;
extern int func_004505C0(void*, int, int, int);
extern void memcpy(void*, void*, int);

/* Copies a 32-byte value into the GUI state when func_004505C0 reports no change. */
void func_00446E00(void* a0, int a1, int a2, void* src) {
    if (func_004505C0(a0, a1, a2, (int)src) == 0) {
        D_00585E60->dirty = 1;
        memcpy(D_00585E60->buf, src, 0x20);
    }
}
