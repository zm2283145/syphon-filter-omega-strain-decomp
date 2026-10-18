/*
 * main/gameobj: range (2 files, 00394720-00394740)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00394720 */
#pragma push /* merge_units */
extern char D_0053B540[];
extern void ParticleLib_Request(void* list, int value, void* item);

/* Registers the object's +0x60 sub-object in the global list D_0053B540. */
void ParticleGob_RequestPar(char* self, int* arg)
{
    ParticleLib_Request(D_0053B540, *arg, self + 0x60);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00394720(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00394720 */

/* merge_units: begin func_00394740 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct Sub {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual void Method14(void* arg); /* +0x14 */
};

struct Object {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21();
    virtual void Method90(void* p, int n); /* +0x90 */
    char pad04[0x50 - 4];
    Sub* sub;   /* +0x50 */
    char pad54[0x64 - 0x54];
    int unk64;  /* +0x64 */
    int unk68;
    int unk6C;  /* +0x6C */
};

/* Calls virtual +0x90(arg+0x10, 0), passes arg to the +0x50 object (virtual +0x14) and clears +0x64/+0x6C. */
extern "C" void ParticleGob_ResetTime(Object* self, char* arg)
{
    self->Method90(arg + 0x10, 0);
    self->sub->Method14(arg);
    self->unk64 = 0;
    self->unk6C = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00394740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00394740 */
