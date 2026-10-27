/*
 * main/gameLight: range (2 files, 00179BB0-00179BF0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00179BB0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct LightBase { int unk0; }; /* data before the vtable pointer (vptr at +4) */
struct Light : LightBase {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08();
    virtual void Method2C(); /* +0x2C */
};

typedef struct cGameLight { char pad[0x60]; Light* light; /* +0x60 */ } cGameLight;

extern "C" void cGOBJ_Activate(cGameLight* self, void* arg);

/* cGOBJ_Activate then light object (+0x60) virtual slot +0x2C. */
extern "C" void cGameLight_Activate(cGameLight* self, void* arg)
{
    cGOBJ_Activate(self, arg);
    self->light->Method2C();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179BB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179BB0 */

/* merge_units: begin func_00179BF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Empty / constant virtual methods.
 */


void cGameLight_NextFrame(void) {
}

void cGameLight_Load(void) {
}

void cGameLight_Init(void) {
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179BF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179BF0 */
