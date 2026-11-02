/*
 * Libs/SFOLib/Source/scriptBase: 18 files, 003D7590-003D8340
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D7590 */
#pragma push /* merge_units */
#include "types.h"

extern char D_00554F28[];

int cScriptBase_getClass(int a0) {
    int v0, v1;
    int cond;

    v0 = a0 < 5100;
    cond = v0 != 0;
    if (cond) goto L003D75A0;
    a0 = a0 + -5000;
L003D75A0:;
    v0 = a0 + -100;
    v1 = v0 << 2;
    v0 = *(int*)(char*)D_00554F28;
    v0 = *(int*)((char*)v0 + 8);
    v0 = v0 + v1;
    v0 = *(int*)(char*)v0;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_003D7590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D7590 */

/* merge_units: begin func_003D75C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "scriptBase_types.h"

extern PtrVec* D_00554F30;  /* global enum table, ids start at 10 */

/* Returns the global enum descriptor for enum id 'id'. */
int cScriptBase_getEnum(int id) {
    int i = id - 10;

    return D_00554F30->data[i];
}
static inline void merge_flush_func_003D75C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D75C0 */

/* merge_units: begin func_003D75E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004BD3B0[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
int strlen(const char* s);
void* memcpy(void* d, const void* s, int n);
}
static inline void* SD_Alloc(int n)
{
    AllocGuard g;
    return cMemMan_Allocate(0, n, D_004BD3B0, 0x130);
}
extern "C" char* cScriptBase_myStrdup(char* s)
{
    char* p = 0;
    if (s) {
        int len = strlen(s) + 1;
        int n = (len + 31) / 32 * 32;
        p = (char*)SD_Alloc(n);
        memcpy(p, s, n);
    }
    return p;
}
static inline void merge_flush_func_003D75E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D75E0 */

/* merge_units: begin func_003D76D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {
void std_vector_pod_int_resize(void* v, int n, int* val);
}
typedef struct { int pad0; int count; int* data; } V76D0;
typedef struct { int pad0; int x4; V76D0 vec; char pad14[0x38 - 0x14]; int x38; } O76D0;
extern "C" {
O76D0* FuncDef_ctor_charP_intPintPint_bool(void* p, char* name, int a, signed char f);
#if 0 /* merge_units */
void std_vector_FuncDefPtr_push_back(int list, O76D0** o);
#endif /* merge_units */
int std_vector_FuncDefPtr_push_back(PtrVec* v, int value); /* merge_units */
#define std_vector_FuncDefPtr_push_back(a0, a1) ((void)std_vector_FuncDefPtr_push_back((PtrVec *)(a0), (int)(a1))) /* merge_units */

extern int D_00554F20;
}
static inline int* At(V76D0* v, unsigned int i) { return &v->data[i]; }
static inline void* SD_Alloc_003D76D0(int n, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, n, D_004BD3B0, line);
}
extern "C" void cScriptBase_addGameFunc(char* name, int a, int x4, int n, int* src, signed char f)
{
    O76D0* o;
    int i;
    int zero;
    void* m = SD_Alloc_003D76D0(0x44, 0x119);
    if (m) m = FuncDef_ctor_charP_intPintPint_bool(m, name, a, f);
    o = (O76D0*)m;
    ((O76D0*)m)->x4 = x4;
    o->x38 = 1;
    zero = 0;
    std_vector_pod_int_resize(&o->vec, n, &zero);
    for (i = 0; i < n; i++) *At(&o->vec, i) = src[i];
    std_vector_FuncDefPtr_push_back(D_00554F20, &o);
}
#undef std_vector_FuncDefPtr_push_back /* merge_units */
static inline void merge_flush_func_003D76D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D76D0 */

