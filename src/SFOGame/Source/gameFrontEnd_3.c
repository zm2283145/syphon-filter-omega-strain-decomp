/*
 * SFOGame/Source/gameFrontEnd: 1 file, 002C9070
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C9070 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x24C]; int textIndex; } Ctx9070;
typedef struct { char pad[0x35]; unsigned char enabled; } Obj9070;
extern unsigned char g_IsMultiplayer;
extern Ctx9070* D_004FFC04;
extern char D_004ACC28[];
extern char D_004ACC38[];
extern char D_004ACC48[];
extern char D_004ACC58[];
static void * const dat_0048C200[18] = { (void*)0x0, (void*)0x0, (void*)0x0, (void*)D_004ACC28, (void*)0x0, (void*)0x0, (void*)D_004ACC38, (void*)0x0, (void*)0x0, (void*)0x0, (void*)D_004ACC48, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)D_004ACC58, (void*)0x0, (void*)0x0 };
extern char* nGlobalization_GetString_charP(char* key);
char* App_GetAgentRankGate(Obj9070* o)
{
    int i;
    char* key;
    if (o->enabled && !g_IsMultiplayer) {
        i = D_004FFC04->textIndex;
        if (i != -1) {
            key = ((char**)dat_0048C200)[i];
            if (key)
                return nGlobalization_GetString_charP(key);
        }
    }
    return 0;
}
static inline void merge_flush_func_002C9070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C9070 */
