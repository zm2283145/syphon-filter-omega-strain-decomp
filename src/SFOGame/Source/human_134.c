/*
 * SFOGame/Source/human: 2 files, 001BA130-001BA510
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001BA130 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
/* Actor_FireRespawnTimer: in game state 15, starts (or, while the screen
 * fader is idle, cancels) the respawn fade for the actor and queues the
 * timed respawn event (vtable D_004DA970). Event allocation as in
 * cGameSound_PauseMusic. */
struct Ghost_A130 { char pad0[0x34]; unsigned char b34; };
struct Actor_A130 {
    char pad0[0x14];
    unsigned char b14;
    char pad15[0x3269 - 0x15];
    unsigned char b3269;
    char pad326A[0x33A4 - 0x326A];
    unsigned char b33A4;
    char pad33A5[0x3584 - 0x33A5];
    Ghost_A130* ghost;
};
struct Self_A130 { char pad0[0xC]; Actor_A130* actor; unsigned char started; };
struct Zone_A130 { char pad0[8]; void* zone; };
struct Fader_A130 { int pad0; float level; };
struct Player_A130 { char pad0[0x30]; int zoneId; };
struct Ev_A130 { int time; unsigned char b4; unsigned char b5; char pad6[2]; void* vt; Actor_A130* actor; unsigned char on; };
extern "C" {
extern unsigned char g_GameState;
extern Player_A130* g_LocalPlayer;
extern Fader_A130* g_Fader;
extern void* g_VisionFxMan;
extern unsigned char g_IsMultiplayer;
extern char D_004D9DE0[];
extern void * const D_004DA970[];
void* GetSceneManager(void);
Zone_A130* cSceneManager_GetSceneBelongingTo(void* a, int id);
int nActivation_IsActivationLoaded(void* z);
void cScreenFader_StartFade(Fader_A130* f, float t, int on);
void ScreenFx_Start(void* s, unsigned char active, float x, float y, float z, float w);
void Actor_Ignite(Actor_A130* a, unsigned char on, void* obj, unsigned char a3, int quiet, float f);
void* cMemMan_Allocate(int, int, const char*, int);
void nCallback_SetCallback(Ev_A130*);
void Actor_FireRespawnTimer(Self_A130* self);
char D_0049ED68[] = "human.cc";
char D_0049ED78[] = "human.cc";
char D_0049ED88[] = "human.cc";
}

static inline void SetRespawning(Actor_A130* a, unsigned char v)
{
    a->b33A4 = v;
    if (g_IsMultiplayer && a->b14 && a->ghost)
        a->ghost->b34 = v;
}
static inline void InitEv(Ev_A130* e, Actor_A130* a, int time, unsigned char on)
{
    e->vt = D_004D9DE0;
    e->b4 = 1;
    e->time = time;
    e->b5 = 0;
    e->vt = (void*)D_004DA970;
    e->actor = a;
    e->on = on;
}

extern "C" void Actor_FireRespawnTimer(Self_A130* self)
{
    Zone_A130* z;
    if (g_GameState != 15)
        return;
    z = cSceneManager_GetSceneBelongingTo(GetSceneManager(), g_LocalPlayer->zoneId);
    if (!self->started) {
        if (nActivation_IsActivationLoaded(z->zone)) {
            Ev_A130* e;
            cScreenFader_StartFade(g_Fader, 1.0f, 1);
            ScreenFx_Start(g_VisionFxMan, 1, 0.0f, 0.0f, 0.0f, 0.0f);
            SetRespawning(self->actor, 1);
            Actor_Ignite(self->actor, 0, 0, 0, 0, -1.0f);
            self->actor->b3269 = 0;
            {
                AllocGuard g;
                e = (Ev_A130*)cMemMan_Allocate(0, 0x14, D_0049ED88, 0x3DC3);
            }
            if (e)
                InitEv(e, self->actor, 3000, 1);
            nCallback_SetCallback(e);
        } else {
            Ev_A130* e;
            {
                AllocGuard g;
                e = (Ev_A130*)cMemMan_Allocate(0, 0x14, D_0049ED78, 0x3DC7);
            }
            if (e)
                InitEv(e, self->actor, 1000, 0);
            nCallback_SetCallback(e);
            SetRespawning(self->actor, 1);
        }
    } else if (self->started) {
        if (g_Fader->level == 0.0f) {
            SetRespawning(self->actor, 0);
        } else {
            Ev_A130* e;
            {
                AllocGuard g;
                e = (Ev_A130*)cMemMan_Allocate(0, 0x14, D_0049ED68, 0x3DD2);
            }
            if (e)
                InitEv(e, self->actor, 1000, 1);
            nCallback_SetCallback(e);
        }
    }
}
static inline void merge_flush_func_001BA130(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001BA130 */

/* merge_units: begin func_001BA510 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

/* Network stream cursor shared by message serializers. */
extern signed char* D_005061D0;
extern int D_004EF010;
extern void cNetMsg_PutGOBJ(int);

/* Serialize: write the word argument, then two bytes. */
void cNetUpdateStatsMsg_Pack(ArgMsg* msg) {
    cNetMsg_PutGOBJ(msg->arg0);
    *D_005061D0 = msg->arg1;
    D_005061D0 = D_005061D0 + 1;
    *D_005061D0 = msg->arg2;
    D_005061D0 = D_005061D0 + 1;
}

/* Message type id. */
int cNetUpdateStatsMsg_v05(void) {
    return D_004EF010;
}
static inline void merge_flush_func_001BA510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001BA510 */
