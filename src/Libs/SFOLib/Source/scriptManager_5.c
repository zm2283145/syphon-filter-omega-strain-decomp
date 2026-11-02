/*
 * Libs/SFOLib/Source/scriptManager: 5 files, 003DD760-003DDFC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003DD760 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_003DD760(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003DD770(Iter* out, Tree* t) {
    out->p = &t->header;
}

int* cArray_intPtr_opIndex_int(PtrVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_003DD760(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003DD760 */

/* merge_units: begin func_003DD790 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int strlen(const char *);

#pragma cplusplus on

struct Var3DD790 {
    int pad0[2];
    unsigned char active;
    int* ptr;
    int refs;
    int v14;
    unsigned char b18;
    int v1C;
};

struct Mgr3DD790 {
    char pad[0x28];
    int count;
    int arr[5000];
};

extern "C" {
void* cMemMan_Allocate(int, int, char*, int);
Var3DD790* cScriptInterpreter_findVar(Mgr3DD790*, char*, int);
#if 0 /* merge_units */
void cScriptBase_sm_printf(char*, char*);
#endif /* merge_units */
void cScriptBase_sm_printf(const char*, ...); /* merge_units */

Var3DD790* VarDef_ctor(void*, char*, int*, int*, int);
void std_vector_VarDefPtr_push_back(int, Var3DD790**);
extern char D_004BD4C0[];
extern char D_004BD4F0[];
extern int D_00554F18;
}

extern "C" Var3DD790* cScriptInterpreter_considerVar(Mgr3DD790* m, char* name, int id, int* out, int t0, int t1, int t2)
{
    Var3DD790* r;
    Var3DD790* p;
    bool has;

    r = cScriptInterpreter_findVar(m, name, id);
    has = out != 0;
    if (r) {
        if (r->active && has && !t2)
            cScriptBase_sm_printf(D_004BD4F0, name);
        if (!r->active || (t2 && has)) {
            r->b18 = has && t0 != 0;
            if (r->active && t2 && has) {
                r->b18 = 0;
                *out = *r->ptr;
            }
            r->active = has;
            r->ptr = out;
            r->v14 = t0;
        }
    } else {
        if (has)
            *out = 0;
        {
            AllocGuard g;
            p = (Var3DD790*)cMemMan_Allocate(0, 0x20, D_004BD4C0, 0xAB3);
        }
        if (p) {
            if ((unsigned int)m->count < 5000) {
                m->arr[m->count] = id;
                m->count++;
            }
            p = (Var3DD790*)VarDef_ctor(p, name, (int*)&m->count + m->count, out, 1);
        }
        r = p;
        p->v14 = t0;
        r->b18 = t0 != 0;
        std_vector_VarDefPtr_push_back(D_00554F18, &r);
    }
    if (has)
        r->v1C = t1;
    r->refs++;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DD790(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DD790 */

/* merge_units: begin func_003DD9F0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Al3DD { int x; };
struct Scr3DD {
    char* name;
    char m4[0x10];
    char m14[0x10];
    char m24[0x10];
    int x34;
    int x38;
    unsigned char x3C;
    char pad3d[3];
    int x40;
    unsigned char x44;
    unsigned char x45;
    char pad46[2];
    int x48;
    unsigned char x4C;
};
struct Info3DD { char pad0[8]; int x8; char padc[0x38 - 0xC]; int id; unsigned char on; };
struct Mgr3DD { int pad0; int count; };
extern "C" {
extern Mgr3DD* D_00554F28;
#if 0 /* merge_units */
void* cMemMan_Allocate(int pool, int size, char* file, int line);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (a1), (a2), (a3))) /* merge_units */



