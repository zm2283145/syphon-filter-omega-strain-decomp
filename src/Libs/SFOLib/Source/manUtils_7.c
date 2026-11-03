/*
 * Libs/SFOLib/Source/manUtils: 1 file, 00405940
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int cMemMan_Deallocate();

/* merge_units: begin func_00405940 */
#pragma push /* merge_units */
typedef struct { __int128 a; __int128 b; } HM_Pair;
typedef struct { __int128 slot0; __int128 slot1; __int128 q20; __int128 q30; HM_Pair pairs[32]; } HM_Pack;
extern char D_004BE910[];
extern char D_004BE920[];
extern char g_AgentPartCache[];
extern char D_0057124C[];
extern int Libc_Strncmp(char* a, char* b, int n);
extern int SKL_FindSex(HM_Pack* p);
extern int Monster_LoadAPart(void* cache, __int128 name, void* ctx, void* arg);
/* Requests the hard mesh (slot 2) when asked, then every pair's part mesh; returns the part count. */
int SKL_LoadSKLParts(HM_Pack* p, int hard, void* arg)
{
    int i;
    if (hard) {
        if (Libc_Strncmp((char*)&p->q20 + 1, D_004BE910, 4) == 0) {
            Monster_LoadAPart(g_AgentPartCache, p->q20, D_0057124C, arg);
        } else {
            Libc_Strcpy(&p->q20, D_004BE920);
            if (SKL_FindSex(p) == 0)
                *(char*)&p->q20 = '2';
            else
                *(char*)&p->q20 = '1';
            Monster_LoadAPart(g_AgentPartCache, p->q20, D_0057124C, arg);
        }
    }
    for (i = 0; p->pairs[i].a; i++)
        Monster_LoadAPart(g_AgentPartCache, p->pairs[i].a, D_0057124C, arg);
    return i;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00405940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00405940 */
