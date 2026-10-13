#include "types.h"
int String_Copy(char*, char*);
int Lobby_GetTime(void);
int func_00469D20(void*, void*);
int func_004689F8(void*, void*);
void* memset(void*, int, int);
void* memcpy(void*, const void*, int);
extern int D_00497728;
extern int D_00497740;
extern int D_00497890;
extern int D_00497910;
extern char D_004C0FA8[];
extern char D_004C0FB0[];
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
int SFOLobby_Poll(Lobby_452050*, int, int, int);
int func_0044CA30(Lobby_452050*);
int func_0044C940(Lobby_452050*, int);
int func_00451D70(Lobby_452050*, int);

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
    if (!func_0044CA30(self))
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
    if (!func_0044C940(self, 1))
        return 0;
    if (!func_00451D70(self, self->f1EAC))
        return 0;
    if (self->err != 5)
        self->err = 0;
    return 1;
}
