#include "types.h"
typedef struct { char pad[0x250]; unsigned char mode; char pad2[3]; int width; int height; int pad3; int rate; } Disp_16;
typedef struct { char pad[0x1C]; float scale; } Cfg_16;
extern char D_005381F0[];
extern Cfg_16* D_004FFD2C;
extern float D_004C1FC8;
extern int D_005383D4;
extern int D_005383C0;
extern void func_0037E320(void* p);
extern void func_0037E780(void* p, int w, int h, int a, int b, int mode, int c, int d);
/* Selects display resolution and refresh settings for a video mode. */
void func_00165420(Disp_16* d, unsigned char mode)
{
    switch (mode) {
    case 0:
        d->width = 0x280;
        d->height = 0x1C0;
        d->rate = 30;
        break;
    case 2:
        d->width = 0x280;
        d->height = 0x200;
        d->rate = 50;
        break;
    case 4:
        d->width = 0x280;
        d->height = 0x1E0;
        d->rate = 30;
        break;
    }
    d->mode = mode;
    func_0037E320(D_005381F0);
    func_0037E780(D_005381F0, d->width, d->height, 0x20, 0x10, d->mode, 0xFA0, 0x1F4);
    D_005383D4 = d->rate;
    D_005383C0 = (unsigned char)(int)(D_004C1FC8 * D_004FFD2C->scale);
}