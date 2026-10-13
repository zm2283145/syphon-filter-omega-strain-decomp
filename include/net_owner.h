#ifndef NET_OWNER_H
#define NET_OWNER_H
/* Session ownership test shared by the 0x002D2xxx net handlers. */
#include "npc_auth.h"
typedef struct { char pad[4]; int owner; } NetOwnerHdl;
extern int D_005721A8;
extern int D_00494178;
extern void NetGame_InitLocalSlot(int* id, int session);
extern int func_002EB650(NetOwnerHdl** out, int id);
static inline int NetOwner_LocalId(int session)
{
    if (D_005721C8) {
        if (D_00494178 == -1)
            NetGame_InitLocalSlot(&D_00494178, session);
        return D_00494178;
    }
    return 0;
}
static inline unsigned char NetOwner_IsMine(int id)
{
    NetOwnerHdl* h;
    unsigned char r = 0;
    if (func_002EB650(&h, id) == 0 && h) {
        r = h->owner == NetOwner_LocalId(D_005721A8);
        if (!r && h->owner == -1 && NpcAuth_IsLocal())
            r = 1;
    }
    return r;
}
#endif