#include "types.h"
typedef struct { char pad[0x6A4]; void* snd; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; } Obj2426;
extern void func_0045DD90(void* p, int on);
extern void func_0036A240(void* p);
extern char D_0055A300[];extern int D_0055A6C0;
extern void func_002427F0(Obj2426* s);
extern void func_00242870(Obj2426* s);
void func_002427A0(Obj2426* s) {
    D_0055A6C0 = -0x41;
    if (s->b6A9) func_002427F0(s);
    else func_00242870(s);
}
