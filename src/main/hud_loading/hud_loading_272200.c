#include "types.h"
typedef struct { char p[0x20]; int f20; } H272200;
typedef struct { char p[0x19]; unsigned char b19; char p1A[0x5A]; H272200* h; } O272200;
typedef struct { char p[0x280]; int f280; } G272200;
extern O272200* Hud_FindOrCreateElement(int a, int b);
extern void IeElement_SetText(O272200* o, void* x);
extern void TextObj_SetColour(H272200* h, void* c);
extern G272200* App_GetInstance(void);
extern char D_004A8DA0[];
O272200* LoadingScreen_SetText(int a, int b, void* x)
{
    O272200* o = Hud_FindOrCreateElement(a, b);
    if (o && x && o->h) {
        IeElement_SetText(o, x);
        o->b19 = 0;
        TextObj_SetColour(o->h, D_004A8DA0);
        o->h->f20 = App_GetInstance()->f280;
    }
    return o;
}
