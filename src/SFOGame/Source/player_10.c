/*
 * SFOGame/Source/player: 2 files, 00175B00-00175B60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00175B00 */
#pragma push /* merge_units */
/* retail keeps the dead nGlobalization_GetString_charP arm of (t ? nGlobalization_GetString_charP(t) : 0) with a char* t propagated to $zero (beq $zero,$zero): opt_dead_code off */
#pragma opt_dead_code off
typedef struct { char pad[0x6AC]; char timer[0x30]; float baseTime; } SoundMgr175B;
typedef union { int i; float f; } ScriptArg175B;
extern SoundMgr175B* g_Hud;
extern int nGlobalization_GetString_charP(int id);
extern void cHud_cHudTimer_ScheduleExpiration(void* timer, int obj, float time);

int Script_cPlayer_SetTimer(ScriptArg175B* args) { float timeArg[1]; float time; int id; *(int*)timeArg = args[1].i; time = *timeArg; { char* t = 0; id = t ? nGlobalization_GetString_charP((int)t) : 0; } cHud_cHudTimer_ScheduleExpiration(g_Hud->timer, id, time + g_Hud->baseTime); return 0; }
static inline void merge_flush_func_00175B00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00175B00 */

/* merge_units: begin func_00175B60 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int a0; int a4; int id; int ac; } Slot_P;
typedef struct { Slot_P s[8]; } Inv_P;
typedef struct { char pad[0x4C]; int kind; char pad2[0x3524 - 0x50]; Inv_P* inv; } Plr_P;
typedef struct { char pad[0x30]; Plr_P* ctl; } GObj_P;
typedef struct { GObj_P* o; unsigned char slot; } Args_5B60;
extern int g_HumanActorClassKey;
extern void cPlayer_RemoveWeapon(GObj_P* o, int id, Plr_P* p);
int Script_cPlayer_RemoveWeaponFromSlot(Args_5B60* args)
{
    unsigned char slot = args->slot;
    GObj_P* o = args->o;
    Plr_P* p = o->ctl;
    if (p && p->kind == g_HumanActorClassKey)
        cPlayer_RemoveWeapon(o, p->inv->s[slot].id, p);
    return 0;
}
static inline void merge_flush_func_00175B60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00175B60 */
