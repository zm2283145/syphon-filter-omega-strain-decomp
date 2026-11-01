/*
 * Libs/SFOLib/Source/scriptManager: 4 files, 003E03D0-003E0510
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E03D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back: inserts one value at the end. */
int std_vector_StringPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

void cScriptInterpreter_setInstructionPtr(ScriptManager* self, int value) {
    self->unk4E68 = value;
}
static inline void merge_flush_func_003E03D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E03D0 */

/* merge_units: begin func_003E0400 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cScriptInterpreter_getObjPtr */
struct Pt2_ObjId { unsigned int v; int Hi() const { return (v & 0xFF0000) >> 16; } int Lo() const { return v & 0xFFFF; } };
struct Pt2_SObj { virtual void v0(); virtual void v1(); virtual void v2(); virtual Pt2_SObj* Resolve(); };
extern "C" {
Pt2_SObj* nGobjManager_LookupGOBJ_cObjectIdR(const Pt2_ObjId&);
void cScriptBase_sm_printf(char*, int, int);
}
extern "C" Pt2_SObj* cScriptInterpreter_getObjPtr(unsigned int id) {
    Pt2_ObjId key;
    unsigned char direct;
    Pt2_SObj* o;
    direct = !((id & 0x80000000) != 0);
    key.v = id & 0x7FFFFFFF;
    o = nGobjManager_LookupGOBJ_cObjectIdR(key);
    if (!o) {
        if (key.Hi() || key.Lo()) cScriptBase_sm_printf("gobj (%d/%d) not found", key.Hi(), key.Lo());
    } else if (direct) {
        o = o->Resolve();
    }
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E0400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E0400 */

/* merge_units: begin func_003E04C0 */
#pragma push /* merge_units */
#pragma cplusplus on
class D2_ScriptObj {
public:
    virtual void v0();
    virtual void v1();
    virtual int* GetId();
    int f4;
    int f8;
    int fC;
};
struct D2_SObj : public D2_ScriptObj { };
extern "C" int cScriptInterpreter_PackPtr(D2_ScriptObj* obj) {
    int id = -1;
    if (obj != 0) {
        id = *obj->GetId();
        if (id == obj->fC) id |= 0x80000000;
    }
    return id;
}
#pragma cplusplus reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E04C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E04C0 */

/* merge_units: begin func_003E0510 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
/* cScriptInterpreter_callEvent_cSystemP_cMessageP_charP_int_etc: cScriptInterpreter::callEvent(cSystem*, const cMessage*, const char*, int, bool)
 * dispatch a message to matching event handlers (instance / instance-var / group / class) */
struct CeObjId { unsigned int id : 31; unsigned int hi : 1; };
struct CeSubScript { char pad0[0x64]; unsigned char mEnabled; };
struct CeVars { char pad0[0x8]; int type; };
struct CeSys {
    VPAD2(a) virtual CeObjId* GetObjectId(); virtual int v14(); VPAD4(b) VPAD2(c) VPAD1(d) virtual int GetRegType();
    char pad4[0x18 - 0x4]; CeVars* mScriptVars;
};
struct CeMsg { VPAD2(a) VPAD1(b) virtual int GetType(); };
struct CeFunc {
    char pad0[0x8]; char mParamVec[0x24 - 0x8];
    CeSubScript* mEnabler; int mInstanceId; CeObjId** mInstanceVar; void*** mGroup; int pad34; int mRefCnt;
    int pad3C; unsigned char mIsAlsoEvent;
};
struct CeArr { int pad0; int count; CeFunc** data; };
struct CeNode { char pad0[0x10]; CeArr* flist; };
struct CeIt { CeNode* n; };
struct CeClass { char pad0[0x40]; int parent; };
struct CeInterp { char pad0[0x4E5C]; void* mMessageHandlers; };
#pragma opt_strength_reduction off
extern "C" {
void std_tree_pair_int_value_compare_cAllocator_pair_find_intR(CeIt* out, void* tree, const int* key);
void func_003DD770(CeIt* out, void* tree);
void func_003DD760(CeIt* out, CeIt* src);
int** cArray_intPtr_opIndex_int(void* arr, int i);
int cGroup_Contains(void* grp, CeSys* g);
CeClass* cScriptBase_getClass(int t);
void cScriptInterpreter_callEvent_FuncDefP_cSystemP_cMessageP(CeInterp* self, CeFunc* f, CeSys* g, CeMsg* msg);

unsigned char cScriptInterpreter_callEvent_cSystemP_cMessageP_charP_int_etc(CeInterp* self, CeSys* g, CeMsg* msg, const char* name, int arg, unsigned char doAlso)
{
    CeFunc* classEvent = 0;
    CeFunc* instEvent = 0;
    CeFunc* instVarEvent = 0;
    CeFunc* instGroupEvent = 0;
    int classDepth = 1000;
    CeObjId* idptr = g->GetObjectId();
    unsigned char instVarHasEnabler = 0;
    unsigned char instGroupHasEnabler = 0;
    unsigned char classHasEnabler = 0;
    unsigned char called = 0;
    int msgType = msg->GetType();
    int objid; if (idptr) objid = *(int*)idptr; else objid = -1;
    int regThisType = g->GetRegType();
    CeIt end, it, e0;
    std_tree_pair_int_value_compare_cAllocator_pair_find_intR(&it, self->mMessageHandlers, &msgType);
    CeNode* node = it.n;
    func_003DD770(&e0, self->mMessageHandlers);
    func_003DD760(&end, &e0);
    if (node == end.n)
        return 0;
    {
        CeArr& flist = *node->flist;
        int n = flist.count;
        int i;
        for (i = 0; i < n; i++) {
            CeFunc* f = flist.data[i];
            if (!f->mRefCnt || f->mIsAlsoEvent != doAlso)
                continue;
            CeSubScript* enabler = f->mEnabler;
            unsigned char hasEnabler = enabler != 0;
            if (enabler == 0 || enabler->mEnabled) {
            if (f->mInstanceId >= 0) {
                if (objid >= 0 && objid == f->mInstanceId) {
                    if (doAlso) {
                        cScriptInterpreter_callEvent_FuncDefP_cSystemP_cMessageP(self, f, g, msg);
                        called = 1;
                    } else {
                        instEvent = f;
                        if (hasEnabler)
                            break;
                    }
                }
            } else if (f->mInstanceVar) {
                if (objid != -1 && objid == (**f->mInstanceVar).id) {
                    if (doAlso) {
                        cScriptInterpreter_callEvent_FuncDefP_cSystemP_cMessageP(self, f, g, msg);
                        called = 1;
                    } else if (!instVarEvent || hasEnabler > instVarHasEnabler) {
                        instVarEvent = f;
                        instVarHasEnabler = hasEnabler;
                    }
                }
            } else if (f->mGroup) {
                if (cGroup_Contains(**f->mGroup, g)) {
                    if (doAlso) {
                        cScriptInterpreter_callEvent_FuncDefP_cSystemP_cMessageP(self, f, g, msg);
                        called = 1;
                    } else if (!instGroupEvent || hasEnabler > instGroupHasEnabler) {
                        instGroupEvent = f;
                        instGroupHasEnabler = hasEnabler;
                    }
                }
            } else if (!instEvent && !instVarEvent && !instGroupEvent && (classDepth || !classEvent)) {
                int type = **cArray_intPtr_opIndex_int(f->mParamVec, 0);
                CeVars* vars = g->mScriptVars;
                int id = vars ? vars->type : -1;
                int depth;
                if (id < 0)
                    id = regThisType;
                for (depth = 0; id >= 0 && depth <= classDepth; depth++) {
                    if (type == id && (depth < classDepth || hasEnabler > classHasEnabler)) {
                        if (doAlso) {
                            cScriptInterpreter_callEvent_FuncDefP_cSystemP_cMessageP(self, f, g, msg);
                            called = 1;
                        } else {
                            classEvent = f;
                            classDepth = depth;
                            classHasEnabler = hasEnabler;
                        }
                        break;
                    }
                    id = cScriptBase_getClass(id)->parent;
                }
            }
            }
        }
    }
    if (!doAlso) {
        CeFunc* func = classEvent;
        if (instEvent) func = instEvent;
        if (instVarEvent) func = instVarEvent;
        if (instGroupEvent) func = instGroupEvent;
        if (func) {
            cScriptInterpreter_callEvent_FuncDefP_cSystemP_cMessageP(self, func, g, msg);
            called = 1;
        }
    }
    return called;
}
}
static inline void merge_flush_func_003E0510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E0510 */
