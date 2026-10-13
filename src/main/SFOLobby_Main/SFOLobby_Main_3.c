/*
 * main/SFOLobby_Main: 2 files, 004526D0-00452A60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004526D0 */
#pragma push /* merge_units */
#include "types.h"
int String_Copy(char*, char*);
int Lobby_GetTime(void);
int* func_00443F40(int);
void func_00443EA0(int*);
int func_0046A2D0(void*, void*);
void func_00454010(char*);
int sprintf(char*, const char*, ...);
void* memset(void*, int, int);
extern int D_00585F90;
extern int D_00497890;
extern char D_004C0FA8[];
extern char D_004C0FB0[];
extern char D_004C0FD0[];
extern char func_00452A70;

typedef struct { char c[0x11]; } Ip_4526D0;
typedef void (*CbFn_4526D0)(int, int);
typedef struct {
    char pad0[0x244];
    unsigned char f244;
    char pad245[3];
    int* f248;
    int f24C;
    char pad250[0x1B38 - 0x250];
    int f1B38;
    char pad1B3C[0x1EB4 - 0x1B3C];
    int f1EB4;
    char f1EB8[0x40];
    char pad1EF8[0x2409 - 0x1EF8];
    char f2409;
    char pad240A[0x2410 - 0x240A];
    int f2410;
    char pad2414[4];
    Ip_4526D0 ip;
    char pad2429[0x2550 - 0x2429];
    CbFn_4526D0 cb;
    char pad2554[0x2564 - 0x2554];
    unsigned char err;
    char pad2565[3];
    char* errFile;
    int errLine;
} Lobby_4526D0;
int SFOLobby_Poll(Lobby_4526D0*, int, int, int);
int func_00452050(Lobby_4526D0*, int, char*);
int func_004524C0(Lobby_4526D0*, char*, char*);

static inline void SetErr_4526D0(Lobby_4526D0* self, unsigned char code, char* file, int line)
{
    if (self->err != 5) {
        self->err = code;
        self->errFile = file;
        self->errLine = line;
    }
}

static inline void Free_4526D0(Lobby_4526D0* self)
{
    func_00443EA0(self->f248);
    self->f248 = 0;
}

int func_004526D0(Lobby_4526D0* self, char* room)
{
    struct { char name[0x15]; Ip_4526D0 ip; char room[0x42]; int f68; } req;
    char info[0x60];
    char pass[0x100];
    char name[0x40];
    int j;
    int i;
    int id;

    memset(&req, 0, sizeof(req));
    String_Copy(req.name, D_004C0FA8);
    String_Copy(req.ip.c, self->ip.c);
    String_Copy(req.room, room);
    req.f68 = 1;
    self->f244 = 0;
    self->f2410 = Lobby_GetTime();
    self->f248 = func_00443F40(D_00585F90 * 4);
    for (i = 0; i < D_00585F90; i++)
        self->f248[i] = -1;
    self->f24C = func_0046A2D0(&req, &func_00452A70);
    while (self->f244 == 0) {
        self->f2409 = 1;
        if (self->cb)
            self->cb(0, 0);
        self->f2409 = 0;
        if (self->f24C) {
            SetErr_4526D0(self, 0x18, D_004C0FB0, 0x4C1);
            Free_4526D0(self);
            return 0;
        }
        if (!SFOLobby_Poll(self, self->f2410, D_00497890, 0)) {
            SetErr_4526D0(self, 2, D_004C0FB0, 0x4CC);
            Free_4526D0(self);
            return 0;
        }
    }
    func_00454010(info);
    String_Copy(pass, D_004C0FA8);
    for (j = 0; j < D_00585F90; j++) {
        id = self->f248[j];
        if (id != -1) {
            if (func_00452050(self, id, info)) {
                self->f1EB4 = id;
                sprintf(self->f1EB8, D_004C0FD0, room, j);
                Free_4526D0(self);
                return 1;
            }
        } else {
            sprintf(name, D_004C0FD0, room, j);
            if (!func_004524C0(self, name, pass)) {
                SetErr_4526D0(self, 0x17, D_004C0FB0, 0x4F6);
                Free_4526D0(self);
                return 0;
            }
            if (!func_00452050(self, self->f1B38, info)) {
                SetErr_4526D0(self, 0x16, D_004C0FB0, 0x4FF);
                Free_4526D0(self);
                return 0;
            }
            self->f1EB4 = self->f1B38;
            String_Copy(self->f1EB8, name);
            Free_4526D0(self);
            return 1;
        }
    }
    Free_4526D0(self);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_004526D0 */

/* merge_units: begin func_00452A60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */



/* True when D_00585F90 is nonzero. */
int func_00452A60(void) {
    return D_00585F90 != 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00452A60 */
