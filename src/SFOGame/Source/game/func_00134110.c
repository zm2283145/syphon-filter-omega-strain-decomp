#pragma cplusplus on
#include "types.h"
#include "cmessage.h"
struct Top_134110 { char pad[8]; void* w; };
struct Stack_134110 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void Draw(); virtual void Update(float dt);
    virtual void Show(void* p, int a); virtual void Hide(void* p);
    char pad4[0x24];
    int count;
    char pad2C[4];
    Top_134110* top;
};
struct Fader_134110 { float a; float b; };
extern "C" {
extern void* D_004FFC04;
extern Fader_134110* g_Fader;
extern char D_005721E0[];
extern char D_005721F0[];
extern char D_0049AA18[];
extern char D_0049AA28[];
extern char D_0049AA40[];
extern char D_0049AA58[];
extern char D_004D9160[];
extern char D_004F2CC0[];
extern char D_005436B0[];
extern char g_Video[];
extern char D_0055A300[];
extern float D_004E9FF8;
extern char D_004EA000;
extern int g_TimerAccum;
extern unsigned long long g_TickCounter64;
void ClearMessages(void);
Stack_134110* Gui_Canvas(void);
void* Gui_Manager(void);
int cGameFrontEnd_PopMessageBox(void* ui, int id);
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, char* c, void* d, int e);
void cScreenFader_StartFade(Fader_134110* f, int mode, float t);
void cScreenFader_NextFrame(Fader_134110* f, float dt);
void cScreenFader_Render(Fader_134110* f);
void XLib_NextFrame(void* p);
char* nGlobalization_GetString_charP(char* key);
void* GuiManager_OpenGui(void* a, char* b, char* c);
float _f_ulltof(unsigned long long t);
void cJoystick_Poll(void* p);
void GuiManager_NextFrame(void* l, float dt);
void cMotionManager_NextFrame(float dt);
void GuiCanvas_ProcessInput_void(Stack_134110* s);
void* GetMachine(void);
void cMachine_NetUpdate(void* p);
void* cSystemContainer_GetSystem(void* a, void* b);
}

static inline unsigned long long Now_134110(void)
{
    return g_TickCounter64 + (unsigned int)(int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f);
}

static inline void Fade_134110(int mode)
{
    cScreenFader_StartFade(g_Fader, mode, 1.0f);
    while (g_Fader->b != 0.0f) {
        cScreenFader_NextFrame(g_Fader, 0.05f);
        cScreenFader_Render(g_Fader);
        XLib_NextFrame(g_Video);
    }
}

static inline char* Title_134110(void)
{
    return D_005721F0[0] ? nGlobalization_GetString_charP(D_005721E0) : 0;
}

static inline char* Text_134110(void)
{
    return D_005721F0[0] ? D_005721F0 : nGlobalization_GetString_charP(D_005721E0);
}

extern "C" void cGameSystem_ShowEndMissionScreens(void* svc, unsigned char mode)
{
    ClearMessages();
    while (Gui_Canvas()->count) {
        Stack_134110* s = Gui_Canvas();
        Gui_Canvas()->Hide(s->top->w);
    }
    while (cGameFrontEnd_PopMessageBox(D_004FFC04, -1)) {
    }
    Fade_134110(1);
    if (mode == 1) {
        char* t = Title_134110() ? Title_134110() : nGlobalization_GetString_charP(D_0049AA18);
        cGameFrontEnd_PushMessageBox(D_004FFC04, 2, t, Text_134110(), 0, 0);
    } else if (mode == 2) {
        char* t = nGlobalization_GetString_charP(D_0049AA18);
        void* ui = D_004FFC04;
        cGameFrontEnd_PushMessageBox(ui, 2, t, nGlobalization_GetString_charP(D_0049AA28), 0, 0);
    }
    {
        void* scr = GuiManager_OpenGui(Gui_Manager(), D_0049AA40, D_0049AA58);
        Gui_Canvas()->Show(scr, 0);
    }
    if (!D_004EA000) {
        D_004E9FF8 = _f_ulltof(Now_134110());
        D_004EA000 = 1;
    }
    while (Gui_Canvas()->count) {
        unsigned long long now;
        float dt;
        cJoystick_Poll(D_0055A300);
        now = Now_134110();
        dt = (_f_ulltof(now) - D_004E9FF8) / 100000.0f;
        GuiManager_NextFrame(Gui_Manager(), dt);
        cMotionManager_NextFrame(dt);
        GuiCanvas_ProcessInput_void(Gui_Canvas());
        Gui_Canvas()->Update(dt);
        Gui_Canvas()->Draw();
        cMachine_NetUpdate(GetMachine());
        XLib_NextFrame(g_Video);
        {
            CMsg m;
            cMessage_ctor_cMessageNameR(&m, D_005436B0);
            m.vtable = D_004D9160;
            QueueMessage_cMessageR_cSystemP_int(&m, cSystemContainer_GetSystem(svc, D_004F2CC0), 1);
            m.vtable = D_004D9160;
            cMessage_dtor(&m, 0);
        }
        D_004E9FF8 = _f_ulltof(now);
    }
    Fade_134110(2);
}
