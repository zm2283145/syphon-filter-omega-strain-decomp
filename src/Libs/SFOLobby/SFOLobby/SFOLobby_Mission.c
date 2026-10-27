/*
 * Libs/SFOLobby/SFOLobby/SFOLobby_Mission: 4 files, 00442510-00442700
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00442510 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x54]; char f54[4]; int n58; char pad2[0x1E54]; int f1eb0; char pad3[0x84]; int f1f38; char pad4[0x76C]; int f26a8; } L442;
extern int D_004976D0;
extern char D_004C0598[];
extern char D_004C05A0[];
extern int func_00452A60(L442*);
extern int SFOLobbyList_GetSlot(char*, int);
extern int sprintf(char*, const char*, ...);
extern int func_004526D0(L442*, char*);
extern int SFOLobby_JoinMissionChannel(L442*, char*);
extern void SFOLobby_FilterGameListByMyMission(L442*, int);
extern void SFOLobby_SetError(L442*, int, char*, int);
int SFOLobby_CheckMissionLobby(L442* l, int idx) {
    char buf[0x100];
    if (idx < 0 || !(idx < l->n58)) return 0;
    if (l->f26a8 != 2 || l->f1eb0 != idx || l->f1f38 != D_004976D0) {
        l->f26a8 = 0;
        l->f1eb0 = idx;
        if (func_00452A60(l)) {
            sprintf(buf, D_004C0598, SFOLobbyList_GetSlot(l->f54, idx), l->f1f38);
            if (!func_004526D0(l, buf)) return 0;
        } else {
            sprintf(buf, D_004C05A0, SFOLobbyList_GetSlot(l->f54, idx), l->f1f38);
            if (!SFOLobby_JoinMissionChannel(l, buf)) return 0;
        }
        SFOLobby_FilterGameListByMyMission(l, idx);
        D_004976D0 = l->f1f38;
        l->f26a8 = 2;
    }
    SFOLobby_SetError(l, 0, "SFOLobby_Mission.cc", 0x105);
    return 1;
}
static inline void merge_flush_func_00442510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00442510 */

/* merge_units: begin func_00442670 */
#pragma push /* merge_units */
typedef struct Tmp16 {
    int a, b, c, d;
} Tmp16;

extern void Libc_Strcpy(Tmp16*);
extern void SFOLobbyList_Append(void*, Tmp16*);

/* Builds a temporary with Libc_Strcpy and passes it to SFOLobbyList_Append(self + 0x54). */
void func_00442670(char* self) {
    Tmp16 tmp;
    Libc_Strcpy(&tmp);
    SFOLobbyList_Append(self + 0x54, &tmp);
}
static inline void merge_flush_func_00442670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00442670 */

/* merge_units: begin func_004426B0 */
#pragma push /* merge_units */
typedef struct { char p[0x255C]; int state; } S4426B0;
extern void SFOLobby_SetCallback(S4426B0* s, int f);
void SFOLobby_MissionScreenExit(S4426B0* s)
{
    int st = s->state;
    if (st != 9 && (st == 4 || st == 0)) {
        s->state = 9;
        SFOLobby_SetCallback(s, 0);
    }
}
static inline void merge_flush_func_004426B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004426B0 */

/* merge_units: begin func_00442700 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Mission.cc and SFOLobby_Servers.cc.
 */

#include "loose05_types.h"

extern int SFOLobby_CellUpdateClanInvitations(SFOLobby* lobby);
extern int SFOLobby_ContactGetInvites(SFOLobby* lobby);
extern int func_00451B30(SFOLobby* lobby);

/* Per-frame lobby update: runs three sub-updates while in mode 4 and not suspended. */
void SFOLobby_MissionScreenIntel(SFOLobby* self) {
    if (self->state == 4 && self->inUpdateHook == 0) {
        SFOLobby_ContactGetInvites(self);
        SFOLobby_CellUpdateClanInvitations(self);
        func_00451B30(self);
    }
}
static inline void merge_flush_func_00442700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00442700 */
