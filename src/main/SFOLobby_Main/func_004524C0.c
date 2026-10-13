#include "types.h"
int String_Copy(char*, char*);
int func_00443E70(void);
int func_00476998(void);
int func_00469B58(void*, void*);
void* memset(void*, int, int);
extern int D_00497758;
extern int D_00497890;
extern char D_004C0FB0[];
extern char D_004C0FC8[];
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
int func_004534A0(Lobby_4524C0*, int, int, int);

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
    self->f2410 = func_00443E70();
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
        if (!func_004534A0(self, self->f2410, D_00497890, 0)) {
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

