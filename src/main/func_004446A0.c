#include "SFOLobby_Callback_types.h"

extern int D_0058423C;
extern int D_004976D8;

/* Publish the callback's value on success, or mark the operation as failed. */
void func_004446A0(int unused0, int unused1, int unused2, LobbyStatusResult* result)
{
    if (!result->status) {
        D_004976D8 = result->value;
        D_0058423C = 1;
    } else {
        D_0058423C = -1;
    }
}
