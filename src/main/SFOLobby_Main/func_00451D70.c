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
