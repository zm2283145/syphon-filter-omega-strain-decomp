/*
 * Matched functions (byte-identical with the retail executable).
 * cAI helpers: setter for field +0x54 (mirrored onto the game object in
 * multiplayer) and two service-wrapped calls.
 */

#include "types.h"
#include "ai_types.h"

extern char g_NpcRouteMgr[];
extern char g_Game[];  /* global service registry */
extern char g_IsMultiplayer[];  /* multiplayer flag byte */
extern int Service_Lookup(int, int);
extern int func_001589D0(void);
extern int NpcAi_ResetFireProgress(void);
extern int func_00164330(int);
extern int NpcRouteMgr_AllocRequestPool(int);

void NpcAi_SetTeam(cAI* self, int value) {
    AIGObj* gobj;
    AIGObjSub* sub;

    self->unk54 = value;
    if (*(unsigned char*)g_IsMultiplayer != 0) {
        gobj = self->gobj;
        if (gobj != 0) {
            sub = gobj->unk3584;
            if (sub != 0) {
                sub->unk30 = value;
            }
        }
    }
}

int func_0016F4D0(void) {
    func_001589D0();
    return func_00164330(Service_Lookup((int)g_Game, (int)g_NpcRouteMgr));
}

int func_0016F510(void) {
    NpcRouteMgr_AllocRequestPool(Service_Lookup((int)g_Game, (int)g_NpcRouteMgr));
    return NpcAi_ResetFireProgress();
}
