/*
 * main/hog: 3 files, 0036D200-0036D380
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036D200 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x14C]; unsigned char on; char p1[3]; unsigned int idx; char* cur; char p2[4]; char* base; } SL36D2;
#pragma opt_rotateloops off
char* Archive_GetMemberName(SL36D2* p, int n) {
    int i;
    char* s;
    char* r;
    if (!p->on) return 0;
    s = p->base;
    i = 0;
    if (!(n < p->idx)) { s = p->cur; i = p->idx; }
    while (i < n) { while (*s++) ; i++; }
    p->idx = i;
    r = s;
    while (*s++) ;
    p->cur = r;
    return p->cur;
}
#pragma opt_rotateloops reset
#pragma pop /* merge_units */
/* merge_units: end func_0036D200 */

/* merge_units: begin func_0036D2A0 */
#pragma push /* merge_units */
typedef struct { int pad0; int count; } H36D2A0;
typedef struct { char pad[0x148]; H36D2A0* hdr; unsigned char loaded; char pad14D[0xF]; char* names; } S36D2A0;
extern int String_CompareNoCase(char* a, char* b);
int Hog_FindFileNoCase(S36D2A0* o, char* name)
{
    int i;
    char* s;
    if (!o->loaded) return 0;
    s = o->names;
    for (i = 0; i < o->hdr->count; i++) {
        char* cur = s;
        while (*s++) ;
        if (String_CompareNoCase(name, cur) == 0) break;
    }
    if (i >= o->hdr->count) i = -1;
    return i;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036D2A0 */

/* merge_units: begin func_0036D380 */
#pragma push /* merge_units */
typedef struct { char pad[0x14C]; unsigned char a14C; char pad2[0x13]; int* a160; } S36D380;
int Hog_GetEntrySize(S36D380* o, int k)
{
    if (!o->a14C) return 0;
    return o->a160[k + 1] - o->a160[k];
}
#pragma pop /* merge_units */
/* merge_units: end func_0036D380 */
