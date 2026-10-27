/*
 * SFOGame/Source/gameFrontEnd: 4 files, 002CB8C0-002CBB30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CB8C0 */
#pragma push /* merge_units */
#pragma opt_propagation off
extern char* GetMachine(void);
extern void cMachine_InitFonts(char* g);
extern void SetFontColors(int x);
extern void cInterfaceManager_RemoveHogPath(char* a, char* b);
extern void func_00413880(char* a, char* b);
extern void cInterfaceManager_SetHogList(char* a, char* b);
extern void cInterfaceManager_OpenHogOfHog(char* a, char* b);
extern void cInterfaceManager_Init(char* a);
extern int Gui_Manager(void);
extern char* Gui_Canvas(void);
extern void Gui_Init(char* s);
extern void GuiCanvas_Activate(char* p, int x);
extern void GuiManager_AddFont(int a, char* b, int c, int d);
extern int sprintf(char* buf, const char* fmt, ...);
extern char D_0048B2F8[];
extern char D_004AD048[];
extern char D_004AD060[];
extern char D_004AD078[];
extern char D_004AD080[];
extern char D_004AD088[];
extern char D_004AD098[];
extern char D_004AD0A8[];
extern char D_004FFB8C[];
extern char g_Video[];
extern int D_00538C60;
extern float D_00539170[4];
extern char D_00571DC0[];

typedef struct {
    unsigned char pad[0x29];
    unsigned char done;
} SelfB8C0;

typedef struct {
    char pad[0x1F0];
    float v[4];
    char pad200[0x2F5 - 0x200];
    char f2F5;
    char f2F6;
} SlotB8C0;

void FrontEnd_CreateCanvas(SelfB8C0* self, int flag)
{
    char buf[0x80];

    if (self->done) {
        return;
    }
    cMachine_InitFonts(GetMachine());
    Gui_Init(flag ? D_004AD048 : D_004AD060);
    {
        char* g = GetMachine();
        GuiManager_AddFont(Gui_Manager(), D_004AD078, *(int*)(g + 0x280), 0);
    }
    {
        char* g = GetMachine();
        GuiManager_AddFont(Gui_Manager(), D_004AD080, *(int*)(g + 0x284), 0);
    }
    {
        char* g = GetMachine();
        GuiManager_AddFont(Gui_Manager(), D_004AD088, *(int*)(g + 0x288), 0);
    }
    SetFontColors(*(int*)(GetMachine() + 0x280));
    SetFontColors(*(int*)(GetMachine() + 0x284));
    SetFontColors(*(int*)(GetMachine() + 0x288));
    Gui_Canvas()[0x51] = 0;
    GuiCanvas_Activate(Gui_Canvas(), 1);
    cInterfaceManager_Init(D_00571DC0);
    cInterfaceManager_SetHogList(D_00571DC0, D_004FFB8C);
    sprintf(buf, D_004AD098, D_0048B2F8);
    func_00413880(D_00571DC0, buf);
    cInterfaceManager_OpenHogOfHog(D_00571DC0, D_004AD0A8);
    cInterfaceManager_RemoveHogPath(D_00571DC0, buf);
    if (!flag) {
        SlotB8C0* s = (SlotB8C0*)(g_Video + D_00538C60 * 0x110);
        float* v = D_00539170;
        s->v[0] = v[0];
        s->v[1] = v[1];
        s->v[2] = v[2];
        s->v[3] = v[3];
        s->f2F5 = 1;
        s->f2F6 = 1;
    }
    self->done = 1;
}
static inline void merge_flush_func_002CB8C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CB8C0 */

/* merge_units: begin func_002CBAC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cGameFrontEnd_HandleMessage(void) {
    return 0;
}
static inline void merge_flush_func_002CBAC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CBAC0 */

/* merge_units: begin func_002CBAD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_classes.h"
extern "C" {
#if 0 /* merge_units */
VSlots67* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((VSlots67 *)Gui_Canvas()) /* merge_units */

void XLib_NextFrame(void* p);
}
struct ObjBAD0 { char pad[0x28]; unsigned char a; char pad2[4]; unsigned char b; };
extern "C" void cGameFrontEnd_Render(ObjBAD0* o)
{
    if (o->a || o->b) {
        Gui_Canvas()->slot21();
        XLib_NextFrame(g_Video);
    }
}
#undef Gui_Canvas /* merge_units */
static inline void merge_flush_func_002CBAD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CBAD0 */

/* merge_units: begin func_002CBB30 */
#pragma push /* merge_units */
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
#if 0 /* merge_units */
Mgr* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((Mgr *)Gui_Canvas()) /* merge_units */

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
#undef Gui_Canvas /* merge_units */
static inline void merge_flush_func_002CBB30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CBB30 */
