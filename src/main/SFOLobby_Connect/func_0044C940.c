#include "SFOLobby.h"
#pragma mpwc_relax on
int String_Copy();
int SFOLobby_SetError();
int func_00468F78();
int memset();
extern char D_004C0E80;             /* "SFOLobby_Connect.cc" */
#pragma opt_common_subs off
/* Sends the session key with flag (func_00468F78). */
int func_0044C940(SFOLobby * self, int flag) {
    struct { int sessionKey[5]; int flag[3]; } sl;
    memset(sl.sessionKey, 0, 0x18);
    String_Copy(sl.sessionKey, self->sessionKey);
    sl.flag[0] = flag;
    self->requestResult = func_00468F78(sl.sessionKey);
    if (self->requestResult != 0) {
        SFOLobby_SetError(self, 0xD, &D_004C0E80, 0x2D1);
        return 0;
    }
    return 1;
}
