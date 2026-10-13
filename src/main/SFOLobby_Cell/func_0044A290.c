#include "types.h"
typedef struct { char p0[0x24C]; int f24C; char p250[0xE84 - 0x250]; int fE84; char pE88[0x15F0 - 0xE88]; char f15F0[0x20]; char f1610[0xC8]; signed char f16D8; char p16D9[0x2408 - 0x16D9]; signed char busy; char p2409[7]; int f2410; char p2414[4]; char name[0x17C]; char out[0xC8]; } S44A290;
extern void String_Copy(char*, char*);
extern char* strncpy(char*, const char*, int);
extern int Lobby_GetTime(void);
extern void SFOLobby_SetError(S44A290*, int, char*, int);
extern void SFOLobby_CallUpdateHook(S44A290*, int, int);
extern int SFOLobby_Poll(S44A290*, int, int, int);
extern int func_004671D8(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0D10[];
extern char D_004C0D38[];
extern char func_004485C0[];
char* func_0044A290(S44A290* s)
{
    struct { char f0[0x15]; char f15[0x13]; int f28; int f2C; int f30; } req;

    memset(&req, 0, sizeof(req));
    String_Copy(req.f0, D_004C0D38);
    String_Copy(req.f15, s->name);
    req.f28 = s->fE84;
    req.f2C = 1;
    req.f30 = 1;
    s->f2410 = Lobby_GetTime();
    memset(s->f15F0, 0, 0xEC);
    s->f24C = func_004671D8(&req, func_004485C0);
    if (s->f24C != 0) {
        SFOLobby_SetError(s, 1, D_004C0D10, 0x2FA);
        return 0;
    }
    s->busy = 1;
    while (s->f16D8 != 1) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (s->f24C != 0) {
            SFOLobby_SetError(s, 1, D_004C0D10, 0x305);
            s->busy = 0;
            return 0;
        }
        if (SFOLobby_Poll(s, s->f2410, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0D10, 0x30D);
            s->busy = 0;
            return 0;
        }
    }
    s->busy = 0;
    memset(s->out, 0, 0xC8);
    strncpy(s->out, s->f1610, 0xC7);
    return s->out;
}
