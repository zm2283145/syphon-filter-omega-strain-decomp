/*
 * main/GuiMissionList: range (2 files, 002ABC90-002ABD50)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();
void *memset(void *, int, int);

/* merge_units: begin func_002ABC90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Release the owned record at +0xA0 (string member at +0x14) under the allocator guard, clear +0xA0/+0xA4. */
extern "C" {
void* String_Dtor(void* self, short flags);
void func_00424A50(void* self);
}
struct O2ABC90 { char pad[0xA8]; char* aA0; int aA4; };
extern "C" void func_002ABC90(O2ABC90* o)
{
    char* p;
    func_00424A50(o);
    p = o->aA0;
    {
        AllocGuard guard;
        if (p) {
            char* s = p + 0x14;
            if (s)
                String_Dtor(s, 0);
        }
        Mem_Free(0, p, "GuiMissionList.cc", 0x2E6);
    }
    o->aA0 = 0;

}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002ABC90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002ABC90 */

/* merge_units: begin func_002ABD50 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x10]; unsigned char b10; unsigned char b11; unsigned char b12; char pad2[0x45]; unsigned char b58; } C2AB;
typedef struct { char pad[0x90]; C2AB* f90; } B2AB;
typedef struct { char pad[0x2480]; int f2480; } L2AB;
typedef struct { char pad[0x3C]; float f3c; float f40; char pad2[0x64]; C2AB* fa8; char p[4]; B2AB* fb0; char p2[8]; unsigned char bbc; char p3[3]; int fc0; int fc4; char p4[4]; int fcc; char p5[0x50]; int f120; } W2AB;
extern "C" {
extern void GuiArrayWidget_OnWake(W2AB*);
extern void* Mem_Alloc(int, int, char*, int);
extern char D_004AB9B0[];
extern char D_00587C40[];
extern int Gui_GetScreenList(void);
extern int GuiFont_Find(int, char*);
extern C2AB* TextObj_Construct(void*, int, int, int, int, int, char*);
extern void TextObj_SetText(C2AB*, char*);
extern L2AB* DME_GetLobby(void);
extern int func_0044FA40(L2AB*);
}
extern "C" void func_002ABD50(W2AB* w) {
    char buf[0x50];
    C2AB* c;
    L2AB* l;
    GuiArrayWidget_OnWake(w);
    {
        AllocGuard g;
        c = (C2AB*)Mem_Alloc(0, 0x60, D_004AB9B0, 0x2C5);
    }
    if (c) {
        int x = (int)w->f3c;
        int y = (int)w->f40;
        c = TextObj_Construct(c, 0, 0, x, y, GuiFont_Find(Gui_GetScreenList(), "callout"), D_00587C40);
    }
    w->fa8 = c;
    w->fa8->b12 = 1;
    w->fa8->b10 = 2;
    memset(buf, 0x2A, 0x50);
    buf[0x4F] = 0;
    TextObj_SetText(w->fa8, buf);
    w->fcc = -1;
    w->fc4 = -1;
    w->fc0 = -1;
    l = DME_GetLobby();
    w->f120 = l ? l->f2480 : -1;
    {
        C2AB* x = w->fb0->f90;
        if (x) {
            x->b11 = 1;
            x->b58 = 1;
        }
    }
    w->bbc = l != 0 && func_0044FA40(l) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002ABD50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002ABD50 */
