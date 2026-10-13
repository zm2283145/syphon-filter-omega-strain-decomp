#include "types.h"
typedef struct { char pad[0xB4]; unsigned char bB4; unsigned char bB5; } P2ADE60;
typedef struct { char pad[0x255C]; int mode; } G2ADE60;
typedef struct { char pad0[0x80]; unsigned char shown; char pad81[7]; P2ADE60* p88; char pad8C[0xAC - 0x8C]; char mAC[0x1C]; char mC8[4]; } S2ADE60;
extern G2ADE60* DME_GetLobby(void);
extern void func_004426B0(G2ADE60* g);
extern void func_002CC260(void);
extern void SFOLobby_EnterContactsState(G2ADE60* g, void* cb, void* a, void* b);
void func_002ADE60(S2ADE60* s)
{
    if (!s->shown) {
        G2ADE60* g = DME_GetLobby();
        if (g) {
            if (g->mode == 4)
                func_004426B0(g);
            SFOLobby_EnterContactsState(g, func_002CC260, s->mAC, s->mC8);
        }
        if (s->p88) {
            s->p88->bB4 = 1;
            s->p88->bB5 = 1;
        }
        s->shown = 1;
    }
}