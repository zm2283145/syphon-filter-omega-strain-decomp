#include "types.h"
typedef struct { char p[0x6C]; void* f6C; char p70[4]; int count; char p78[0x18]; int sel; char p94[8]; unsigned char b9C; } W45C540;
extern void func_0045C5E0(W45C540* w);
extern void* Gui_GetScreenStack(void);
extern void func_0041E0F0(void* w, void* src, int kind, int a, int b);
void func_0045C540(W45C540* w, int dir)
{
    int i;
    if (w->count <= 1) return;
    w->b9C = 1;
    i = w->sel + (dir ? 1 : -1);
    if (i < 0) i = w->count - 1; else if (!(i < w->count)) i = 0;
    w->sel = i;
    func_0045C5E0(w);
    func_0041E0F0(w->f6C, Gui_GetScreenStack(), 0x10, 0, 0);
}
