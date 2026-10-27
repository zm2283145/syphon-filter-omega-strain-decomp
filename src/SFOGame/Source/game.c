/*
 * SFOGame/Source/game: 2 files, 0012ECD0-0012ED60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0012ECD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cGameSystem_IsNetworked(void) {
    return 1;
}

void* cSystem_ScriptGetObjectId(char* self) {
    return self + 12;
}

void* cSystem_ScriptGetRealObj(void* self) {
    return self;
}

int cSystem_SendCreated(void) {
    return 1;
}

void cSystem_NetActivate(void) {
}

void cSystem_NetDeactivate(void) {
}

void cSystem_NetEnable(void) {
}

void cSystem_NetDisable(void) {
}

int cSystem_IsDeliverable(void) {
    return 1;
}
static inline void merge_flush_func_0012ECD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0012ECD0 */

/* merge_units: begin func_0012ED60 */
#pragma push /* merge_units */
unsigned char* cGameSystem_GetAgentData(int, int);
int NetGetMyClientIndex(int*, int);
int cNetObj_GetPlayer(int);
unsigned int D_00494178[2] = { 0xFFFFFFFF, 0x0 };
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
int cGameSystem_AllAgentDataReceived(int arg0)
{
    int i;
    i = 0;
    do {
        int v;
        int a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */
        if (g_IsMultiplayer) {
            if ((*(int*)D_00494178) == -1) NetGetMyClientIndex(&(*(int*)D_00494178), a);
            v = (*(int*)D_00494178);
        } else v = 0;
        if (i != v && cNetObj_GetPlayer(i)) {
            unsigned char* p = cGameSystem_GetAgentData(arg0, i);
            if (p && p[0xB70] == 0) return 0;
        }
        i++;
    } while (i < 4);
    return 1;
}
static inline void merge_flush_func_0012ED60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0012ED60 */
