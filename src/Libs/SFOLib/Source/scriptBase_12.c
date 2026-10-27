/*
 * Libs/SFOLib/Source/scriptBase: 7 files, 003D8340-003D8720
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D8340 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

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

#include "buf_holder_dtor.h"

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

extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_004BD3B0[];
typedef struct { char pad[8]; char** tab; } ScrMgr;
extern ScrMgr* D_00554F28;
void Alloc_Lock(int id);
void EnableIntc(int id);
void* cMemMan_Allocate(int a, int size, char* file, int line);
void* MemberFunc_ctor(void* p, int a3, int a1, int a2, int count, int* args);
#if 0 /* merge_units */
void std_vector_MemberFuncPtr_push_back(char* list, void** item);
#endif /* merge_units */
int std_vector_MemberFuncPtr_push_back(); /* merge_units */

void cScriptBase_addGameFunc(int a3, int a1, int a2, int count, int* args, int flag);

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
static inline void merge_flush_func_003D84F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D84F0 */

/* merge_units: begin func_003D8720 */
#pragma push /* merge_units */
#include "scriptBase_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

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
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);
extern void cScriptBase_checkInitTypes(void);
extern char* strrchr(const char*, int);
extern int buildNameWithPrefix(const char*);
#if 0 /* merge_units */
extern void cScriptBase_addGameFunc(char*, int, int, int, int*, int);
#endif /* merge_units */
#define cScriptBase_addGameFunc(a0, a1, a2, a3, a4, a5) (cScriptBase_addGameFunc((int)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

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
