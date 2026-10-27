/*
 * Libs/SFOLobby/SFOLobby/SFO_MGCL: 2 files, 004446E0-004449C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004446E0 */
#pragma push /* merge_units */
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
void Libc_Strcpy(char*, char*);
int MGCLSendServerReport(char*);
void NetGetLocalTime(int*);
void NetGetTime(int*);
int NetGetValidClientCount(int*, int);
int func_003A6BC0(void);
void SFOLobby_Intel(Mgr6E0*);
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
        Libc_Strcpy(msg.name, D_00584220);
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
            ret = MGCLSendServerReport(D_00584378);
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
            Libc_Strcpy(D_00584398, D_00584220);
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
            SFOLobby_Intel(D_00585E60);
        }
    } else if (func_00453F30(2) == 0) {
        D_005723B8 = 1;
    }
    return ret;
}
static inline void merge_flush_func_004446E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004446E0 */

/* merge_units: begin func_004449C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_common_subs off

typedef struct {
    char pad0[0x38];
    char sub[0x40];
    char pad78[0x9C - 0x78];
    int wait;
} Conn9C0;
typedef struct {
    char kind[0x15];
    char pad15[0x18 - 0x15];
    int id;
    int ver;
    int mode;
    char pad24[0x38 - 0x24];
} Req9C0A;
typedef struct {
    char kind[0x15];
    char pad15[0x18 - 0x15];
    int one;
    char pad1C[0x4C - 0x1C];
} Req9C0B;

extern "C" {
#if 0 /* merge_units */
void Libc_Strcpy(char*, const char*);
#endif /* merge_units */
#define Libc_Strcpy(a0, a1) (Libc_Strcpy((a0), (char *)(a1))) /* merge_units */

void MGCLSetDefaultConnectParams(Conn9C0*);
int atoi(char*);
void MGCLSetAuthConnectParams(Conn9C0*, int, int, int, void*);
void KM_GetMediusPublicKey(char*);
int Medius_ConnectServer(Conn9C0*, int*);
int MGCLSessionBegin(Req9C0A*, void*);
int MGCLAuthenticationSend(Req9C0B*, void*);
int KM_GetSoftwareID(void);
int MGCLDisconnect(void);
#if 0 /* merge_units */
int SFOMGCL_Update(int);
#endif /* merge_units */
#define SFOMGCL_Update(a0) (SFOMGCL_Update((a0))) /* merge_units */

void SFOLobby_GuiCallback(char*, int, int);
void func_00444DD0(void);
void Callback_MGCLServerSessionBegin(void);
void Callback_MGCLServerAuthentication(void);
extern unsigned char D_00584232;
extern unsigned char D_00584233;
extern unsigned char D_00584235;
extern unsigned char D_00584236;
extern unsigned char D_00584239;
extern unsigned char D_0058423A;
extern int D_00584528;
#if 0 /* merge_units */
extern char* D_00585E60;
#endif /* merge_units */
#define D_00585E60 (*(char **)&D_00585E60) /* merge_units */

extern char D_004C0B38[];
int SFOMGCL_Connect_MAS(int a, char* b);
}

static inline bool Poll(void) {
    int now = 0;
    NetGetLocalTime(&now);
    if (now - D_00584528 > 30000) return false;
    SFOLobby_GuiCallback(D_00585E60, 0, 0);
    return true;
}

static inline int Busy(void) {
    int r = MGCLDisconnect();
    if (r) return r;
    return 0;
}

int SFOMGCL_Connect_MAS(int a, char* b) {
    Conn9C0 conn;
    int x;
    Req9C0A req;
    Req9C0B join;
    int r;
    memset(&conn, 0, sizeof(conn));
    memset(&x, 0, sizeof(x));
    memset(&req, 0, sizeof(req));
    memset(&join, 0, sizeof(join));
    MGCLSetDefaultConnectParams(&conn);
    MGCLSetAuthConnectParams(&conn, a, atoi(b), 1, (void*)func_00444DD0);
    if (((unsigned char*)D_00585E60)[0x23D6] == 0)
        KM_GetMediusPublicKey(conn.sub);
    else
        memset(conn.sub, 0, sizeof(conn.sub));
    r = Medius_ConnectServer(&conn, &x);
    if (r) return r;
    if (conn.wait) {
        D_00584528 = 0;
        NetGetLocalTime(&D_00584528);
        SFOLobby_GuiCallback(D_00585E60, 2, 1);
        while (D_00584232 == 0) {
            if (!Poll()) return -1000;
            if (SFOMGCL_Update(0)) return -12;
        }
        if (!D_00584233) return -12;
    }
    Libc_Strcpy(req.kind, D_004C0B38);
    req.id = *(int*)(D_00585E60 + 0x1F38);
    req.ver = KM_GetSoftwareID();
    req.mode = 2;
    r = MGCLSessionBegin(&req, (void*)Callback_MGCLServerSessionBegin);
    if (r) return r;
    D_00584528 = 0;
    NetGetLocalTime(&D_00584528);
    SFOLobby_GuiCallback(D_00585E60, 2, 1);
    while (D_00584235 == 0) {
        if (!Poll()) return -1000;
        if (SFOMGCL_Update(0)) return -12;
    }
    if (!D_00584236) return -12;
    Libc_Strcpy(join.kind, D_004C0B38);
    join.one = 1;
    r = MGCLAuthenticationSend(&join, (void*)Callback_MGCLServerAuthentication);
    if (r) return r;
    D_00584528 = 0;
    NetGetLocalTime(&D_00584528);
    SFOLobby_GuiCallback(D_00585E60, 2, 1);
    while (D_00584239 == 0) {
        if (!Poll()) return -1000;
        if (SFOMGCL_Update(0)) return -12;
    }
    if (!D_0058423A) return -12;
    return Busy();
}
#undef Libc_Strcpy /* merge_units */
#undef SFOMGCL_Update /* merge_units */
#undef D_00585E60 /* merge_units */
static inline void merge_flush_func_004449C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004449C0 */
