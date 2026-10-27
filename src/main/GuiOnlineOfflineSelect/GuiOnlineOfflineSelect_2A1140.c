/*
 * main/GuiOnlineOfflineSelect: 2 files, 002A1140-002A12F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A1140 */
#pragma push /* merge_units */
typedef struct { char pad[0x32]; unsigned char unk32; } G_2A1140;
typedef struct { int unk0; char name[4]; } Ctl_2A1140;
typedef struct { char pad[0xDC]; Ctl_2A1140* unkDC; Ctl_2A1140* unkE0; } Obj_2A1140;

extern int std_basic_string_char_char_traits_char_compare_charP(void*, const char*);
extern void GuiLobbyScreen_PushLobbyScreen(Obj_2A1140*, int);
extern void GuiMissionSetup_CreateMission(Obj_2A1140*);
extern void GuiMissionSetup_CycleNumAgents(Obj_2A1140*, int);
extern void GuiMissionSetup_CycleJoinFilter(Obj_2A1140*, int);
extern int GuiLobbyScreen_onMessage(Obj_2A1140*, Ctl_2A1140*, unsigned int, int, int);
extern const char* D_0048BA40;
extern const char* D_0048BA48;
extern const char* D_0048BA60;
extern G_2A1140* D_004FFC04;
extern unsigned char D_005064A8;
extern int D_005064B0;
extern int D_005064B8;

int GuiMissionSetup_onMessage(Obj_2A1140* self, Ctl_2A1140* ctl, unsigned int msg, int code, int param)
{
    unsigned short m = msg;

    if ((m == 27 || m == 26) && code == 11) {
        GuiLobbyScreen_PushLobbyScreen(self, 1);
        return 1;
    }
    if (m == 2) {
        if (std_basic_string_char_char_traits_char_compare_charP(ctl->name, D_0048BA60) == 0) {
            GuiMissionSetup_CreateMission(self);
            return 1;
        }
        if (std_basic_string_char_char_traits_char_compare_charP(ctl->name, D_0048BA40) == 0) {
            GuiMissionSetup_CycleNumAgents(self, 1);
            return 1;
        }
        if (std_basic_string_char_char_traits_char_compare_charP(ctl->name, D_0048BA48) == 0) {
            GuiMissionSetup_CycleJoinFilter(self, 1);
            return 1;
        }
    }
    if (m == 16 && code == 1 && (ctl == self->unkE0 || ctl == self->unkDC)) {
        return 1;
    }
    if (m == 30 && D_004FFC04->unk32 == 0) {
        D_005064B0 = code;
        D_005064B8 = param;
        D_005064A8 = 1;
        return 1;
    }
    return GuiLobbyScreen_onMessage(self, ctl, msg, code, param);
}
#pragma pop /* merge_units */
/* merge_units: end func_002A1140 */

/* merge_units: begin func_002A12F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct Ev_002A12F0 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct Pg_002A12F0 { char pad[0x14]; unsigned short flags; };
struct Ui_002A12F0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual void Show(void* p, int a); virtual void Hide(void* p);
};
struct S_002A12F0 { char pad0[0x20]; void* f20; char pad24[0xDC - 0x24]; void* pDC; void* pE0; };
extern "C" {
#if 0 /* merge_units */
void GuiMissionSetup_CycleNumAgents(S_002A12F0* self, int a);
#endif /* merge_units */
#define GuiMissionSetup_CycleNumAgents(a0, a1) (GuiMissionSetup_CycleNumAgents((Obj_2A1140 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void GuiMissionSetup_CycleJoinFilter(S_002A12F0* self, int a);
#endif /* merge_units */
#define GuiMissionSetup_CycleJoinFilter(a0, a1) (GuiMissionSetup_CycleJoinFilter((Obj_2A1140 *)(a0), (a1))) /* merge_units */

void* Gui_Manager(void);
Pg_002A12F0* GuiManager_FindOpenGui(void* a, char* b);
Ui_002A12F0* Gui_Canvas(void);
#if 0 /* merge_units */
void GuiLobbyScreen_PushLobbyScreen(S_002A12F0* self, int a);
#endif /* merge_units */
#define GuiLobbyScreen_PushLobbyScreen(a0, a1) (GuiLobbyScreen_PushLobbyScreen((Obj_2A1140 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void GuiMissionSetup_CreateMission(S_002A12F0* self);
#endif /* merge_units */
#define GuiMissionSetup_CreateMission(a0) (GuiMissionSetup_CreateMission((Obj_2A1140 *)(a0))) /* merge_units */

int GuiLobbyScreen_onInput(S_002A12F0* self, Ev_002A12F0* ev);
}
static inline unsigned char Down_002A12F0(Ev_002A12F0* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline unsigned char Btn_002A12F0(Ev_002A12F0* e, int b)
{
    unsigned char r = 0;
    if (Down_002A12F0(e) && e->btn == b)
        r = 1;
    return r;
}
static inline unsigned char Press_002A12F0(Ev_002A12F0* e, int b)
{
    unsigned char r = 0;
    if (Btn_002A12F0(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
extern "C" int GuiMissionSetup_onInput(S_002A12F0* self, Ev_002A12F0* ev)
{
    if (Press_002A12F0(ev, 0x8000)) {
        if (self->f20 == self->pDC)
            GuiMissionSetup_CycleNumAgents(self, 0);
        else if (self->f20 == self->pE0)
            GuiMissionSetup_CycleJoinFilter(self, 0);
    } else {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x2000 && ev->f6 == 0;
        if (b) {
            if (self->f20 == self->pDC)
                GuiMissionSetup_CycleNumAgents(self, 1);
            else if (self->f20 == self->pE0)
                GuiMissionSetup_CycleJoinFilter(self, 1);
        }
    }
    if (Press_002A12F0(ev, 0x10)) {
        Pg_002A12F0* p = GuiManager_FindOpenGui(Gui_Manager(), "GuiNetJoinMission");
        if (p) {
            Gui_Canvas()->Hide(self);
            p->flags |= 2;
        } else {
            GuiLobbyScreen_PushLobbyScreen(self, 1);
        }
        return 1;
    } else {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x80 && ev->f6 == 0;
        if (b) {
            GuiMissionSetup_CreateMission(self);
            return 1;
        }
    }
    return GuiLobbyScreen_onInput(self, ev);
}
#undef GuiMissionSetup_CycleNumAgents /* merge_units */
#undef GuiMissionSetup_CycleJoinFilter /* merge_units */
#undef GuiLobbyScreen_PushLobbyScreen /* merge_units */
#undef GuiMissionSetup_CreateMission /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A12F0 */
