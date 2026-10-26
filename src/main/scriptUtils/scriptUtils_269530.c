/*
 * main/scriptUtils: range (7 files, 00269530-002699E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptUtils_types.h"

/* merge_units: begin func_00269530 */
#pragma push /* merge_units */
void* cNodeList_SOBJ_convert(void* self); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern ListPos* List_InsertBefore(ListPos* result, void* list, ListPos* pos, int value);
extern int cNode_Identity(void* obj);
#if 0 /* merge_units */
extern cNodeList* cNodeList_SOBJ_convert(void* obj);
#endif /* merge_units */
#define cNodeList_SOBJ_convert(a0) ((cNodeList *)cNodeList_SOBJ_convert((a0))) /* merge_units */

extern void* Group_GetAt(ScriptGroup* group, int index);

/* push_back on a list whose sentinel node is at +4. */
ListPos* List_PushBack_269530(void* list, int value) {
    ListPos end;
    ListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}

/* Script native: cNodeList.Get(index = args[1]); returns the element's script handle.
 * volatile mirrors the original stack temporary. */
int Script_cNodeList_Get(ScriptArg* args) {
    volatile int arg1 = args[1].i;
    int index = arg1;

    return cNode_Identity(Group_GetAt(cNodeList_SOBJ_convert(args[0].p)->group, index));
}

/* Script native: cNodeList.GetSize(). volatile mirrors the original stack temporary. */
int Script_cNodeList_GetSize(ScriptArg* args) {
    volatile int count = cNodeList_SOBJ_convert(args[0].p)->group->count;
    return count;
}
#undef cNodeList_SOBJ_convert /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269530(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269530 */

/* merge_units: begin func_002695E0 */
#pragma push /* merge_units */
typedef struct NodeList {
    char pad[0x60];
    void* group;
} NodeList;

extern int ScriptNode_Identity(int);
#if 0 /* merge_units */
extern NodeList* cNodeList_SOBJ_convert(void*);
#endif /* merge_units */
#define cNodeList_SOBJ_convert(a0) ((NodeList *)cNodeList_SOBJ_convert((a0))) /* merge_units */

extern int Group_FindByObject(void*, int);

/* Script: cNodeList.Contains(node). */
int Script_cNodeList_Contains(ScriptArg* args) {
    int node = ScriptNode_Identity(args[1].i);
    return Group_FindByObject(cNodeList_SOBJ_convert(args[0].p)->group, node) != -1;
}
#undef cNodeList_SOBJ_convert /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002695E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002695E0 */

/* merge_units: begin func_00269630 */
#pragma push /* merge_units */
typedef struct { char pad[0x60]; void* list; } Obj00269630;
#if 0 /* merge_units */
extern int ScriptNode_Identity(int handle);
#endif /* merge_units */
#define ScriptNode_Identity(a0) (ScriptNode_Identity((a0))) /* merge_units */

#if 0 /* merge_units */
extern Obj00269630* cNodeList_SOBJ_convert(int handle);
#endif /* merge_units */
#define cNodeList_SOBJ_convert(a0) ((Obj00269630 *)cNodeList_SOBJ_convert((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int Group_FindByObject(void* list, int key);
#endif /* merge_units */
#define Group_FindByObject(a0, a1) (Group_FindByObject((a0), (a1))) /* merge_units */

/* Script: cNodeList.Find(key). */
int Script_cNodeList_Find(int* args)
{
    int key = ScriptNode_Identity(args[1]);
    volatile int result = Group_FindByObject(cNodeList_SOBJ_convert(args[0])->list, key);
    return result;
}
#undef ScriptNode_Identity /* merge_units */
#undef cNodeList_SOBJ_convert /* merge_units */
#undef Group_FindByObject /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269630(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269630 */

/* merge_units: begin func_00269680 */
#pragma push /* merge_units */
extern int D_004F8400;  /* cNodeList script type id (>= 100) */
extern void Group_AddObject(ScriptGroup* group, void* obj);
extern int Group_RemoveObject(ScriptGroup* group, void* obj);
#if 0 /* merge_units */
extern void* ScriptNode_Identity(int handle);
#endif /* merge_units */
#define ScriptNode_Identity(a0) ((void *)ScriptNode_Identity((a0))) /* merge_units */

