/*
 * main/group: 8 files, 003D9960-003D9BF0
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

void func_003D9960(void) {
}

void* Group_FromHandle(void* self) {
    return self;
}

int cGroup_GetScriptTypeKeyPtr(void) {
    return (int)D_0055A120;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9960 */

/* merge_units: begin func_003D9990 */
#pragma push /* merge_units */
typedef struct { int a; int count; int* items; } G399;
extern void Script_PrintWarning(char*);
extern int Script_LookupObjectById(int);
int Group_GetAt(G399* g, int i) {
    if (i < 0 || !(i < g->count)) {
        Script_PrintWarning("group index out of range");
        return 0;
    }
    return Script_LookupObjectById(g->items[i]);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9990 */

/* merge_units: begin func_003D99F0 */
#pragma push /* merge_units */
void Group_Print(void) {
}
#pragma pop /* merge_units */
/* merge_units: end func_003D99F0 */

/* merge_units: begin func_003D9A00 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct Group {int capacity,count;int*items;} Group;
int Random_Next(void);
static inline float RandF(){return (float)Random_Next()/2147483648.0f;}
void Group_Shuffle(Group*g0){
 int count;Group*g=g0;int i=0;
 if(0<g->count)do{
 int n,value;count=*(volatile int*)&g->count;
 n=(int)((float)count*RandF());
 value=g->items[i];g->items[i]=g->items[n];g->items[n]=value;
 i++;
 }while(i<g->count);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9A00 */

/* merge_units: begin func_003D9AC0 */
#pragma push /* merge_units */
#include "loose04_types.h"

extern void Actor_VirtualLeaf175230(void*);

void Group_RemoveAll(void* self) {
    Actor_VirtualLeaf175230(self);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9AC0 */

/* merge_units: begin func_003D9AD0 */
#pragma push /* merge_units */
/* Group_RemoveObject */
typedef struct { int pad0; int count; int* ids; } Pt2_Group;
extern int Script_ObjectToId(void*);
extern void func_003E2FF0(Pt2_Group*, int, int*);

#pragma opt_strength_reduction off
void Group_RemoveObject(Pt2_Group* g, void* obj) {
    int id = Script_ObjectToId(obj);
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
            func_003E2FF0(g, n - 1, fill);
            return;
        }
    }
    Script_PrintWarning("warning: obj to remove is not in group");
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9AD0 */

/* merge_units: begin func_003D9BA0 */
#pragma push /* merge_units */
typedef struct { int unk0; int count; void** data; } PtrVector;
#if 0 /* merge_units */
extern void* Script_ObjectToId(void* object);
#endif /* merge_units */
#define Script_ObjectToId(a0) ((void *)Script_ObjectToId((a0))) /* merge_units */

extern void KeyVector_PushBack(PtrVector* vec, void** pos, int n, void** value);

/* Appends a duplicate handle of object to the group's pointer vector. */
void Group_AddObjectDup(PtrVector* group, void* object)
{
    void* dup = Script_ObjectToId(object);
    KeyVector_PushBack(group, group->data + group->count, 1, &dup);
}
#undef Script_ObjectToId /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D9BA0 */

/* merge_units: begin func_003D9BF0 */
#pragma push /* merge_units */
extern int Script_IsGroupMember(void* g, void* o);
#if 0 /* merge_units */
extern void Script_PrintWarning(char* msg);
#endif /* merge_units */
#define Script_PrintWarning(a0) (Script_PrintWarning((a0))) /* merge_units */

#if 0 /* merge_units */
extern void Group_AddObjectDup(void* g, void* o);
#endif /* merge_units */
#define Group_AddObjectDup(a0, a1) (Group_AddObjectDup((PtrVector *)(a0), (a1))) /* merge_units */

void Group_AddObject(void* g, void* o)
{
    if (Script_IsGroupMember(g, o)) {
        Script_PrintWarning("warning: obj already part of group (not added).");
    } else {
        Group_AddObjectDup(g, o);
    }
}
#undef Script_PrintWarning /* merge_units */
#undef Group_AddObjectDup /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D9BF0 */
