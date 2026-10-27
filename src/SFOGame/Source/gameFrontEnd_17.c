/*
 * SFOGame/Source/gameFrontEnd: 2 files, 002CBCE0-002CBD40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CBCE0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Message destructor: restore vtable, run cMessage base, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_002CBCE0, D_004D9160, cMessage_dtor)
static inline void merge_flush_func_002CBCE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CBCE0 */

/* merge_units: begin func_002CBD40 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_rotateloops off
/* cGameFrontEnd_LobbySetAgentStats: fills the network agent-info block (version 11) of the
 * selected agent: team, accuracy/headshot percentages, stats, rating and
 * award bits, appearance block. Stat use as in GuiAgentInfo_DisplayLocalAgent
 * (GuiAgentInfo_360610.c). */
typedef struct { char pad[8]; unsigned char on; char pad2[0xB]; } Item_BD40;
struct Rel_BD40 { int a0; int count; Item_BD40* data; unsigned char own; char pad[3]; int Size() { return count; } Item_BD40& operator[](unsigned int i) { return data[i]; } };
struct App_BD40 { char d[0xC0]; };
struct Agent_BD40 { char pad0[0x9A8]; App_BD40 app; char pad1[0xB50 - 0x9A8 - 0xC0]; int* team; };
struct Info_BD40 {
    unsigned char ver; unsigned char team; unsigned char accuracy; unsigned char headshots;
    short kills; short s6; short s8; short sA; short sC; char pE[2];
    int shots; int hits; int w18; int w1C; int w20; int bits;
    App_BD40 app;
};
extern "C" {
extern char g_Game[];
void* memset(void* d, int c, unsigned int n);
void* memcpy(void* d, const void* s, unsigned int n);
Agent_BD40* cGameSystem_GetAgentData(void* list, int idx);
int cAgentData_GetStat(Agent_BD40* a, int id);
void func_00296FA0(Rel_BD40* r);
void func_00299360(Rel_BD40* r, short f);
void cAgentData_GetRatings(Agent_BD40* a, Rel_BD40* r);
void cAgentData_GetAchievements(Agent_BD40* a, int k, Rel_BD40* r);
void cGameFrontEnd_LobbySetAgentStats(void* self, Info_BD40* info);
}
static inline void CopyApp(App_BD40* d, App_BD40* s) { if (s) memcpy(d, s, sizeof(App_BD40)); }

extern "C" void cGameFrontEnd_LobbySetAgentStats(void* self, Info_BD40* info)
{
    Agent_BD40* a;
    int bits;
    if (info->ver != 11) {
        memset(info, 0, 0xFC);
        info->ver = 11;
    }
    a = cGameSystem_GetAgentData(g_Game, -1);
    info->team = a->team ? a->team[1] : 0;
    info->accuracy = (cAgentData_GetStat(a, 0xC) && cAgentData_GetStat(a, 0xC)) ? (int)(100.0f * ((float)cAgentData_GetStat(a, 0xC) / (float)cAgentData_GetStat(a, 0xB))) : 0;
    info->headshots = (cAgentData_GetStat(a, 0xA) && cAgentData_GetStat(a, 0xA)) ? (int)(100.0f * ((float)cAgentData_GetStat(a, 0xA) / (float)cAgentData_GetStat(a, 9))) : 0;
    info->kills = cAgentData_GetStat(a, 0xD);
    info->s6 = cAgentData_GetStat(a, 1);
    info->s8 = cAgentData_GetStat(a, 4);
    info->sA = cAgentData_GetStat(a, 6);
    info->sC = cAgentData_GetStat(a, 7);
    info->shots = cAgentData_GetStat(a, 9);
    info->hits = cAgentData_GetStat(a, 0xA);
    info->w18 = cAgentData_GetStat(a, 2);
    info->w1C = cAgentData_GetStat(a, 0);
    info->w20 = cAgentData_GetStat(a, 8);
    bits = 0;
    {
        Rel_BD40 r;
        int i;
        func_00296FA0(&r);
        r.own = 1;
        cAgentData_GetRatings(a, &r);
        for (i = 0; i < r.Size() && i < 24; i++) {
            if (r[i].on)
                bits |= 1 << i;
        }
        func_00299360(&r, 0);
    }
    {
        Rel_BD40 r;
        int i;
        func_00296FA0(&r);
        r.own = 1;
        cAgentData_GetAchievements(a, 0, &r);
        for (i = 0; i < r.Size() && i < 8; i++) {
            if (r[i].on)
                bits |= 1 << (i + 24);
        }
        func_00299360(&r, 0);
    }
    info->bits = bits;
    memset(&info->app, 0, sizeof(App_BD40));
    CopyApp(&info->app, &a->app);
}
static inline void merge_flush_func_002CBD40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CBD40 */
