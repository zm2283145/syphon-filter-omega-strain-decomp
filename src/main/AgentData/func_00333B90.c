
#include "types.h"
/* AgentData_SetObjectiveBit */
typedef struct { void* vt; char pad04[0x18]; int x1C; signed char kind; char pad21[3]; int key; } Msg_333B90;
typedef struct { char pad0[4]; int magic; } Pt2_Tag;
typedef struct { char pad0[0x30]; Pt2_Tag* tgt; } Pt2_Hud;
typedef struct { char pad0[0x84]; unsigned int done[8]; unsigned int seen[8]; } Pt2_Agent;
extern unsigned char D_005721C8;
extern Pt2_Hud* D_004FFC0C;
extern char D_005329C0[];
extern void Message_GetScriptTypeKey();
extern void cNetAddObjectiveMsg_dtor();
extern void cNetAddObjectiveMsg_v01();
extern void cNetAddObjectiveMsg_v04();
extern void cNetAddObjectiveMsg_v05();
extern void func_002823E0();
void * const D_004DE810[8] = { (void*)0x0, (void*)0x0, (void*)cNetAddObjectiveMsg_dtor, (void*)cNetAddObjectiveMsg_v01, (void*)func_002823E0, (void*)Message_GetScriptTypeKey, (void*)cNetAddObjectiveMsg_v04, (void*)cNetAddObjectiveMsg_v05 };
extern char D_004DCF10[];
extern __int128 func_003FDA40(char*);
extern int Objective_Find(__int128);
extern int Loc_FindKeyThunk(char*);
extern void Event_Construct(Msg_333B90* m, void* type);
extern void Event_Send(Msg_333B90* m, void* target, int x);
extern void cMessage_dtor(Msg_333B90* m, int f);
static inline void Pt2_SetBit(unsigned int* bits, int i) { if (i > -1) bits[i / 32] |= 1 << (i & 0x1F); }

#pragma opt_propagation off
void AgentData_SetObjectiveBit(Pt2_Agent* ag, char* name, int notify) {
    int idx = Objective_Find(func_003FDA40(name));
    Pt2_SetBit(ag->done, idx);
    Pt2_SetBit(ag->seen, idx);
    if (notify && D_005721C8 && D_004FFC0C && D_004FFC0C->tgt->magic == 0xBEBAAFDE) {
        Msg_333B90 m;
        Msg_333B90* mp = &m;
        Event_Construct(mp, D_005329C0);
        m.vt = ((char*)D_004DE810);
        mp->key = Loc_FindKeyThunk(name);
        mp->kind = 4;
        mp->x1C = 0x40;
        Event_Send(mp, D_004FFC0C->tgt, 0);
        m.vt = D_004DCF10;
        cMessage_dtor(mp, 0);
    }
}
