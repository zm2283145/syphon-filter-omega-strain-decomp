/*
 * main/scriptManager: range (2 files, 003E0D90-003E0F50)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003E0D90 */
#pragma push /* merge_units */
typedef struct Vec_E0D90 { int x0; int count; struct Ent_E0D90** data; } Vec_E0D90;
typedef struct Ent_E0D90 {
    char* name; int x4; int x8; int count; int** arr; char p14[0x10];
    int x24; int x28; int x2C; int x30; int x34; int x38; int x3C; unsigned char x40;
} Ent_E0D90;
typedef struct Desc_E0D90 {
    char* name; int x4; int count; int xC; char p10[8]; unsigned char x18; char p19[3];
    int vals[20]; int x6C; int x70; int x74;
} Desc_E0D90;
extern Vec_E0D90* D_00554F20;
int String_CompareNoCase(char*, char*);
#pragma opt_strength_reduction off
Ent_E0D90* ScriptDesc_Find(void* self, Desc_E0D90* d) {
    char* name = d->name;
    int count = d->count;
    int* vals = d->vals;
    int x6C = d->x6C;
    int x70 = d->x70;
    int xC = d->xC;
    int x74 = d->x74;
    int i;
    int n = D_00554F20->count;
    for (i = 0; i < n; i++) {
        Ent_E0D90* e = D_00554F20->data[i];
        if (e->x38 != 0 && e->x40 == d->x18 && count == e->count &&
            String_CompareNoCase(e->name, name) == 0 && x70 == e->x2C &&
            xC == e->x28 && x6C == e->x24 && x74 == e->x30) {
            unsigned char ok = 1;
            int j;
            int* p;
            for (j = 0, p = vals; j < count && ok; p++, j++) {
                if (*p != *e->arr[j]) ok = 0;
            }
            if (ok) return e;
        }
    }
    return 0;
}
#pragma opt_strength_reduction reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E0D90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E0D90 */

/* merge_units: begin func_003E0F50 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma push
#pragma bool off
#pragma inline_depth(12)
struct Func { char* name; char pad4[8]; int type; char pad10[0x24]; unsigned char defined; char pad35[3]; int body; };
struct Ft { Func** p; };
extern "C" {
Ft func_003E10C0(void*);
Ft func_003E1090(void*);
void func_003E10B0(Ft*,const Ft*);
#if 0 /* merge_units */
extern void* D_00554F20;
#endif /* merge_units */
#define D_00554F20 (*(void **)&D_00554F20) /* merge_units */

}
struct FE:Ft { FE(const Ft& i) { func_003E10B0(this,&i); } };
static inline FE beginF() { return FE(func_003E10C0(D_00554F20)); }
static inline FE endF() { return FE(func_003E1090(D_00554F20)); }
static inline int neqF(const Ft& a,const Ft& b) { return (a.p == b.p)^1; }
extern "C" Func* func_003E0F50(void* self, char* name, int type) {
    Ft f=beginF();
    while(neqF(f,endF())) {
        Func* p=*f.p;
        if(p->defined && p->body && type == p->type && !String_CompareNoCase(p->name, name)) return *f.p;
        f.p++;
    }
    return 0;
}
#pragma pop
#undef D_00554F20 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E0F50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E0F50 */
