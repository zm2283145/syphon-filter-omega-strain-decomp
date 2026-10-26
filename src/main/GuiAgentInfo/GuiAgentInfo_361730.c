/*
 * main/GuiAgentInfo: 3 files, 00361730-00361A70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00361730 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0xB8]; char sB8[0x40]; int aF8; char padFC[0x18]; int a114; int a118; } S361730;
extern int String_CStr(void* p);
extern void GuiLobbyScreen_CellInviteAgent(S361730* o, int a, int b);
extern void GuiLobbyScreen_ContactInviteAgent(S361730* o, int a, int b);
extern int GuiScreen_HandleEvent(S361730* o);
int GuiAgentInfo_HandleEvent(S361730* o, int id, unsigned short type)
{
    if (type == 2) {
        if (id == o->a118) {
            GuiLobbyScreen_CellInviteAgent(o, o->aF8, String_CStr(o->sB8));
            return 1;
        }
        if (id == o->a114) {
            GuiLobbyScreen_ContactInviteAgent(o, o->aF8, String_CStr(o->sB8));
            return 1;
        }
    }
    return GuiScreen_HandleEvent(o);
}
#pragma pop /* merge_units */
/* merge_units: end func_00361730 */

/* merge_units: begin func_003617C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_3617C0 { char pad[0x14]; unsigned short flags; };
class M_3617C0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void Close(void* w);
};
struct L_3617C0 { char pad[0x14]; char list[0xC]; };
struct P_3617C0 { char pad[0x4E0]; float zoom; };
struct S_3617C0 { char pad[0x10]; W_3617C0* w10; char pad14[0xE8]; int fFC; char pad100[0x20]; P_3617C0* p120; };
struct Ev_3617C0 { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; };
typedef struct { void* n; } It_3617C0;
extern "C" {
L_3617C0* Gui_GetScreenList(void);
M_3617C0* Gui_GetScreenStack(void);
void* GuiManager_FindOrLoad(void* mgr, char* a, char* b);
void GuiStack_SwapScreens(void* mgr, S_3617C0* o, void* w);
void cLList_GuiWidgetPtr_Find(It_3617C0* out, void* list, W_3617C0** val);
void cLList_GuiWidgetPtr_End(It_3617C0* out, void* list);
int opNe_cLListIteratorR_cLListIteratorR_6(It_3617C0* a, It_3617C0* b);
int GuiScreen_HandleInput(S_3617C0* o);
int GuiAgentInfo_HandleInput(S_3617C0* o, Ev_3617C0* ev);
}
static inline unsigned char Down_3617C0(Ev_3617C0* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_3617C0(Ev_3617C0* e, int b) { unsigned char r = 0; if (Down_3617C0(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_3617C0(Ev_3617C0* e, int b) { unsigned char r = 0; if (Btn_3617C0(e, b) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_3617C0(Ev_3617C0* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_3617C0(Ev_3617C0* e, int b) { return Down2_3617C0(e) && e->btn == b; }
static inline bool NoMod2_3617C0(Ev_3617C0* e) { return Down2_3617C0(e) && e->b6 == 0; }

int GuiAgentInfo_HandleInput(S_3617C0* o, Ev_3617C0* ev)
{
    if (Plain_3617C0(ev, 0x10)) {
        if (o->fFC == 0) {
            void* w = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiDossiers", "DOSSIERS");
            GuiStack_SwapScreens(Gui_GetScreenStack(), o, w);
        } else {
            W_3617C0* w = o->w10;
            if (w) {
                W_3617C0* val = w;
                It_3617C0 res;
                It_3617C0 end;
                L_3617C0* l = Gui_GetScreenList();
                cLList_GuiWidgetPtr_Find(&res, l->list, &val);
                cLList_GuiWidgetPtr_End(&end, l->list);
                if (opNe_cLListIteratorR_cLListIteratorR_6(&res, &end)) w->flags |= 2;
            }
            Gui_GetScreenStack()->Close(o);
        }
        return 1;
    }
    if (Btn2_3617C0(ev, 2)) {
        o->p120->zoom += NoMod2_3617C0(ev) ? -1.0f : 1.0f;
        return 1;
    }
    if (Btn2_3617C0(ev, 1)) {
        o->p120->zoom += NoMod2_3617C0(ev) ? 1.0f : -1.0f;
        return 1;
    }
    return GuiScreen_HandleInput(o);
}
#pragma pop /* merge_units */
/* merge_units: end func_003617C0 */

/* merge_units: begin func_00361A70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAgentInfo virtual (vtable GuiAgentInfo_vtable slot 2); calls the GuiWidget
 * implementation GuiWidget_Deinit, then cGameFrontEnd_CloseCharacter(D_004FFC04, 0).
 */

#include "loose03_types.h"

extern int D_004FFC04;
extern int cGameFrontEnd_CloseCharacter(int, int);
extern int GuiWidget_Deinit(GuiAgentInfo*);

int GuiAgentInfo_Deinit(GuiAgentInfo* self) {
    GuiWidget_Deinit(self);
    return cGameFrontEnd_CloseCharacter(D_004FFC04, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00361A70 */
