#include "types.h"
typedef struct { char p0[0x198]; int done; char p19C[0xB0]; int f24C; char p250[0xDC]; int f32C; char p330[0x20E0]; int f2410; char p2414[4]; char name[0x14C]; } S445B90;
extern void String_Copy(char*, char*);
extern char* strncpy(char*, const char*, int);
extern int Lobby_GetTime(void);
extern int func_00443100(S445B90*, char*, int);
extern void SFOLobby_SetError(S445B90*, int, char*, int);
extern void SFOLobby_CallUpdateHook(S445B90*, int, int);
extern int SFOLobby_Poll(S445B90*, int, int, int);
extern int func_00469458(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0B50[];
extern char D_004C0B60[];
extern char func_00447270[];
int func_00445B90(S445B90* s, char* arg1, char* arg2)
{
    struct { char f40[0x15]; char f55[0x13]; int f68; char f6C[0x20]; char f8C[0x20]; } req;

    SFOLobby_CallUpdateHook(s, 2, 1);
    if (func_00443100(s, arg1, 0) == 0) {
        SFOLobby_SetError(s, 3, D_004C0B60, 0xD5);
        return 0;
    }
    if (func_00443100(s, arg2, 0) == 0) {
        SFOLobby_SetError(s, 3, D_004C0B60, 0xDA);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    String_Copy(req.f40, D_004C0B50);
    String_Copy(req.f55, s->name);
    req.f68 = 1;
    strncpy(req.f6C, arg1, 0x20);
    strncpy(req.f8C, arg2, 0x20);
    s->done = 0;
    s->f2410 = Lobby_GetTime();
    s->f24C = func_00469458(&req, func_00447270);
    while (s->done == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (s->f24C != 0) {
            SFOLobby_SetError(s, 0xB, D_004C0B60, 0xF5);
            return 0;
        }
        if (SFOLobby_Poll(s, s->f2410, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0B60, 0xFC);
            return 0;
        }
    }
    if (s->f32C != 0) {
        if (s->f32C == -0x3E7) {
            SFOLobby_SetError(s, 0x3D, D_004C0B60, 0x105);
        } else {
            SFOLobby_SetError(s, 0xB, D_004C0B60, 0x109);
        }
        return 0;
    }
    SFOLobby_SetError(s, 0, D_004C0B60, 0x10E);
    return 1;
}


