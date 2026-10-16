#include "types.h"
typedef struct { int a; int count; int* items; } G399;
extern void Script_PrintWarning(char*);
extern int Script_LookupObjectById(int);
int Group_GetAt(G399* g, int i) {
    if (i < 0 || !(i < g->count)) {
        Script_PrintWarning("group index out of range");
        return 0;
    }
    return Script_LookupObjectById(g->items[i]);
}
