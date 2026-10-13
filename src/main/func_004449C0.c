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
void func_002D0D70(Conn9C0*);
int func_00121BC8(char*);
void func_002D0DB0(Conn9C0*, int, int, int, void*);
void func_00352C30(char*);
int func_002CF420(Conn9C0*, int*);
int func_002CF1C8(Req9C0A*, void*);
int func_002CF078(Req9C0B*, void*);
int func_00476998(void);
int func_002CF5E0(void);
void func_002EBC48(int*);
int func_004446E0(int);
void SFOLobby_CallUpdateHook(char*, int, int);
void func_00444DD0(void);
void func_00445260(void);
void func_00444E10(void);
extern unsigned char D_00584232;
extern unsigned char D_00584233;
extern unsigned char D_00584235;
extern unsigned char D_00584236;
extern unsigned char D_00584239;
extern unsigned char D_0058423A;
extern int D_00584528;
extern char* D_00585E60;
extern char D_004C0B38[];
int func_004449C0(int a, char* b);
}

static inline bool Poll(void) {
    int now = 0;
    func_002EBC48(&now);
    if (now - D_00584528 > 30000) return false;
    SFOLobby_CallUpdateHook(D_00585E60, 0, 0);
    return true;
}

static inline int Busy(void) {
    int r = func_002CF5E0();
    if (r) return r;
    return 0;
}

int func_004449C0(int a, char* b) {
    Conn9C0 conn;
    int x;
    Req9C0A req;
    Req9C0B join;
    int r;
    memset(&conn, 0, sizeof(conn));
    memset(&x, 0, sizeof(x));
    memset(&req, 0, sizeof(req));
    memset(&join, 0, sizeof(join));
    func_002D0D70(&conn);
    func_002D0DB0(&conn, a, func_00121BC8(b), 1, (void*)func_00444DD0);
    if (((unsigned char*)D_00585E60)[0x23D6] == 0)
        func_00352C30(conn.sub);
    else
        memset(conn.sub, 0, sizeof(conn.sub));
    r = func_002CF420(&conn, &x);
    if (r) return r;
    if (conn.wait) {
        D_00584528 = 0;
        func_002EBC48(&D_00584528);
        SFOLobby_CallUpdateHook(D_00585E60, 2, 1);
        while (D_00584232 == 0) {
            if (!Poll()) return -1000;
            if (func_004446E0(0)) return -12;
        }
        if (!D_00584233) return -12;
    }
    String_Copy(req.kind, D_004C0B38);
    req.id = *(int*)(D_00585E60 + 0x1F38);
    req.ver = func_00476998();
    req.mode = 2;
    r = func_002CF1C8(&req, (void*)func_00445260);
    if (r) return r;
    D_00584528 = 0;
    func_002EBC48(&D_00584528);
    SFOLobby_CallUpdateHook(D_00585E60, 2, 1);
    while (D_00584235 == 0) {
        if (!Poll()) return -1000;
        if (func_004446E0(0)) return -12;
    }
    if (!D_00584236) return -12;
    String_Copy(join.kind, D_004C0B38);
    join.one = 1;
    r = func_002CF078(&join, (void*)func_00444E10);
    if (r) return r;
    D_00584528 = 0;
    func_002EBC48(&D_00584528);
    SFOLobby_CallUpdateHook(D_00585E60, 2, 1);
    while (D_00584239 == 0) {
        if (!Poll()) return -1000;
        if (func_004446E0(0)) return -12;
    }
    if (!D_0058423A) return -12;
    return Busy();
}

