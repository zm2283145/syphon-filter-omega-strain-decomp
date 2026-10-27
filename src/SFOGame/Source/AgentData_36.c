/*
 * SFOGame/Source/AgentData: 9 files, 00336C50-00337020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00336C50 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "owned_buffer8_dtor_deep.h"
#pragma pop

#pragma cplusplus on

DEFINE_OWNED_BUFFER8_DTOR_MID(std_vector_imp_eRequirementState_1_dtor, D_004B99B8)
static inline void merge_flush_func_00336C50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00336C50 */

/* merge_units: begin func_00336D40 */
#pragma push /* merge_units */
typedef struct { char a; char pad[7]; int n; char* p; } B3_336D40;
void cAgentData_tAchievement_Reset(B3_336D40* s)
{
    int i;
    s->a = 0;
    for (i = 0; i < s->n; i++) {
        s->p[i] = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336D40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336D40 */

/* merge_units: begin func_00336D80 */
#pragma push /* merge_units */
#include "AgentData_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Small constructors / forwarding helpers.
 */


extern Rel* std_vector_imp_eRequirementState_1_ctor(Rel* r);
extern int std_vector_pod_eRequirementState_resize(int a0, int a1, int a2);

int cArray_eRequirementState_ResizeActual(int a0, int a1, int a2) {
    return std_vector_pod_eRequirementState_resize(a0, a1, a2);
}

/* Clears the three words and sets the flag. */
RelFlag* cArray_eRequirementState_ctor(RelFlag* self) {
    std_vector_imp_eRequirementState_1_ctor(&self->rel);
    self->flag = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336D80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336D80 */

/* merge_units: begin func_00336DC0 */
#pragma push /* merge_units */
extern int std_vector_pod_int_reserve(int, int);
extern Rel* std_vector_imp_tAchievement_ctor(Rel* r);

Rel* std_vector_imp_eRequirementState_1_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int std_vector_charPtr_reserve(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* std_vector_eAchievementState_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Clears the three words and sets the flag. */
RelFlag* cArray_tAchievement_ctor(RelFlag* self) {
    std_vector_imp_tAchievement_ctor(&self->rel);
    self->flag = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336DC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336DC0 */

/* merge_units: begin func_00336E40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* std_vector_imp_tAchievement_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Rel* std_vector_tMissionStats_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336E40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336E40 */

/* merge_units: begin func_00336E80 */
#pragma push /* merge_units */
#include "net_write_one_word.h"

typedef struct { char d[0xAC]; } E36E80;
extern int D_0052FE80;
extern E36E80 D_0052FE90[];
E36E80* func_00336E80(int unused, int i)
{
    if (i >= 0 && i < D_0052FE80)
        return &D_0052FE90[i];
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336E80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336E80 */

/* merge_units: begin func_00336EC0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char s[0x20]; } S20_36EC0;
typedef struct { char s[0x80]; } S80_36EC0;
typedef struct { int a, b, c; char s1[0x20]; char s2[0x80]; } E336EC0;
#if 0 /* merge_units */
extern E336EC0 D_0052FE90[];
#endif /* merge_units */
#define D_0052FE90 ((E336EC0*)&D_0052FE90) /* merge_units */



/* Appends a copy of e to the fixed 64-entry table. */
extern "C" void func_00336EC0(void* self, E336EC0* e)
{
    if (e && D_0052FE80 < 0x40) {
        D_0052FE90[D_0052FE80++] = *e;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336EC0(void) {}
#undef D_0052FE90 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00336EC0 */

/* merge_units: begin func_00336F70 */
#pragma push /* merge_units */
/* Serialize the 32-bit message field. */
DEFINE_NET_WRITE_ONE_WORD(cNetAddObjectiveMsg_Pack)
static inline void merge_flush_func_00336F70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00336F70 */

/* merge_units: begin func_00337020 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cNetAddObjectiveMsg virtual slot.
 */


extern int D_005329C8;

int cNetAddObjectiveMsg_GetMsgId(void) {
    return D_005329C8;
}
static inline void merge_flush_func_00337020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00337020 */
