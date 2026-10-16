/*
 * main/GuiNetMessages: range (6 files, 003488E0-00348B90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();
int sprintf(void *, const void *, ...);

/* merge_units: begin func_003488E0 */
#pragma push /* merge_units */
#include "types.h"
extern char D_004BA3B8[];
extern char D_004BA338[];
extern char* Loc_LookupText(char* key);
char* func_003488E0(void* self, int n)
{
    char buf[16];
    char* t;
    if (n < 0 || (unsigned int)n >= 12) return 0;
    sprintf(buf, D_004BA3B8, n);
    t = Loc_LookupText(buf);
    if (t) return t;
    return D_004BA338;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003488E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003488E0 */

/* merge_units: begin func_00348950 */
#pragma push /* merge_units */
typedef struct { char pad[0x94]; int a94; int a98; int a9C; } S348950;
int func_00348950(S348950* o, int k)
{
    switch (k) {
    case 9:
        return o->a98;
    case 0:
    case 1:
        return o->a9C;
    default:
        return o->a94;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00348950(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00348950 */

/* merge_units: begin func_003489A0 */
#pragma push /* merge_units */
extern char D_00587BF0[];
extern char D_00587C00[];
extern char D_00587C10[];
char* func_003489A0(void* self, int k)
{
    switch (k) {
    case 9:
        return D_00587BF0;
    case 0:
    case 1:
        return D_00587C10;
    default:
        return D_00587C00;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003489A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003489A0 */

/* merge_units: begin func_00348A00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
struct C348A00 { int pad0; int a4; char pad8[0x10]; unsigned char a18; };
class S348A00 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void f5C(int, int);
    char pad[0x48]; unsigned int a4C; int pad50; int a54; char pad2[0x4C]; C348A00* aA4;
};
extern "C" {
extern void GuiWidget_Update(S348A00*);
extern void func_00424410(S348A00*, int*, unsigned int*);
extern void GuiArrayWidget_Select(S348A00*, int, unsigned int);
extern void LobbyArray_SetDirty(C348A00*, int);
void func_00348A00(S348A00* o);
}
static inline void inl_348A00(S348A00* o)
{
    int a;
    unsigned int b;
    if (o->aA4) o->f5C(4, o->aA4->a4);
    func_00424410(o, &a, &b);
    if (b >= o->a4C && o->a4C != 0) b = o->a4C - 1;
    else if (b >= o->a4C) b = 0;
    o->a54 = 100000;
    GuiArrayWidget_Select(o, a, b);
}
void func_00348A00(S348A00* o)
{
    GuiWidget_Update(o);
    if (o->aA4 && o->aA4->a18) {
        inl_348A00(o);
        LobbyArray_SetDirty(o->aA4, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00348A00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00348A00 */

/* merge_units: begin func_00348AD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

/* Release the owned record at +0xA0 (string member at +0x14) under the allocator guard, clear +0xA0/+0xA4. */
extern "C" {
void* String_Dtor(void* self, short flags);
void func_00424A50(void* self);
}
struct O348AD0 { char pad[0xA0]; char* aA0; int aA4; };
extern "C" void func_00348AD0(O348AD0* o)
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
        Mem_Free(0, p, "GuiNetMessages.cc", 0xC1);
    }
    o->aA0 = 0;
    o->aA4 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00348AD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00348AD0 */

/* merge_units: begin func_00348B90 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x10]; unsigned char b10; unsigned char b11; unsigned char b12; char pad2[0x45]; unsigned char b58; } C48B90;
typedef struct { char pad[0x90]; C48B90* f90; } B48B90;
typedef struct { int f0; int f4; } L48B90;
class W48B90 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void SetCount(int kind, int n); /* +0x5C */
    char pad4[0x38]; float f3c; float f40; char p44[8]; unsigned int f4C; char p50[4]; int f54; char p58[0x38];
    B48B90* f90; char p94[0xC]; C48B90* fa0; L48B90* fa4;
};
extern "C" {
extern void GuiArrayWidget_OnWake(W48B90*);
extern void* Mem_Alloc(int, int, char*, int);
extern char D_004BA3D0[];
extern char D_00587C20[];
extern int Gui_GetScreenList(void);
extern int GuiFont_Find(int, char*);
extern C48B90* TextObj_Construct(void*, int, int, int, int, int, char*);
extern char* DME_GetLobby(void);
#if 0 /* merge_units */
extern void func_00424410(W48B90*, int*, unsigned int*);
#endif /* merge_units */
#define func_00424410(a0, a1, a2) (func_00424410((S348A00 *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void GuiArrayWidget_Select(W48B90*, int, unsigned int);
#endif /* merge_units */
#define GuiArrayWidget_Select(a0, a1, a2) (GuiArrayWidget_Select((S348A00 *)(a0), (a1), (a2))) /* merge_units */

}
/* List screen init: creates the callout, binds the lobby list and clamps the restored selection. */
extern "C" void func_00348B90(W48B90* w) {
    C48B90* c;
    GuiArrayWidget_OnWake(w);
    {
        AllocGuard g;
        c = (C48B90*)Mem_Alloc(0, 0x60, D_004BA3D0, 0x89);
    }
    if (c) {
        int x = (int)w->f3c;
        int y = (int)w->f40;
        c = TextObj_Construct(c, 0, 0, x, y, GuiFont_Find(Gui_GetScreenList(), "callout"), D_00587C20);
    }
    w->fa0 = c;
    w->fa0->b12 = 1;
    w->fa0->b10 = 2;
    if (DME_GetLobby()) w->fa4 = (L48B90*)(DME_GetLobby() + 0x1C);
    w->f54 = 0;
    if (w->fa4) w->SetCount(4, w->fa4->f4);
    {
        int top[1];
unsigned int sel[1];
        func_00424410(w, top, sel);
        if (sel[0] >= w->f4C && w->f4C != 0) sel[0] = w->f4C - 1;
        else if (sel[0] >= w->f4C) sel[0] = 0;
        w->f54 = 100000;
        GuiArrayWidget_Select(w, top[0], sel[0]);
    }
    if (w->f90 && w->f90->f90) {
        C48B90* x = w->f90->f90;
        x->b11 = 1;
        x->b58 = 1;
    }
}
#undef func_00424410 /* merge_units */
#undef GuiArrayWidget_Select /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00348B90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00348B90 */
