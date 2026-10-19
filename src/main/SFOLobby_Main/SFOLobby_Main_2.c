/*
 * main/SFOLobby_Main: 4 files, 00451D70-004524C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00451D70 */
#pragma push /* merge_units */
#include "types.h"
int String_Copy(char*, char*);
int Lobby_GetTime(void);
int func_0046A188(void*, void*);
void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0FA8[];
extern char D_004C0FB0[];
extern char func_00446F30;

typedef struct { char c[0x11]; } Ip_451D70;
typedef void (*CbFn_451D70)(int, int);
typedef struct {
    char pad0[0x200];
    int f200;
    char pad204[0x24C - 0x204];
    int f24C;
    char pad250[0x2409 - 0x250];
    char f2409;
    char pad240A[0x2410 - 0x240A];
    int f2410;
    char pad2414[4];
    Ip_451D70 ip;
    char pad2429[0x2550 - 0x2429];
    CbFn_451D70 cb;
    char pad2554[0x2564 - 0x2554];
    unsigned char err;
    char pad2565[3];
    char* errFile;
    int errLine;
} Lobby_451D70;
int SFOLobby_Poll(Lobby_451D70*, int, int, int);

static inline void SetErr_451D70(Lobby_451D70* self, unsigned char code, char* file, int line)
{
    if (self->err != 5) {
        self->err = code;
        self->errFile = file;
        self->errLine = line;
    }
}

