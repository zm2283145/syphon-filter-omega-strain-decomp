#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Str_00292B90 { char d[0x10]; };
struct Blk_00292B90 { char d[0x440]; };
struct Obj_00292B90 {
    VPAD16(a) VPAD4(b) virtual int IsA(void* t);
    Str_00292B90 s4;
    char pad14[0x34];
    Str_00292B90 s48;
};
struct Agent_00292B90 { char pad[0x9A4]; Blk_00292B90* p9A4; };
struct Mgr_00292B90 { char pad[0x2E]; unsigned char b2E; };
extern "C" {
extern char D_004A9870[];
extern char D_004A9CA0[];
extern char D_004A9CB8[];
extern char D_004A9CD0[];
extern char D_004A9CE8[];
extern char D_004A9D38[];
extern char D_004A9D48[];
extern char D_004A9D58[];
extern char D_004FFB50[];
extern Mgr_00292B90* D_004FFC04;
extern char D_00493A60;
extern Blk_00292B90 D_0055D510;
char* Loc_LookupText(char* key);
char* String_CStr(Str_00292B90* s);
int atoi(char* s);
Agent_00292B90* Agent_GetSelected(void* a, int b);
unsigned char AgentData_Load(Agent_00292B90* a, char* s, int id);
void* Gui_GetScreenList(void);
void* GuiManager_FindOrLoad(void* a, char* b, char* c);
void* Gui_GetScreenStack(void);
void GuiStack_SwapScreens(void* a, void* b, void* c);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, void* d, int e);
int func_00441CA0(void* self, Obj_00292B90* o, int msg);
}

static inline void QCopy(void* d0, void* s0, int n0) { int n = n0; void* d = d0; void* s = s0;
    asm {
        .set noreorder
    loop:
        lq $v1, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, loop
        sq $v1, -0x10(d)
        .set reorder
    }
}
extern "C" int GuiAgentLoad_HandleEvent(void* self, Obj_00292B90* o, int msg)
{
    if ((msg & 0xFFFF) == 2) {
        Obj_00292B90* p;
        {
            unsigned char ok = 0;
            if (o) {
                if (o->IsA(D_004A9870)) {
                    asm { .set reorder }
                    ok = 1;
                }
            }
            if (ok) { p = o; } else { asm { .set reorder } p = 0; }
        }
        o = p;
        if (o) {
            int id = atoi(String_CStr(&o->s4));
            Agent_00292B90* ag = (Agent_00292B90*)Agent_GetSelected(D_004FFB50, -1);
            unsigned char r = AgentData_Load(ag, String_CStr(&o->s48), id);
            if (r == 0) {
                void* pg;
                D_00493A60 = 0;
                QCopy(&D_0055D510, ag->p9A4, 0x44);
                if (D_004FFC04->b2E) {
                    asm { .set reorder }
                    pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A9CA0, D_004A9CB8);
                } else {
                    asm { .set reorder }
                    pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A9CD0, D_004A9CE8);
                }
                GuiStack_SwapScreens(Gui_GetScreenStack(), self, pg);
            } else if (r == 2) {
                Mgr_00292B90* ui = D_004FFC04;
                char* t = Loc_LookupText(D_004A9D38);
                FrontEnd_OpenPopup(ui, 2, t, Loc_LookupText(D_004A9D48), self, -1);
            } else {
                Mgr_00292B90* ui = D_004FFC04;
                char* t = Loc_LookupText(D_004A9D38);
                FrontEnd_OpenPopup(ui, 2, t, Loc_LookupText(D_004A9D58), self, -1);
            }
        }
        return 1;
    }
    return func_00441CA0(self, o, msg);
}





