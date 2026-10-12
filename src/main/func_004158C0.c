#include "types.h"
typedef struct { char p[0x14]; unsigned short flags; char p16[0x3B]; unsigned char b51; unsigned char b52; } W4158C0;
extern char D_0055A700[];
extern void func_003D1770(void* p);
extern void func_003D1730(void* p);
void func_004158C0(W4158C0* w, int on)
{
    if ((unsigned char)on == ((w->flags & 4) != 0)) return;
    if (on) w->flags |= 4; else w->flags &= ~4;
    if (w->b52 && (w->flags & 4) && w->b51) {
        func_003D1770(D_0055A700);
        func_003D1730(D_0055A700);
    }
}