char* cScriptBase_myStrdup(char*);
Al3DD* cArrayCapacity_ctor(Al3DD*, int);
void cArray_FieldDefPtr_ctor(void*, Al3DD*, int);
void cArray_MemberFuncPtr_ctor(void*, Al3DD*, int);
void cArray_int_ctor(void*);
void std_vector_ClassDefPtr_push_back(Mgr3DD*, Scr3DD**);
void ClassDef_init(Scr3DD*, int, int, int, int, int);
Info3DD* cScriptInterpreter_findCls(int, char*);
}
static inline int Data3DD(Info3DD* i) { return i->on ? i->x8 : 0; }
extern "C" Scr3DD* cScriptInterpreter_considerClass(int ctx, char* name, int noInit, char* parent, int a, int b, int c)
{
    Scr3DD* s = (Scr3DD*)cScriptInterpreter_findCls(ctx, name);
    Info3DD* p = parent ? cScriptInterpreter_findCls(ctx, parent) : 0;
    int id = p ? p->id : -1;
    int d = (p && p->on) ? p->x8 : 0;
    if (!s) {
        Scr3DD* n;
        {
            AllocGuard g;
            n = (Scr3DD*)cMemMan_Allocate(0, 0x50, D_004BD4C0, 0xA84);
        }
        if (n) {
            char* nm = cScriptBase_myStrdup(name);
            Al3DD t1;
            cArray_FieldDefPtr_ctor(n->m4, cArrayCapacity_ctor(&t1, 5), 1);
            Al3DD t2;
            cArray_MemberFuncPtr_ctor(n->m14, cArrayCapacity_ctor(&t2, 5), 1);
            cArray_int_ctor(n->m24);
            n->name = nm;
            n->x34 = 0;
            n->x3C = 0;
            n->x40 = -1;
            n->x44 = 0;
            n->x45 = 0;
            n->x48 = 0;
            n->x4C = 1;
        }
        s = n;
        if (!noInit)
            ClassDef_init(s, a, b, c, id, d);
        s->x38 = D_00554F28->count + 100;
        std_vector_ClassDefPtr_push_back(D_00554F28, &s);
    } else if (!noInit) {
        ClassDef_init(s, a, b, c, id, d);
    }
    return s;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DD9F0(void) {}
#undef cMemMan_Allocate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003DD9F0 */

/* merge_units: begin func_003DDC30 */
#pragma push /* merge_units */
typedef struct { char pad[0xA8]; int* cursor; } Writer;
typedef struct { void* key; } KeyRef;
typedef struct { char* name; KeyRef* ref; int pad8; int count; KeyRef** args; } ScrEntry;
typedef struct { int x0; int count; void** data; } PtrList;
extern PtrList* D_00554F30;
#if 0 /* merge_units */
extern PtrList* D_00554F28;
#endif /* merge_units */
#define D_00554F28 (*(PtrList **)&D_00554F28) /* merge_units */



#if 0 /* merge_units */
extern PtrList* D_00554F18;
#endif /* merge_units */
#define D_00554F18 (*(PtrList **)&D_00554F18) /* merge_units */



extern PtrList* D_00554F20;
extern void ScriptFileBuff_put(Writer* w, int size);
extern int ScriptFileBuff_charsToInts(Writer* w, int size);
extern void ScriptFileBuff_expand(Writer* w, int words);
extern char* cScriptBase_getClassName(void* key);
extern void EnumDef_exportData(void*, Writer*);
extern void ClassDef_exportNames(void*, Writer*);
extern void ClassDef_exportFields(void*, Writer*);
extern void VarDef_exportData(void*, Writer*);
static inline void* At(PtrList* l, unsigned int i) { return l->data[i]; }
static inline void Writer_PutInt(Writer* w, int v)
{
    ScriptFileBuff_expand(w, 1);
    *w->cursor++ = v;
}
static inline void Writer_PutString(Writer* w, char* s)
{
    int size = strlen(s) + 1;
    int words;
    ScriptFileBuff_put(w, size);
    words = ScriptFileBuff_charsToInts(w, size);
    ScriptFileBuff_expand(w, words);
    Libc_Strcpy((char*)w->cursor, s);
    w->cursor += words;
}
void cScriptInterpreter_exportData(void* self, Writer* w)
{
    int n;
    int i;
    n = D_00554F30->count;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++)
        EnumDef_exportData(At(D_00554F30, i), w);
    n = D_00554F28->count;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++)
        ClassDef_exportNames(At(D_00554F28, i), w);
    for (i = 0; i < n; i++)
        ClassDef_exportFields(At(D_00554F28, i), w);
    n = D_00554F18->count;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++)
        VarDef_exportData(At(D_00554F18, i), w);
    n = D_00554F20->count;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++) {
        ScrEntry* e; int na; int j;
        e = (ScrEntry*)At(D_00554F20, i);
        Writer_PutString(w, e->name);
        na = e->count;
        Writer_PutString(w, cScriptBase_getClassName(e->ref->key));
        Writer_PutInt(w, na);
        for (j = 0; j < na; j++)
            Writer_PutString(w, cScriptBase_getClassName(e->args[(unsigned int)j]->key));
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DDC30(void) {}
#undef D_00554F28 /* merge_units */
#undef D_00554F18 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003DDC30 */

/* merge_units: begin func_003DDFC0 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct ScArray { int cap; int count; void** data; unsigned char canExpand; } ScArray;
typedef struct ScString { char* str; int refCnt; int depth; } ScString;
typedef struct ScVars { int pad[2]; int typeId; } ScVars;
struct ScSystem { virtual void v0(); virtual void v1(); virtual void* GetID(); int validator; void* name; int objId; int netId; unsigned char isLocal; ScVars* vars; void* list; };
typedef struct ScClassDef { char pad[0x40]; int mParentId; } ScClassDef;
typedef struct ScVarDef { char* mName; int* mType; unsigned char mDefined; int* mData; } ScVarDef;
typedef struct ScGroup { ScArray mMembers; } ScGroup;
typedef struct ScTable {
    ScArray vars;      /* 0x00 */
    ScArray funcs;     /* 0x10 */
    ScArray structs;   /* 0x20 */
    char pad30[0x30];
    ScArray strings;   /* 0x60 */
    char pad70[0x1C];
    int version;       /* 0x8C */
} ScTable;
typedef struct ScFuncDef {
    char* mName;
    int* mRetType;
    ScArray mParamVec;
    int* mCode;
    int (*mFuncPtr)(int*, int);
    ScTable* mContext;
} ScFuncDef;
typedef struct ScInterp {
    char pad0[0x18];
    ScArray mStrings;           /* 0x18 */
    char pad28[0x4E4C - 0x28];
    ScArray mAllocatedGroups;   /* 0x4E4C */
    void* mMessageHandlers;
    int mNumClientScripts;
    int mNumClientTypeInts;
    int* mInstructionPtr;       /* 0x4E68 */
    int* mStack;                /* 0x4E6C */
    int* mStackPtr;             /* 0x4E70 */
    int* mBasePtr;              /* 0x4E74 */
    int mStackSize;             /* 0x4E78 */
    int mDepth;                 /* 0x4E7C */
    int mCurDebugLine;          /* 0x4E80 */
    ScFuncDef* mCurFunc;        /* 0x4E84 */
} ScInterp;

