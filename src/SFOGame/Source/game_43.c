/*
 * SFOGame/Source/game: 7 files, 001363C0-00136710
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001363C0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop

#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cGOBJPtr_dtor)
static inline void merge_flush_func_001363C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001363C0 */

/* merge_units: begin func_001364B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma peephole off
typedef struct { int x, y, z, w; } __attribute__((aligned(16))) V4;
struct R { int a, b, c, d; };
struct T { V4 q; int m10; int m14; };
extern "C" signed char D_004E1D88;
extern "C" V4 D_004E1D90;
/* Inlined cVector_GetZero: lazily zeroed shared vector. */
static inline V4* Vec4_Zero(void) {
    if (!D_004E1D88) {
        D_004E1D90.x = 0;
        D_004E1D88 = 1;
        D_004E1D90.y = 0;
        D_004E1D90.z = 0;
        D_004E1D90.w = 0;
    }
    return &D_004E1D90;
}
static inline __int128 GL(const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%1)" : "=&r"(q) : "r"(s) : "memory"); return q; }
/* Inlined getter with a default: the -1 temporary is materialized only in the null arm. */
static inline const int* Id(const R* p) {
    int t;
    const int* r;
    if (p) r = &p->d;
    else { t = -1; r = &t; }
    return r;
}
/* Resets the vector to zero, m10 to 0 and m14 to -1. */
extern "C" T* cActivationTracker_ctor(T* d)
{
    *(__int128*)&d->q = GL(Vec4_Zero());
    d->m14 = -1;
    d->m10 = 0;
    d->m14 = *Id(0);
    return d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001364B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001364B0 */

/* merge_units: begin func_00136540 */
#pragma push /* merge_units */
#include "types.h"

Rel* std_vector_cGOBJPtr_ctor_void(Rel* r); /* gsynth: defined below */
#if 0 /* merge_units */
int std_vector_cGOBJPtr_reserve(int a0, int a1); /* gsynth: defined below */
#endif /* merge_units */
int std_vector_cGOBJPtr_reserve(); /* merge_units */
typedef struct { char pad[0xC]; unsigned char flag; } Sub00136540;
typedef struct { void* vtable; Sub00136540 sub; char pad[0x14 - 4 - sizeof(Sub00136540)]; int unk14; } Obj00136540;
extern char D_004D9140[];
#if 0 /* merge_units */
extern void std_vector_cGOBJPtr_ctor_void(Sub00136540* sub);
#endif /* merge_units */
#define std_vector_cGOBJPtr_ctor_void(a0) ((void)std_vector_cGOBJPtr_ctor_void((Rel *)(a0))) /* merge_units */


extern int cArrayCapacity_Int(void* src);
#if 0 /* merge_units */
extern int std_vector_cGOBJPtr_reserve(Sub00136540* sub, int value);
#endif /* merge_units */
int std_vector_cGOBJPtr_reserve(); /* merge_units */


/* Constructor. */
Obj00136540* cCollisionModelList_ctor(Obj00136540* obj, void* src)
{
    Sub00136540* sub;
    obj->vtable = D_004D9140;
    sub = &obj->sub;
    std_vector_cGOBJPtr_ctor_void(sub);
    std_vector_cGOBJPtr_reserve(sub, cArrayCapacity_Int(src));
    sub->flag = 1;
    obj->unk14 = 0;
    return obj;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00136540(void) {}
#undef std_vector_cGOBJPtr_ctor_void /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00136540 */

/* merge_units: begin func_001365B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int std_vector_pod_int_reserve(int, int);

int std_vector_cGOBJPtr_reserve(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* std_vector_cGOBJPtr_ctor_void(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Rel* std_vector_cNodePtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001365B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001365B0 */

/* merge_units: begin func_00136600 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_cNodePtr_1_dtor)
static inline void merge_flush_func_00136600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00136600 */

/* merge_units: begin func_001366F0 */
#pragma push /* merge_units */
Rel* std_vector_cArray_int_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_001366F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001366F0 */

/* merge_units: begin func_00136710 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern "C" {
#include "net_local_id.h"
int cAgentData_ctor(...);
int cMemMan_Allocate(...);
int cScriptInterpreter_CallFunction(...);
int cWeaponDB_LoadOnce(...);
int cMemCard_Init(...);
extern char D_0049A890;
extern unsigned char D_004E9FF0;
extern char D_00555070;
extern char g_MemCard;
}

extern "C" void cGameSystem_InitAgentData(char * arg0) {
    int var_s1;
    int var_a2;
    int var_s3;
    char * var_s0;

    if (D_004E9FF0 == 0) {
        D_004E9FF0 = 1;
        cWeaponDB_LoadOnce(F_(arg0, 0x1E0, int));
        cMemCard_Init(&g_MemCard);
        cScriptInterpreter_CallFunction(&D_00555070, "awards::init", 0);
        var_s1 = 0;
        var_s0 = arg0;
        do {
            {
                AllocGuard g;
            var_s3 = cMemMan_Allocate(0, 0xB78, &D_0049A890, 0x186);
            }
            if (var_s3 != 0) {
                var_s3 = cAgentData_ctor(var_s3);
            }
            var_s1 += 1;
            F_(var_s0, 0x1C8, int) = var_s3;
            var_s0 += 4;
        } while (var_s1 < 4);
    }
    var_a2 = g_IsMultiplayer ? NetLocalId() : 0;
    { int cur = F_(arg0, 0x1D8, int); if (var_a2 != cur) { int* pa = (int*)(arg0 + 0x1C8) + cur; int* pb = (int*)(arg0 + 0x1C8) + var_a2; int t = *pa; *pa = *pb; *pb = t; *(int*)(arg0 + 0x1D8) = var_a2; } }
}
static inline void merge_flush_func_00136710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00136710 */
