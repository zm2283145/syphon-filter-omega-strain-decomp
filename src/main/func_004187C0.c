#include "types.h"
extern int func_0041F960(void* b);
extern void* GuiManager_LoadGui(void* a, void* c, int r);
void* func_004187C0(void* a, void* b, void* c) {
    int r = func_0041F960(b);
    if (!r) return 0;
    /* .set reorder barrier keeps the empty then-arm */
    return GuiManager_LoadGui(a, c ? c : b, r);
}