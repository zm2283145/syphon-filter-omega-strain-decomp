#include "types.h"
typedef struct { char name[16]; } MorphShape;
extern MorphShape* D_005712F8[];
extern int D_005712F0[];
extern int strcmp(const char*, const char*);
int Morph_FindShapeIndex(const char* name, int set)
{
    MorphShape* s = D_005712F8[set];
    int n = D_005712F0[set];
    int i;
    for (i = 0; i < n; i++, s++) {
        if (strcmp(s->name, name) == 0)
            return i;
    }
    return 0;
}