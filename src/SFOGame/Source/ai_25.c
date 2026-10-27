/*
 * SFOGame/Source/ai: 2 files, 0016DFA0-0016DFD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016DFA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Initializes a few fields of an AI state record.
 */

#include "types.h"

extern char g_LevelFarDistance[]; /* float */
extern char g_VideoFrameCounter[]; /* pointer */

typedef struct AIStateInit {
    char pad00[0x10];
    float unk10;  /* 0x10 */
    int unk14;    /* 0x14: written as the bit pattern of pi/4 */
    char pad18[0x38];
    int unk50;    /* 0x50 */
} AIStateInit;

void cAITarget_Activate(AIStateInit* self) {
    self->unk14 = 0x3F490FDB; /* 0.7853982f */
    self->unk10 = *(float*)g_LevelFarDistance;
    self->unk50 = *(int*)g_VideoFrameCounter + 20;
}
static inline void merge_flush_func_0016DFA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016DFA0 */

/* merge_units: begin func_0016DFD0 */
#pragma push /* merge_units */
extern void cAITarget_dtor(void* self);
extern void cLList_cTargetAwarenessPtr_dtor(void* p, int flag);
extern void operator_delete(void* p);
void* func_0016DFD0(char* self, short flag)
{
    if (self) {
        void* m;
        cAITarget_dtor(self);
        m = self + 0x30;
        if (m)
            cLList_cTargetAwarenessPtr_dtor(m, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_0016DFD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016DFD0 */