extern "C" {
void* memset(void*, int, unsigned int);
char* Libc_Strcat(char*, const char*);
#if 0 /* merge_units */
char* Libc_Strcpy(char*, const char*);
#endif /* merge_units */
#define Libc_Strcpy(a0, a1) (Libc_Strcpy((void *)(a0), (const void *)(a1))) /* merge_units */

double SoftFloat_FloatToDouble(float);
int sprintf(char*, const char*, ...);
ScFuncDef** cArray_FuncDefPtr_opIndex(void*, int);
ScVarDef** cArray_VarDefPtr_opIndex(void*, int);
void cArray_cObjectId_ctor(void*);
char** cArray_charPtr_opIndex(void*, int);
int** cArray_intPtr_opIndex_int_2(void*, int);
void cGroup_Add(ScGroup*, int);
int cGroup_Get(ScGroup*, int);
#if 0 /* merge_units */
void* cMemMan_Allocate(int, int, const char*, int);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (a1), (char *)(a2), (a3))) /* merge_units */

ScClassDef* cScriptBase_getClass(int);
void cScriptBase_sm_printf(const char*, ...);
int cScriptInterpreter_PackPtr(int);
int cScriptInterpreter_Schedule(ScInterp*, ScFuncDef*, float, int*, int); /* prototype: Schedule(FuncDef*, float time, int* args, int cnt) */
int cScriptInterpreter_SymbolTable_remapEnum(ScTable*, int);
int cScriptInterpreter_SymbolTable_remapEnumVal(ScTable*, int, int);
int cScriptInterpreter_SymbolTable_remapType(ScTable*, int);
int cScriptInterpreter_allocString(ScInterp*, const char*);
int cScriptInterpreter_callFunction(ScInterp*, ScFuncDef*, int*, int);
void cScriptInterpreter_error(ScInterp*, const char*, ...);
ScString* cScriptInterpreter_findString(ScInterp*, int);
char* cScriptInterpreter_getEnumValString(ScInterp*, int, int);
int cScriptInterpreter_getObjPtr(int);
float cScriptInterpreter_popFloat(ScInterp*);
int cScriptInterpreter_popInt(ScInterp*);
void cScriptInterpreter_pushFloat(ScInterp*, float);
void cScriptInterpreter_pushInt(ScInterp*, int);
void cScriptInterpreter_removeString(ScInterp*, ScString*);
int cScriptVars_getExtVar(ScVars*, int);
char* nGobjManager_GetObjectName(void*, int);
ScString** std_vector_StringPtr_opIndex(void*, int);
void std_vector_cGroupPtr_push_back(void*, ScGroup**);
int cScriptInterpreter_execute(ScInterp* self, ScFuncDef* f);
}

