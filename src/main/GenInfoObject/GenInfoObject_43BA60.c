/*
 * main/GenInfoObject: 3 files, 0043BA60-0043BB20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043BA60 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int m0; void* m4; } R1Tree_0043BA60;
typedef struct { R1Tree_0043BA60 tree; } R1Own_0043BA60;
extern void func_0043BA00(R1Tree_0043BA60* t, short del);
extern void operator_delete(void* p);
R1Own_0043BA60* func_0043BA60(R1Own_0043BA60* o, short del)
{
    if (o) {
        R1Tree_0043BA60* t = &o->tree;
        if (t)
            func_0043BA00(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043BA60 */

/* merge_units: begin func_0043BAC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_0043BAC0, func_00135C90)
#pragma pop /* merge_units */
/* merge_units: end func_0043BAC0 */

/* merge_units: begin func_0043BB20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void func_00293950();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E3B0();
extern "C" void func_0041E470();
extern "C" void func_0041EBF0();
extern "C" void func_0041EF10();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern "C" void func_0043BB80();
extern "C" void func_0043BB90();
extern "C" void func_0043BDE0();
extern "C" void func_0043BE70();
extern void * const D_004E0F40[];
void* func_0041F370(void* self, short deleteFlag);
}
extern "C" VtableObject* func_0043BB20(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0F40);
        func_0041F370(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0F40[24] = { (void*)0x0, (void*)0x0, (void*)func_0043BB20, (void*)func_0043BE70, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0043BDE0, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00293950, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_0041EF10, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_0043BB80, (void*)func_0043BB90, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_0043BB20 */
