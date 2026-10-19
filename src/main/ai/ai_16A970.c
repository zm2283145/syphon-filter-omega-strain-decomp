/*
 * main/ai: range (2 files, 0016A970-0016AA80)
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

/* merge_units: begin func_0016A970 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Alloc(...);
int TeamRelations_CreateMultiplayer(...);
int TeamRelations_SetDefaults(...);
extern unsigned char D_0048A100;
extern char D_0049C650;
extern int D_004EE620;
extern unsigned char D_004EE628;
extern unsigned char g_ProfileLockEnabled;
extern unsigned char g_IsMultiplayer;
}
extern "C" void TeamRelations_Create(void) {
    int temp_s0;

    if (g_IsMultiplayer != 0) {
        if (D_004EE628 == 0) {
            TeamRelations_CreateMultiplayer();
        }
        if (D_0048A100 != 0) {
            D_0048A100 = 0;
            TeamRelations_SetDefaults(D_004EE620);
        }
    } else {
        if (D_004EE620 == 0) {
            {
                AllocGuard g;
            temp_s0 = Mem_Alloc(0, 0x100, &D_0049C650, 0x71B);
            }
            asm { nop } /* scheduling barrier: keeps the store after the unlock, as in retail */
            D_004EE620 = temp_s0;
        }
        TeamRelations_SetDefaults(D_004EE620);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016A970(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016A970 */

/* merge_units: begin func_0016AA80 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
#if 0 /* merge_units */
extern void* D_004EE620;
#endif /* merge_units */
#define D_004EE620 (*(void **)&D_004EE620) /* merge_units */

#if 0 /* merge_units */
extern signed char D_0048A100;
#endif /* merge_units */
#define D_0048A100 (*(signed char*)&D_0048A100) /* merge_units */

extern unsigned char D_005723C8;
#if 0 /* merge_units */
extern char D_0049C650[];
#endif /* merge_units */
#define D_0049C650 ((char*)&D_0049C650) /* merge_units */

}
extern "C" void TeamRelations_Teardown(void)
{
    void* p = D_004EE620;
    if (p && !D_004EE628) {
        AllocGuard g;
        Mem_Free(0, p, D_0049C650, 0x6FE);
    }
    D_004EE620 = 0;
    D_004EE628 = 0;
    D_0048A100 = 1;
}
#undef D_004EE620 /* merge_units */
#undef D_0048A100 /* merge_units */
#undef D_0049C650 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016AA80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016AA80 */
