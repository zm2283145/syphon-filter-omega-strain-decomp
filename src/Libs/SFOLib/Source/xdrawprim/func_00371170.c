#include "types.h"
typedef struct { int pad[0x3F6]; int aFD8; int padFDC; int aFE0; int aFE4; char padFE8[0x10]; } E371170;
typedef struct { char pad[0x1020]; int cur; char pad1024[0xBC]; unsigned int a10E0; } S371170;
extern int XLib_ValidateBatch(S371170* o);
extern void XLib_ApplyContext(S371170* o, unsigned int flags);
extern void XLib_DrawDma(S371170* o, int a, int b, int c, int d, int e, int f, int g, int h, int i);
void XLib_DrawSprites(S371170* o)
{
    if (XLib_ValidateBatch(o)) {
        E371170* e;
        XLib_ApplyContext(o, o->a10E0 | 0x40000);
        e = (E371170*)((char*)o + o->cur * 56);
        XLib_DrawDma(o, e->aFD8, e->aFE0, e->aFE4, 0, 2, 6, 0x412412, 6, 0x14);
    }
}