#include "types.h"
typedef struct { char name[0x14]; int ver; char data[0xFC]; char pad[0x118 - 0x114]; } Msg46A9;
typedef struct { char pad[0x26A0]; unsigned char dirty; } Mgr6E0;
extern int D_004976D8;
extern char D_005723B8;
extern char D_00584220[];
extern unsigned char D_00584231;
extern unsigned char D_00584240;
extern unsigned char D_005842C8;
extern int D_005842CC;
extern int D_005842D0;
extern int D_005842D4;
extern int D_005842D8;
extern char D_00584378[];
extern short D_0058438E;
extern short D_00584390;
extern char D_00584398[];
extern int D_005843AC;
extern int D_005843B0;
extern char D_005843F4[];
extern int D_00584508;
extern int D_00584514;
extern int D_00584520;
extern Mgr6E0* D_00585E60;
extern char D_00585E70[];
extern int D_00585E80;
extern char D_00585E90[];
int MGCLUpdate(void);
void String_Copy(char*, char*);
int Medius_SendServerReport(char*);
void NetGetLocalTime(int*);
void NetGetTime(int*);
int NetGetValidClientCount(int*, int);
int func_003A6BC0(void);
void SFOLobby_Update(Mgr6E0*);
int func_00453F30(int);
void MediusSendPlayerReport(Msg46A9*);
void MediusSendWorldReport(char*);
void* memcpy(void*, const void*, unsigned int);
void* memset(void*, int, unsigned int);

int SFOMGCL_Update(int update)
{
    int status;
    int now;
    int tmp;
    Msg46A9 msg;
    int ret;

    now = 0;
    NetGetLocalTime(&now);
    if (D_005842C8) {
        D_00585E80 = (now - D_005842CC) / 1000;
    }
    if (update && now >= D_005842D4 + 15000) {
        D_005842D4 = now;
        memset(&msg, 0, sizeof(msg));
        String_Copy(msg.name, D_00584220);
        msg.ver = D_004976D8;
        memcpy(msg.data, D_00585E90, sizeof(msg.data));
        MediusSendPlayerReport(&msg);
    }
    if (!D_00584231) {
        return -6;
    }
    if (D_00584240 && now >= D_005842D0 + 15000) {
        D_005842D0 = now;
        if (NetGetValidClientCount(&status, D_00584520) == 0 && status >= 0) {
            D_00584390 = status;
            D_0058438E = 1;
            NetGetTime(&tmp);
            ret = Medius_SendServerReport(D_00584378);
            if (ret) {
                return ret;
            }
        }
    }
    if (update && D_00584240) {
        unsigned char* dirty = &D_00585E60->dirty;
        if (*dirty || now >= D_005842D8 + 15000) {
            D_005842D8 = now;
            *dirty = 0;
            if (NetGetValidClientCount(&status, D_00584520)) {
                status = 1;
            }
            D_005843B0 = status;
            String_Copy(D_00584398, D_00584220);
            D_005843AC = D_004976D8;
            D_00584514 = func_003A6BC0() ? 1 : 3;
            D_00584508 = *(volatile int*)&D_00584514;
            memcpy(D_005843F4, D_00585E70, 0x18);
            MediusSendWorldReport(D_00584398);
        }
    }
    ret = MGCLUpdate();
    if (ret == 0) {
        if (!update) {
            SFOLobby_Update(D_00585E60);
        }
    } else if (func_00453F30(2) == 0) {
        D_005723B8 = 1;
    }
    return ret;
}

