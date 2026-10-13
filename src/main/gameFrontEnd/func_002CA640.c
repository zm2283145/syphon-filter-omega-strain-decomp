#include "types.h"
typedef struct { char pad[0x255C]; int mode; } G2CA640;
typedef struct { char pad[0x264]; unsigned char b264; } S2CA640;
extern void func_002CA160(S2CA640* s);
extern G2CA640* DME_GetLobby(void);
extern void func_00445850(G2CA640* g);
extern void func_002C8090(S2CA640* s);
extern void func_00453B00(G2CA640* g, int a);
extern void DME_SetLobbyActive(int a);
int func_002CA640(S2CA640* s, int a)
{
    func_002CA160(s);
    if (DME_GetLobby()) {
        if (s->b264 && DME_GetLobby()->mode != 10)
            func_00445850(DME_GetLobby());
        s->b264 = 0;
        func_002C8090(s);
        func_00453B00(DME_GetLobby(), a);
        DME_SetLobbyActive(0);
        return 1;
    }
    return 0;
}