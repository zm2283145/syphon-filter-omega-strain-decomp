#pragma cplusplus on
#include "types.h"
struct M_454150 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(void* o);
};
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_454150;
typedef struct { char pad[0x48]; void* f48; } O_454150;
extern "C" {
extern void* D_004FFC2C;
extern char D_004FFB50[];
M_454150* Gui_GetScreenStack(void);
void func_00456160(O_454150* o);
void Hud_ClosePauseMenu(void* p);
void Game_SetPaused(void* p, int v);
int func_00454150(O_454150* o, Ev_454150* ev);
}
static inline unsigned char Down_454150(Ev_454150* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_454150(Ev_454150* e, int b) { unsigned char r = 0; if (Down_454150(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_454150(Ev_454150* e, int b) { unsigned char r = 0; if (Btn_454150(e, b) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_454150(Ev_454150* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_454150(Ev_454150* e, int b) { return Down2_454150(e) && e->btn == b; }
static inline bool Plain2_454150(Ev_454150* e, int b) { return Btn2_454150(e, b) && e->b6 == 0; }

int func_00454150(O_454150* o, Ev_454150* ev)
{
    if (Plain_454150(ev, 0x10)) {
        func_00456160(o);
        return 1;
    }
    if (Plain2_454150(ev, 0x800)) {
        Gui_GetScreenStack()->v24(o);
        Hud_ClosePauseMenu(D_004FFC2C);
        Game_SetPaused(D_004FFB50, 0);
        return 1;
    }
    return 0;
}
