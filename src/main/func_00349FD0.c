#pragma cplusplus on
#include "types.h"
struct V_49FD0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); };
typedef struct { void* vt; char f4[0x44]; void* f48; } O_49FD0;
typedef struct { char pad[0x25C]; int f25c; int f260; } G_49FD0;
extern "C" {
extern char D_004FFB50[];
extern G_49FD0* D_004FFC04;
extern char D_004BA5C8[];
extern char D_004BA5D0[];
extern char D_004BA5E0[];
extern char D_004BA5F0[];
extern char D_004BA600[];
extern char D_004BA610[];
extern char D_004BA620[];
extern int GuiTextListWidget_GetItemId(void*);
extern void* Agent_GetSelected(char*, int);
extern int AgentData_IsDossierOpen(void*, int);
extern int Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(O_49FD0*, int, int, int, int);
extern void FrontEnd_StartSplashThread(void*);
extern char* Loc_LookupText(char*);
extern int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, void* d, int e);
extern void FrontEnd_ClosePopup(void* ui, int p);
extern void FrontEnd_StopSplashThread(void* ui);
extern int Gui_GetScreenList(void);
extern void* GuiManager_FindOrLoad(int, char*, char*);
extern void GuiAgentInfo_Fill(void*);
extern void GuiStack_SwapScreens(int, O_49FD0*, void*);
extern char* String_CStr(void*);
extern void GuiSlideShow_SetReturn(void*, int, char*, int);
extern void GuiSlideShow_Clear(void*);
extern int GuiTextListWidget_GetItemText(void*, int);
extern int GuiSlideShow_AddCategory(void*, int);
extern int sprintf(char*, const char*, ...);
extern void GuiSlideShow_AddSlide(void*, int, char*, int, char*);
void GuiDossiers_Select(O_49FD0* o, int idx);
}
void GuiDossiers_Select(O_49FD0* o, int idx)
{
    int id = GuiTextListWidget_GetItemId(o->f48);
    if (id == -1 || !AgentData_IsDossierOpen(Agent_GetSelected(D_004FFB50, -1), id)) {
        GuiWidget_SendEvent(o, Gui_GetScreenStack(), 0x10, 4, 0);
        return;
    }
    GuiWidget_SendEvent(o, Gui_GetScreenStack(), 0x10, 0, 0);
    if (id == 0) {
        bool splash = !D_004FFC04->f260;
        int popup = -2;
        void* w;
        if (splash) {
            FrontEnd_StartSplashThread(D_004FFC04);
            {
                void* ui = D_004FFC04;
                popup = FrontEnd_OpenPopup(ui, 0, D_004BA5C8, Loc_LookupText(D_004BA5D0), 0, 0);
            }
        }
        w = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004BA5E0, D_004BA5F0);
        if (splash) {
            FrontEnd_ClosePopup(D_004FFC04, popup);
            FrontEnd_StopSplashThread(D_004FFC04);
        }
        if (w) {
            GuiAgentInfo_Fill(w);
            GuiStack_SwapScreens(Gui_GetScreenStack(), o, w);
        }
    } else {
        void* w = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004BA600, D_004BA610);
        if (w) {
            char buf[0x20];
            int x;
            {
                char* t = String_CStr(o->f4);
                GuiSlideShow_SetReturn(w, ((V_49FD0*)o)->v19(), t, idx);
            }
            GuiSlideShow_Clear(w);
            x = GuiSlideShow_AddCategory(w, GuiTextListWidget_GetItemText(o->f48, idx));
            sprintf(buf, D_004BA620, 1, id);
            GuiSlideShow_AddSlide(w, x, buf, D_004FFC04->f25c, 0);
            GuiStack_SwapScreens(Gui_GetScreenStack(), o, w);
        }
    }
}