int func_00451D70(Lobby_451D70* self, int id)
{
    struct { char name[0x15]; char ip[0x13]; int f28; } req;

    memset(&req, 0, sizeof(req));
    String_Copy(req.name, D_004C0FA8);
    String_Copy(req.ip, self->ip.c);
    req.f28 = id;
    self->f200 = 0;
    self->f2410 = Lobby_GetTime();
    self->f24C = func_0046A188(&req, &func_00446F30);
    while (self->f200 == 0) {
        self->f2409 = 1;
        if (self->cb)
            self->cb(0, 0);
        self->f2409 = 0;
        if (self->f24C) {
            SetErr_451D70(self, 0x18, D_004C0FB0, 0x629);
            return 0;
        }
        if (!SFOLobby_Poll(self, self->f2410, D_00497890, 0)) {
            SetErr_451D70(self, 2, D_004C0FB0, 0x62F);
            return 0;
        }
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00451D70 */

/* merge_units: begin func_00451ED0 */
#pragma push /* merge_units */
int func_0046A2D0(void*, void*);
extern char func_00447020;

typedef struct { char c[0x11]; } Ip_451ED0;
typedef void (*CbFn_451ED0)(int, int);
typedef struct {
    char pad0[0x1FC];
    int f1FC;
    char pad200[0x24C - 0x200];
    int f24C;
    char pad250[0x1B3C - 0x250];
    char f1B3C[0x18];
    int f1B54;
    char pad1B58[0x1BC8 - 0x1B58];
    signed char f1BC8;
    char pad1BC9[0x2409 - 0x1BC9];
    char f2409;
    char pad240A[0x2410 - 0x240A];
    int f2410;
    char pad2414[4];
    Ip_451ED0 ip;
    char pad2429[0x2550 - 0x2429];
    CbFn_451ED0 cb;
    char pad2554[0x2564 - 0x2554];
    unsigned char err;
    char pad2565[3];
    char* errFile;
    int errLine;
} Lobby_451ED0;
#if 0 /* merge_units */
int SFOLobby_Poll(Lobby_451ED0*, int, int, int);
#endif /* merge_units */
#define SFOLobby_Poll(a0, a1, a2, a3) (SFOLobby_Poll((Lobby_451D70 *)(a0), (a1), (a2), (a3))) /* merge_units */


static inline void SetErr_451ED0(Lobby_451ED0* self, unsigned char code, char* file, int line)
{
    if (self->err != 5) {
        self->err = code;
        self->errFile = file;
        self->errLine = line;
    }
}

int func_00451ED0(Lobby_451ED0* self, char* room)
{
    struct { char name[0x15]; Ip_451ED0 ip; char room[0x42]; int f68; } req;

    memset(&req, 0, sizeof(req));
    memset(self->f1B3C, 0, 0x90);
    String_Copy(req.name, D_004C0FA8);
    String_Copy(req.ip.c, self->ip.c);
    String_Copy(req.room, room);
    req.f68 = 1;
    self->f1FC = 0;
    self->f2410 = Lobby_GetTime();
    self->f24C = func_0046A2D0(&req, &func_00447020);
    while (self->f1BC8 != 1) {
        self->f2409 = 1;
        if (self->cb)
            self->cb(0, 0);
        self->f2409 = 0;
        if (self->f24C) {
            SetErr_451ED0(self, 0x18, D_004C0FB0, 0x5FD);
            return 0;
        }
        if (!SFOLobby_Poll(self, self->f2410, D_00497890, 0)) {
            SetErr_451ED0(self, 2, D_004C0FB0, 0x603);
            return 0;
        }
    }
    return self->f1B54 != 1;
}
#undef SFOLobby_Poll /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00451ED0 */

/* merge_units: begin func_00452050 */
#pragma push /* merge_units */
int func_00469D20(void*, void*);
int func_004689F8(void*, void*);
void* memcpy(void*, const void*, int);
extern int D_00497728;
extern int D_00497740;
extern int D_00497910;
extern char D_004C0FC8[];
extern char func_00446FD0;
extern char func_00447220[];
extern char func_00447D80[];
extern char func_00447D70[];

typedef struct { char c[0x11]; } Ip_452050;
typedef void (*CbFn_452050)(int, int);
typedef struct {
    char pad0[0x180];
    int f180;
    int f184;
    char pad188[0x1C0 - 0x188];
    int f1C0;
    char pad1C4[0x24C - 0x1C4];
    int f24C;
    char pad250[0x9C8 - 0x250];
    int f9C8;
    char f9CC[0x9C];
    char padA68[0x1EAC - 0xA68];
    int f1EAC;
    char pad1EB0[0x2409 - 0x1EB0];
    char f2409;
    char pad240A[0x2410 - 0x240A];
    int f2410;
    char pad2414[4];
    Ip_452050 ip;
    char pad2429[0x2550 - 0x2429];
    CbFn_452050 cb;
    char pad2554[0x2564 - 0x2554];
    unsigned char err;
    char pad2565[3];
    char* errFile;
    int errLine;
} Lobby_452050;
#if 0 /* merge_units */
int SFOLobby_Poll(Lobby_452050*, int, int, int);
#endif /* merge_units */
#define SFOLobby_Poll(a0, a1, a2, a3) (SFOLobby_Poll((Lobby_451D70 *)(a0), (a1), (a2), (a3))) /* merge_units */

int SFOLobby_DisconnectAuthServer(Lobby_452050*);
int SFOLobby_UpdateClientState(Lobby_452050*, int);
#if 0 /* merge_units */
int func_00451D70(Lobby_452050*, int);
#endif /* merge_units */
#define func_00451D70(a0, a1) (func_00451D70((Lobby_451D70 *)(a0), (a1))) /* merge_units */


static inline void SetErr_452050(Lobby_452050* self, unsigned char code, char* file, int line)
{
    if (self->err != 5) {
        self->err = code;
        self->errFile = file;
        self->errLine = line;
    }
}

static inline void Pump_452050(Lobby_452050* self)
{
    self->f2409 = 1;
    if (self->cb)
        self->cb(0, 0);
    self->f2409 = 0;
}

int func_00452050(Lobby_452050* self, int id, int unused)
{
    char tail[8];
    struct { char p0[0xA0]; int fA0; char pA4[0xF0 - 0xA4]; int fF0; char* fF4; char* fF8; char* fFC; } buf;
    struct { char name[0x15]; Ip_452050 ip; char p26[2]; int f28; char name2[0x20]; } req;
    int i;
    int j;

    i = 0;
    memset(&buf, 0, sizeof(buf));
    memset(tail, 0, 8);
    memset(&req, 0, sizeof(req));
    String_Copy(req.name, D_004C0FC8);
    req.ip = self->ip;
    req.f28 = id;
    String_Copy(req.name2, D_004C0FA8);
    self->f1C0 = 0;
    self->f2410 = Lobby_GetTime();
    for (j = 0; j < D_00497910 && self->f1C0 == 0; ) {
        j++;
        self->f24C = func_00469D20(&req, &func_00446FD0);
        while (self->f1C0 == 0) {
            Pump_452050(self);
            if (self->f24C) {
                SetErr_452050(self, 0x16, D_004C0FB0, 0x57E);
                return 0;
            }
            if (!SFOLobby_Poll(self, self->f2410, D_00497890, 0))
                break;
        }
    }
    if (self->f1C0 == 0) {
        SetErr_452050(self, 2, D_004C0FB0, 0x58D);
        return 0;
    }
    if (self->f9C8) {
        SetErr_452050(self, 0x16, D_004C0FB0, 0x594);
        return 0;
    }
    if (!SFOLobby_DisconnectAuthServer(self))
        return 0;
    memcpy(&buf, self->f9CC, 0x9C);
    buf.fA0 = 0;
    buf.fF4 = func_00447220;
    buf.fF8 = func_00447D80;
    buf.fFC = func_00447D70;
    buf.fF0 = D_00497728;
    for (; i < D_00497740 && self->f180 == -1; ) {
        Pump_452050(self);
        i++;
        self->f24C = func_004689F8(&buf, tail);
        if (self->f24C) {
            SetErr_452050(self, 0xC, D_004C0FB0, 0x5B6);
            continue;
        }
        self->f184 = 0;
        self->f2410 = Lobby_GetTime();
        while (self->f184 == 0) {
            Pump_452050(self);
            if (!SFOLobby_Poll(self, self->f2410, D_00497890, 0)) {
                SetErr_452050(self, 2, D_004C0FB0, 0x5C2);
                return 0;
            }
        }
    }
    if (self->f180 == -1) {
        SetErr_452050(self, 0xC, D_004C0FB0, 0x5CC);
        return 0;
    }
    self->f1EAC = id;
    if (!SFOLobby_UpdateClientState(self, 1))
        return 0;
    if (!func_00451D70(self, self->f1EAC))
        return 0;
    if (self->err != 5)
        self->err = 0;
    return 1;
}
#undef SFOLobby_Poll /* merge_units */
#undef func_00451D70 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00452050 */

/* merge_units: begin func_004524C0 */
#pragma push /* merge_units */
int func_00476998(void);
int func_00469B58(void*, void*);
extern int D_00497758;
extern char func_00446F80;

typedef struct { char c[0x11]; } Ip_4524C0;
typedef void (*CbFn_4524C0)(int, int);
typedef struct {
    char pad0[0x1F8];
    int f1F8;
    char pad1FC[0x24C - 0x1FC];
    int f24C;
    char pad250[0x1B34 - 0x250];
    int f1B34;
    char pad1B38[0x2409 - 0x1B38];
    char f2409;
    char pad240A[0x2410 - 0x240A];
    int f2410;
    char pad2414[4];
    Ip_4524C0 ip;
    char pad2429[0x2550 - 0x2429];
    CbFn_4524C0 cb;
    char pad2554[0x2564 - 0x2554];
    unsigned char err;
    char pad2565[3];
    char* errFile;
    int errLine;
} Lobby_4524C0;
#if 0 /* merge_units */
int SFOLobby_Poll(Lobby_4524C0*, int, int, int);
#endif /* merge_units */
#define SFOLobby_Poll(a0, a1, a2, a3) (SFOLobby_Poll((Lobby_451D70 *)(a0), (a1), (a2), (a3))) /* merge_units */


static inline void SetErr_4524C0(Lobby_4524C0* self, unsigned char code, char* file, int line)
{
    if (self->err != 5) {
        self->err = code;
        self->errFile = file;
        self->errLine = line;
    }
}

int func_004524C0(Lobby_4524C0* self, char* user, char* pass)
{
    char tail[8];
    char buf[0x100];
    struct { char name[0x15]; Ip_4524C0 ip; int f68; int f6C; char user[0x40]; char pass[0x24]; } sl;

    memset(buf, 0, 0x100);
    memset(tail, 0, 8);
    memset(&sl, 0, 0x94);
    String_Copy(sl.name, D_004C0FC8);
    sl.ip = self->ip;
    sl.f68 = func_00476998();
    sl.f6C = D_00497758;
    String_Copy(sl.user, user);
    String_Copy(sl.pass, pass);
    self->f1F8 = 0;
    self->f2410 = Lobby_GetTime();
    self->f24C = func_00469B58(&sl, &func_00446F80);
    while (self->f1F8 == 0) {
        self->f2409 = 1;
        if (self->cb)
            self->cb(0, 0);
        self->f2409 = 0;
        if (self->f24C) {
            SetErr_4524C0(self, 0x17, D_004C0FB0, 0x53F);
            return 0;
        }
        if (!SFOLobby_Poll(self, self->f2410, D_00497890, 0)) {
            SetErr_4524C0(self, 2, D_004C0FB0, 0x545);
            return 0;
        }
    }
    if (self->f1B34) {
        SetErr_4524C0(self, 0x17, D_004C0FB0, 0x54D);
        return 0;
    }
    return 1;
}
#undef SFOLobby_Poll /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004524C0 */
