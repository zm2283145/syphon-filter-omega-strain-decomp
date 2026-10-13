#include "types.h"
int String_Copy(char*, char*);
int Lobby_GetTime(void);
int func_0046A2D0(void*, void*);
void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0FA8[];
extern char D_004C0FB0[];
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
int SFOLobby_Poll(Lobby_451ED0*, int, int, int);

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