/* merge_units: begin func_003D7910 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back: inserts one value at the end. */
int std_vector_FuncDefPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D7910(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D7910 */

/* merge_units: begin func_003D7930 */
#pragma push /* merge_units */
/* Variadic no-op (debug print stub). */
void cScriptBase_sm_printf(int fmt, ...) {
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D7930(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D7930 */

/* merge_units: begin func_003D7960 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)

typedef struct { int pad0; int count; void** data; } Pool_3D7960;
typedef struct { void* buf; char m4[0x10]; void* p14; } A_3D7960;
typedef struct { void* buf; char pad4[0x10]; void* p14; } C_3D7960;
struct G_3D7960;
extern "C" {
extern Pool_3D7960* volatile D_00554F18;
#if 0 /* merge_units */
extern Pool_3D7960* volatile D_00554F20;
#endif /* merge_units */
#define D_00554F20 (*(Pool_3D7960 * volatile*)&D_00554F20) /* merge_units */

#if 0 /* merge_units */
extern Pool_3D7960* volatile D_00554F28;
#endif /* merge_units */
#define D_00554F28 (*(Pool_3D7960 * volatile*)&D_00554F28) /* merge_units */

#if 0 /* merge_units */
extern Pool_3D7960* volatile D_00554F30;
#endif /* merge_units */
#define D_00554F30 (*(Pool_3D7960 * volatile*)&D_00554F30) /* merge_units */

extern int D_00554F38;
extern int D_00554F40;
extern int D_00554F48;
extern int D_00554F50;
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void cTimerDisable_dtor(G_3D7960* g, int f);
void cTimerDisable_ctor(G_3D7960* g);
void FuncDef_dtor(void* p, int f);
void ClassDef_dtor(void* p, int f);
void std_vector_deleter_EnumField_dtor(void* p, int f);
}
struct G_3D7960 { char c; G_3D7960() { cTimerDisable_ctor(this); } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~G_3D7960() { cTimerDisable_dtor(this, -1); } };
static inline void M3_3D7960(void* p) { if (p) std_vector_deleter_EnumField_dtor(p, 0); }
static inline void M2_3D7960(void* p) { if (p) M3_3D7960(p); }
static inline void M1_3D7960(void* p) { if (p) M2_3D7960(p); }
static inline void FreeP_3D7960(void* p, int line) { AllocGuard g; cMemMan_Deallocate(0, p, D_004BD3B0, line); }
static inline void DtorA_3D7960(A_3D7960* a) { FreeP_3D7960(a->buf, 0x1D8); M1_3D7960(a->m4); }
static inline void DtorC_3D7960(C_3D7960* c) { FreeP_3D7960(c->buf, 0x1F9); if (c->p14) FreeP_3D7960(c->p14, 0x1FC); }

static inline void DelA_3D7960(A_3D7960* a) { AllocGuard g; if (a) DtorA_3D7960(a); cMemMan_Deallocate(0, a, D_004BD3B0, 0xF2); }
static inline void DelC_3D7960(C_3D7960* c) { AllocGuard g; if (c) DtorC_3D7960(c); cMemMan_Deallocate(0, c, D_004BD3B0, 0xFE); }
static inline void DelB0_3D7960(void* b) { G_3D7960 g; FuncDef_dtor(b, -1); cMemMan_Deallocate(0, b, D_004BD3B0, 0xF8); }
static inline void DelD0_3D7960(void* d) { G_3D7960 g; ClassDef_dtor(d, -1); cMemMan_Deallocate(0, d, D_004BD3B0, 0x104); }
/* nested delete helpers (inline depth sets the guard slot order) */
static inline void DelB1_3D7960(void* b) { DelB0_3D7960(b); }
static inline void DelB2_3D7960(void* b) { DelB1_3D7960(b); }
static inline void DelB_3D7960(void* b) { DelB2_3D7960(b); }
static inline void DelD1_3D7960(void* d) { DelD0_3D7960(d); }
static inline void DelD2_3D7960(void* d) { DelD1_3D7960(d); }
static inline void DelD_3D7960(void* d) { DelD2_3D7960(d); }
extern "C" void cScriptBase_FreeScriptSyms(void)
{
    while (D_00554F30->count > D_00554F50) {
        Pool_3D7960* p = D_00554F30; A_3D7960* a = (A_3D7960*)p->data[p->count - 1];
        DelA_3D7960(a);
        D_00554F30->count--;
    }
    while (D_00554F20->count > D_00554F40) {
        Pool_3D7960* p = D_00554F20; void* b = p->data[p->count - 1];
        DelB_3D7960(b);
        D_00554F20->count--;
    }
    while (D_00554F18->count > D_00554F38) {
        Pool_3D7960* p = D_00554F18; C_3D7960* c = (C_3D7960*)p->data[p->count - 1];
        DelC_3D7960(c);
        D_00554F18->count--;
    }
    while (D_00554F28->count > D_00554F48) {
        Pool_3D7960* p = D_00554F28; void* d = p->data[p->count - 1];
        DelD_3D7960(d);
        D_00554F28->count--;
    }
}
#undef D_00554F20 /* merge_units */
#undef D_00554F28 /* merge_units */
#undef D_00554F30 /* merge_units */
static inline void merge_flush_func_003D7960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D7960 */

/* merge_units: begin func_003D7E30 */
#pragma push /* merge_units */
typedef struct Node4 {
    int unk0;
    int next;
} Node4;

#if 0 /* merge_units */
extern Node4* D_00554F18;
#endif /* merge_units */
#define D_00554F18 (*(Node4 **)&D_00554F18) /* merge_units */



#if 0 /* merge_units */
extern Node4* D_00554F20;
#endif /* merge_units */
#define D_00554F20 (*(Node4 **)&D_00554F20) /* merge_units */



#if 0 /* merge_units */
extern Node4* D_00554F28;
#endif /* merge_units */
#define D_00554F28 (*(Node4 **)&D_00554F28) /* merge_units */



#if 0 /* merge_units */
extern Node4* D_00554F30;
#endif /* merge_units */
#define D_00554F30 (*(Node4 **)&D_00554F30) /* merge_units */




/* Caches the second word of four list heads. */
void cScriptBase_SetGameSymsAdded(void) {
    D_00554F48 = D_00554F28->next;
    D_00554F50 = D_00554F30->next;
    D_00554F40 = D_00554F20->next;
    D_00554F38 = D_00554F18->next;
}
#undef D_00554F18 /* merge_units */
#undef D_00554F20 /* merge_units */
#undef D_00554F28 /* merge_units */
#undef D_00554F30 /* merge_units */
static inline void merge_flush_func_003D7E30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D7E30 */

/* merge_units: begin func_003D7E90 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#pragma pop
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop

#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
#if 0 /* merge_units */
char * cMemMan_Allocate(int, int, char *, int);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) ((char *)cMemMan_Allocate((a0), (a1), (a2), (a3))) /* merge_units */
                      
int cArrayCapacity_Int(int *);                           
#if 0 /* merge_units */
int std_vector_VarDefPtr_reserve(char * , int);
#endif /* merge_units */
int std_vector_VarDefPtr_reserve(int a0, int a1); /* merge_units */
#define std_vector_VarDefPtr_reserve(a0, a1) (std_vector_VarDefPtr_reserve((int)(a0), (a1))) /* merge_units */
                       
#if 0 /* merge_units */
int std_vector_VarDefPtr_ctor(char * );
#endif /* merge_units */
Rel* std_vector_VarDefPtr_ctor(Rel* r); /* merge_units */
#define std_vector_VarDefPtr_ctor(a0) ((int)std_vector_VarDefPtr_ctor((Rel *)(a0))) /* merge_units */
                            
#if 0 /* merge_units */
int std_vector_FuncDefPtr_reserve(char * , int);
#endif /* merge_units */
int std_vector_FuncDefPtr_reserve(int a0, int a1); /* merge_units */
#define std_vector_FuncDefPtr_reserve(a0, a1) (std_vector_FuncDefPtr_reserve((int)(a0), (a1))) /* merge_units */
                       
#if 0 /* merge_units */
int std_vector_FuncDefPtr_ctor(char * );
#endif /* merge_units */
Rel* std_vector_FuncDefPtr_ctor(Rel* r); /* merge_units */
#define std_vector_FuncDefPtr_ctor(a0) ((int)std_vector_FuncDefPtr_ctor((Rel *)(a0))) /* merge_units */
                            
#if 0 /* merge_units */
int std_vector_EnumDefPtr_reserve(char * , int);
#endif /* merge_units */
int std_vector_EnumDefPtr_reserve(int a0, int a1); /* merge_units */
#define std_vector_EnumDefPtr_reserve(a0, a1) (std_vector_EnumDefPtr_reserve((int)(a0), (a1))) /* merge_units */
                       
#if 0 /* merge_units */
int std_vector_EnumDefPtr_ctor(char * );
#endif /* merge_units */
Rel* std_vector_EnumDefPtr_ctor(Rel* r); /* merge_units */
#define std_vector_EnumDefPtr_ctor(a0) ((int)std_vector_EnumDefPtr_ctor((Rel *)(a0))) /* merge_units */
                            
#if 0 /* merge_units */
int std_vector_ClassDefPtr_reserve(char * , int);
#endif /* merge_units */
int std_vector_ClassDefPtr_reserve(int a0, int a1); /* merge_units */
#define std_vector_ClassDefPtr_reserve(a0, a1) (std_vector_ClassDefPtr_reserve((int)(a0), (a1))) /* merge_units */
                       
#if 0 /* merge_units */
int std_vector_ClassDefPtr_ctor(char * );
#endif /* merge_units */
Rel* std_vector_ClassDefPtr_ctor(Rel* r); /* merge_units */
#define std_vector_ClassDefPtr_ctor(a0) ((int)std_vector_ClassDefPtr_ctor((Rel *)(a0))) /* merge_units */
                            
#if 0 /* merge_units */
extern char D_004BD3B0;
#endif /* merge_units */
#define D_004BD3B0 (*(char*)&D_004BD3B0) /* merge_units */


extern unsigned char g_ProfileLockEnabled;
extern unsigned char D_00554F10;
#if 0 /* merge_units */
extern char * D_00554F18;
#endif /* merge_units */
#define D_00554F18 (*(char **)&D_00554F18) /* merge_units */


#if 0 /* merge_units */
extern char * D_00554F20;
#endif /* merge_units */
#define D_00554F20 (*(char **)&D_00554F20) /* merge_units */


#if 0 /* merge_units */
extern char * D_00554F28;
#endif /* merge_units */
#define D_00554F28 (*(char **)&D_00554F28) /* merge_units */


#if 0 /* merge_units */
extern char * D_00554F30;
#endif /* merge_units */
#define D_00554F30 (*(char **)&D_00554F30) /* merge_units */


}
extern "C" void cScriptBase_checkInitTypes(void) {
    int sp3C;
    int sp38;
    int sp34;
    int sp30;
    char * temp_s0;
    char * temp_s0_2;
    char * temp_s0_3;
    char * temp_s0_4;

    if (D_00554F10 == 0) {
        D_00554F10 = 1;
        {
            AllocGuard g;
        temp_s0 = cMemMan_Allocate(0, 0x10, &D_004BD3B0, 0xDE);
        }
        if (temp_s0 != NULL) {
            sp3C = 0x100;
            std_vector_ClassDefPtr_ctor(temp_s0);
            std_vector_ClassDefPtr_reserve(temp_s0, cArrayCapacity_Int(&sp3C));
            F_(temp_s0, 0xC, signed char) = 0;
        }
        D_00554F28 = temp_s0;
        {
            AllocGuard g;
        temp_s0_2 = cMemMan_Allocate(0, 0x10, &D_004BD3B0, 0xDF);
        }
        if (temp_s0_2 != NULL) {
            sp38 = 0x80;
            std_vector_EnumDefPtr_ctor(temp_s0_2);
            std_vector_EnumDefPtr_reserve(temp_s0_2, cArrayCapacity_Int(&sp38));
            F_(temp_s0_2, 0xC, signed char) = 0;
        }
        D_00554F30 = temp_s0_2;
        {
            AllocGuard g;
        temp_s0_3 = cMemMan_Allocate(0, 0x10, &D_004BD3B0, 0xE0);
        }
        if (temp_s0_3 != NULL) {
            sp34 = 0x800;
            std_vector_FuncDefPtr_ctor(temp_s0_3);
            std_vector_FuncDefPtr_reserve(temp_s0_3, cArrayCapacity_Int(&sp34));
            F_(temp_s0_3, 0xC, signed char) = 0;
        }
        D_00554F20 = temp_s0_3;
        {
            AllocGuard g;
        temp_s0_4 = cMemMan_Allocate(0, 0x10, &D_004BD3B0, 0xE1);
        }
        if (temp_s0_4 != NULL) {
            sp30 = 0x400;
            std_vector_VarDefPtr_ctor(temp_s0_4);
            std_vector_VarDefPtr_reserve(temp_s0_4, cArrayCapacity_Int(&sp30));
            F_(temp_s0_4, 0xC, signed char) = 0;
        }
        D_00554F18 = temp_s0_4;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D7E90(void) {}
#undef cMemMan_Allocate /* merge_units */
#undef std_vector_VarDefPtr_reserve /* merge_units */
#undef std_vector_VarDefPtr_ctor /* merge_units */
#undef std_vector_FuncDefPtr_reserve /* merge_units */
#undef std_vector_FuncDefPtr_ctor /* merge_units */
#undef std_vector_EnumDefPtr_reserve /* merge_units */
#undef std_vector_EnumDefPtr_ctor /* merge_units */
#undef std_vector_ClassDefPtr_reserve /* merge_units */
#undef std_vector_ClassDefPtr_ctor /* merge_units */
#undef D_004BD3B0 /* merge_units */
#undef D_00554F18 /* merge_units */
#undef D_00554F20 /* merge_units */
#undef D_00554F28 /* merge_units */
#undef D_00554F30 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D7E90 */

/* merge_units: begin func_003D8160 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_VarDefPtr_dtor)
static inline void merge_flush_func_003D8160(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D8160 */

/* merge_units: begin func_003D8250 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_FuncDefPtr_dtor)
static inline void merge_flush_func_003D8250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D8250 */

/* merge_units: begin func_003D8340 */
#pragma push /* merge_units */
extern int std_vector_pod_int_reserve(int, int);

int std_vector_VarDefPtr_reserve(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* std_vector_VarDefPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int std_vector_FuncDefPtr_reserve(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* std_vector_FuncDefPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_003D8340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D8340 */

/* merge_units: begin func_003D83A0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_FuncDefPtr_1_dtor)
static inline void merge_flush_func_003D83A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D83A0 */

/* merge_units: begin func_003D8490 */
#pragma push /* merge_units */
int std_vector_EnumDefPtr_reserve(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* std_vector_EnumDefPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int std_vector_ClassDefPtr_reserve(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* std_vector_ClassDefPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_003D8490(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D8490 */

/* merge_units: begin func_003D84F0 */
#pragma push /* merge_units */
typedef char* va_list;
#define va_start(__AP, __LASTARG) (__AP = ((char*) __builtin_next_arg (__LASTARG) - (__builtin_args_info (2) >= 8 ? 0 : (8 - __builtin_args_info (2)) * 8)))
#define va_arg(__AP, __type) (*(__type *) (void *) ((__AP += 8) - 8))

extern int g_ProfileLockDepth;
typedef struct { char pad[8]; char** tab; } ScrMgr;
#if 0 /* merge_units */
extern ScrMgr* D_00554F28;
#endif /* merge_units */
#define D_00554F28 (*(ScrMgr **)&D_00554F28) /* merge_units */

void Alloc_Lock(int id);
void EnableIntc(int id);
#if 0 /* merge_units */
void* cMemMan_Allocate(int a, int size, char* file, int line);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (a1), (a2), (a3))) /* merge_units */

void* MemberFunc_ctor(void* p, int a3, int a1, int a2, int count, int* args);
#if 0 /* merge_units */
void std_vector_MemberFuncPtr_push_back(char* list, void** item);
#endif /* merge_units */
int std_vector_MemberFuncPtr_push_back(); /* merge_units */


#if 0 /* merge_units */
void cScriptBase_addGameFunc(int a3, int a1, int a2, int count, int* args, int flag);
#endif /* merge_units */
#define cScriptBase_addGameFunc(a0, a1, a2, a3, a4, a5) (cScriptBase_addGameFunc((char *)(a0), (a1), (a2), (a3), (a4), (signed char)(a5))) /* merge_units */


int cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(int id, int a1, int a2, int a3, int count, ...)
{
    char* o;
    void* item;
    int args[20];
    void* p;
    va_list ap;
    int i;

    { int k = id - 0x64; o = D_00554F28->tab[k]; }
    va_start(ap, count);
    for (i = 0; i < count; i++) {
        args[i] = va_arg(ap, int);
    }
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    p = cMemMan_Allocate(0, 0x1C, D_004BD3B0, 0xCA);
    if (g_ProfileLockEnabled) EnableIntc(9);
    g_ProfileLockDepth--;
    if (p) p = MemberFunc_ctor(p, a3, a1, a2, count, args);
    item = p;
    std_vector_MemberFuncPtr_push_back(o + 0x14, &item);
    cScriptBase_addGameFunc(a3, a1, a2, count, args, 1);
    return 0;
}
#undef D_00554F28 /* merge_units */
#undef cMemMan_Allocate /* merge_units */
#undef cScriptBase_addGameFunc /* merge_units */
static inline void merge_flush_func_003D84F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D84F0 */

/* merge_units: begin func_003D8720 */
#pragma push /* merge_units */
/* push_back: inserts one value at the end. */
int std_vector_MemberFuncPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_003D8720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D8720 */

/* merge_units: begin func_003D8740 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);
extern void cScriptBase_checkInitTypes(void);
extern char* strrchr(const char*, int);
extern int buildNameWithPrefix(const char*);
#if 0 /* merge_units */
extern void cScriptBase_addGameFunc(char*, int, int, int, int*, int);
#endif /* merge_units */
#define cScriptBase_addGameFunc(a0, a1, a2, a3, a4, a5) (cScriptBase_addGameFunc((a0), (a1), (a2), (a3), (a4), (signed char)(a5))) /* merge_units */


extern char D_004BD3C8[];

int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(int a0, int a1, const char* name, int count, ...)
{
    int args[20];
    char buf[0x100];
    va_list ap;
    char* p;
    int i;

    va_start(ap, count);
    cScriptBase_checkInitTypes();
    p = strrchr(name, ':');
    name = p ? p + 1 : name;
    sprintf(buf, D_004BD3C8, buildNameWithPrefix(name));
    for (i = 0; i < count; i++) {
        args[i] = va_arg(ap, int);
    }
    cScriptBase_addGameFunc(buf, a0, a1, count, args, 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D8740(void) {}
#undef cScriptBase_addGameFunc /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D8740 */

/* merge_units: begin func_003D88E0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Pt2_NEnt { char* name; int a; int b; };
struct Pt2_NType { int pad; char list[1]; };
struct Pt2_NReg { char pad[8]; Pt2_NType** types; };
extern "C" {
#if 0 /* merge_units */
extern Pt2_NReg* D_00554F28;
#endif /* merge_units */
#define D_00554F28 (*(Pt2_NReg **)&D_00554F28) /* merge_units */


extern signed char D_00499C71[];
#if 0 /* merge_units */
void* cMemMan_Allocate(int, int, char*, int);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (a1), (a2), (a3))) /* merge_units */


void std_vector_FieldDefPtr_push_back(void*, Pt2_NEnt**);
}
extern "C" void cScriptBase_registerField(int type, char* name, int a, int b) {
    Pt2_NEnt* tmp[1];
    Pt2_NType* t;
    Pt2_NEnt* e;
    if (name[0] == 'm' && (D_00499C71[name[1]] & 1)) name++;
    { int i = type - 100; t = D_00554F28->types[i]; }
    {
        AllocGuard g;
        e = (Pt2_NEnt*)cMemMan_Allocate(0, 0xC, D_004BD3B0, 0x96);
    }
    if (e) {
        e->a = a;
        e->b = b;
        e->name = name;
    }
    tmp[0] = e;
    std_vector_FieldDefPtr_push_back(t->list, tmp);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D88E0(void) {}
#undef D_00554F28 /* merge_units */
#undef cMemMan_Allocate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D88E0 */
