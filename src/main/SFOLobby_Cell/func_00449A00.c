#pragma cplusplus on
#include "types.h"
typedef struct {
    char name[0x15];
    int a;
    int b;
    int c;
    char s1[0x20];
    int d;
    char s2[0x20];
    char s3[0x100];
    int e;
    char f;
} Info449A00;
typedef struct {
    char p0[0x1E0]; int done;
    char p1E4[0x68]; int f24C;
    char p250[0xAA8]; Info449A00 cur;
    Info449A00 last;
    char pFD8[0x1430]; signed char busy;
    char p2409[7]; int t0;
    char p2414[4]; char name[0x68];
    int f2480; int f2484;
    char p2488[0x100]; int f2588;
    char p258C[0xD0]; char b265C; char b265D;
} S449A00;
extern "C" {
extern void String_Copy(char*, char*);
extern int Lobby_GetTime(void);
extern void SFOLobby_SetError(S449A00*, int, char*, int);
extern void SFOLobby_CallUpdateHook(S449A00*, int, int);
extern int SFOLobby_Poll(S449A00*, int, int, int);
extern int func_004676F8(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0D10[];
extern char D_004C0D38[];
extern char func_00448B70[];
}

extern "C" int func_00449A00(S449A00* s)
{
    struct { char a[0x15]; char b[0x13]; int x; int y; } req;
    int now = Lobby_GetTime();
    if (s->f2588 && now - s->f2588 < 50) return 1;
    s->f2588 = Lobby_GetTime();
    memset(&req, 0, sizeof(req));
    memset(&s->cur, 0, sizeof(s->cur));
    s->cur.b = -1;
    s->cur.d = -1;
    String_Copy(req.a, D_004C0D38);
    String_Copy(req.b, s->name);
    req.x = 1;
    req.y = 999;
    s->done = 0;
    s->t0 = Lobby_GetTime();
    s->f24C = func_004676F8(&req, func_00448B70);
    s->busy = 1;
    while (s->done == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (s->f24C != 0) {
            SFOLobby_SetError(s, 1, D_004C0D10, 0x4AE);
            s->f2484 = -1;
            s->busy = 0;
            s->b265D = 0;
            s->b265C = 0;
            return 0;
        }
        if (SFOLobby_Poll(s, s->t0, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0D10, 0x4B9);
            s->f2484 = -1;
            s->busy = 0;
            s->b265D = 0;
            s->b265C = 0;
            return 0;
        }
    }
    s->busy = 0;
    s->last = s->cur;
    if (s->last.e == 1 || s->last.e == -1) {
        s->f2484 = -1;
        s->b265D = 0;
        s->b265C = 0;
    } else if (s->last.e == 0) {
        s->f2484 = s->last.b;
        if (s->last.d == s->f2480) {
            s->b265C = 1;
            s->b265D = 1;
        } else if (s->last.d >= 0) {
            s->b265C = 0;
            s->b265D = 1;
        } else {
            s->b265C = 0;
            s->b265D = 0;
            return 0;
        }
    } else {
        s->f2484 = -1;
        s->b265C = 0;
        s->b265D = 0;
        return 0;
    }
    return 1;
}