/*
 * SFOGame/Source/hud: 1 file, 00245750
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00245750 */
#pragma push /* merge_units */
#include "types.h"
#pragma mpwc_relax on
int cMessage_ctor_cMessageNameR(char **, char *);
int cNetMsg_GetFloat_floatR(float *);
int cNetMsg_GetString(char *, int);
int nGlobalization_GetString_charP(char *);
int func_0012F2C0(char *);
void HudTimer_Start_Thunk(int, int, float);
int cMessage_dtor(char **, int);
extern char D_004DC310;
extern char D_004DCF10;
extern char D_004F7DC0;
extern char g_Game;

void cNetTimerMsg_NetReceive(void) {
    struct { char * f40[9]; float f; char s[16]; } sl;
    int text;

    cMessage_ctor_cMessageNameR(sl.f40, &D_004F7DC0);
    sl.f40[0] = &D_004DC310;
    sl.s[0] = 0;
    cNetMsg_GetFloat_floatR(&sl.f);
    cNetMsg_GetString(sl.s, 16);
    text = sl.s[0] ? nGlobalization_GetString_charP(sl.s) : 0;
    HudTimer_Start_Thunk(func_0012F2C0(&g_Game), text, sl.f);
    sl.f40[0] = &D_004DCF10;
    cMessage_dtor(sl.f40, 0);
}
static inline void merge_flush_func_00245750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00245750 */
