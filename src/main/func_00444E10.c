#include "types.h"
#include "SFOLobby_Callback_types.h"

extern unsigned char D_00584239;
extern unsigned char D_0058423A;
extern char D_005842DC[0x9C];

/* Save a successful callback's payload and record its completion status. */
void func_00444E10(int unused0, int unused1, int unused2, const LobbyPayloadResult* result)
{
    D_00584239 = 1;
    if (result->status) {
        D_0058423A = 0;
    } else {
        memcpy(D_005842DC, result->payload, sizeof(D_005842DC));
        D_0058423A = 1;
    }
}
