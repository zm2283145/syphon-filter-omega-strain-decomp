/*
 * main/GuiNetMessages: range (3 files, 00348FC0-003490F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable_member_base_dtor.h"
#pragma pop

/* merge_units: begin func_00348FC0 */
#pragma push /* merge_units */
typedef struct { int a; int b; int c; } Str348FC0;
typedef struct {
    void* vtable; char pad4[0x54]; unsigned char a58; char pad59[0x37];
    int a90; int a94; int a98; int a9C; int padA0; int aA4; Str348FC0 sA8;
} S348FC0;
extern char D_004DEB80[];
extern char D_004BA338[];
extern void func_00424C50(S348FC0* self);
extern char* Loc_LookupText(char* key);
extern void String_CtorCStr_13B480(Str348FC0* s, char* text);
extern void func_0013D680(Str348FC0* dst, Str348FC0* src);
extern void String_Dtor(Str348FC0* s, int flags);
S348FC0* func_00348FC0(S348FC0* self)
{
    Str348FC0 tmp;
    char* t;
    func_00424C50(self);
    self->vtable = D_004DEB80;
    self->sA8.a = 0;
    self->sA8.b = 0;
    self->sA8.c = 0;
    self->a90 = 0;
    self->a94 = 0;
    self->a98 = 0;
    self->a9C = 0;
    self->a58 = 2;
    self->aA4 = 0;
    t = Loc_LookupText("TOSSystem");
    { Str348FC0* p = &tmp; String_CtorCStr_13B480(p, t ? t : D_004BA338); }
    func_0013D680(&self->sA8, &tmp);
    String_Dtor(&tmp, 0);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00348FC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00348FC0 */

/* merge_units: begin func_00349070 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Derived destructor: member, then base, optionally delete. */
DEFINE_VTABLE_MEMBER_BASE_DTOR(func_00349070, D_004E0D20, 0x60, func_0013A040, func_0041F370)
#pragma pop /* merge_units */
/* merge_units: end func_00349070 */

/* merge_units: begin func_003490F0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: string member at +0xA8, middle class with a member at +0x60, base func_0041F370. */
extern "C" {
extern char D_004E0D20[];
#if 0 /* merge_units */
void operator_delete(void* allocation);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

#if 0 /* merge_units */
void* String_Dtor(void* self, short deleteFlag);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str348FC0 *)(a0), (int)(a1))) /* merge_units */

void* func_0013B2E0(void* self, short deleteFlag);
void* func_0041F370(void* self, short deleteFlag);
}
struct O3490F0 { void* vtable; };
extern "C" O3490F0* func_003490F0(O3490F0* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DEB80;
        char* m = (char*)self + 0xA8;
        if (m)
            String_Dtor(m, 0);
        if (self) {
            self->vtable = D_004E0D20;
            func_0013B2E0((char*)self + 0x60, -1);
            func_0041F370(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
#undef String_Dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003490F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003490F0 */
