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


extern ListPos* std_list_deleter_voidPtr_insert(ListPos* result, void* list, ListPos* pos, int value);
extern int cNode_SOBJ_toInt(void* obj);
#if 0 /* merge_units */
extern cNodeList* cNodeList_SOBJ_convert(void* obj);
#endif /* merge_units */
#define cNodeList_SOBJ_convert(a0) ((cNodeList *)cNodeList_SOBJ_convert((a0))) /* merge_units */

extern void* cGroup_Get(ScriptGroup* group, int index);

/* push_back on a list whose sentinel node is at +4. */
ListPos* std_list_cNodeListPtr_push_back(void* list, int value) {
    ListPos end;
    ListPos result;

    end.node = (char*)list + 4;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}

/* Script native: cNodeList.Get(index = args[1]); returns the element's script handle.
 * volatile mirrors the original stack temporary. */
int Script_cNodeList_Get(ScriptArg* args) {
    volatile int arg1 = args[1].i;
    int index = arg1;

    return cNode_SOBJ_toInt(cGroup_Get(cNodeList_SOBJ_convert(args[0].p)->group, index));
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

extern int cNode_SOBJ_convert(int);
#if 0 /* merge_units */
extern NodeList* cNodeList_SOBJ_convert(void*);
#endif /* merge_units */
#define cNodeList_SOBJ_convert(a0) ((NodeList *)cNodeList_SOBJ_convert((a0))) /* merge_units */

extern int cGroup_Find_cSystemP(void*, int);

/* Script: cNodeList.Contains(node). */
int Script_cNodeList_Contains(ScriptArg* args) {
    int node = cNode_SOBJ_convert(args[1].i);
    return cGroup_Find_cSystemP(cNodeList_SOBJ_convert(args[0].p)->group, node) != -1;
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
extern int cNode_SOBJ_convert(int handle);
#endif /* merge_units */
#define cNode_SOBJ_convert(a0) (cNode_SOBJ_convert((a0))) /* merge_units */

#if 0 /* merge_units */
extern Obj00269630* cNodeList_SOBJ_convert(int handle);
#endif /* merge_units */
#define cNodeList_SOBJ_convert(a0) ((Obj00269630 *)cNodeList_SOBJ_convert((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int cGroup_Find_cSystemP(void* list, int key);
#endif /* merge_units */
#define cGroup_Find_cSystemP(a0, a1) (cGroup_Find_cSystemP((a0), (a1))) /* merge_units */

/* Script: cNodeList.Find(key). */
int Script_cNodeList_Find(int* args)
{
    int key = cNode_SOBJ_convert(args[1]);
    volatile int result = cGroup_Find_cSystemP(cNodeList_SOBJ_convert(args[0])->list, key);
    return result;
}
#undef cNode_SOBJ_convert /* merge_units */
#undef cNodeList_SOBJ_convert /* merge_units */
#undef cGroup_Find_cSystemP /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269630(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269630 */

/* merge_units: begin func_00269680 */
#pragma push /* merge_units */
extern int D_004F8400;  /* cNodeList script type id (>= 100) */
extern void cGroup_Add(ScriptGroup* group, void* obj);
extern int cGroup_Remove(ScriptGroup* group, void* obj);
#if 0 /* merge_units */
extern void* cNode_SOBJ_convert(int handle);
#endif /* merge_units */
#define cNode_SOBJ_convert(a0) ((void *)cNode_SOBJ_convert((a0))) /* merge_units */

extern int cNodeList_SOBJ_toInt(int value);
#if 0 /* merge_units */
extern cNodeList* cNodeList_SOBJ_convert(void* obj);
#endif /* merge_units */
#define cNodeList_SOBJ_convert(a0) ((cNodeList *)cNodeList_SOBJ_convert((a0))) /* merge_units */

extern int* cSystem_SOBJ_getClassId(void);
extern void cScriptBase_declareParent(int typeId, int value);
extern float cGroup_Randomize(ScriptGroup* group);
extern int cGroup_AddDup(ScriptGroup* group, void* obj);

/* Script native: cNodeList.Randomize(). */
int Script_cNodeList_Randomize(ScriptArg* args) {
    cGroup_Randomize(cNodeList_SOBJ_convert(args[0].p)->group);
    return 0;
}

/* Script native: cNodeList.Remove(obj handle = args[1]). */
int Script_cNodeList_Remove(ScriptArg* args) {
    void* obj = cNode_SOBJ_convert(args[1].i);
    cGroup_Remove(cNodeList_SOBJ_convert(args[0].p)->group, obj);
    return 0;
}

/* Script native: cNodeList.AddDup(obj handle = args[1]). */
int Script_cNodeList_AddDup(ScriptArg* args) {
    void* obj = cNode_SOBJ_convert(args[1].i);
    cGroup_AddDup(cNodeList_SOBJ_convert(args[0].p)->group, obj);
    return 0;
}

/* Script native: cNodeList.Add(obj handle = args[1]). */
int Script_cNodeList_Add(ScriptArg* args) {
    void* obj = cNode_SOBJ_convert(args[1].i);
    cGroup_Add(cNodeList_SOBJ_convert(args[0].p)->group, obj);
    return 0;
}

/* Registers the cNodeList script type with the value returned by cSystem_SOBJ_getClassId. */
void cNodeList_SOBJ_init(void) {
    int* key = cSystem_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F8400, *key);
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
#undef cNode_SOBJ_convert /* merge_units */
#undef cNodeList_SOBJ_convert /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269680(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269680 */

/* merge_units: begin func_00269810 */
#pragma push /* merge_units */
extern int D_004F83F8;  /* cNodeList script type key */
extern char D_00555070[];  /* script manager */
extern int cScriptInterpreter_CallEvent(void* manager, void* receiver, void* event);
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
int cNodeList_ScriptHandleMessage(void* self, void* event) {
    return cScriptInterpreter_CallEvent(D_00555070, self, event);
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
