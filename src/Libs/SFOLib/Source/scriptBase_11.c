/*
 * Libs/SFOLib/Source/scriptBase: 7 files, 003D7910-003D7E90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D7910 */
#pragma push /* merge_units */
#include "types.h"
#include "scriptBase_types.h"

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
#include "alloc_guard.h"
#pragma inline_depth(10)

typedef struct { int pad0; int count; void** data; } Pool_3D7960;
typedef struct { void* buf; char m4[0x10]; void* p14; } A_3D7960;
typedef struct { void* buf; char pad4[0x10]; void* p14; } C_3D7960;
struct G_3D7960;
extern "C" {
extern char D_004BD3B0[];
extern Pool_3D7960* volatile D_00554F18;
extern Pool_3D7960* volatile D_00554F20;
extern Pool_3D7960* volatile D_00554F28;
extern Pool_3D7960* volatile D_00554F30;
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
char * cMemMan_Allocate(int, int, char *, int);                      
int cArrayCapacity_Int(int *);                           
int std_vector_VarDefPtr_reserve(char * , int);                       
int std_vector_VarDefPtr_ctor(char * );                            
int std_vector_FuncDefPtr_reserve(char * , int);                       
int std_vector_FuncDefPtr_ctor(char * );                            
int std_vector_EnumDefPtr_reserve(char * , int);                       
int std_vector_EnumDefPtr_ctor(char * );                            
int std_vector_ClassDefPtr_reserve(char * , int);                       
int std_vector_ClassDefPtr_ctor(char * );                            
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
