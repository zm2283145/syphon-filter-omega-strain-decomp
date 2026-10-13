#pragma opt_strength_reduction off
#include "types.h"

typedef struct LookupE6 {
    void* name;
    int pad[4];
    int value;
} LookupE6;

extern int D_00532AF4;
extern LookupE6* D_00532AF8;
extern void* Loc_GetStoredKey(void* name);
extern int String_CompareNoCase(void* a, void* b);

static inline LookupE6* EntryE6(int i) { return &D_00532AF8[i]; }

/* Finds the table entry whose name matches, returning its value (default 0x16). */
int Objective_GetLevelMissionNumber(void* name)
{
    int count = D_00532AF4;
    int i;
    for (i = 0; i < count; i++) {
        if (String_CompareNoCase(Loc_GetStoredKey(EntryE6(i)->name), name) == 0) {
            return EntryE6(i)->value;
        }
    }
    return 0x16;
}