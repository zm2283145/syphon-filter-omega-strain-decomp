#include "types.h"

typedef struct PtrTable {
    int unk0;
    int unk4;
    void** items;
} PtrTable;

extern PtrTable* D_004FFBE0;
extern int D_004EE130;

/* Returns table item i, or &D_004EE130 when no table exists. */
void* func_0015DDB0(int i) {
    if (D_004FFBE0 != 0) return D_004FFBE0->items[i];
    return &D_004EE130;
}
