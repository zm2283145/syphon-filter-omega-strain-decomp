#pragma cplusplus on
#include "types.h"
struct V4EC00 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); };
typedef struct { char pad[0x10]; char f10[0x14]; } E4EC00;
typedef struct { char pad[8]; E4EC00* f8; } T4EC00;
typedef struct { char pad[4]; int f4; } B4EC00;
typedef struct { char pad[0xB50]; B4EC00* fb50; } A4EC00;
typedef struct { void* vt; char f4[0x44]; void* f48; char pad[0x18]; int f64; } O4EC00;
typedef struct { char pad[0x25C]; int f25c; } G4EC00;
typedef struct { char pad[8]; unsigned char kind; char pad9[3]; int a; int b; int c; int d; } Item_4EC00;
struct AwardVec_4EC00;
extern "C" {
extern void func_00296F20(AwardVec_4EC00*);
extern void func_00299270(AwardVec_4EC00*, int);
extern void AgentData_GetAwardItems(A4EC00*, int, int, AwardVec_4EC00*);
extern char D_004BA9B8[];
extern char D_004BA9C8[];
extern char D_004BA9D8[];
extern int GuiTextListWidget_GetItemId(void*);
extern char g_Game[];
extern A4EC00* Agent_GetSelected(char*, int);
extern int Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(O4EC00*, int, int, int, int);
extern int Gui_GetScreenList(void);
extern void* GuiManager_FindOrLoad(int, char*, char*);
extern char* String_CStr(void*);
extern void GuiSlideShow_SetReturn(void*, int, char*, int);
extern void GuiSlideShow_Clear(void*);
extern int GuiTextListWidget_GetItemText(void*, int);
extern int GuiSlideShow_AddCategory(void*, int);
extern int sprintf(char*, const char*, ...);
extern T4EC00* func_0034E760(void);
extern G4EC00* D_004FFC04;
extern void GuiSlideShow_AddSlide(void*, int, char*, int, char*);
extern void GuiStack_SwapScreens(int, O4EC00*, void*);
}
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
struct AwardVec_4EC00 {
    int x0; int count; Item_4EC00* data; unsigned char owns;
    AwardVec_4EC00() { func_00296F20(this); owns = 1; }
    /* out-of-line copy is weak and dropped at link (as include/alloc_guard.h) */
    __declspec(weak) __declspec(DROPDTOR) ~AwardVec_4EC00() { func_00299270(this, 0); }
};
extern "C" void GuiOmegaStrain_Select(O4EC00* o, int idx) {
    AwardVec_4EC00 v;
    char buf[0x20];
    void* w;
    int x;
    Item_4EC00** pd; int off;
    AgentData_GetAwardItems(Agent_GetSelected(g_Game, -1), 4, 0, &v);
    if (idx >= 0 && idx < v.count) {
        pd = &v.data; off = idx * (int)sizeof(Item_4EC00);
        if (((Item_4EC00*)((char*)*pd + off))->kind == 2) {
            GuiWidget_SendEvent(o, Gui_GetScreenStack(), 0x10, 1, 0);
            w = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004BA9B8, D_004BA9C8);
            if (w) {
                {
                    char* t = String_CStr(o->f4);
                    GuiSlideShow_SetReturn(w, ((V4EC00*)o)->v19(), t, idx);
                }
                GuiSlideShow_Clear(w);
                x = GuiSlideShow_AddCategory(w, GuiTextListWidget_GetItemText(o->f48, idx));
                {
                    Item_4EC00* it = (Item_4EC00*)((char*)*pd + off);
                    sprintf(buf, D_004BA9D8, it->a, it->b, it->c);
                }
                GuiSlideShow_AddSlide(w, x, buf, D_004FFC04->f25c, 0);
                GuiStack_SwapScreens(Gui_GetScreenStack(), o, w);
            }
        } else {
            GuiWidget_SendEvent(o, Gui_GetScreenStack(), 0x10, 4, 0);
        }
    }
}
