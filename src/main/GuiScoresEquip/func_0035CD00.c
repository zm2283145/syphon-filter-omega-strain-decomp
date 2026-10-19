#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

/* GuiScoresEquip_Init: bind the scores/equipment screen widgets: the figure view (render callback),
 * the 4x20 equipment grid, the optional player tabs (with the multiplayer stats query) and the
 * 4 pairs of row labels. */

class W {
public:
    VPAD16(a) VPAD4(b)
    virtual int IsA(char* type);
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x48 - 0x16];
    void* cb;
};

struct Stats { char pad[0x10]; int a; int b; };

struct Screen {
    char pad0[0x48];
    W* tab[4];
    int x58;
    int x5C;
    unsigned char hasTabs;
    char pad61[3];
    W* grid[4][20];
    char pad1A4[0x230 - 0x1A4];
    struct { W* a; W* b; } rows[4];
};

extern "C" {
extern char D_004BB590[];
extern char D_004A9BF0[];
extern char D_004A7520[];
extern char D_004BB5A0[];
extern char D_004BB5B8[];
extern char D_004BB5C0[];
extern char D_004BB5E0[];
extern char D_00492D10[20][20];
extern Screen* D_00533760;
extern unsigned char g_IsMultiplayer;
void GuiWidget_Init(Screen* s);
W* GuiWidget_FindChildByName(void* self, char* name);
void GuiScoresEquip_FigureCallback(void);
void func_0041C0D0(W* w, int on);
void func_0041C0F0(W* w, int on);
int sprintf(char* buf, const char* fmt, ...);
void GuiWidget_SendEvent(Screen* s, W* to, int ev, int name, int data);
void GuiScoresEquip_Init(Screen* s);
}

static inline W* FindAs(void* self, char* name, char* type)
{
    W* w = GuiWidget_FindChildByName(self, name);
    return (w && w->IsA(type)) ? w : 0;
}

void GuiScoresEquip_Init(Screen* s)
{
    int i;
    int j;
    GuiWidget_Init(s);
    {
        W* f = FindAs(s, D_004BB590, D_004A9BF0);
        if (f) {
            D_00533760 = s;
            f->cb = (void*)GuiScoresEquip_FigureCallback;
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 20; j++) {
            *((char*)D_00492D10 + j * 20) = '1' + i;
            s->grid[i][j] = FindAs(s, D_00492D10[j], D_004A7520);
            if (s->grid[i][j]) {
                func_0041C0D0(s->grid[i][j], 1);
                func_0041C0F0(s->grid[i][j], 1);
            }
        }
    }
    if (s->hasTabs) {
        for (i = 0; i < 4; i++) {
            char buf[0x1C];
            sprintf(buf, D_004BB5A0, i + 1);
            s->tab[i] = GuiWidget_FindChildByName(s, buf);
            if (s->tab[i]) s->tab[i]->flags &= ~2;
        }
        if (g_IsMultiplayer && s->tab[0]) {
            Stats* r = 0;
            GuiWidget_SendEvent(s, s->tab[0], 4, (int)D_004BB5B8, (int)&r);
            if (r) {
                s->x58 = r->a;
                s->x5C = r->b;
            }
        }
    }
    /* row labels: retail places the loop setup after the body (entry jumps to it, then to the test) */
    {
        int k;
        char* a;
        char* b;
        k = 0;
        goto init;
    loop:
        a[0] = '1' + k;
        b[0] = '1' + k;
        s->rows[k].a = GuiWidget_FindChildByName(s, a);
        s->rows[k].b = GuiWidget_FindChildByName(s, b);
        k++;
    test:
        if (k < 4) goto loop;
        return;
    init:
        a = D_004BB5C0;
        b = D_004BB5E0;
        goto test;
    }
}
