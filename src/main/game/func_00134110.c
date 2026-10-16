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
extern Fader_134110* D_004FFC38;
extern char D_005721E0[];
extern char D_005721F0[];
extern char D_0049AA18[];
extern char D_0049AA28[];
extern char D_0049AA40[];
extern char D_0049AA58[];
extern char D_004D9160[];
extern char D_004F2CC0[];
extern char D_005436B0[];
extern char D_005381F0[];
extern char D_0055A300[];
extern float D_004E9FF8;
extern char D_004EA000;
extern int D_00533870;
extern unsigned long long D_00533878;
void MsgQueue_ClearPending(void);
Stack_134110* Gui_GetScreenStack(void);
void* Gui_GetScreenList(void);
int FrontEnd_ClosePopup(void* ui, int id);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, void* d, int e);
void ActorFader_Start(Fader_134110* f, int mode, float t);
void ActorFader_Update(Fader_134110* f, float dt);
void ActorFader_GetAlpha(Fader_134110* f);
void Video_BeginFrame(void* p);
char* Loc_LookupText(char* key);
void* GuiManager_FindOrLoad(void* a, char* b, char* c);
float SoftFloat_U64ToFloat(unsigned long long t);
void Pad_Reset(void* p);
void GuiManager_Update(void* l, float dt);
void World_PhysicsTraversal(float dt);
void func_00415870(Stack_134110* s);
void* App_GetInstance(void);
void func_00169390(void* p);
void* Service_Lookup(void* a, void* b);
}

static inline unsigned long long Now_134110(void)
{
    return D_00533878 + (unsigned int)(int)((float)(unsigned int)(*(volatile int*)0x10000800 + D_00533870) / 5.76f);
}

static inline void Fade_134110(int mode)
{
    ActorFader_Start(D_004FFC38, mode, 1.0f);
    while (D_004FFC38->b != 0.0f) {
        ActorFader_Update(D_004FFC38, 0.05f);
        ActorFader_GetAlpha(D_004FFC38);
        Video_BeginFrame(D_005381F0);
    }
}

static inline char* Title_134110(void)
{
    return D_005721F0[0] ? Loc_LookupText(D_005721E0) : 0;
}

static inline char* Text_134110(void)
{
    return D_005721F0[0] ? D_005721F0 : Loc_LookupText(D_005721E0);
}

extern "C" void func_00134110(void* svc, unsigned char mode)
{
    MsgQueue_ClearPending();
    while (Gui_GetScreenStack()->count) {
        Stack_134110* s = Gui_GetScreenStack();
        Gui_GetScreenStack()->Hide(s->top->w);
    }
    while (FrontEnd_ClosePopup(D_004FFC04, -1)) {
    }
    Fade_134110(1);
    if (mode == 1) {
        char* t = Title_134110() ? Title_134110() : Loc_LookupText(D_0049AA18);
        FrontEnd_OpenPopup(D_004FFC04, 2, t, Text_134110(), 0, 0);
    } else if (mode == 2) {
        char* t = Loc_LookupText(D_0049AA18);
        void* ui = D_004FFC04;
        FrontEnd_OpenPopup(ui, 2, t, Loc_LookupText(D_0049AA28), 0, 0);
    }
    {
        void* scr = GuiManager_FindOrLoad(Gui_GetScreenList(), D_0049AA40, D_0049AA58);
        Gui_GetScreenStack()->Show(scr, 0);
    }
    if (!D_004EA000) {
        D_004E9FF8 = SoftFloat_U64ToFloat(Now_134110());
        D_004EA000 = 1;
    }
    while (Gui_GetScreenStack()->count) {
        unsigned long long now;
        float dt;
        Pad_Reset(D_0055A300);
        now = Now_134110();
        dt = (SoftFloat_U64ToFloat(now) - D_004E9FF8) / 100000.0f;
        GuiManager_Update(Gui_GetScreenList(), dt);
        World_PhysicsTraversal(dt);
        func_00415870(Gui_GetScreenStack());
        Gui_GetScreenStack()->Update(dt);
        Gui_GetScreenStack()->Draw();
        func_00169390(App_GetInstance());
        Video_BeginFrame(D_005381F0);
        {
            CMsg m;
            Event_Construct(&m, D_005436B0);
            m.vtable = D_004D9160;
            Event_Send(&m, Service_Lookup(svc, D_004F2CC0), 1);
            m.vtable = D_004D9160;
            cMessage_dtor(&m, 0);
        }
        D_004E9FF8 = SoftFloat_U64ToFloat(now);
    }
    Fade_134110(2);
}
