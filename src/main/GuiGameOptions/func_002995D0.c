#include "types.h"
typedef struct { char pad[0x48]; char m48[0x9C]; char mE4[4]; } M2995D0;
typedef struct { void* vt; char pad[0xDC]; M2995D0 mE0; char pad2[0x270 - 0xE0 - sizeof(M2995D0)]; M2995D0 m270; } O2995D0;
extern void func_00299690();
extern void func_002996A0();
extern void GuiGameOptions_HandleInput();
extern void GuiGameOptions_HandleEvent();
extern void GuiGameOptions_OnSaveDone();
extern void GuiGameOptions_Sleep();
extern void GuiGameOptions_Wake();
extern void GuiGameOptions_Init();
extern void GuiGameOptions_Update();
extern void func_0041D400();
extern void func_0041D5C0();
extern void func_0041D780();
extern void func_0041D8C0();
extern void func_0041E230();
extern void func_0041E2B0();
extern void func_0041E330();
extern void func_0041E470();
extern void func_0041F070();
extern void func_0041F080();
extern void func_0041F090();
extern void func_0041F210();
extern void * const D_004DD580[];
extern char D_004E1220[];
extern void FileMan_Release(void* p, int f);
extern void func_0041F370(void* p, int f);
extern void operator_delete(void* p);
static inline void M2995D0_dtor(M2995D0* m)
{
    if (m) {
        FileMan_Release(m->mE4, -1);
        FileMan_Release(m->m48, -1);
    }
}
static inline void Base2995D0(O2995D0* p)
{
    if (p) {
        p->vt = D_004E1220;
        func_0041F370(p, 0);
    }
}
O2995D0* func_002995D0(O2995D0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DD580);
        M2995D0_dtor(&self->m270);
        M2995D0_dtor(&self->mE0);
        Base2995D0(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD580[24] = { (void*)0x0, (void*)0x0, (void*)func_002995D0, (void*)GuiGameOptions_Init, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)GuiGameOptions_Wake, (void*)GuiGameOptions_Sleep, (void*)func_0041E330, (void*)func_0041E2B0, (void*)GuiGameOptions_HandleInput, (void*)func_0041E470, (void*)func_0041E230, (void*)GuiGameOptions_Update, (void*)GuiGameOptions_HandleEvent, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00299690, (void*)func_002996A0, (void*)GuiGameOptions_OnSaveDone };
