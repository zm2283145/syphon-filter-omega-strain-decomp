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

int func_003D8340(int a0, int a1) {
    return PtrVec_Reserve(a0, a1);
}

Rel* func_003D8350(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_003D8370(int a0, int a1) {
    return PtrVec_Reserve(a0, a1);
}

Rel* func_003D8380(Rel* r) {
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
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_003D83A0)
#pragma pop /* merge_units */
/* merge_units: end func_003D83A0 */

/* merge_units: begin func_003D8490 */
#pragma push /* merge_units */
int func_003D8490(int a0, int a1) {
    return PtrVec_Reserve(a0, a1);
}

Rel* func_003D84A0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_003D84C0(int a0, int a1) {
    return PtrVec_Reserve(a0, a1);
}

Rel* func_003D84D0(Rel* r) {
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

extern unsigned char D_00533880;
extern int D_00533888;
extern char D_004BD3B0[];
typedef struct { char pad[8]; char** tab; } ScrMgr;
extern ScrMgr* D_00554F28;
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
void* Mem_Alloc(int a, int size, char* file, int line);
void* func_003D7380(void* p, int a3, int a1, int a2, int count, int* args);
void func_003D8720(char* list, void** item);
void func_003D76D0(int a3, int a1, int a2, int count, int* args, int flag);

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
    if (D_00533880) Alloc_Lock(9);
    D_00533888++;
    p = Mem_Alloc(0, 0x1C, D_004BD3B0, 0xCA);
    if (D_00533880) Alloc_Unlock(9);
    D_00533888--;
    if (p) p = func_003D7380(p, a3, a1, a2, count, args);
    item = p;
    func_003D8720(o + 0x14, &item);
    func_003D76D0(a3, a1, a2, count, args, 1);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D84F0 */
