#include "SFOLobby.h"
#pragma mpwc_relax on
int SFOLobby_SetError(SFOLobby * , int, char *, int);
int func_00468CD0();
extern char D_004C0E80;             /* "SFOLobby_Connect.cc" */
/* Disconnects (func_00468CD0) and forgets the connection. */
int func_0044C9D0(SFOLobby *self) {
    self->requestResult = func_00468CD0();
    if (self->requestResult != 0) {
        SFOLobby_SetError(self, 0x2B, &D_004C0E80, 0x2A0);
        return 0;
    }
    self->connHandle = -1;
    self->gotConnect = 0;
    return 1;
}
