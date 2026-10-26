/*
 * main/NPCInfoObject: 3 files, 004343E0-004344A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004343E0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cNPCInfoObject_Setup();                                  
char * cNPCInfoObject_Find(int *, int);                      

int cNPCInfoObject_GetOwner_uint(int d0, int arg1) {
    int sp1C;
    unsigned char temp_v0;
    char * temp_v0_2;

    sp1C = arg1;
    cNPCInfoObject_Setup();
    temp_v0_2 = cNPCInfoObject_Find(&sp1C, 0);
    if (temp_v0_2 != NULL) {
        temp_v0 = F_(temp_v0_2, 0x4, unsigned char);
        if (temp_v0 != 0xFF) {
            return temp_v0;
        }
    }
    return -1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004343E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004343E0 */

/* merge_units: begin func_00434440 */
#pragma push /* merge_units */
typedef struct { char pad[4]; unsigned char state; } E4440;
extern int cNPCInfoObject_Setup(int a);
#if 0 /* merge_units */
extern E4440* cNPCInfoObject_Find(int key, int b);
#endif /* merge_units */
#define cNPCInfoObject_Find(a0, a1) ((E4440 *)cNPCInfoObject_Find((int *)(a0), (a1))) /* merge_units */


int cNPCInfoObject_GetOwner_cObjectIdR(int a, int key) {
    E4440* p;
    cNPCInfoObject_Setup(a);
    p = cNPCInfoObject_Find(key, 0);
    if (p != 0 && p->state != 0xFF) return p->state;
    return -1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00434440(void) {}
#undef cNPCInfoObject_Find /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00434440 */

/* merge_units: begin func_004344A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */

#include "npc_types.h"

extern void cNPCInfoObject_SetOwner_cObjectIdR_int(void* self, int* key);

/* Calls cNPCInfoObject_SetOwner_cObjectIdR_int with the key passed by address. */
void cNPCInfoObject_SetOwner_uint_int(void* self, int key) {
    int k[1];

    *(int*)(char*)k = key;
    cNPCInfoObject_SetOwner_cObjectIdR_int(self, k);
}
#pragma pop /* merge_units */
/* merge_units: end func_004344A0 */
