#include "types.h"

typedef struct GuiState {
    char pad[0x1A8];
    int dirty;
    char pad2[0x380 - 0x1AC];
    char buf[0x1C];
} GuiState;

extern GuiState* D_00585E60;
extern int func_004505C0(void*, int, int, int);
extern void memcpy(void*, void*, int);

/* Copies a 28-byte value into the GUI state when func_004505C0 reports no change. */
void func_00447470(void* a0, int a1, int a2, void* src) {
    if (func_004505C0(a0, a1, a2, (int)src) == 0) {
        D_00585E60->dirty = 1;
        memcpy(D_00585E60->buf, src, 0x1C);
    }
}
