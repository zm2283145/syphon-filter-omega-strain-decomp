/*
 * main/GuiSubTitleDisplay: 4 files, 00455550-00455840
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00455550 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x4C]; int type; } A_455550;
typedef struct { char pad[0x30]; A_455550* f30; } G_455550;
typedef struct { char pad[0x48]; void* f48; } O_455550;
extern G_455550* D_004FFC0C;
extern int D_0049D010;
extern void func_0041EFA0(O_455550*);
extern int func_00176110(G_455550*);
extern void func_00454F80(O_455550*, int);
extern void func_00455260(O_455550*, A_455550*, int);

void func_00455550(O_455550* o)
{
    G_455550* g;
    func_0041EFA0(o);
    if (o->f48 && (g = D_004FFC0C)) {
        if (func_00176110(g) == -1) {
            func_00454F80(o, 1);
        } else {
            A_455550* a = g->f30;
            a = (a && a->type == D_0049D010) ? a : 0;
            func_00455260(o, a, func_00176110(g));
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00455550 */

/* merge_units: begin func_00455610 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "gui_widget_vslots.h"
struct W_455610 : GuiWidgetV { char pad4[0x10]; unsigned short f14; char pad16[0x4A]; int f60; char pad64[0x18]; GuiWidgetV* f7C; };
struct S_455610 { char pad0[0x48]; GuiWidgetV* f48; W_455610* f4C; GuiWidgetV* f50; GuiWidgetV* f54; };
extern "C" {
extern char* D_00497998;
extern char D_004C1A60[];
extern char D_004C19C0[];
extern char D_004C1A78[];
extern char D_004C19B0[];
extern char D_004BB3D0[];
extern char D_004A7520[];
extern char D_004C1D88[];
extern char D_004AAE20[];
extern char D_004AAE00[];
void GuiWidget_Init(S_455610* s);
}
extern "C" void func_00455610(S_455610* s)
{
    GuiWidget_Init(s);
    s->f48 = GuiFindAs(s, D_00497998, D_004BB3D0);
    s->f50 = GuiFindAs(s, D_004C1A60, D_004A7520);
    s->f54 = GuiFindAs(s, D_004C19C0, D_004C1D88);
    s->f4C = (W_455610*)GuiFindAs(s, D_004C1A78, D_004AAE20);
    if (s->f4C) {
        s->f4C->f60 = 0;
        s->f4C->f7C = GuiFindAs(s, D_004C19B0, D_004AAE00);
        s->f4C->f14 |= 0x80;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00455610 */

/* merge_units: begin func_004557C0 */
#pragma push /* merge_units */
typedef struct { unsigned short a0; unsigned short a2; short pad4; unsigned short a6; unsigned short a8; } E4557C0;
extern int GuiStartMenu_ReturnToMenu(void* self, E4557C0* e);
extern int GuiArrayWidget_OnInput(void* self, E4557C0* e);
int func_004557C0(void* self, E4557C0* e)
{
    int b = e->a0 == 1 && e->a2 == 0 && e->a8 == 0x10 && e->a6 == 0;
    if (b) {
        GuiStartMenu_ReturnToMenu(self, e);
        return 1;
    }
    return GuiArrayWidget_OnInput(self, e);
}
#pragma pop /* merge_units */
/* merge_units: end func_004557C0 */

/* merge_units: begin func_00455840 */
#pragma push /* merge_units */
typedef struct { char pad0[0x60]; int f60; int f64; char pad68[8]; int f70; int f74; } Wpn_00455840;
typedef struct { char pad0[0x30]; int f30; } G_00455840;
#if 0 /* merge_units */
extern G_00455840* D_004FFC0C;
#endif /* merge_units */
#define D_004FFC0C (*(G_00455840 **)&D_004FFC0C) /* merge_units */

extern int D_004FFD30;
extern char D_004C1A38[];
extern char D_004C1A50[];
extern char D_004C1A88[];
extern char D_004C1A98[];
int sprintf(char* d, const char* f, ...);
char* Loc_LookupText(char* key);
void func_00426510(void* list, int col, int row, char* text);
Wpn_00455840* WeaponDb_Get(int db, int id);
void String_Copy(char* d, char* s);
int func_002C9020(int a);
int func_002C8FD0(int a);
void func_002C8EC0(int a, char* buf, int n);
int WeaponInv_ClipsForActor(int actor, int a);
void func_00455840(void* list, int id)
{
    char key[0x10];
    char buf[0x20];
    int i;
    Wpn_00455840* w;
    for (i = 0; i < 4; i++) {
        char* t;
        sprintf(key, D_004C1A88, i);
        t = Loc_LookupText(key);
        func_00426510(list, 0, i, t ? t : D_004C1A38);
    }
    w = WeaponDb_Get(D_004FFD30, id);
    if (w) {
        int actor = D_004FFC0C->f30;
        for (i = 0; i < 4; i++) {
            String_Copy(buf, D_004C1A98);
            switch (i) {
            case 0:
                if (w->f60)
                    func_002C8EC0(func_002C9020(w->f60), buf, 0x20);
                break;
            case 1:
                if (w->f64)
                    func_002C8EC0(func_002C8FD0(w->f64), buf, 0x20);
                break;
            case 2:
                if (w->f70)
                    sprintf(buf, D_004C1A50, w->f70);
                break;
            case 3: {
                int n = w->f70 * WeaponInv_ClipsForActor(actor, w->f74);
                if (n)
                    sprintf(buf, D_004C1A50, n);
                break;
            }
            }
            func_00426510(list, 1, i, buf);
        }
    }
}
#undef D_004FFC0C /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455840 */
