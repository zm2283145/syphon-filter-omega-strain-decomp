/*
 * main/Generator: range (2 files, 0021CC30-0021CC60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0021CC30 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct cGenerator {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Disable(int value); /* +0x68 */
};

/* Script native: cGenerator::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_cGenerator_DisableAnon(ScriptArg* args)
{
    cGenerator* obj = (cGenerator*)args[0].p;
    obj->Disable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CC30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CC30 */

/* merge_units: begin func_0021CC60 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_0021CC60 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_0021CC60;

/* Virtual-call view of cGenerator: only the slots used here are named (vtable offset in comments). */
struct cGenerator_0021CC60 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int who); /* +0x64 */
};

/* Script native: cGenerator::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_cGenerator_EnableAnon(ScriptArg_0021CC60* args)
{
    cGenerator_0021CC60* obj = (cGenerator_0021CC60*)args[0].p;
    obj->Enable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CC60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CC60 */
