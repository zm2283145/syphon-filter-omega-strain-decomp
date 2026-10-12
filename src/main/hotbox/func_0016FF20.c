#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Ctl_FF20 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsPlayer(); };
struct Hum_FF20 { char pad[0x58]; Ctl_FF20* ctl; };
struct Obj_FF20 { char pad[0x30]; Hum_FF20* hum; };
extern "C" void func_0014A670(Ctl_FF20*);
static inline unsigned char IsPlayer_FF20(Obj_FF20* o) { unsigned char r = 0; if (o->hum->ctl && o->hum->ctl->IsPlayer()) r = 1; return r; }
static inline unsigned char IsNpc_FF20(Obj_FF20* o) { unsigned char r = 0; bool np = !IsPlayer_FF20(o); if (np && o->hum->ctl) r = 1; return r; }
static inline Ctl_FF20* Npc_FF20(Obj_FF20* o) { return IsNpc_FF20(o) ? o->hum->ctl : 0; }
/* script: hand the target's NPC controller (null for the player) to func_0014A670 */
extern "C" void Script_cHotboxMsg_WhoNPC(Obj_FF20** args)
{
    func_0014A670(Npc_FF20(args[0]));
}
