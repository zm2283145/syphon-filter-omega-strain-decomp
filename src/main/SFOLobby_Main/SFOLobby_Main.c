/*
 * main/SFOLobby_Main: 4 files, 004518F0-00451B30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004518F0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct {
    char p0[0x170]; int f170; char p174[0x1E98-0x174]; int t98; int t9C; int fA0; int fA4;
    char p1EA8[0x1EAC-0x1EA8]; int fAC; char p1EB0[4]; int fB4;
    char p1EB8[0x23EC-0x1EB8]; int h0; int h2; int h1; char p23F8[0x255C-0x23F8]; int state;
} Cell;
extern void func_00452FC0(Cell*, int);
extern void LobbyArray_Init(void*, int, int, int);
extern int func_00451BE0(Cell*, int);
extern void LobbyArray_Free(int);
extern void func_0044D780(Cell*);
extern int Lobby_GetTime(void);
extern int D_00497788;
static inline void SetA0(Cell* o, int v) { if (v != o->fA0) o->fA0 = v; }
static inline void RelH(int* h) { int t = *h; if (t != 0) LobbyArray_Free(t); *h = 0; }

int func_004518F0(Cell* self, int a1, int a2, int a3, int t0)
{
    char* b = (char*)self;
    if (self->state != 9) return 0;
    self->state = 5;
    func_00452FC0(self, a1);
    self->h0 = a2;
    self->h1 = a3;
    self->h2 = t0;
    LobbyArray_Init((void*)self->h0, self->fA4, 0, 0x68);
    LobbyArray_Init((void*)self->h1, 0x104, 0x104, 0x50);
    LobbyArray_Init((void*)self->h2, 0x104, 0x104, 0x50);
    LobbyArray_Init(b + 0x8C, 0x104, 0x104, 0x50);
    LobbyArray_Init(b + 0xA8, 0x104, 0x104, 0x50);
    LobbyArray_Init(b, 0x20, 0x20, 0x14);
    self->f170 = 1;
    self->t98 = 0;
    self->t9C = 0;
    self->fA0 = 1;
    SetA0(self, 0);
    if (self->fB4 != self->fAC && !func_00451BE0(self, self->fB4)) {
        RelH(&self->h0);
        RelH(&self->h1);
        RelH(&self->h2);
        return 0;
    }
    func_0044D780(self);
    if (Lobby_GetTime() - self->t98 > D_00497788 - 1000) {
        self->t98 = Lobby_GetTime() - D_00497788 + 1000;
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_004518F0 */

/* merge_units: begin func_00451AE0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma opt_common_subs off
void func_00451AE0(int arg0) {
    if (F_(arg0, 0x2564, unsigned char) != 5) {
        F_(arg0, 0x2564, unsigned char) = 0U;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00451AE0 */

/* merge_units: begin SFOLobby_SetError */
#pragma push /* merge_units */
#pragma opt_common_subs off
void SFOLobby_SetError(int arg0, unsigned char arg1, int arg2, int arg3) {
    if (F_(arg0, 0x2564, unsigned char) != 5) {
        F_(arg0, 0x2564, unsigned char) = arg1;
        F_(arg0, 0x2568, int) = arg2;
        F_(arg0, 0x256C, int) = arg3;
    }
}
#pragma pop /* merge_units */
/* merge_units: end SFOLobby_SetError */

/* merge_units: begin func_00451B30 */
#pragma push /* merge_units */
typedef struct { char p0[0xE8]; int fE8; char pEC[0xF4 - 0xEC]; int fF4; char pF8[0x100 - 0xF8]; } R451B30;
typedef struct {
    char p0[0xAA4]; char fAA4[0x2C]; R451B30 room;
    char pBD0[0x2480 - 0xBD0]; int f2480; int f2484;
    char p2488[0x2590 - 0x2488]; int f2590;
} S451B30;
extern int D_00497830;
extern R451B30 D_00585E90;
extern unsigned char SFOLobby_RequestAccountInfo(S451B30*, int);
extern void func_004499A0(S451B30*);
extern void func_004505E0(S451B30*, R451B30*);
extern void SFOLobby_CacheAccount(S451B30*, int, char*, int, R451B30*);

void func_00451B30(S451B30* s)
{
    int dt;
    unsigned char ok;
    R451B30* room;

    dt = Lobby_GetTime() - s->f2590;
    if (D_00497830 < dt) {
        ok = SFOLobby_RequestAccountInfo(s, s->f2480);
        func_004499A0(s);
        room = ok ? &s->room : &D_00585E90;
        room->fE8 = s->f2484;
        func_004505E0(s, room);
        SFOLobby_CacheAccount(s, s->f2480, s->fAA4, room->fF4, room);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00451B30 */