extern int cNodeList_SOBJ_toInt(int value);
#if 0 /* merge_units */
extern cNodeList* cNodeList_SOBJ_convert(void* obj);
#endif /* merge_units */
#define cNodeList_SOBJ_convert(a0) ((cNodeList *)cNodeList_SOBJ_convert((a0))) /* merge_units */

extern int* cSystem_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int typeId, int value);
extern float Group_Shuffle(ScriptGroup* group);
extern int Group_AddObjectDup(ScriptGroup* group, void* obj);

/* Script native: cNodeList.Randomize(). */
int Script_cNodeList_Randomize(ScriptArg* args) {
    Group_Shuffle(cNodeList_SOBJ_convert(args[0].p)->group);
    return 0;
}

/* Script native: cNodeList.Remove(obj handle = args[1]). */
int Script_cNodeList_Remove(ScriptArg* args) {
    void* obj = ScriptNode_Identity(args[1].i);
    Group_RemoveObject(cNodeList_SOBJ_convert(args[0].p)->group, obj);
    return 0;
}

/* Script native: cNodeList.AddDup(obj handle = args[1]). */
int Script_cNodeList_AddDup(ScriptArg* args) {
    void* obj = ScriptNode_Identity(args[1].i);
    Group_AddObjectDup(cNodeList_SOBJ_convert(args[0].p)->group, obj);
    return 0;
}

/* Script native: cNodeList.Add(obj handle = args[1]). */
int Script_cNodeList_Add(ScriptArg* args) {
    void* obj = ScriptNode_Identity(args[1].i);
    Group_AddObject(cNodeList_SOBJ_convert(args[0].p)->group, obj);
    return 0;
}

/* Registers the cNodeList script type with the value returned by cSystem_GetScriptTypeKeyPtr. */
void ScriptType_cNodeList_Init(void) {
    int* key = cSystem_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F8400, *key);
}

int func_002697D0(int value) {
    return cNodeList_SOBJ_toInt(value);
}

/* Identity. volatile mirrors the original stack temporary. */
int cNodeList_SOBJ_toInt(int value) {
    volatile int v = value;
    return v;
}

cNodeList* func_00269800(void* obj) {
    return cNodeList_SOBJ_convert(obj);
}
#undef ScriptNode_Identity /* merge_units */
#undef cNodeList_SOBJ_convert /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269680(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269680 */

/* merge_units: begin func_00269810 */
#pragma push /* merge_units */
extern int D_004F83F8;  /* cNodeList script type key */
extern char D_00555070[];  /* script manager */
extern int ScriptFilter_Dispatch(void* manager, void* receiver, void* event);
extern int* cNodeList_SOBJ_getClassId(void);

/* Cast from script object to cNodeList (identity). */
void* cNodeList_SOBJ_convert(void* self) {
    return self;
}

int* func_00269820(void) {
    return cNodeList_SOBJ_getClassId();
}

int* cNodeList_SOBJ_getClassId(void) {
    return &D_004F83F8;
}

/* Returns the cNodeList script type key. */
int cNodeList_v0B(void) {
    return *cNodeList_SOBJ_getClassId();
}

/* Script event filter: dispatches to script handlers through the script manager. */
int cNodeList_v0C(void* self, void* event) {
    return ScriptFilter_Dispatch(D_00555070, self, event);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269810 */

/* merge_units: begin func_00269880 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0; /* network write cursor */

static inline void write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

static inline void write32(int v)
{
    write16((unsigned short)v);
    write16(v >> 16);
}

static inline void writeFloat(float f)
{
    write32(*(int*)&f);
}

typedef struct { char pad[0x24]; float time; int id; } cNetLocalTimerMsg;

/* cNetLocalTimerMsg virtual 4: writes the time (raw float bits) and the id little-endian. */
void cNetLocalTimerMsg_v04(cNetLocalTimerMsg* self)
{
    writeFloat(self->time);
    write32(self->id);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269880(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269880 */

/* merge_units: begin func_002699E0 */
#pragma push /* merge_units */
extern int D_004F8588;  /* script type key of cNetLocalTimerMsg */

/* Returns the cNetLocalTimerMsg script type key. */
int cNetLocalTimerMsg_v05(void) {
    return D_004F8588;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002699E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002699E0 */
