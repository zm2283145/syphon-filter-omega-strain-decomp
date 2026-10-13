#include "types.h"
typedef struct { char p0[0x1EC]; int done; char p1F0[0x5C]; int f24C; char p250[0x1144]; char f1394[0x18]; int f13AC; char p13B0[0xAF8]; int f1EA8; char p1EAC[0x55C]; signed char busy; char p2409[0xF]; char name[0x20]; } S449F40;
extern void String_Copy(char*, char*);
extern int Lobby_GetTime(void);
extern void SFOLobby_SetError(S449F40*, int, char*, int);
extern void SFOLobby_CallUpdateHook(S449F40*, int, int);
extern int SFOLobby_Poll(S449F40*, int, int, int);
extern int func_00466B70(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0D10[];
extern char D_004C0D38[];
extern char func_00447F00[];
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
char* func_00449F40(S449F40* s, char* arg1)
{
    struct { char f30[0x15]; char f45[0x13]; int f58; char f5C[0x20]; } req;
    int h;

    memset(&req, 0, sizeof(req));
    String_Copy(req.f30, D_004C0D38);
    String_Copy(req.f45, s->name);
    String_Copy(req.f5C, arg1);
    req.f58 = s->f1EA8;
    s->f24C = func_00466B70(&req, func_00447F00);
    h = Lobby_GetTime();
    s->done = 0;
    s->f13AC = -0x3C6;
    s->busy = 1;
    while (s->done == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (SFOLobby_Poll(s, h, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0D10, 0x3D4);
            break;
        }
    }
    s->busy = 0;
    return s->f1394;
}
#pragma pop
