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
unsigned long long Time_GetMilliseconds(void);
float SoftFloat_U64ToFloat(unsigned long long);
void func_0040E320(void* p);
Mgr* Gui_GetScreenStack(void);
int Gui_GetScreenList(void);
void GuiCanvas_NestedUpdate(Mgr* m, float dt);
void GuiManager_Update(int a, float dt);
void GuiCanvas_UpdatePads(Mgr* m);
int Service_Lookup(void* a, void* b);
void Event_Construct(Msg* m, void* type);
void Event_Send(Msg* m, int target, int immediate);
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

extern "C" void FrontEnd_UpdateGui(ObjCBB30* o)
{
    if (o->b28 || o->b2D) {
        unsigned long long now = Time_GetMilliseconds();
        float dt;
        if (!o->last)
            o->last = 0;
        if (now - o->last > 100)
            o->last = now - 100;
        dt = SoftFloat_U64ToFloat(now - o->last) / 1000.0f;
        if (o->b2A && o->b28)
            func_0040E320(g_MemCard);
        if (g_DebugTriangle) {
            GuiCanvas_NestedUpdate(Gui_GetScreenStack(), dt);
        } else {
            GuiManager_Update(Gui_GetScreenList(), dt);
            GuiCanvas_UpdatePads(Gui_GetScreenStack());
            Gui_GetScreenStack()->Update(dt);
        }
        o->last = now;
        if (!D_0051EE90) {
            int target = Service_Lookup(g_Game, D_004F2CC0);
            Msg msg;
            Event_Construct(&msg, D_005436B0);
            msg.vtable = D_004D9160;
            Event_Send(&msg, target, 1);
            msg.vtable = D_004D9160;
            cMessage_dtor(&msg, 0);
        }
    }
}
