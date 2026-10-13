#include "SFOLobby.h"
int SFOLobby_NoInstance();
int SFOLobby_SetError(SFOLobby *, int, char *, int);
int memcpy();
extern char D_004C0CB0; /* "SFOLobby_Callback.cc" */
extern SFOLobby *D_00585E60;
/* Login reply callback: flags gotLogin, maps the Medius status to a lobby error
 * (0x3A bad password, 0x3B unknown account, 0x3C already logged in, else 1),
 * stores the account id and keeps the reply. */
void func_004475E0(int d0, int d1, int d2, LobbyLoginReply *src) {
    if (SFOLobby_NoInstance() == 0) {
        D_00585E60->gotLogin = 1;
        switch (src->statusCode) {
        case MediusSuccess:
            break;
        case MediusInvalidPassword:
            SFOLobby_SetError(D_00585E60, 0x3A, &D_004C0CB0, 0x2D0);
            break;
        case MediusAccountNotFound:
            SFOLobby_SetError(D_00585E60, 0x3B, &D_004C0CB0, 0x2E0);
            break;
        case MediusPlayerNotPrivileged:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x2EB);
            break;
        case MediusAccountLoggedIn:
            SFOLobby_SetError(D_00585E60, 0x3C, &D_004C0CB0, 0x2F6);
            break;
        case MediusDMEError:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x301);
            break;
        case MediusDBError:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x30C);
            break;
        case MediusWMError:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x317);
            break;
        }
        D_00585E60->accountId = src->accountId;
        memcpy(&D_00585E60->loginReply, src, 0xC4);
    }
}
