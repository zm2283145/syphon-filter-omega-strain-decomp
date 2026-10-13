#pragma cplusplus on
#include "types.h"
struct Look { char pad[0x440]; } __attribute__((aligned(16)));
struct Prof { char pad0[0x40]; Look look; };
/* quad copy loop idiom as in src\main\LightMgr_RemoveFromTable.c (retail uses a hand-written addi) */
static inline void QMoveP(void* d, Prof* p, int n) {
    void* ss = &p->look;
    int nn = n;
    void* dd = d;
    __int128 t;
    asm {
        .set noreorder
    lp:
        lq t, 0(ss)
        addiu dd, dd, 0x10
        addi nn, nn, -1
        addiu ss, ss, 0x10
        bgtz nn, lp
        sq t, -0x10(dd)
        .set reorder
    }
}

struct Data { char pad0[0x60]; Prof prof; };
struct Screen { char pad0[0x70]; Data* data; };
struct Agent {
    char pad0[0x8DC]; unsigned char b8DC; char pad8DD[0x91C - 0x8DD];
    unsigned char b91C; char pad91D[0x95C - 0x91D];
    unsigned char b95C; char pad95D[0x99C - 0x95D];
    int i99C; int i9A0;
};
struct Cfg { char pad[0x59D]; unsigned char b59D; };
struct Holder { Cfg* cfg; };
extern "C" {
extern char D_004A9930[], D_004A9940[], D_004A9950[], D_004A9960[];
extern char D_004FFB50[];
extern int D_004FFC04;
extern Holder D_0055A830;
extern char D_0055DDA0[];
void Appearance_RemoveBlankPairs(Look* l);
void func_00403310(void* p);
Agent* Agent_GetSelected(void* p, int i);
void func_00334000(Agent* a, Look* l);
int Gui_GetScreenList(void);
int Gui_GetScreenStack(void);
int GuiManager_FindOrLoad(int list, char* a, char* b);
void GuiStack_SwapScreens(int stack, Screen* s, int n);
int Loc_LookupText(char* s);
void FrontEnd_OpenPopup(int a, int b, int t1, int t2, Screen* s, int c);
}
/* opt_propagation off + the Holder* local keep the lui/addiu/lw 0 form for D_0055A830. */
#pragma opt_propagation off
extern "C" void func_0028BA90(Screen* self)
{
    Look look;
    QMoveP(&look, &self->data->prof, 0x44);
    Appearance_RemoveBlankPairs(&look);
    func_00403310(D_0055DDA0);
    {
        Agent* a = Agent_GetSelected(D_004FFB50, -1);
        a->b8DC = 0;
        a->b91C = 0;
        a->i99C = -1;
        a->b95C = 0;
        a->i9A0 = -1;
    }
    func_00334000(Agent_GetSelected(D_004FFB50, -1), &look);
    Holder* h = &D_0055A830;
    if (h->cfg->b59D) {
        int n = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A9930, D_004A9940);
        GuiStack_SwapScreens(Gui_GetScreenStack(), self, n);
    } else {
        int p = D_004FFC04;
        int t1 = Loc_LookupText(D_004A9950);
        FrontEnd_OpenPopup(p, 4, t1, Loc_LookupText(D_004A9960), self, 3);
    }
}


