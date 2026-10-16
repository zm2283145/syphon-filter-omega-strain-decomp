#include "types.h"
typedef struct { void* vt; char pad[0x5C]; char m60[0xAC]; char m10C[4]; } O2AAC60;
extern void func_002AAD00();
extern void func_002AAD10();
extern void func_002AAD40();
extern void func_002AB2A0();
extern void func_002ABC90();
extern void func_002ABD50();
extern void func_002AC300();
extern void func_002ACCA0();
extern void func_002ACCF0();
extern void GuiWidget_FocusPrev();
extern void GuiWidget_FocusNext();
extern void GuiWidget_FocusLast();
extern void GuiWidget_FocusFirst();
extern void func_0041E230();
extern void GuiWidget_OnEvent();
extern void func_0041F070();
extern void func_0041F080();
extern void GuiWidget_Deinit();
extern void func_0041F210();
extern void func_004235C0();
extern void func_00423660();
extern void func_00423670();
extern void GuiArrayWidget_OnInput();
extern void GuiArrayWidget_SetDims();
extern void GuiArrayWidget_OnLoseFocus();
extern void GuiArrayWidget_OnGainFocus();
extern void * const D_004DDB80[];
extern char D_004E0D20[];
extern void func_002AD780(void* p, int f);
extern void func_0013B2E0(void* p, int f);
extern void GuiWidget_Destroy(void* p, int f);
extern void operator_delete(void* p);
static inline void C2AAC60(void* p) { if (p) func_002AD780(p, 0); }
static inline void B2AAC60(void* p) { if (p) C2AAC60(p); }
static inline void A2AAC60(void* p) { if (p) B2AAC60(p); }
static inline void Base2AAC60(O2AAC60* p)
{
    if (p) {
        p->vt = D_004E0D20;
        func_0013B2E0(p->m60, -1);
        GuiWidget_Destroy(p, 0);
    }
}
O2AAC60* func_002AAC60(O2AAC60* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DDB80);
        A2AAC60(self->m10C);
        Base2AAC60(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DDB80[30] = { (void*)0x0, (void*)0x0, (void*)func_002AAC60, (void*)func_002ACCF0, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)func_002ABD50, (void*)func_002ABC90, (void*)GuiArrayWidget_OnGainFocus, (void*)GuiArrayWidget_OnLoseFocus, (void*)GuiArrayWidget_OnInput, (void*)func_00423670, (void*)func_0041E230, (void*)func_002ACCA0, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_002AAD00, (void*)func_002AAD10, (void*)GuiArrayWidget_SetDims, (void*)func_00423660, (void*)func_002AB2A0, (void*)func_002AAD40, (void*)func_002AC300, (void*)func_004235C0, (void*)0x0 };
