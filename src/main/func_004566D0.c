#pragma cplusplus on
#include "types.h"
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_4566D0;
typedef struct { char pad[0x1C]; void* f1C; } Sel_4566D0;
typedef struct { char pad[0x20]; Sel_4566D0* sel; } Mgr_4566D0;
typedef struct { char pad[0xAC]; void* fAC; } O_4566D0;
extern "C" {
extern void* D_004FFC2C;
extern unsigned char D_004FFBB7;
extern char D_004FFB50[];
Mgr_4566D0* Gui_GetScreenStack(void);
void Hud_ClosePauseMenu(void* p);
void Game_SetPaused(void* p, int v);
int func_00368300(O_4566D0* o, Ev_4566D0* ev);
int func_004566D0(O_4566D0* o, Ev_4566D0* ev);
}
static inline bool Down2_4566D0(Ev_4566D0* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_4566D0(Ev_4566D0* e, int b) { return Down2_4566D0(e) && e->btn == b; }
static inline bool Plain2_4566D0(Ev_4566D0* e, int b) { return Btn2_4566D0(e, b) && e->b6 == 0; }

int func_004566D0(O_4566D0* o, Ev_4566D0* ev)
{
    if (Plain2_4566D0(ev, 0x10) && Gui_GetScreenStack()->sel->f1C == o->fAC) {
        Hud_ClosePauseMenu(D_004FFC2C);
        if (D_004FFBB7)
            Game_SetPaused(D_004FFB50, 0);
        return 1;
    }
    if (Plain2_4566D0(ev, 0x800)) {
        Hud_ClosePauseMenu(D_004FFC2C);
        if (D_004FFBB7)
            Game_SetPaused(D_004FFB50, 0);
        return 1;
    }
    return func_00368300(o, ev);
}

