#include "types.h"
typedef struct { char pad[0x44]; int state; } S1519A0;
extern int NpcAi_ModePatrol(S1519A0*, int);
extern int NpcAi_ModeAlert(S1519A0*, int);
extern int func_001564C0(S1519A0*, int);
extern int func_00155BA0(S1519A0*, int);
extern int NpcAi_ModeAttack(S1519A0*, int);
extern int func_00154DD0(S1519A0*, int);
extern int func_001548F0(S1519A0*, int);
extern int NpcAi_ScriptControlMode(S1519A0*, int);
extern int func_00153150(S1519A0*, int);
extern int func_00153870(S1519A0*, int);
extern int func_001535E0(S1519A0*, int);
unsigned char NpcAi_DispatchMode(S1519A0* p, int a) {
    unsigned char r;
    switch (p->state) {
    case 0: r = NpcAi_ModePatrol(p, a); break;
    case 1: r = NpcAi_ModeAlert(p, a); break;
    case 2: r = func_001564C0(p, a); break;
    case 3: r = func_00155BA0(p, a); break;
    case 4: r = NpcAi_ModeAttack(p, a); break;
    case 5: r = func_00154DD0(p, a); break;
    case 6: r = func_001548F0(p, a); break;
    case 7: r = NpcAi_ScriptControlMode(p, a); break;
    case 8: r = func_00153150(p, a); break;
    case 9: r = func_00153870(p, a); break;
    case 10: r = func_001535E0(p, a); break;
    }
    return r;
}