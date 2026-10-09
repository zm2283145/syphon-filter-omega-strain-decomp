/*
 * Matched functions (byte-identical with the retail executable).
 * Player component (cPlayer): script natives, type registration and setup.
 */

#include "types.h"
#include "player_types.h"

extern int D_0049D010;     /* NPC class token */
extern int D_004EE788;     /* cPlayer class type id */
extern int D_004EE790;     /* cPlayer script type */
extern char D_00555070[];
extern unsigned char D_005721C8;
extern int GObj_IdentityA(void*);
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int func_001439B0(void* inventory, int a1);
extern int* func_001450C0(void);
extern void* func_0014A690(int handle);
extern void func_001B8750(PlayerActor* actor, int invulnerable);
extern int* func_0022DE00(void);
extern int* func_0022F170(void);
extern int* func_0022F1F0(void);
extern void func_002493C0(PlayerInputState* input, PlayerActor* actor);
extern int ScriptType_AddAccepted(int type, int messageType);
extern void ScriptType_SetParent(int type, int parentType);
extern int* func_004080E0(void);

int Script_cPlayer_RestoreBody(void) {
    return 0;
}

int Script_cPlayer_SwitchBodies(PlayerScriptArg* args) {
    func_0014A690(args[1].i);
    return 0;
}

int Script_cPlayer_SetInvulnerable(PlayerScriptArg* args) {
    int flag = args[1].i;

    func_001B8750(((PlayerComponent*)args[0].p)->actor, (unsigned int)0 < (unsigned int)flag);
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
    type = func_0022DE00();
    ScriptType_AddAccepted(D_004EE790, *type);
    type = func_0022F1F0();
    ScriptType_AddAccepted(D_004EE790, *type);
    type = func_004080E0();
    ScriptType_AddAccepted(D_004EE790, *type);
    type = func_001450C0();
    return ScriptType_AddAccepted(D_004EE790, *type);
}

/* volatile mirrors the original stack temporary. */
int cHotboxMsg_WhoPlayer(int obj) {
    volatile int tmp = obj;
    return tmp;
}

void* func_00175FA0(void* self) {
    return self;
}

int* func_00175FB0(void) {
    return &D_004EE788;
}

int cPlayer_v0B(void) {
    return D_004EE788;
}

int cPlayer_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

/*
 * For an NPC-class actor: calls func_001439B0 on its inventory (a1 is passed
 * through) and, when the D_005721C8 flag is set, func_002493C0 on the input state.
 */
void func_00175FF0(PlayerComponent* self, int a1) {
    PlayerActor* actor = self->actor;

    if (actor != 0 && actor->classToken == D_0049D010) {
        func_001439B0(actor->inventory, a1);
        if (D_005721C8 != 0) {
            func_002493C0(&self->input, actor);
        }
    }
}
