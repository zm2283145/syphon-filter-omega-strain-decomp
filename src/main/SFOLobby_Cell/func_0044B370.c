#include "types.h"
typedef struct {
    char p0[0x70]; char f70[0xE84 - 0x70]; int fE84; char pE88[0x1B38 - 0xE88];
    int f1B38; char p1B3C[0x1B80 - 0x1B3C]; int f1B80; char p1B84[0x1EA4 - 0x1B84];
    int f1EA4; char p1EA8[0x23E4 - 0x1EA8]; void* f23E4; int p23E8; void* f23EC;
    char p23F0[0x255C - 0x23F0]; int state; char p2560[0x2588 - 0x2560];
    int f2588; int f258C; char p2590[0x265C - 0x2590]; unsigned char f265C; unsigned char f265D;
    char p265E[0x26A8 - 0x265E]; int f26A8;
} SLB;
extern void String_Copy(char*, char*);
extern int sprintf(char*, const char*, ...);
extern int Lobby_GetTime(void);
extern void func_00451AE0(void);
extern void SFOLobby_SetError(SLB*, int, char*, int);
extern int func_00449A00(SLB*);
extern void func_00449D20(SLB*, int);
extern void func_0044A290(SLB*);
extern void func_00452FC0(SLB*, int);
extern void func_00453FB0(SLB*);
extern void func_0044F810(void*);
extern void LobbyArray_Free(void*);
extern void LobbyArray_Init(void*, int, int, int);
extern int func_00451ED0(SLB*, char*);
extern int func_004524C0(SLB*, char*, char*);
extern int func_00452050(SLB*, int, char*);
extern void func_00454010(char*);
extern void func_00454050(SLB*);
extern int D_00497800;
extern char D_004C0D10[];
extern char D_004C0D30[];
extern char D_004C0D40[];
static inline void ClearLists(SLB* s)
{
    if (s->f23E4) LobbyArray_Free(s->f23E4);
    s->f23E4 = 0;
    if (s->f23EC) LobbyArray_Free(s->f23EC);
    s->f23EC = 0;
}void func_0044B370(SLB* s)
{
    int st;
    func_00451AE0();
    st = s->state;
    if (st == 9) return;
    if (st == 7 || st == 10) {
        if (st != 10) s->state = 9;
        s->f2588 = 0;
        func_00453FB0(s);
        func_00452FC0(s, 0);
        func_0044F810(s->f70);
        ClearLists(s);
    }
}
