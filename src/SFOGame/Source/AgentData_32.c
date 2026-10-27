/*
 * SFOGame/Source/AgentData: 3 files, 003361E0-00336460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003361E0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int unk0; int count; char* data; } BV_61E0;
typedef struct { unsigned char flag; char pad[3]; BV_61E0 v; int pad10; } E20_61E0;
typedef struct { int unk0; int count; E20_61E0* data; int pad; } V16_61E0;
typedef struct { int w[8]; } Lvl_61E0;
typedef struct { int capacity; unsigned int count; Lvl_61E0* data; } LvlVec_61E0;

typedef struct {
    char pad00[0x08];
    int stats[31];
    unsigned int objectiveBits[8];
    unsigned int missionBits[8];
    LvlVec_61E0 levels;
    char padD0[0xD8 - 0xD0];
    int unkD8;
    char padDC[0xAA8 - 0xDC];
    V16_61E0 lists[5];
    BV_61E0 bytes;
    int padB04;
    int unkB08[9];
    int unkB2C[9];
    int unkB50;
    char padB54[0xB68 - 0xB54];
    unsigned char unkB68;
    char padB69[3];
    int unkB6C;
    unsigned char unkB70;
    unsigned char unkB71;
    unsigned char unkB72;
    unsigned char padB73;
    unsigned char unkB74;
} Agent_61E0;

extern int g_LevelRowCount;
#if 0 /* merge_units */
int cArray_eRequirementState_Size(BV_61E0* v);
#endif /* merge_units */
int cArray_eRequirementState_Size(); /* merge_units */

#if 0 /* merge_units */
char* cArray_eRequirementState_opIndex(BV_61E0* v, int i);
#endif /* merge_units */
char * cArray_eRequirementState_opIndex(); /* merge_units */

void std_vector_imp_tMissionStats_resize(LvlVec_61E0* v, unsigned int n, const Lvl_61E0* value);

void cAgentData_Reset(Agent_61E0* a)
{
    int i;
    int k;
    int n;
    Lvl_61E0 e1;
    Lvl_61E0 e0;
    for (i = 0; i < 31; i++) a->stats[i] = 0;
    for (k = 0; k < 5; k++) {
        int j;
        for (j = 0; j < a->lists[k].count; j++) {
            E20_61E0* e = &a->lists[k].data[(unsigned)j];
            int m;
            e->flag = 0;
            for (m = 0; m < cArray_eRequirementState_Size(&e->v); m++) *cArray_eRequirementState_opIndex(&e->v, m) = 0;
        }
    }
    for (i = 0; i < a->bytes.count; i++) a->bytes.data[i] = 0;
    for (i = 0; i < 8; i++) a->objectiveBits[i] = 0;
    for (i = 0; i < 8; i++) a->missionBits[i] = 0;
    { int j; for (j = 0; j < 9; j++) a->unkB08[j] = 0; }
    { int j; for (j = 0; j < 9; j++) a->unkB2C[j] = 0; }
    a->unkD8 = 0;
    a->unkB50 = 0;
    a->unkB71 = 0;
    a->unkB70 = 0;
    n = g_LevelRowCount;
    e1.w[1] = -1;
    e1.w[0] = -1;
    e1.w[3] = 0;
    e1.w[2] = 0;
    e1.w[4] = -1;
    e1.w[5] = -1;
    e0.w[1] = -1;
    e0.w[0] = -1;
    e0.w[3] = 0;
    e0.w[2] = 0;
    e0.w[4] = -1;
    e0.w[5] = -1;
    std_vector_imp_tMissionStats_resize(&a->levels, 0, &e0);
    std_vector_imp_tMissionStats_resize(&a->levels, n, &e1);
    a->unkB72 = 0;
    a->unkB74 = 0;
    a->unkB6C = -1;
    a->unkB68 = 0;
}
static inline void merge_flush_func_003361E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003361E0 */

/* merge_units: begin func_00336440 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Byte-vector accessors.
 */

#include "AgentData_types.h"

int cArray_eRequirementState_Size(ByteVec* v) {
    return v->count;
}

char* cArray_eRequirementState_opIndex(ByteVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_00336440(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00336440 */

/* merge_units: begin func_00336460 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int cMemMan_Deallocate(int, int, char *, int);                         
int __destroy_array(char * , char *, int, int);               
int std_vector_charPtr_dtor_void_2(char * , int);                         
int std_vector_eAchievementState_dtor(char * , int);                         
int std_vector_deleter_tMissionStats_dtor(char * , int);                         
int operator_delete(char * );                          
extern unsigned char g_ProfileLockEnabled;
extern char cArray_tAchievement_dtor;
}
extern "C" char * cAgentData_dtor(char * arg0, long long arg1) {
    int temp_s2;
    char * temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        temp_s2 = F_(arg0, 0x9A4, int);
        {
            AllocGuard g;
        cMemMan_Deallocate(0, temp_s2, "AgentData.cc", 0xE0);
        }
        temp_a0 = arg0 + 0xB58;
        if (temp_a0 != NULL) {
            std_vector_charPtr_dtor_void_2(temp_a0, -1);
        }
        temp_a0_2 = arg0 + 0xAF8;
        if (temp_a0_2 != NULL) {
            std_vector_eAchievementState_dtor(temp_a0_2, -1);
        }
        __destroy_array(arg0 + 0xAA8, &cArray_tAchievement_dtor, 0x10, 5);
        temp_a0_3 = arg0 + 0xC4;
        if ((temp_a0_3 != NULL) && (temp_a0_3 != NULL) && (temp_a0_3 != NULL)) {
            std_vector_deleter_tMissionStats_dtor(temp_a0_3, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
static inline void merge_flush_func_00336460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00336460 */
