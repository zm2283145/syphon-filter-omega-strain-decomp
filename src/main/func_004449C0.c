#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#include "types.h"

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
void* memset(void*, int, unsigned int);
void String_Copy(char*, const char*);
void MGCLSetDefaultConnectParams(Conn9C0*);
int atoi(char*);
void MGCLSetAuthConnectParams(Conn9C0*, int, int, int, void*);
void KM_GetMediusPublicKey(char*);
int Medius_ConnectServer(Conn9C0*, int*);
int MGCLSessionBegin(Req9C0A*, void*);
int MGCLAuthenticationSend(Req9C0B*, void*);
int KM_GetSoftwareID(void);
int Medius_DisconnectServer(void);
void NetGetLocalTime(int*);
int SFOMGCL_Update(int);
void SFOLobby_CallUpdateHook(char*, int, int);
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
extern char* D_00585E60;
extern char D_004C0B38[];
int SFOMGCL_Connect_MAS(int a, char* b);
}

static inline bool Poll(void) {
    int now = 0;
    NetGetLocalTime(&now);
    if (now - D_00584528 > 30000) return false;
    SFOLobby_CallUpdateHook(D_00585E60, 0, 0);
    return true;
}

static inline int Busy(void) {
    int r = Medius_DisconnectServer();
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
        SFOLobby_CallUpdateHook(D_00585E60, 2, 1);
        while (D_00584232 == 0) {
            if (!Poll()) return -1000;
            if (SFOMGCL_Update(0)) return -12;
        }
        if (!D_00584233) return -12;
    }
    String_Copy(req.kind, D_004C0B38);
    req.id = *(int*)(D_00585E60 + 0x1F38);
    req.ver = KM_GetSoftwareID();
    req.mode = 2;
    r = MGCLSessionBegin(&req, (void*)Callback_MGCLServerSessionBegin);
    if (r) return r;
    D_00584528 = 0;
    NetGetLocalTime(&D_00584528);
    SFOLobby_CallUpdateHook(D_00585E60, 2, 1);
    while (D_00584235 == 0) {
        if (!Poll()) return -1000;
        if (SFOMGCL_Update(0)) return -12;
    }
    if (!D_00584236) return -12;
    String_Copy(join.kind, D_004C0B38);
    join.one = 1;
    r = MGCLAuthenticationSend(&join, (void*)Callback_MGCLServerAuthentication);
    if (r) return r;
    D_00584528 = 0;
    NetGetLocalTime(&D_00584528);
    SFOLobby_CallUpdateHook(D_00585E60, 2, 1);
    while (D_00584239 == 0) {
        if (!Poll()) return -1000;
        if (SFOMGCL_Update(0)) return -12;
    }
    if (!D_0058423A) return -12;
    return Busy();
}

