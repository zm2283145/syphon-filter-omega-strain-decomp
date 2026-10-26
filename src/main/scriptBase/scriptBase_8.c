/*
 * main/scriptBase: 4 files, 003D8340-003D84F0
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

extern int PtrVec_Reserve(int, int);

int std_vector_VarDefPtr_reserve(int a0, int a1) {
    return PtrVec_Reserve(a0, a1);
}

Rel* std_vector_VarDefPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int std_vector_FuncDefPtr_reserve(int a0, int a1) {
    return PtrVec_Reserve(a0, a1);
}

Rel* std_vector_FuncDefPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D8340 */

/* merge_units: begin func_003D83A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_FuncDefPtr_1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003D83A0 */

/* merge_units: begin func_003D8490 */
#pragma push /* merge_units */
int std_vector_EnumDefPtr_reserve(int a0, int a1) {
    return PtrVec_Reserve(a0, a1);
}

Rel* std_vector_EnumDefPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int std_vector_ClassDefPtr_reserve(int a0, int a1) {
    return PtrVec_Reserve(a0, a1);
}

Rel* std_vector_ClassDefPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
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
void Alloc_Unlock(int id);
void* Mem_Alloc(int a, int size, char* file, int line);
void* MemberFunc_ctor(void* p, int a3, int a1, int a2, int count, int* args);
void std_vector_MemberFuncPtr_push_back(char* list, void** item);
void cScriptBase_addGameFunc(int a3, int a1, int a2, int count, int* args, int flag);

int Script_RegisterNative(int id, int a1, int a2, int a3, int count, ...)
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
    p = Mem_Alloc(0, 0x1C, D_004BD3B0, 0xCA);
    if (g_ProfileLockEnabled) Alloc_Unlock(9);
    g_ProfileLockDepth--;
    if (p) p = MemberFunc_ctor(p, a3, a1, a2, count, args);
    item = p;
    std_vector_MemberFuncPtr_push_back(o + 0x14, &item);
    cScriptBase_addGameFunc(a3, a1, a2, count, args, 1);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D84F0 */
