#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; } E294F50;
typedef struct { char pad[0x118]; E294F50* items[45]; int cur; } S294F50;
extern int func_002952C0(S294F50* s);
extern void func_00295090(S294F50* s, int i, int f);
extern void* Gui_GetScreenStack(void);
extern void func_0041E0F0(void* a, void* b, int c, int d, int e);
void func_00294F50(S294F50* s, int dir)
{
    int cur = s->cur;
    int i;
    int step;
    if (cur == -1) {
        func_00295090(s, func_002952C0(s), 1);
        return;
    }
    {
        int up = dir == 4;
        int down = dir == 8;
        if (up || down) {
            if (up)
                step = 1;
            else
                step = -1;
            for (i = cur + step; i != cur; i += step) {
                E294F50* e;
                if (i >= 24)
                    i = 0;
                if (i < 0)
                    i = 23;
                e = s->items[i];
                if (e && (e->flags & 4) && (e->flags & 2)) {
                    func_0041E0F0(s, Gui_GetScreenStack(), 0x10, 9, 0);
                    func_00295090(s, i, 1);
                    return;
                }
            }
        }
    }
}