/*
 * Libs/SFOLobby/SFOLobby/SFOLobby_Games: 2 files, 0044EFF0-0044F0C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0044EFF0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int SFOLobbyList_SetUpdateFlag(char * , int);                         
char * SFOLobbyList_GetSlot(char * , int);                   

typedef struct { int f0; int f4; int f8; char pC[4]; int f10; char p14[4]; int f18; int f1C; char p20[4]; int f24; } PS0_0044EFF0;
void SFOLobby_RefreshGameInfo(int d0, char * arg1, PS0_0044EFF0 *arg2) {
    int temp_s1;
    int var_s0;
    char * temp_v0;

    if ((arg1 == NULL) || (temp_s1 = F_(arg1, 0x4, int), (temp_s1 == 0))) {
        return;
    }
    for (var_s0 = 0; var_s0 < temp_s1; var_s0++) {
            temp_v0 = SFOLobbyList_GetSlot(arg1, var_s0);
            if (F_(temp_v0, 0x48, int) == arg2->f0) {
                F_(temp_v0, 0x30, int) = arg2->f24;
                F_(temp_v0, 0x34, int) = arg2->f4;
                F_(temp_v0, 0x38, int) = arg2->f8;
                F_(temp_v0, 0x3C, int) = arg2->f1C;
                F_(temp_v0, 0x40, int) = arg2->f10;
                F_(temp_v0, 0x44, int) = arg2->f18;
                SFOLobbyList_SetUpdateFlag(arg1, 1);
            }
    }
}
static inline void merge_flush_func_0044EFF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044EFF0 */

/* merge_units: begin func_0044F0C0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
#if 0 /* merge_units */
int *SFOLobbyList_GetSlot(char * , int);
#endif /* merge_units */
#define SFOLobbyList_GetSlot(a0, a1) ((int *)SFOLobbyList_GetSlot((a0), (a1))) /* merge_units */
                    

int *SFOLobby_FindGameData(char * arg0, int arg1) {
    int *temp_v0;
    int temp_s1;
    int var_s0;

    if (arg1 == 0) {
        return NULL;
    }
    temp_s1 = F_(arg0, 0x11C, int);
    for (var_s0 = 0; var_s0 < temp_s1; var_s0++) {
        temp_v0 = SFOLobbyList_GetSlot(arg0 + 0x118, var_s0);
        if (arg1 == *temp_v0) {
            return temp_v0;
        }
    }
    return NULL;
}
#undef SFOLobbyList_GetSlot /* merge_units */
static inline void merge_flush_func_0044F0C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044F0C0 */
