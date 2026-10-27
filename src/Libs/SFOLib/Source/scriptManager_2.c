/*
 * Libs/SFOLib/Source/scriptManager: 9 files, 003D9960-003D9C50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D9960 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0055A120[];

void cGroup_SOBJ_init(void) {
}

void* cGroup_SOBJ_convert(void* self) {
    return self;
}

int cGroup_SOBJ_getClassId(void) {
    return (int)D_0055A120;
}
static inline void merge_flush_func_003D9960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D9960 */

/* merge_units: begin func_003D9990 */
#pragma push /* merge_units */
typedef struct { int a; int count; int* items; } G399;
extern void cScriptBase_sm_printf(char*);
extern int cScriptInterpreter_getObjPtr(int);
int cGroup_Get(G399* g, int i) {
    if (i < 0 || !(i < g->count)) {
        cScriptBase_sm_printf("group index out of range");
        return 0;
    }
    return cScriptInterpreter_getObjPtr(g->items[i]);
}
static inline void merge_flush_func_003D9990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D9990 */

/* merge_units: begin func_003D99F0 */
#pragma push /* merge_units */
void cGroup_Print(void) {
}
static inline void merge_flush_func_003D99F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D99F0 */

/* merge_units: begin func_003D9A00 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct Group {int capacity,count;int*items;} Group;
int Libc_Rand(void);
static inline float RandF(){return (float)Libc_Rand()/2147483648.0f;}
void cGroup_Randomize(Group*g0){
 int count;Group*g=g0;int i=0;
 if(0<g->count)do{
 int n,value;count=*(volatile int*)&g->count;
 n=(int)((float)count*RandF());
 value=g->items[i];g->items[i]=g->items[n];g->items[n]=value;
 i++;
 }while(i<g->count);
}
static inline void merge_flush_func_003D9A00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D9A00 */

/* merge_units: begin func_003D9AC0 */
#pragma push /* merge_units */
#include "loose04_types.h"

extern void std_vector_deleter_cObjectId_clear(void*);

void Group_RemoveAll(void* self) {
    std_vector_deleter_cObjectId_clear(self);
}
static inline void merge_flush_func_003D9AC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D9AC0 */

/* merge_units: begin func_003D9AD0 */
#pragma push /* merge_units */
/* cGroup_Remove */
typedef struct { int pad0; int count; int* ids; } Pt2_Group;
extern int cScriptInterpreter_PackPtr(void*);
extern void std_vector_imp_cObjectId_resize(Pt2_Group*, int, int*);

#pragma opt_strength_reduction off
void cGroup_Remove(Pt2_Group* g, void* obj) {
    int id = cScriptInterpreter_PackPtr(obj);
    int n = g->count;
    int i;
    for (i = 0; i < n; i++) {
        if ((void*)g->ids[i] == (void*)id) {
            int j;
            int fill[1];
            for (j = i + 1; j < n; j++) {
                int k = j - 1;
                g->ids[k] = g->ids[j];
            }
            fill[0] = -1;
            std_vector_imp_cObjectId_resize(g, n - 1, fill);
            return;
        }
    }
    cScriptBase_sm_printf("warning: obj to remove is not in group");
}
static inline void merge_flush_func_003D9AD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D9AD0 */

/* merge_units: begin func_003D9BA0 */
#pragma push /* merge_units */
typedef struct { int unk0; int count; void** data; } PtrVector;
#if 0 /* merge_units */
extern void* cScriptInterpreter_PackPtr(void* object);
#endif /* merge_units */
#define cScriptInterpreter_PackPtr(a0) ((void *)cScriptInterpreter_PackPtr((a0))) /* merge_units */


extern void std_vector_imp_cObjectId_insert(PtrVector* vec, void** pos, int n, void** value);

/* Appends a duplicate handle of object to the group's pointer vector. */
void cGroup_AddDup(PtrVector* group, void* object)
{
    void* dup = cScriptInterpreter_PackPtr(object);
    std_vector_imp_cObjectId_insert(group, group->data + group->count, 1, &dup);
}
#undef cScriptInterpreter_PackPtr /* merge_units */
static inline void merge_flush_func_003D9BA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D9BA0 */

/* merge_units: begin func_003D9BF0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int cGroup_Contains(void* g, void* o);
#endif /* merge_units */
int cGroup_Contains(); /* merge_units */

#if 0 /* merge_units */
extern void cScriptBase_sm_printf(char* msg);
#endif /* merge_units */
#define cScriptBase_sm_printf(a0) (cScriptBase_sm_printf((a0))) /* merge_units */


#if 0 /* merge_units */
extern void cGroup_AddDup(void* g, void* o);
#endif /* merge_units */
#define cGroup_AddDup(a0, a1) (cGroup_AddDup((PtrVector *)(a0), (a1))) /* merge_units */


void cGroup_Add(void* g, void* o)
{
    if (cGroup_Contains(g, o)) {
        cScriptBase_sm_printf("warning: obj already part of group (not added).");
    } else {
        cGroup_AddDup(g, o);
    }
}
#undef cScriptBase_sm_printf /* merge_units */
#undef cGroup_AddDup /* merge_units */
static inline void merge_flush_func_003D9BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D9BF0 */

/* merge_units: begin group_3D9C50 */
#pragma push /* merge_units */
extern int cGroup_Find_cSystemP(void);

/* Script native: returns whether cGroup_Find_cSystemP result is not -1. */
int cGroup_Contains(void) {
    return cGroup_Find_cSystemP() != -1;
}
static inline void merge_flush_group_3D9C50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end group_3D9C50 */
