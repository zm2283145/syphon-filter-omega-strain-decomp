/*
 * Matched functions (byte-identical with the retail executable).
 * Player component (cPlayer): script natives, type registration and setup.
 */

#include "types.h"
#include "player_types.h"

extern int g_HumanActorClassKey;     /* NPC class token */
extern int D_004EE788;     /* cPlayer class type id */
extern int D_004EE790;     /* cPlayer script type */
extern char D_00555070[];
extern unsigned char g_IsMultiplayer;
extern int GObj_IdentityA(void*);
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int WeaponInv_EquipItem(void* inventory, int a1);
extern int* func_001450C0(void);
extern void* NpcScript_GetReceiver(int handle);
extern void Actor_SetInvulnerable(PlayerActor* actor, int invulnerable);
extern int* cNotifyCheckpointMsg_SOBJ_getClassId(void);
extern int* func_0022F170(void);
extern int* func_0022F1F0(void);
extern void cPlayerControls_NetSelectNextWeapon(PlayerInputState* input, PlayerActor* actor);
extern int ScriptType_AddAccepted(int type, int messageType);
extern void ScriptType_SetParent(int type, int parentType);
extern int* cDamageMsg_SOBJ_getClassId(void);

int Script_cPlayer_RestoreBody(void) {
    return 0;
}

int Script_cPlayer_SwitchBodies(PlayerScriptArg* args) {
    NpcScript_GetReceiver(args[1].i);
    return 0;
}

int Script_cPlayer_SetInvulnerable(PlayerScriptArg* args) {
    int flag = args[1].i;

    Actor_SetInvulnerable(((PlayerComponent*)args[0].p)->actor, (unsigned int)0 < (unsigned int)flag);
    return 0;
}

int Script_cPlayer_GetPlayerObject(PlayerScriptArg* args) {
    return GObj_IdentityA(((PlayerComponent*)args[0].p)->actor);
}

/* Registers the cPlayer script type under its parent and adds its message types. */
int ScriptType_cPlayer_Init(void) {
    int* type;

    type = func_0022F170();
    ScriptType_SetParent(D_004EE790, *type);
    type = cNotifyCheckpointMsg_SOBJ_getClassId();
    ScriptType_AddAccepted(D_004EE790, *type);
    type = func_0022F1F0();
    ScriptType_AddAccepted(D_004EE790, *type);
    type = cDamageMsg_SOBJ_getClassId();
    ScriptType_AddAccepted(D_004EE790, *type);
    type = func_001450C0();
    return ScriptType_AddAccepted(D_004EE790, *type);
}

/* volatile mirrors the original stack temporary. */
int cHotboxMsg_WhoPlayer(int obj) {
    volatile int tmp = obj;
    return tmp;
}

void* cPlayer_SOBJ_convert(void* self) {
    return self;
}

int* cPlayer_SOBJ_getClassId(void) {
    return &D_004EE788;
}

int cPlayer_v0B(void) {
    return D_004EE788;
}

int cPlayer_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

/*
 * For an NPC-class actor: calls WeaponInv_EquipItem on its inventory (a1 is passed
 * through) and, when the g_IsMultiplayer flag is set, cPlayerControls_NetSelectNextWeapon on the input state.
 */
void Player_EquipItem(PlayerComponent* self, int a1) {
    PlayerActor* actor = self->actor;

    if (actor != 0 && actor->classToken == g_HumanActorClassKey) {
        WeaponInv_EquipItem(actor->inventory, a1);
        if (g_IsMultiplayer != 0) {
            cPlayerControls_NetSelectNextWeapon(&self->input, actor);
        }
    }
}
