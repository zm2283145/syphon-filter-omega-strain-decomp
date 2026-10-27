/*
 * main/GuiRatings: 4 files, 0034D770-0034DBE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034D770 */
#pragma push /* merge_units */
typedef struct Item { char pad[0x10]; int idx; } Item;
typedef struct Ui { char pad[0x20]; Item *focus; } Ui;
typedef struct Self { char pad[0x6C]; void *items[24]; } Self;
extern Ui *Gui_Canvas(void);
extern void GuiCanvas_SetFocus(Ui *ui, void *w);

void GuiRatings_MoveFocus(Self *self, int dir)
{
    Item *f;
    int idx;
    int col;
    int row;

    f = Gui_Canvas()->focus;
    if (f == 0 || (idx = f->idx) == -1)
        return;
    col = idx % 4;
    row = idx / 4;
    switch (dir) {
    case 0:
        col--;
        break;
    case 1:
        col++;
        break;
    case 2:
        row--;
        break;
    case 3:
        row++;
        break;
    }
    col = col < 0 ? 3 : (col >= 4 ? 0 : col);
    row = row < 0 ? 5 : (row >= 6 ? 0 : row);
    GuiCanvas_SetFocus(Gui_Canvas(), self->items[row * 4 + col]);
}
#pragma pop /* merge_units */
/* merge_units: end func_0034D770 */

/* merge_units: begin func_0034D8C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef struct { __int128 q[4]; } M4_4D8C0;
typedef struct { char pad[0xA80]; M4_4D8C0 m[1]; } MStack_4D8C0;
typedef struct { char pad[8]; unsigned char b8; char pad9[7]; int x10; } Rec_4D8C0;
typedef struct { char pad[0x34]; float f34; float f38; float f3C; float f40; } W_4D8C0;
typedef struct { int x0; int x4; int x8; int xC; } TO_4D8C0;
typedef struct { char pad[0x6C]; W_4D8C0* w6C[0x19]; int countD0; Rec_4D8C0* recsD4; char padD8[4]; TO_4D8C0* textDC; } S_4D8C0;
extern "C" {
extern MStack_4D8C0 g_Video;
extern int D_00538C64;
extern char D_00538C68;
extern char D_004BA870[];
extern char D_004BA878[];
void GuiWidget_onRender(S_4D8C0* s);
int sprintf(char*, const char*, ...);
void cTextArea_SetText(TO_4D8C0* t, char* s);
void TextObj_Draw(TO_4D8C0* t);
void GuiRatings_onRender(S_4D8C0* s);
}
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline void SetPos(TO_4D8C0* t, float y, float x) { int a, b; b = (int)y; a = (int)x; t->x0 = a; t->x4 = b; }
static inline void SetSize(TO_4D8C0* t, float h, float w) { int a, b; b = (int)h; a = (int)w; t->x8 = a; t->xC = b; }
#pragma opt_rotateloops off
void GuiRatings_onRender(S_4D8C0* s)
{
    int i;
    GuiWidget_onRender(s);
    if (!s->textDC) return;
    GQR(&g_Video.m[D_00538C64 + 1], &g_Video.m[D_00538C64]);
    D_00538C64++;
    UM(&g_Video.m[D_00538C64]);
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
                cTextArea_SetText(s->textDC, buf);
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
#pragma pop /* merge_units */
/* merge_units: end func_0034D8C0 */

/* merge_units: begin func_0034DB10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

/* Release the owned record at +0xDC (string member at +0x14) under the allocator guard, reset +0x10. */
extern "C" {
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void* String_Dtor(void* self, short flags);
void GuiWidget_onSleep(void* self);
}
struct O34DB10 { char pad[0x10]; int a10; char pad14[0xC8]; char* aDC; };
extern "C" void GuiRatings_onSleep(O34DB10* o)
{
    char* p;
    GuiWidget_onSleep(o);
    p = o->aDC;
    if (p) {
        {
            AllocGuard guard;
            if (p) {
                char* s = p + 0x14;
                if (s)
                    String_Dtor(s, 0);
            }
            cMemMan_Deallocate(0, p, "GuiRatings.cc", 0x96);
        }
        o->aDC = 0;
    }
    o->a10 = -1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0034DB10 */

/* merge_units: begin func_0034DBE0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; int idx; char pad2[0x58]; int table[1]; } Obj34;
extern int GuiWidget_FindFirstFocus(Obj34* o);
/* Returns the table entry for the current index, or the fallback lookup. */
int GuiRatings_FindFirstFocus(Obj34* o) { if (o->idx != -1) return o->table[o->idx]; return GuiWidget_FindFirstFocus(o); }
#pragma pop /* merge_units */
/* merge_units: end func_0034DBE0 */
