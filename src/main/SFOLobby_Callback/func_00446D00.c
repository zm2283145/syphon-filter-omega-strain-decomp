#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
extern int String_Copy(char* dst, char* src);
extern int SFOLobby_NoInstance(void);

/* Reply to the own-IP request (SFOLobby_RequestMyIp). */
typedef struct LobbyMyIpReply {
    char messageId[0x15];
    char ip[0x2C - 0x15];           /* 0x15 */
    int statusCode;                 /* 0x2C */
} LobbyMyIpReply;

/* Own-IP reply callback: flags gotMyIp and stores the address on success. */
void func_00446D00(int a0, int a1, int a2, LobbyMyIpReply* info) {
    if (SFOLobby_NoInstance() == 0) {
        D_00585E60->gotMyIp = 1;
        if (info->statusCode == MediusSuccess) {
            String_Copy(D_00585E60->myIp, info->ip);
        }
    }
}
