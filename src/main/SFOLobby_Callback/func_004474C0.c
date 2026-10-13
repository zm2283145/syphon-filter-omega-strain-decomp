#include "SFOLobby.h"
int SFOLobby_NoInstance();
int SFOLobby_SetError(SFOLobby *, int, char *, int);
extern char D_004C0CB0; /* "SFOLobby_Callback.cc" */
extern SFOLobby *D_00585E60;
/* Reply callback: flags gotReply190 and reports server-side failures as error 1. */
void func_004474C0(int d0, int d1, int d2, LobbyReply *src) {
    if (SFOLobby_NoInstance() == 0) {
        int e;
        D_00585E60->gotReply190 = 1;
        e = src->statusCode;
        switch (e) {
        case MediusSuccess:
            break;
        case MediusPlayerNotPrivileged:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x351);
            break;
        case MediusDMEError:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x35C);
            break;
        case MediusDBError:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x367);
            break;
        case MediusWMError:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x372);
            break;
        default:
            if (e < 0) SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x379);
            break;
        }
    }
}
