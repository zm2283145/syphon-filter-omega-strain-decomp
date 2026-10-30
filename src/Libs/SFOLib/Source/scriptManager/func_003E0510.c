#pragma cplusplus on
#include "types.h"
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
