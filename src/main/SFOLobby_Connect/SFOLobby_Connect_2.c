/*
 * main/SFOLobby_Connect: 3 files, 0044C940-0044CA30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0044C940 */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end func_0044C940 */

/* merge_units: begin func_0044C9D0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int SFOLobby_SetError(SFOLobby * , int, char *, int);
int func_00468CD0();
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
#pragma pop /* merge_units */
/* merge_units: end func_0044C9D0 */

/* merge_units: begin func_0044CA30 */
#pragma push /* merge_units */
#pragma mpwc_relax on

/* Disconnects (func_00468CD0) and forgets the connection. */
int func_0044CA30(SFOLobby *self) {
    self->requestResult = func_00468CD0();
    if (self->requestResult != 0) {
        SFOLobby_SetError(self, 0x2C, &D_004C0E80, 0x288);
        return 0;
    }
    self->connHandle = -1;
    self->gotConnect = 0;
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0044CA30 */
