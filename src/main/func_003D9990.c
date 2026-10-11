#include "types.h"
/* Group_GetAt */
typedef struct { int pad0; int count; int* ids; } Pt2_Group;
extern char D_004BD440[];
extern void func_003D7930(char*);
extern void* Script_LookupObjectById(int);
void* Group_GetAt(Pt2_Group* g, int i) {
    if (i < 0 || i >= g->count) {
        func_003D7930(D_004BD440);
        return 0;
    }
    return Script_LookupObjectById(g->ids[i]);
}