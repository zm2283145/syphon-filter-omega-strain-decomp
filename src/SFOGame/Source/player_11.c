/*
 * SFOGame/Source/player: 10 files, 00175BC0-00175E80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00175BC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Player component (cPlayer): script natives, type registration and setup.
 */

#include "types.h"
#include "player_types.h"

extern int cPlayer_RemoveWeapon(PlayerComponent* self, int weapon);

int Script_cPlayer_RemoveWeapon(PlayerScriptArg* args) {
    int spill[1]; /* original stack temporary; the cast form keeps it in memory */
    int weapon;
    PlayerComponent* self;

    *(int*)(char*)spill = args[1].i;
    weapon = *(int*)(char*)spill;
    self = (PlayerComponent*)args[0].p;
    cPlayer_RemoveWeapon(self, weapon);
    return 0;
}
static inline void merge_flush_func_00175BC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00175BC0 */

/* merge_units: begin func_00175BF0 */
#pragma push /* merge_units */
typedef struct { char pad[0x4C]; int classKey; char pad50[0x3524 - 0x50]; void* inv; } Hum_5BF0;
typedef struct { char pad[0x30]; Hum_5BF0* hum; } Obj_5BF0;
typedef struct { Obj_5BF0* obj; int id; } Arg_5BF0;
typedef struct { char pad[0x13C]; int ok; } Wdb_5BF0;
Wdb_5BF0* cWeaponDB_GetEntry(int, int);
int cWeapon_Add(void*, int, int, int, int, int);
extern int g_HumanActorClassKey;
extern int g_WeaponDatabase;
/* script: give the player a weapon when the weapon database entry is valid;
 * the id is staged through a stack slot (volatile) */
