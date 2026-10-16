/*
 * main/mem: 3 files, 00355790-00355920
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00355790 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiPersonnelMenu virtual (vtable D_004DF020 slot 5).
 */

#include "loose03_types.h"

extern void func_00356C70(GuiPersonnelScreen*);   /* GuiPersonnelScreen slot 5 */
extern int func_0036B250(int);                      /* mem.cc */
extern int func_0036B3B0(int, int, int);            /* mem.cc */

/* Calls the base implementation, then two mem.cc functions. */
int func_00355790(GuiPersonnelScreen* self) {
    func_00356C70(self);
    func_0036B250(1);
    return func_0036B3B0(1, 0x100000, 2048);
}
#pragma pop /* merge_units */
/* merge_units: end func_00355790 */

/* merge_units: begin func_003557D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003557D0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(...); };
extern "C" {
int String_CtorCStr_13B480(...);                 
int String_Dtor(...);                            
int func_0013D680(...);                          
int func_00355490(...);                         
int func_00356CD0(...);                                  
void **GuiWidget_FindChildByName(...);                  
int GuiArrayWidget_RowHeight(...);                       
extern "C" char D_004BB098[];
extern "C" char D_004BB0A8[];
extern "C" char D_004BB0B8[];
extern "C" char D_004BB0C8[];
static void * const dat_00492C50[2] = { (void*)D_004BB098, (void*)0x0 };
static void * const dat_00492C58[2] = { (void*)D_004BB0A8, (void*)0x0 };
static void * const dat_00492C60[2] = { (void*)D_004BB0B8, (void*)0x0 };
static void * const dat_00492C68[2] = { (void*)D_004BB0C8, (void*)0x0 };
extern char D_004B88F0;
extern char D_004BB0F8;
}
extern "C" void func_003557D0(char * arg0) {
    int sp40[4];
    int sp30[4];
    void **temp_v1;
    void **var_s0;
    char * temp_a0;

    func_00356CD0();
    String_CtorCStr_13B480(sp40, &D_004BB0F8);
    func_0013D680(arg0 + 0x6C, sp40);
    String_Dtor(sp40, 0);
    String_CtorCStr_13B480(sp30, &D_004BB0F8);
    func_0013D680(arg0 + 0x78, sp30);
    String_Dtor(sp30, 0);
    F_(arg0, 0x84, signed char) = 0;
    F_(arg0, 0x88, int) = -1;
    F_(arg0, 0x8C, int) = 0;
    F_(arg0, 0x90, int) = 0;
    var_s0 = GuiWidget_FindChildByName(arg0, (*(int*)dat_00492C60));
    F_(arg0, 0x98, int) = (int)(((var_s0 != NULL) && (((VC003557D0 *)(var_s0))->v20(&D_004B88F0) != 0)) ? var_s0 : NULL);
    temp_v1 = (void **)(F_(arg0, 0x98, int));
    if (temp_v1 != NULL) {
        F_(temp_v1, 0x70, int) = 0x42B40000;
    }
    F_(arg0, 0x9C, int) = (int)(GuiWidget_FindChildByName(arg0, (*(int*)dat_00492C50)));
    F_(arg0, 0xA0, int) = (int)(GuiWidget_FindChildByName(arg0, (*(int*)dat_00492C58)));
    F_(arg0, 0xA4, int) = (int)(GuiWidget_FindChildByName(arg0, (*(int*)dat_00492C68)));
    F_(arg0, 0xF4, signed char) = 0;
    temp_a0 = (char *)(F_(arg0, 0x48, int));
    GuiArrayWidget_RowHeight(temp_a0, F_(temp_a0, 0x5C, int) - 2);
    func_00355490(arg0, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_003557D0 */

/* merge_units: begin func_00355920 */
#pragma push /* merge_units */
typedef struct { char unused; } Alloc003491C0; /* empty allocator object passed by value */
typedef struct { int w0, w4, w8; } Str003491C0;
extern int strlen(const char* s);
extern void String_Reserve(Str003491C0* str, int n);
extern void String_Replace(Str003491C0* str, int pos, int count, const char* first, const char* last, Alloc003491C0 alloc);
/* Construct a string from a C string. */
Str003491C0* func_00355920(Str003491C0* str, const char* s)
{
    Alloc003491C0 alloc;
    int n;
    str->w0 = 0;
    str->w4 = 0;
    str->w8 = 0;
    n = strlen(s);
    String_Reserve(str, n);
    String_Replace(str, 0, 0, s, s + n, alloc);
    return str;
}
#pragma pop /* merge_units */
/* merge_units: end func_00355920 */
