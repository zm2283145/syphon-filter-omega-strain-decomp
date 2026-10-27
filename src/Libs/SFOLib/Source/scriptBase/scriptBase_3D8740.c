/*
 * main/scriptBase: range (2 files, 003D8740-003D88E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_003D8740 */
#pragma push /* merge_units */
typedef char* va_list;
#define va_start(__AP, __LASTARG) (__AP = ((char*) __builtin_next_arg (__LASTARG) - (__builtin_args_info (2) >= 8 ? 0 : (8 - __builtin_args_info (2)) * 8)))
#define va_arg(__AP, __type) (*(__type *) (void *) ((__AP += 8) - 8))

extern void cScriptBase_checkInitTypes(void);
extern char* strrchr(const char*, int);
extern int buildNameWithPrefix(const char*);
extern void cScriptBase_addGameFunc(char*, int, int, int, int*, int);
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
#pragma pop /* merge_units */
/* merge_units: end func_003D8740 */

/* merge_units: begin func_003D88E0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Pt2_NEnt { char* name; int a; int b; };
struct Pt2_NType { int pad; char list[1]; };
struct Pt2_NReg { char pad[8]; Pt2_NType** types; };
extern "C" {
extern Pt2_NReg* D_00554F28;
extern signed char D_00499C71[];
extern char D_004BD3B0[];
void* cMemMan_Allocate(int, int, char*, int);
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
#pragma pop /* merge_units */
/* merge_units: end func_003D88E0 */
