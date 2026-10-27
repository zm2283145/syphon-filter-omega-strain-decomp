/*
 * Libs/SFOLib/Source/ska: 2 files, 003AB880-003AB8B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003AB880 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char unused; } Alloc;
typedef struct { Alloc alloc; int value; } TaggedInt;
extern void std_list_imp_voidPtr_remove_if(void* self, TaggedInt arg);
/* Forwards value, paired with an empty allocator tag, to std_list_imp_voidPtr_remove_if. */
void cLList_cSkaTransPlaybackPtr_Remove(void* self, int value)
{
    Alloc alloc;
    TaggedInt arg;
    arg.alloc = alloc;
    arg.value = value;
    std_list_imp_voidPtr_remove_if(self, arg);
}
static inline void merge_flush_func_003AB880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AB880 */

/* merge_units: begin func_003AB8B0 */
#pragma push /* merge_units */
#pragma bool off

typedef struct CurveE6 { char pad[0x3C]; } CurveE6;
typedef struct ChannelsE6 { CurveE6* data; int count; } ChannelsE6;

extern CurveE6** std_vector_deleter_cSkaSliderValue_data(ChannelsE6* self);
extern void cSplinedMotion_float_NextFrame(CurveE6* c, float dt, float rate);

static inline int CurveE6_Ne(CurveE6* a, CurveE6* b) { return (a == b) ^ 1; }

/* Advances every scalar curve channel. */
void cSkaSliderValueList_NextFrame(ChannelsE6* self, float dt, float rate)
{
    CurveE6* it = *std_vector_deleter_cSkaSliderValue_data(self);
    CurveE6* end = *std_vector_deleter_cSkaSliderValue_data(self) + self->count;
    for (; CurveE6_Ne(it, end); it++) {
        cSplinedMotion_float_NextFrame(it, dt, rate);
    }
}
static inline void merge_flush_func_003AB8B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AB8B0 */
