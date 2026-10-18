#pragma cplusplus on
#include "types.h"
typedef struct { __int128 q[4]; } M4_4D8C0;
typedef struct { char pad[0xA80]; M4_4D8C0 m[1]; } MStack_4D8C0;
typedef struct { char pad[8]; unsigned char b8; char pad9[7]; int x10; } Rec_4D8C0;
typedef struct { char pad[0x34]; float f34; float f38; float f3C; float f40; } W_4D8C0;
typedef struct { int x0; int x4; int x8; int xC; } TO_4D8C0;
typedef struct { char pad[0x6C]; W_4D8C0* w6C[0x19]; int countD0; Rec_4D8C0* recsD4; char padD8[4]; TO_4D8C0* textDC; } S_4D8C0;
extern "C" {
extern MStack_4D8C0 D_005381F0;
extern int D_00538C64;
extern char D_00538C68;
extern char D_004BA870[];
extern char D_004BA878[];
void GuiWidget_Draw(S_4D8C0* s);
int sprintf(char*, const char*, ...);
void TextObj_SetText(TO_4D8C0* t, char* s);
void TextObj_Draw(TO_4D8C0* t);
void GuiRatings_Draw(S_4D8C0* s);
}
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline void SetPos(TO_4D8C0* t, float y, float x) { int a, b; b = (int)y; a = (int)x; t->x0 = a; t->x4 = b; }
static inline void SetSize(TO_4D8C0* t, float h, float w) { int a, b; b = (int)h; a = (int)w; t->x8 = a; t->xC = b; }
#pragma opt_rotateloops off
void GuiRatings_Draw(S_4D8C0* s)
{
    int i;
    GuiWidget_Draw(s);
    if (!s->textDC) return;
    GQR(&D_005381F0.m[D_00538C64 + 1], &D_005381F0.m[D_00538C64]);
    D_00538C64++;
    UM(&D_005381F0.m[D_00538C64]);
    D_00538C68 = 1;
    for (i = 0; i < 6; i++) {
        int j;
        int idx;
        for (j = 0; j < 4; j++) {
            idx = j + i * 4;
            if (idx < s->countD0 && ((Rec_4D8C0*)((char*)s->recsD4 + idx * 20))->b8 == 0) break;
        }
        if (j != 4) {
            if (s->w6C[idx]) {
                char buf[0x20];
                SetPos(s->textDC, s->w6C[idx]->f38, s->w6C[idx]->f34);
                SetSize(s->textDC, s->w6C[idx]->f40, s->w6C[idx]->f3C);
                buf[0] = 0;
                {
                    int v = ((Rec_4D8C0*)((char*)s->recsD4 + idx * 20))->x10;
                    sprintf(buf, v >= 10 ? D_004BA870 : D_004BA878, v);
                }
                TextObj_SetText(s->textDC, buf);
                TextObj_Draw(s->textDC);
            }
        }
    }
    {
        int count = *(int*)&D_00538C64;
        *(char*)&D_00538C68 = 1;
        *(int*)&D_00538C64 = count - 1;
    }
}
