/*
 * main/hotbox: range (3 files, 0016FB50-0016FBB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "hotbox_types.h"
#include "scriptUtils_types.h"

/* merge_units: begin func_0016FB50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */


int Script_cHotbox_Occupied(HotboxScriptArg* args) {
    return 0 < ((cHotbox*)args[0].p)->occupants;
}

int Script_cHotbox_ClearInteractMessage(HotboxScriptArg* args) {
    ((cHotbox*)args[0].p)->interactMessage = 0;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016FB50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016FB50 */

/* merge_units: begin func_0016FB70 */
#pragma push /* merge_units */
typedef struct cHotboxM {
    char pad00[0xA0];
    void* interactMessage; /* 0xA0 */
} cHotboxM;

extern void* Loc_LookupText(int id);

/* Script native: cHotbox.SetInteractMessage(textId). */
int Script_cHotbox_SetInteractMessage(ScriptArg* args) {
    volatile int id = args[1].i;
    cHotboxM* hotbox = args[0].p;
    hotbox->interactMessage = Loc_LookupText(id);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016FB70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016FB70 */

/* merge_units: begin func_0016FBB0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_0016FBB0 { int i; float f; void* p; unsigned char b; } ScriptArg_0016FBB0;

struct cHotbox_0016FBB0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Disable(int value); /* +0x68 */
};

/* Script native: cHotbox::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_cHotbox_Disable(ScriptArg_0016FBB0* args)
{
    cHotbox_0016FBB0* obj = (cHotbox_0016FBB0*)args[0].p;
    obj->Disable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016FBB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016FBB0 */
