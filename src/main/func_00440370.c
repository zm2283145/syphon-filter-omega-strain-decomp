#pragma cplusplus on
#include "types.h"
extern "C" unsigned char D_005723C8;
#pragma define_section REENT_DTOR ".dtors_drop" far_absolute RX
struct ReentGuard {
    ReentGuard() { if (!D_005723C8) D_005723C8 = 1; }
    __declspec(weak) __declspec(REENT_DTOR) ~ReentGuard() { D_005723C8 = 0; }
};typedef struct { int a, b, f8; } E440;
extern "C" {
extern int D_00494198;
extern int func_004147A0(void);
extern void func_0041E0F0(int, int, int, int, int);
}
extern "C" int func_00440370(int a0, int a1, int a2, E440* ev) {
    ReentGuard g;
    if (ev->f8 == D_00494198) {
        if (func_004147A0()) func_0041E0F0(func_004147A0(), func_004147A0(), 0x1E, 1, 0);
    } else {
        if (func_004147A0()) func_0041E0F0(func_004147A0(), func_004147A0(), 0x1E, 0, (int)"F_TO_CONNECT");
    }
    return 12;
}
