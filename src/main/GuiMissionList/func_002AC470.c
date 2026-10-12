#include "types.h"
typedef struct {
    char pad0[0xAC]; unsigned char bAC; unsigned char bAD; char padAE[0xB5 - 0xAE]; unsigned char bB5;
    char padB6[0xBC - 0xB6]; unsigned char bBC; char padBD[0x120 - 0xBD]; int f120;
} S_002AC470;
typedef struct {
    int id; char name[0x20]; int f24; char pad28[0x30 - 0x28]; int f30; int f34; int f38; char pad3C[0x40 - 0x3C];
    int f40; int f44;
} E_002AC470;
typedef struct { char pad0[0x248]; int f248; } U_002AC470;
extern U_002AC470* D_004FFC04;
extern unsigned char D_004FFBB5;
extern char D_004FFB50[];
extern int D_004ACB30[];
extern const char* D_0048C160[];
extern void* func_004294C0(void);
extern void* Agent_GetSelected(void* list, int idx);
extern __int128 func_003FDA40(const char* s);
extern int func_00332FE0(void* agent, __int128 key);
extern unsigned char func_0044A0D0(void* g, int id, int a);
extern unsigned char func_0044D670(void* g, int id, int a);
int func_002AC470(S_002AC470* self, E_002AC470* e)
{
    void* g;
    unsigned char ok;
    int same;
    if (!e)
        return 0;
    g = func_004294C0();
    if (!g)
        return 0;
    same = e->id == self->f120;
    ok = 0;
    switch (self->bAD) {
    case 0:
        if (!same && e->f24 == 2)
            ok = 1;
        break;
    case 1:
        ok = 1;
        break;
    case 3:
        if (!same)
            ok = 1;
        break;
    case 2:
        if ((self->bB5 && e->f24 == 1) || (e->f24 == 0 && e->f30 == 1)) {
            int k = e->f40;
            if (k >= 0 && k <= 16) {
                int cur = D_004FFC04->f248;
                if (cur == -1 || k == cur) {
                    if (D_004FFBB5) {
                        void* ag = Agent_GetSelected(D_004FFB50, -1);
                        if (!func_00332FE0(ag, func_003FDA40(D_0048C160[D_004ACB30[k]])))
                            goto check;
                    }
                    if (e->f34 && e->f34 < e->f38) {
                        if (e->f44 == 2)
                            ok = func_0044A0D0(g, e->id, 0);
                        else if (e->f44 == 1)
                            ok = func_0044D670(g, e->id, 0);
                        else
                            ok = 1;
                    }
                }
            }
        }
    check:
        if (self->bBC && !self->bAC && !ok)
            return e->name[0] ? 2 : 6;
        break;
    }
    return ok ? 3 : 0;
}
