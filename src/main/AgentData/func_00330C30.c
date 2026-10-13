#pragma opt_strength_reduction off
#include "types.h"

typedef struct Lookup30C30 { void* name; int pad[5]; } Lookup30C30;
typedef struct Pair30C30 { int a; int b; } Pair30C30;

extern int D_00532AF4;
extern Lookup30C30* D_00532AF8;
extern Pair30C30* D_00532B98;
extern void* Loc_GetStoredKey(void* name);
extern int String_CompareNoCase(void* a, void* b);

static inline Lookup30C30* Entry30C30(int i) { return &D_00532AF8[i]; }

/* Finds the table entry whose name matches and returns one of its two paired values. */
int func_00330C30(void* name, int second)
{
    int count = D_00532AF4;
    int i;
    for (i = 0; i < count; i++) {
        if (String_CompareNoCase(Loc_GetStoredKey(Entry30C30(i)->name), name) == 0) {
            return second ? ((int*)D_00532B98)[i * 2 + 1] : ((int*)D_00532B98)[i * 2];
        }
    }
    return 0;
}