static inline void MemClear_DFC0(void* dst, int n) {
    asm {
        .set noreorder
        blez n, done
        nop
        andi $v1, dst, 0xF
        andi $v0, n, 0xF
        or $v1, $v1, $v0
        nop
        bgtz $v1, bytes
        srl $v0, n, 4
        nop
        blez $v0, bytes
        nop
    quads:
        addi $v0, $v0, -1
        sq $zero, 0(dst)
        bgtz $v0, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
    done:
        .set reorder
    }
}

static inline float ScAbs(float x) { float r; asm { abs.s r, x } return r; }
static inline int ScFEq(float a, float b) { return ScAbs(a - b) < 0.001f; }

static inline ScString* ScAt(ScInterp* s, int i) { return (ScString*)s->mStrings.data[i]; }
static inline int ScSD(ScString* s) { return s->depth; } /* string depth accessor (colours depth after the string chain) */
int cScriptInterpreter_execute(ScInterp* self, ScFuncDef* f)
{
    /* Barrier (emits no code): a volatile asm switches MW to its less-optimised mode, which retail used for this
       function (no strength reduction / CSE, b;nop kept). Pending owner review, same idiom as cHuman_Land. */
    if (0) { asm volatile { nop } }

    unsigned char done;
    int retVal;
    int* saveBP;
    char tempstr[512];

    done = 0;
    saveBP = self->mBasePtr;
    self->mCurFunc = f;
    self->mCurDebugLine = -1;
    self->mDepth++;
    goto test; top: {
        int* ip = self->mInstructionPtr;
        int op = *(unsigned short*)ip;
        int data;
        float fval1;
        float fval2;
        int val1;
        int val2;
        int* ptr;
        int num;
        self->mInstructionPtr = ip + 1;
        data = *ip >> 16;
        switch (op) {
        case 0x1:
            self->mBasePtr = self->mStackPtr - 1;
            { self->mStackPtr = (int*)((char*)self->mStackPtr - data * 4);
            MemClear_DFC0(self->mStackPtr, data * 4); }
            break;
        case 0x2:
            if (*f->mRetType != 4) {
                retVal = cScriptInterpreter_popInt(self);
            }
            self->mBasePtr = saveBP;
            done = 1;
            self->mStackPtr += data;
            break;
        case 0x3E: {
            float time;
            int funcNum;
            int numArgs;
            int i;
            int* saveIP;
            int res;
            int args[20];
            time = cScriptInterpreter_popFloat(self);
            funcNum = cScriptInterpreter_popInt(self);
            numArgs = cScriptInterpreter_popInt(self);
            for (i = 0; i < numArgs; i++) {
                args[i] = cScriptInterpreter_popInt(self);
            }
            saveIP = self->mInstructionPtr;
            res = cScriptInterpreter_Schedule(self, *cArray_FuncDefPtr_opIndex(&f->mContext->funcs, funcNum), time, args, numArgs);
            if (f->mContext->version >= 7) {
                cScriptInterpreter_pushInt(self, res);
            }
            self->mInstructionPtr = saveIP;
            break;
        }
        case 0x40: {
            int args[20];
            int i;
            ScGroup* g;
            int numArgs;
            int cnt;
            int* saveIP;
            ScFuncDef* newf;
            newf = *cArray_FuncDefPtr_opIndex(&f->mContext->funcs, data);
            g = *(ScGroup**)cScriptInterpreter_popInt(self);
            numArgs = cScriptInterpreter_popInt(self);
            for (i = 0; i < numArgs; i++) {
                args[i + 1] = cScriptInterpreter_popInt(self);
            }
            cnt = g->mMembers.count;
            for (i = 0; i < cnt; i++) {
                args[0] = cGroup_Get(g, i);
                saveIP = self->mInstructionPtr;
                cScriptInterpreter_callFunction(self, newf, args, numArgs + 1);
                self->mInstructionPtr = saveIP;
            }
            break;
        }
        case 0x3F: {
            int numObjs;
            ScGroup* g;
            int i;
            ScGroup* p;
            numObjs = cScriptInterpreter_popInt(self);
            { AllocGuard lock; p = (ScGroup*)cMemMan_Allocate(0, 0x10, D_004BD4C0, 0x822); }
            if (p) {
                cArray_cObjectId_ctor(p);
            }
            g = p;
            std_vector_cGroupPtr_push_back(&self->mAllocatedGroups, &g);
            for (i = 0; i < numObjs; i++) {
                int obj = cScriptInterpreter_popInt(self);
                if (obj) {
                    cGroup_Add(g, obj);
                }
            }
            cScriptInterpreter_pushInt(self, (int)g);
            break;
        }
        case 0x12: {
            ScFuncDef* newf;
            int* saveIP;
            ScFuncDef* oldFunc;
            int* code;
            newf = *cArray_FuncDefPtr_opIndex(&f->mContext->funcs, data);
            saveIP = self->mInstructionPtr;
            oldFunc = self->mCurFunc;
            code = newf->mCode;
            if (code) {
                int r;
                self->mInstructionPtr = code;
                r = cScriptInterpreter_execute(self, newf);
                if (*newf->mRetType != 4) {
                    cScriptInterpreter_pushInt(self, r);
                }
            } else {
                int args[20];
                unsigned char null_ptr;
                int i;
                num = newf->mParamVec.count;
                null_ptr = 0;
                for (i = 0; i < num; i++) {
                    int paramType;
                    int v = cScriptInterpreter_popInt(self);
                    int off = i * 4;
                    *(int*)((char*)args + off) = v;
                    paramType = **(int**)((char*)newf->mParamVec.data + off);
                    if (paramType >= 100 || paramType == 3) {
                        if (args[i] < 1000) {
                            cScriptInterpreter_error(self, "null pointer param %d in call to %s", i, newf->mName);
                            null_ptr = 1;
                        }
                    }
                }
                if (null_ptr) {
                    if (*newf->mRetType != 4) {
                        cScriptInterpreter_pushInt(self, 0);
                    }
                } else {
                    int (*fptr)(int*, int) = newf->mFuncPtr;
                    if (fptr) {
                        retVal = fptr(args, num);
                    } else {
                        retVal = 0;
                        cScriptInterpreter_error(self, "null function pointer: C function %s", newf->mName);
                    }
                    if (*newf->mRetType != 4) {
                        cScriptInterpreter_pushInt(self, retVal);
                    }
                }
            }
            self->mInstructionPtr = saveIP;
            self->mCurFunc = oldFunc;
            break;
        }
        case 0x42: {
            ScSystem* sys;
            int id;
            val1 = *self->mInstructionPtr++;
            val1 = cScriptInterpreter_SymbolTable_remapType(f->mContext, val1);
            sys = (ScSystem*)cScriptInterpreter_popInt(self);
            if (!sys) {
                cScriptInterpreter_error(self, "can't cast null pointer");
            } else {
                ScVars* v = sys->vars;
                id = v ? v->typeId : -1;
                while (id > 0 && val1 != id) {
                    id = cScriptBase_getClass(id)->mParentId;
                }
                if (id <= 0) {
                    sys = 0;
                    cScriptBase_sm_printf("warning: dynamic cast failed");
                }
            }
            cScriptInterpreter_pushInt(self, (int)sys);
            break;
        }
        case 0x3D:
        case 0x41:
            val1 = cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushInt(self, cScriptInterpreter_getObjPtr(val1));
            break;
        case 0x3C:
            cScriptInterpreter_pushInt(self, cScriptInterpreter_PackPtr(cScriptInterpreter_popInt(self)));
            break;
        case 0x2F: {
            int num = *self->mInstructionPtr++;
            val2 = (*cArray_intPtr_opIndex_int_2(&f->mContext->structs, num))[data];
            val1 = cScriptInterpreter_popInt(self);
            if (!val1) {
                cScriptInterpreter_pushInt(self, 0);
                cScriptInterpreter_error(self, "null pointer error");
            } else {
                cScriptInterpreter_pushInt(self, val1 + val2);
            }
            break;
        }
        case 0x30: {
            int structIndex;
            ScSystem* sys;
            structIndex = *self->mInstructionPtr++;
            sys = (ScSystem*)cScriptInterpreter_popInt(self);
            if (sys) {
                int* varptr = (int*)cScriptVars_getExtVar(sys->vars, (*cArray_intPtr_opIndex_int_2(&f->mContext->structs, structIndex))[data]);
                if (!varptr) {
                    cScriptInterpreter_error(self, "null ext var pointer error");
                }
                cScriptInterpreter_pushInt(self, (int)varptr);
            } else {
                cScriptInterpreter_error(self, "null pointer error");
                cScriptInterpreter_pushInt(self, 0);
            }
            break;
        }
        case 0x4:
            self->mInstructionPtr += data;
            break;
        case 0x3:
            val1 = cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushInt(self, !val1);
            break;
        case 0x23:
        case 0x24: {
            val1 = cScriptInterpreter_popInt(self);
            ptr = (int*)cScriptInterpreter_popInt(self);
            if (ptr) {
                *ptr = val1;
            } else {
                cScriptInterpreter_error(self, "null pointer error");
            }
            break;
        }
        case 0x25: {
            unsigned char nonLocal;
            val1 = cScriptInterpreter_popInt(self);
            ptr = (int*)cScriptInterpreter_popInt(self);
            {
                bool t = true;
                int* stk = self->mStack;
                if (ptr >= stk && ptr <= stk + self->mStackSize) t = false;
                nonLocal = t;
            }
            if (nonLocal) {
                int s = *ptr;
                if (s) {
                    ScString* ss = cScriptInterpreter_findString(self, s);
                    if (ss && ss->refCnt-- == 0) {
                        cScriptInterpreter_removeString(self, ss);
                    }
                }
            }
            *ptr = val1;
            if (nonLocal) {
                ScString* ss = cScriptInterpreter_findString(self, *ptr);
                if (ss) {
                    ss->refCnt++;
                }
            }
            break;
        }
        case 0x31:
            val1 = cScriptInterpreter_popInt(self);
            sprintf(tempstr, "%d\0\0", val1); /* 5-byte literal: retail aligns it to 8 */
            cScriptInterpreter_pushInt(self, cScriptInterpreter_allocString(self, tempstr));
            break;
        case 0x32:
            sprintf(tempstr, "%.2f", SoftFloat_FloatToDouble(cScriptInterpreter_popFloat(self)));
            cScriptInterpreter_pushInt(self, cScriptInterpreter_allocString(self, tempstr));
            break;
        case 0x33: {
            ScSystem* g = (ScSystem*)cScriptInterpreter_popInt(self);
            if (!g) {
                Libc_Strcpy(tempstr, "Null Obj ptr");
            } else {
                void* id = g->GetID();
                if (id) {
                    sprintf(tempstr, nGobjManager_GetObjectName(id, 1));
                } else {
                    Libc_Strcpy(tempstr, "Null ID");
                }
            }
            cScriptInterpreter_pushInt(self, cScriptInterpreter_allocString(self, tempstr));
            break;
        }
        case 0x39: {
            val1 = cScriptInterpreter_popInt(self);
            val2 = *self->mInstructionPtr++;
            val2 = cScriptInterpreter_SymbolTable_remapEnum(f->mContext, val2);
            cScriptInterpreter_pushInt(self, cScriptInterpreter_allocString(self, cScriptInterpreter_getEnumValString(self, val2, val1)));
            break;
        }
        case 0x3A:
            val1 = cScriptInterpreter_SymbolTable_remapEnumVal(f->mContext, data, *self->mInstructionPtr++);
            cScriptInterpreter_pushInt(self, val1);
            break;
        case 0x34:
            cScriptInterpreter_pushInt(self, cScriptInterpreter_allocString(self, *cArray_charPtr_opIndex(&f->mContext->strings, data)));
            break;
        case 0x43:
            cScriptInterpreter_pushInt(self, (int)*cArray_charPtr_opIndex(&f->mContext->strings, data));
            break;
        case 0x1B: {
            char* s2 = (char*)cScriptInterpreter_popInt(self);
            char* s1 = (char*)cScriptInterpreter_popInt(self);
            if (!s1 || !s2) {
                tempstr[0] = 0;
                cScriptInterpreter_error(self, "Null String Detected");
            } else {
                Libc_Strcpy(tempstr, s1);
                Libc_Strcat(tempstr, s2);
            }
            cScriptInterpreter_pushInt(self, cScriptInterpreter_allocString(self, tempstr));
            break;
        }
        case 0x2A:
            cScriptInterpreter_pushInt(self, cScriptInterpreter_allocString(self, *(char**)cScriptInterpreter_popInt(self)));
            break;
        case 0x28:
        case 0x29: {
            ptr = (int*)cScriptInterpreter_popInt(self);
            if (ptr) {
                cScriptInterpreter_pushInt(self, *ptr);
            } else {
                cScriptInterpreter_error(self, "null ptr error");
                cScriptInterpreter_pushInt(self, 0);
            }
            break;
        }
        case 0x35: {
            int* ptr = (int*)cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushInt(self, *ptr);
            (*ptr)++;
            break;
        }
        case 0x36: {
            float* ptr = (float*)cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushFloat(self, *ptr);
            *ptr += 1.0f;
            break;
        }
        case 0x37: {
            int* ptr = (int*)cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushInt(self, *ptr);
            (*ptr)--;
            break;
        }
        case 0x38: {
            float* ptr = (float*)cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushFloat(self, *ptr);
            *ptr -= 1.0f;
            break;
        }
        case 0x5:
            val1 = cScriptInterpreter_popInt(self);
            if (!val1) {
                self->mInstructionPtr += data;
            }
            break;
        case 0x13:
            cScriptInterpreter_popInt(self);
            break;
        case 0x6: {
            val2 = cScriptInterpreter_popInt(self);
            val1 = cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushInt(self, val1 == val2);
            break;
        }
        case 0x8: {
            val2 = cScriptInterpreter_popInt(self);
            val1 = cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushInt(self, val1 > val2);
            break;
        }
        case 0xA: {
            val2 = cScriptInterpreter_popInt(self);
            val1 = cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushInt(self, val1 >= val2);
            break;
        }
        case 0xC: {
            val2 = cScriptInterpreter_popInt(self);
            val1 = cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushInt(self, val1 < val2);
            break;
        }
        case 0xE: {
            val2 = cScriptInterpreter_popInt(self);
            val1 = cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushInt(self, val1 <= val2);
            break;
        }
        case 0x10: {
            val2 = cScriptInterpreter_popInt(self);
            val1 = cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushInt(self, val1 != val2);
            break;
        }
        case 0x7: {
            fval2 = cScriptInterpreter_popFloat(self);
            cScriptInterpreter_pushInt(self, ScAbs(cScriptInterpreter_popFloat(self) - fval2) < 0.001f);
            break;
        }
        case 0x9: {
            fval2 = cScriptInterpreter_popFloat(self);
            cScriptInterpreter_pushInt(self, cScriptInterpreter_popFloat(self) - 0.001f > fval2);
            break;
        }
        case 0xB: {
            fval2 = cScriptInterpreter_popFloat(self);
            cScriptInterpreter_pushInt(self, cScriptInterpreter_popFloat(self) + 0.001f > fval2);
            break;
        }
        case 0xD: {
            fval2 = cScriptInterpreter_popFloat(self);
            cScriptInterpreter_pushInt(self, cScriptInterpreter_popFloat(self) + 0.001f < fval2);
            break;
        }
        case 0xF: {
            fval2 = cScriptInterpreter_popFloat(self);
            cScriptInterpreter_pushInt(self, cScriptInterpreter_popFloat(self) - 0.001f < fval2);
            break;
        }
        case 0x11: {
            fval2 = cScriptInterpreter_popFloat(self);
            cScriptInterpreter_pushInt(self, !ScFEq(cScriptInterpreter_popFloat(self), fval2));
            break;
        }
        case 0x15:
            cScriptInterpreter_pushInt(self, (int)(self->mBasePtr + data));
            break;
        case 0x16:
            cScriptInterpreter_pushInt(self, (int)(*cArray_VarDefPtr_opIndex(&f->mContext->vars, data))->mData);
            break;
        case 0x17:
        case 0x18:
            cScriptInterpreter_pushInt(self, *self->mInstructionPtr++);
            break;
        case 0x2C: {
            val1 = cScriptInterpreter_popInt(self);
            val2 = cScriptInterpreter_popInt(self);
            { unsigned char t = 0; if (!(val1 == 0 || val2 == 0)) t = 1; cScriptInterpreter_pushInt(self, t); }
            break;
        }
        case 0x2B: {
            val1 = cScriptInterpreter_popInt(self);
            val2 = cScriptInterpreter_popInt(self);
            { unsigned char t = 1; if (val1 == 0 && val2 == 0) t = 0; cScriptInterpreter_pushInt(self, t); }
            break;
        }
        case 0x19: {
            val2 = cScriptInterpreter_popInt(self);
            val1 = cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushInt(self, val1 + val2);
            break;
        }
        case 0x1C: {
            val2 = cScriptInterpreter_popInt(self);
            val1 = cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushInt(self, val1 - val2);
            break;
        }
        case 0x1E: {
            val2 = cScriptInterpreter_popInt(self);
            val1 = cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushInt(self, val1 * val2);
            break;
        }
        case 0x20: {
            val2 = cScriptInterpreter_popInt(self);
            val1 = cScriptInterpreter_popInt(self);
            cScriptInterpreter_pushInt(self, val1 / val2);
            break;
        }
        case 0x26:
            cScriptInterpreter_pushInt(self, -cScriptInterpreter_popInt(self));
            break;
        case 0x1A: {
            fval2 = cScriptInterpreter_popFloat(self);
            fval1 = cScriptInterpreter_popFloat(self);
            cScriptInterpreter_pushFloat(self, fval1 + fval2);
            break;
        }
        case 0x1D: {
            fval2 = cScriptInterpreter_popFloat(self);
            fval1 = cScriptInterpreter_popFloat(self);
            cScriptInterpreter_pushFloat(self, fval1 - fval2);
            break;
        }
        case 0x1F: {
            fval2 = cScriptInterpreter_popFloat(self);
            fval1 = cScriptInterpreter_popFloat(self);
            cScriptInterpreter_pushFloat(self, fval1 * fval2);
            break;
        }
        case 0x21: {
            fval2 = cScriptInterpreter_popFloat(self);
            fval1 = cScriptInterpreter_popFloat(self);
            cScriptInterpreter_pushFloat(self, fval1 / fval2);
            break;
        }
        case 0x27:
            cScriptInterpreter_pushFloat(self, -cScriptInterpreter_popFloat(self));
            break;
        case 0x2E: {
            fval1 = cScriptInterpreter_popFloat(self);
            cScriptInterpreter_pushInt(self, (int)fval1);
            break;
        }
        case 0x2D:
            cScriptInterpreter_pushFloat(self, (float)cScriptInterpreter_popInt(self));
            break;
        case 0x3B:
            self->mCurDebugLine = data;
            break;
        }
    }
    test: if (!done) goto top;
    {
        int cnt = self->mStrings.count;
        int i;
        for (i = 0; i < cnt && self->mStrings.data[i]; i++) {
            if (self->mDepth == ScSD(ScAt(self, i)) && (*std_vector_StringPtr_opIndex(&self->mStrings, i))->refCnt == 0) {
                cScriptInterpreter_removeString(self, (ScString*)self->mStrings.data[i]);
                i--;
                cnt--;
            }
        }
    }
    self->mDepth--;
    return retVal;
}
#undef Libc_Strcpy /* merge_units */
#undef cMemMan_Allocate /* merge_units */
static inline void merge_flush_func_003DDFC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003DDFC0 */
