#include "types.h"
typedef struct {
    void* vtbl;             /* 0x000 */
    char p04[0x10];
    unsigned short flags;   /* 0x014 */
    char p16[0x84 - 0x16];
    int f84;                /* 0x084 */
    char p88[0x98 - 0x88];
    int f98[3];             /* 0x098 */
    int fA4[3];             /* 0x0A4 */
    int pB0;
    int fB4[17];            /* 0x0B4 */
    char pF8[0x10C - 0xF8];
    int f10C[3];            /* 0x10C */
    int f118[24];           /* 0x118 */
    unsigned char f178[24]; /* 0x178 */
    char p190[0x1B0 - 0x190];
    int f1B0;               /* 0x1B0 */
    char p1B4[0x1CC - 0x1B4];
    int f1CC;               /* 0x1CC */
    int f1D0;               /* 0x1D0 */
    unsigned char f1D4;     /* 0x1D4 */
    char p1D5[3];
    int f1D8[6];            /* 0x1D8 */
    unsigned char f1F0[17]; /* 0x1F0 */
    char p201[3];
    char f204[17][0xC];     /* 0x204 */
    int f2D0[6];            /* 0x2D0 */
    unsigned char f2E8;     /* 0x2E8 */
    char p2E9[3];
    int f2EC;               /* 0x2EC */
    int f2F0;               /* 0x2F0 */
    unsigned char f2F4;     /* 0x2F4 */
} Scr_2984D0;
extern char D_004DD4F0[];
extern void GuiScreen_ctor(Scr_2984D0* s);
extern void __construct_array(void* arr, void (*ctor)(void*), void (*dtor)(void*), int size, int count);
extern void func_00298690(void*);
extern void func_00138350(void*);

Scr_2984D0* func_002984D0(Scr_2984D0* s)
{
    int i;
    GuiScreen_ctor(s);
    s->vtbl = D_004DD4F0;
    __construct_array(s->f204, func_00298690, func_00138350, 0xC, 0x11);
    s->f84 = 1;
    s->f1D4 = 0;
    for (i = 0; i < 3; i++) s->f98[i] = 0;
    s->f2F0 = 0;
    for (i = 0; i < 3; i++) s->fA4[i] = 0;
    s->f2F4 = 0;
    for (i = 0; i < 3; i++) s->f10C[i] = 0;
    for (i = 0; i < 17; i++) {
        s->fB4[i] = 0;
        s->f1F0[i] = 0;
    }
    for (i = 0; i < 6; i++) {
        s->f1D8[i] = 0;
        s->f2D0[i] = 0;
    }
    { int j; for (j = 0; j < 24; j++) {
        s->f118[j] = 0;
        s->f178[j] = 1;
    } }
    s->f1CC = -1;
    s->f1D0 = 0;
    s->f2E8 = 0;
    s->f2EC = 0;
    s->f1B0 = 0;
    s->flags &= ~0x20;
    return s;
}


