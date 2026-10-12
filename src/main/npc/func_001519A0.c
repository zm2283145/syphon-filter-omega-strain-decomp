#include "types.h"
typedef struct { char pad[0x44]; int state; } S1519A0;
extern int NpcAi_ModePatrol(S1519A0*, int);
extern int NpcAi_ModeAlert(S1519A0*, int);
extern int NpcAi_ModeTakeCover(S1519A0*, int);
extern int NpcAi_ModeAttackFromCover(S1519A0*, int);
extern int NpcAi_ModeAttack(S1519A0*, int);
extern int NpcAi_ModeSearch(S1519A0*, int);
extern int NpcAi_ModeFlee(S1519A0*, int);
extern int NpcAi_ScriptControlMode(S1519A0*, int);
extern int NpcAi_ModeCarryBody(S1519A0*, int);
extern int NpcAi_ModeFollow(S1519A0*, int);
extern int NpcAi_ModeGrenadeEvasion(S1519A0*, int);
unsigned char NpcAi_DispatchMode(S1519A0* p, int a) {
    unsigned char r;
    switch (p->state) {
    case 0: r = NpcAi_ModePatrol(p, a); break;
    case 1: r = NpcAi_ModeAlert(p, a); break;
    case 2: r = NpcAi_ModeTakeCover(p, a); break;
    case 3: r = NpcAi_ModeAttackFromCover(p, a); break;
    case 4: r = NpcAi_ModeAttack(p, a); break;
    case 5: r = NpcAi_ModeSearch(p, a); break;
    case 6: r = NpcAi_ModeFlee(p, a); break;
    case 7: r = NpcAi_ScriptControlMode(p, a); break;
    case 8: r = NpcAi_ModeCarryBody(p, a); break;
    case 9: r = NpcAi_ModeFollow(p, a); break;
    case 10: r = NpcAi_ModeGrenadeEvasion(p, a); break;
    }
    return r;
}