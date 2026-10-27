/*
 * SFOGame/Source/ai: 2 files, 0016F430-0016F490
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016F430 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cAITimeElapsedMsg_dtor, D_004DCC10, cMessage_dtor)
static inline void merge_flush_func_0016F430(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016F430 */

/* merge_units: begin func_0016F490 */
#pragma push /* merge_units */
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
extern int cSystemContainer_GetSystem(int, int);
extern int cNPC_SystemClear(void);
extern int cNPC_SystemInit(void);
extern int cPathSystem_Clear(int);
extern int cPathSystem_Init(int);

void cAI_SetTeam(cAI* self, int value) {
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

int cAI_SystemClear(void) {
    cNPC_SystemClear();
    return cPathSystem_Clear(cSystemContainer_GetSystem((int)g_Game, (int)g_NpcRouteMgr));
}

int cAI_SystemInit(void) {
    cPathSystem_Init(cSystemContainer_GetSystem((int)g_Game, (int)g_NpcRouteMgr));
    return cNPC_SystemInit();
}
static inline void merge_flush_func_0016F490(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016F490 */
