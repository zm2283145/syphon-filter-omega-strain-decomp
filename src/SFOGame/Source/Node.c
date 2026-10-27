/*
 * main/node: range (5 files, 0015BE80-0015C080)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "node_types.h"

/* merge_units: begin func_0015BE80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cNode virtual slots: position getters and default (empty) handlers.
 */


extern int cNode_GetNodeMatrix(void* a0, cNode* node);

int cNode_v34(void* a0, cNode* node) {
    return cNode_GetNodeMatrix(a0, node);
}

/* v35..v37: write the node translation as a point (w = 1). */
void cNode_GetTranslation(Vec4* out, cNode* node) {
    float z = node->translation.z;
    float y = node->translation.y;
    float x = node->translation.x;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 1.0f;
}

void cNode_GetActivationPoint(Vec4* out, cNode* node) {
    float z = node->translation.z;
    float y = node->translation.y;
    float x = node->translation.x;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 1.0f;
}

void cNode_GetCenterOfMass(Vec4* out, cNode* node) {
    float z = node->translation.z;
    float y = node->translation.y;
    float x = node->translation.x;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 1.0f;
}

int cNode_v38(void* a0, cNode* node) {
    return cNode_GetNodeMatrix(a0, node);
}

int cNode_v39(void* a0, cNode* node) {
    return cNode_GetNodeMatrix(a0, node);
}

int cNode_v3B(void* a0, cNode* node) {
    return cNode_GetNodeMatrix(a0, node);
}

void cNode_Init(void) {
}

void cNode_Load(void) {
}

void cGOBJ_CriticalUpdateMotion(void) {
}

void cGOBJ_Enable(cNode* self) {
    self->flag2C = 1;
}

void cGOBJ_Disable(cNode* self) {
    self->flag2C = 0;
}

unsigned char cGOBJ_IsEnabled(cNode* self) {
    return self->flag2C;
}

int cGOBJ_HasHeadset(void) {
    return 0;
}

void cGOBJ_SetStatus(void) {
}

int cGOBJ_GetStatus(void) {
    return 0;
}

int cGOBJ_GetChildList_void(void) {
    return 0;
}

int cGOBJ_GetChildList_void_2(void) {
    return 0;
}

void cGOBJ_ScaleBBox(void) {
}

int cGOBJ_GetTargetPriority(void) {
    return 0;
}

int cGOBJ_GetMovementState(void) {
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015BE80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015BE80 */

/* merge_units: begin func_0015C030 */
#pragma push /* merge_units */
/* Returns 1.0f. */
float cGOBJ_GetSubTargetAimAdjust(void)
{
    return 1.0f;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015C030(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015C030 */

/* merge_units: begin func_0015C040 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int cGOBJ_GetNumSubTargets(void) {
    return 0;
}

int cGOBJ_IsAimed(void) {
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015C040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015C040 */

/* merge_units: begin func_0015C060 */
#pragma push /* merge_units */
typedef struct Object { char pad[0x58]; struct Object* attached; } Object;

/* Returns the object's attached object, or the object itself when none. */
Object* cGOBJ_ScriptGetRealObj(Object* o)
{
    if (o->attached)
        return o->attached;
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015C060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015C060 */

/* merge_units: begin func_0015C080 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cNode script type registration and small helpers.
 */


extern int D_004EA778; /* cNode script type key */
extern int D_004EA780; /* cNode script type id */
extern char D_00555070[]; /* global script filter */
extern int cScriptInterpreter_CallEvent(void* filter, int a1, int a2);
extern int* cGOBJ_SOBJ_getClassId(void); /* address of the cGObj type key */
extern void cScriptBase_declareParent(int type, int parentType);

void cGOBJ_InitNetwork(void) {
}

int cGOBJ_IsNetworked(void) {
    return 1;
}

int cGOBJ_CheckBullet(void) {
    return 0;
}

/* IsType(object, mask): nonzero when the object's type bits intersect mask. */
int Script_cNode_IsType(NodeScriptArg* args) {
    NodeScriptObj* obj = args[0].p;
    return (unsigned int)(args[1].u16 & obj->typeMask) > 0u;
}

/* cNode derives from cGObj. */
void cNode_SOBJ_init(void) {
    int* parent = cGOBJ_SOBJ_getClassId();
    cScriptBase_declareParent(D_004EA780, *parent);
}

/* volatile mirrors the original stack temporary. */
int cNode_SOBJ_toInt(int value) {
    volatile int tmp = value;
    return tmp;
}

void* cNode_SOBJ_convert(void* self) {
    return self;
}

int* cNode_SOBJ_getClassId(void) {
    return &D_004EA778;
}

int cNode_getSOBJClassId(void) {
    return D_004EA778;
}

int cNode_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015C080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015C080 */
