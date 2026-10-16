#include "types.h"
typedef struct { char pad[0x60]; int f60; } G1C5;
typedef struct { void* vt; char pad[0x1C]; unsigned char b20; char pad2[0x19F]; } M1C5;
typedef struct { char pad[0x190]; } R1C5;
extern void cPARTICLE_GOBJ_v10(G1C5*);
extern int func_00394170(G1C5*);
extern int func_00394140(G1C5*, int*);
extern int* SpecFx_GetEffectDef(int);
extern int D_005383C8;
extern void SoundRequest_Ctor(R1C5*, int, char*, int, int);
extern void SoundPosRequest_Ctor(M1C5*, R1C5*, int*);
extern void Event_Send(M1C5*, char*, int);
extern char D_004FFB50[];
extern char D_004DAE30[];
extern void FileMan_Release(void*, int);
extern void cMessage_dtor(M1C5*, int);
void ParticleGob_Update(G1C5* g) {
    int x[4];
    R1C5 req;
    M1C5 msg;
    cPARTICLE_GOBJ_v10(g);
    if (!func_00394170(g)) return;
    if ((unsigned char)func_00394140(g, x) != 1) return;
    if (g->f60 != *SpecFx_GetEffectDef(9)) return;
    if (D_005383C8 & 7) return;
    SoundRequest_Ctor(&req, 0, "O_GLASS_BREAK_S", 0, 0);
    SoundPosRequest_Ctor(&msg, &req, x);
    msg.b20 = 1;
    Event_Send(&msg, D_004FFB50, 0);
    msg.vt = D_004DAE30;
    FileMan_Release((char*)&msg + 0x114, -1);
    FileMan_Release((char*)&msg + 0x78, -1);
    cMessage_dtor(&msg, 0);
    FileMan_Release((char*)&req + 0xE4, -1);
    FileMan_Release((char*)&req + 0x48, -1);
}