#pragma push
int Script_cPlayer_AddWeapon(Arg_5BF0* args)
{
    volatile int w[1];
    Hum_5BF0* h;
    int id;
    w[0] = args->id;
    h = args->obj->hum;
    id = w[0];
    if (h && h->classKey == g_HumanActorClassKey && cWeaponDB_GetEntry(g_WeaponDatabase, id)->ok)
        cWeapon_Add(h->inv, id, 1, 1, 0, 0);
    return 0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175BF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00175BF0 */

/* merge_units: begin func_00175C80 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char g_HumanActorClassKey[];
#endif /* merge_units */
#define g_HumanActorClassKey ((char*)&g_HumanActorClassKey) /* merge_units */


extern int cWeapon_Select(int, int);

int Script_cPlayer_ArmWeapon(int a0) {
    int loc[1];
    int a1, v0, v1;
    int cond;

    v0 = *(int*)((char*)a0 + 4);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)a0;
    a0 = *(int*)((char*)v0 + 48);
    cond = a0 == 0;
    a1 = *(int*)(char*)loc;
    if (cond) goto L00175CC0;
    v1 = *(int*)((char*)a0 + 76);
    v0 = *(int*)(char*)g_HumanActorClassKey;
    cond = v1 != v0;
    if (cond) goto L00175CC0;
    a0 = *(int*)((char*)a0 + 13604);
    v0 = cWeapon_Select(a0, a1);
L00175CC0:;
    v0 = 0;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175C80(void) {}
#undef g_HumanActorClassKey /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00175C80 */

/* merge_units: begin func_00175CD0 */
#pragma push /* merge_units */
#pragma global_optimizer off
typedef struct { int a0; int a4; int id; int ac; } Slot_P;
typedef struct { Slot_P s[8]; char pad[4]; unsigned char cur; } Inv_P;
typedef struct { char pad[0x4C]; int kind; char pad2[0x3524 - 0x50]; Inv_P* inv; } Plr_P;
typedef struct { char pad[0x30]; Plr_P* ctl; } GObj_P;
typedef struct { char pad[0x6A4]; Plr_P* player; } Game_P;
extern Game_P* g_Hud;
static inline Plr_P* AsPlayer(GObj_P* o) { Plr_P* p = o->ctl; if (p && p->kind == g_HumanActorClassKey) return p; return 0; }
static inline int ActiveId(Inv_P* inv) { unsigned char c = inv->cur; if (c != 6) return inv->s[c].id; return -1; }
static inline int GetW(GObj_P* o)
{
    int r = -1;
    Plr_P* p = o->ctl;
    if (p && p->kind == g_HumanActorClassKey)
        r = ActiveId(p->inv);
    return r;
}
int Script_cPlayer_GetActiveWeapon(GObj_P** args)
{
    int r[1];
    r[0] = GetW(args[0]);
    return *(int*)r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175CD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00175CD0 */

/* merge_units: begin func_00175D30 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg;

/* Virtual-call view of cPlayer: only the slots used here are named (vtable offset in comments). */
struct cPlayer {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual int Team(); /* +0x68 */
};

/* Script native: returns cPlayer::Team() of args[0]. */
extern "C" int Script_cPlayer_Team(ScriptArg* args)
{
    cPlayer* obj = (cPlayer*)args[0].p;
    volatile int result = obj->Team(); /* returned through a stack temporary */
    return result;
}
static inline void merge_flush_func_00175D30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00175D30 */

/* merge_units: begin func_00175D60 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char g_Hud[];
#endif /* merge_units */
#define g_Hud ((char*)&g_Hud) /* merge_units */

extern int cSystem_SOBJ_convert(int);
extern void GuiGameScreen_SetMenuReceiver(int, int);

int Script_cPlayer_SetMenuReceiver(int a0) {
    int a1, v0, v1;
    int cond;

    a0 = *(int*)((char*)a0 + 4);
    v0 = cSystem_SOBJ_convert(a0);
    v1 = *(int*)(char*)g_Hud;
    a0 = *(int*)((char*)v1 + 1700);
    cond = a0 == 0;
    a1 = v0;
    if (cond) goto L00175D90;
    GuiGameScreen_SetMenuReceiver(a0, a1);
L00175D90:;
    v0 = 0;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175D60(void) {}
#undef g_Hud /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00175D60 */

/* merge_units: begin func_00175DA0 */
#pragma push /* merge_units */
#pragma global_optimizer off
typedef struct { char pad[0x6A4]; void* player; } Game_P_00175DA0;
#if 0 /* merge_units */
extern Game_P_00175DA0* g_Hud;
#endif /* merge_units */
#define g_Hud (*(Game_P_00175DA0 **)&g_Hud) /* merge_units */


extern void GuiGameScreen_SetMenuTitle(void* p, int v);
static inline void Call_00175DA0(int v)
{
    void* p = g_Hud->player;
    if (p)
        GuiGameScreen_SetMenuTitle(p, v);
}
int Script_cPlayer_SetMenuTitle(int* args)
{
    int v[1];
    v[0] = args[1];
    Call_00175DA0(*(int*)v);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175DA0(void) {}
#undef g_Hud /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00175DA0 */

/* merge_units: begin func_00175DE0 */
#pragma push /* merge_units */
#pragma global_optimizer off


extern void GuiGameScreen_AddMenuChoice(void* p, int v);
static inline void Call_00175DE0(int v)
{
    void* p = g_Hud->player;
    if (p)
        GuiGameScreen_AddMenuChoice(p, v);
}
int Script_cPlayer_AddMenuChoice(int* args)
{
    int v[1];
    v[0] = args[1];
    Call_00175DE0(*(int*)v);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175DE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00175DE0 */

/* merge_units: begin func_00175E20 */
#pragma push /* merge_units */
#pragma global_optimizer off

typedef struct { char pad[0x6A4]; Plr_P* player; } Game_P_00175E20;
#if 0 /* merge_units */
extern Game_P_00175E20* g_Hud;
#endif /* merge_units */
#define g_Hud (*(Game_P_00175E20 **)&g_Hud) /* merge_units */

static inline Plr_P* AsPlayer_00175E20(GObj_P* o) { Plr_P* p = o->ctl; return (p && p->kind == g_HumanActorClassKey) ? p : 0; }
extern void GuiGameScreen_BeginChooseMenu(Plr_P* pl, Plr_P* who);
int Script_cPlayer_LaunchChooseMenu(GObj_P** args)
{
    GObj_P* o = args[0];
    Plr_P* pl = g_Hud->player;
    if (pl)
        GuiGameScreen_BeginChooseMenu(pl, AsPlayer_00175E20(o));
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175E20(void) {}
#undef g_Hud /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00175E20 */

/* merge_units: begin func_00175E80 */
#pragma push /* merge_units */
extern int D_004EE788;     /* cPlayer class type id */
extern int D_004EE790;     /* cPlayer script type */
extern char D_00555070[];
extern unsigned char g_IsMultiplayer;
extern int cGOBJ_SOBJ_toInt(void*);
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);
#if 0 /* merge_units */
extern int cWeapon_Select(void* inventory, int a1);
#endif /* merge_units */
#define cWeapon_Select(a0, a1) (cWeapon_Select((int)(a0), (a1))) /* merge_units */

extern int* func_001450C0(void);
extern void* cNPC_SOBJ_convert(int handle);
extern void cHuman_SetInvulnerable(PlayerActor* actor, int invulnerable);
extern int* cNotifyCheckpointMsg_SOBJ_getClassId(void);
extern int* func_0022F170(void);
extern int* func_0022F1F0(void);
extern void cPlayerControls_NetSelectNextWeapon(PlayerInputState* input, PlayerActor* actor);
extern int cScriptBase_declareMsgUse(int type, int messageType);
extern void cScriptBase_declareParent(int type, int parentType);
extern int* cDamageMsg_SOBJ_getClassId(void);

int Script_cPlayer_RestoreBody(void) {
    return 0;
}

int Script_cPlayer_SwitchBodies(PlayerScriptArg* args) {
    cNPC_SOBJ_convert(args[1].i);
    return 0;
}

int Script_cPlayer_SetInvulnerable(PlayerScriptArg* args) {
    int flag = args[1].i;

    cHuman_SetInvulnerable(((PlayerComponent*)args[0].p)->actor, (unsigned int)0 < (unsigned int)flag);
    return 0;
}

int Script_cPlayer_GetPlayerObject(PlayerScriptArg* args) {
    return cGOBJ_SOBJ_toInt(((PlayerComponent*)args[0].p)->actor);
}

/* Registers the cPlayer script type under its parent and adds its message types. */
int cPlayer_SOBJ_init(void) {
    int* type;

    type = func_0022F170();
    cScriptBase_declareParent(D_004EE790, *type);
    type = cNotifyCheckpointMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(D_004EE790, *type);
    type = func_0022F1F0();
    cScriptBase_declareMsgUse(D_004EE790, *type);
    type = cDamageMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(D_004EE790, *type);
    type = func_001450C0();
    return cScriptBase_declareMsgUse(D_004EE790, *type);
}

/* volatile mirrors the original stack temporary. */
int cPlayer_SOBJ_toInt(int obj) {
    volatile int tmp = obj;
    return tmp;
}

void* cPlayer_SOBJ_convert(void* self) {
    return self;
}

int* cPlayer_SOBJ_getClassId(void) {
    return &D_004EE788;
}

int cPlayer_getSOBJClassId(void) {
    return D_004EE788;
}

int cPlayer_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}

/*
 * For an NPC-class actor: calls cWeapon_Select on its inventory (a1 is passed
 * through) and, when the g_IsMultiplayer flag is set, cPlayerControls_NetSelectNextWeapon on the input state.
 */
void cPlayer_SelectWeapon(PlayerComponent* self, int a1) {
    PlayerActor* actor = self->actor;

    if (actor != 0 && actor->classToken == g_HumanActorClassKey) {
        cWeapon_Select(actor->inventory, a1);
        if (g_IsMultiplayer != 0) {
            cPlayerControls_NetSelectNextWeapon(&self->input, actor);
        }
    }
}
#undef cWeapon_Select /* merge_units */
static inline void merge_flush_func_00175E80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00175E80 */
