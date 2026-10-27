#pragma cplusplus on

class Mgr {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21();
    virtual void Update(float dt);
};

typedef struct { void* vtable; char pad[0x2C]; } Msg;

extern "C" {
unsigned long long cTimer_GetMillisecondTime(void);
float _f_ulltof(unsigned long long);
void cMemCard_NextFrame(void* p);
Mgr* Gui_Canvas(void);
int Gui_Manager(void);
void GuiCanvas_AdvanceAnimations(Mgr* m, float dt);
void GuiManager_NextFrame(int a, float dt);
void GuiCanvas_ProcessInput_void(Mgr* m);
int cSystemContainer_GetSystem(void* a, void* b);
void cMessage_ctor_cMessageNameR(Msg* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(Msg* m, int target, int immediate);
void cMessage_dtor(Msg* m, int flags);
extern char g_MemCard[];
extern unsigned char g_DebugTriangle;
extern unsigned char D_0051EE90;
extern char g_Game[];
extern char D_004F2CC0[];
extern char D_005436B0[];
extern char D_004D9160[];
}

struct ObjCBB30 {
    char pad[0x20];
    unsigned long long last;
    unsigned char b28;
    unsigned char b29;
    unsigned char b2A;
    unsigned char b2B;
    unsigned char b2C;
    unsigned char b2D;
};

extern "C" void cGameFrontEnd_NextFrame(ObjCBB30* o)
{
    if (o->b28 || o->b2D) {
        unsigned long long now = cTimer_GetMillisecondTime();
        float dt;
        if (!o->last)
            o->last = 0;
        if (now - o->last > 100)
            o->last = now - 100;
        dt = _f_ulltof(now - o->last) / 1000.0f;
        if (o->b2A && o->b28)
            cMemCard_NextFrame(g_MemCard);
        if (g_DebugTriangle) {
            GuiCanvas_AdvanceAnimations(Gui_Canvas(), dt);
        } else {
            GuiManager_NextFrame(Gui_Manager(), dt);
            GuiCanvas_ProcessInput_void(Gui_Canvas());
            Gui_Canvas()->Update(dt);
        }
        o->last = now;
        if (!D_0051EE90) {
            int target = cSystemContainer_GetSystem(g_Game, D_004F2CC0);
            Msg msg;
            cMessage_ctor_cMessageNameR(&msg, D_005436B0);
            msg.vtable = D_004D9160;
            QueueMessage_cMessageR_cSystemP_int(&msg, target, 1);
            msg.vtable = D_004D9160;
            cMessage_dtor(&msg, 0);
        }
    }
}
