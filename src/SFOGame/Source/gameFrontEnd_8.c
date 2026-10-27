/*
 * main/gameFrontEnd: range (2 files, 002C9A40-002C9AA0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

/* merge_units: begin func_002C9A40 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: restore vtable, run cMessage base, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_002C9A40, D_004D97F0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_002C9A40 */

/* merge_units: begin func_002C9AA0 */
#pragma push /* merge_units */
extern char g_Game[];
extern char D_004F2CC0[];
extern void* cSystemContainer_GetSystem(char* a, char* b);
extern void SoundMgr_StopMusic(void* p);
typedef struct { char pad[0x30C]; int handle; } Obj9AA0;
void FrontEnd_StopMusic(Obj9AA0* o)
{
    void* s = cSystemContainer_GetSystem(g_Game, D_004F2CC0);
    if (s)
        SoundMgr_StopMusic(s);
    o->handle = -1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C9AA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C9AA0 */
