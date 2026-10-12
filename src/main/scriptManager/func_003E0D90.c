#include "types.h"
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
