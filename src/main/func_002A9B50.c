#include "types.h"
typedef struct { char pad[0x1C]; } M2A9B50;
typedef struct { char pad0[0x80]; unsigned char active; char pad81[0xA0 - 0x81]; M2A9B50 mA0; } S2A9B50;
extern void* DME_GetLobby(void);
extern void func_00442E90(void* p);
extern void LobbyArray_Free(M2A9B50* m);
void func_002A9B50(S2A9B50* s)
{
    if (s->active) {
        void* p = DME_GetLobby();
        if (p)
            func_00442E90(p);
        LobbyArray_Free(&s->mA0);
        s->active = 0;
    }
}