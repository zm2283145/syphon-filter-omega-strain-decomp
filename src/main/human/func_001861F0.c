#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Ctl_61F0 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer(); };
struct Hum_61F0 { char pad[0xC]; unsigned int flags; char pad10[0x48]; Ctl_61F0* ctl; };
extern "C" {
void* Agent_GetSelected(void*, int);
int func_00332F90(void*, int);
extern char D_004FFB50[];
extern float D_0048A2D0;
extern unsigned char D_005721C8;
}
static inline unsigned char IsPlayer_61F0(Hum_61F0* h) { unsigned char r = 0; if (h->ctl && h->ctl->IsPlayer()) r = 1; return r; }
static inline int IsPlayerB_61F0(Hum_61F0* h) { int b = h->ctl != 0; if (b) b = h->ctl->IsPlayer(); return b; }
static inline int LocalId_61F0(Hum_61F0* h) { int id; if (D_005721C8) { if (IsPlayer_61F0(h)) id = ((h->flags & 0x7F000000) >> 24) - 1; else id = -1; } else id = 0; return id; }
static inline void* Agent_61F0(Hum_61F0* h) { return IsPlayerB_61F0(h) ? Agent_GetSelected(D_004FFB50, LocalId_61F0(h)) : 0; }
/* clips granted to an actor: the player's count is scaled when the agent has perk 5 */
#pragma push
#pragma opt_propagation off
extern "C" int WeaponInv_ClipsForActor(Hum_61F0* h, int n)
{
    int r = n;
    if (IsPlayer_61F0(h)) {
        int id = LocalId_61F0(h); void* ag = IsPlayerB_61F0(h) ? Agent_GetSelected(D_004FFB50, id) : 0;
        if (func_00332F90(ag, 5)) {
            r = (int)(n * D_0048A2D0);
            if (r == n) r++;
        }
    }
    return r;
}
#pragma pop
