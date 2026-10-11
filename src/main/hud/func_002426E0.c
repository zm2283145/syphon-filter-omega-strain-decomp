#include "types.h"
typedef struct { char pad[0x6A4]; void* snd; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; } Obj2426;
extern void func_0045DD90(void* p, int on);
extern void func_0036A240(void* p);
extern char D_0055A300[];void func_002426E0(Obj2426* s) {
    if (!s->b6AA || !s->snd) return;
    func_0045DD90(s->snd, 0);
    func_0036A240(D_0055A300);
    s->b6AA = 0;
}
