#include "types.h"
typedef struct { char p0[0x1CC]; int done; char p1D0[0x7C]; int f24C; char p250[0x21B8]; signed char busy; char p2409[7]; int f2410; char p2414[4]; char name[0x14C]; unsigned char b2564; } S44AF60;
extern void String_Copy(char*, char*);
extern unsigned int strlen(const char*);
extern char* strncpy(char*, const char*, int);
extern int Lobby_GetTime(void);
extern int func_00443100(S44AF60*, char*, int);
extern void func_00451AE0(void);
extern void SFOLobby_SetError(S44AF60*, int, char*, int);
extern void SFOLobby_CallUpdateHook(S44AF60*, int, int);
extern int SFOLobby_Poll(S44AF60*, int, int, int);
extern int func_00466A28(void*, void*);
extern int func_00476998(void);
extern char* func_00449F40(S44AF60*, char*);
extern void func_0044A420(S44AF60*, char*);
extern void func_00449A00(S44AF60*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0D10[];
extern char D_004C0D30[];
extern char D_004C0D38[];
extern char func_00448EB0[];
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
int func_0044AF60(S44AF60* s, char* arg1)
{
    struct { char f30[0x15]; char f45[0x13]; int f58; char f5C[0x20]; } req;

    func_00451AE0();
    if (strlen(arg1) > 0x20) {
        SFOLobby_SetError(s, 0x1B, D_004C0D10, 0xEB);
        return 0;
    }
    if (*(int*)(func_00449F40(s, arg1) + 0x18) == 0) {
        SFOLobby_SetError(s, 0x1A, D_004C0D10, 0xF1);
        return 0;
    }
    if (func_00443100(s, arg1, 0) == 0) {
        SFOLobby_SetError(s, 3, D_004C0D10, 0xF7);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    String_Copy(req.f30, D_004C0D38);
    String_Copy(req.f45, s->name);
    strncpy(req.f5C, arg1, 0x20);
    req.f58 = func_00476998();
    s->done = 0;
    s->f2410 = Lobby_GetTime();
    s->f24C = func_00466A28(&req, func_00448EB0);
    SFOLobby_SetError(s, 0, D_004C0D10, 0x113);
    s->busy = 1;
    while (s->done == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (s->f24C != 0) {
            s->busy = 0;
            return 0;
        }
        if (SFOLobby_Poll(s, s->f2410, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0D10, 0x123);
            s->busy = 0;
            return 0;
        }
    }
    s->busy = 0;
    if (s->b2564)
        return 0;
    func_0044A420(s, D_004C0D30);
    func_00449A00(s);
    return 1;
}
#pragma pop

