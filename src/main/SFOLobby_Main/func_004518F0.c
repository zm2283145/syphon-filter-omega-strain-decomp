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
