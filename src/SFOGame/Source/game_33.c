/*
 * SFOGame/Source/game: 5 files, 00133EC0-00134110
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00133EC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_00133EC0(char* self) {
    return self + 48;
}
static inline void merge_flush_func_00133EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00133EC0 */

/* merge_units: begin func_00133ED0 */
#pragma push /* merge_units */
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma cplusplus on
#include "vslot_pad.h"
#include "node_world_q4.h"
typedef MtxQ4 M_ED0;
struct Node_ED0 { VPAD16(a) VPAD4(b) virtual void Update(); int pad4[3]; M_ED0 m; unsigned char dirty; char pad51[0x1D0 - 0x51]; };
struct Mdl_ED0 { char pad[0x14]; unsigned char hasSkel; char pad15[0xB]; Node_ED0* nodes; char pad24[4]; Node_ED0* root; };
#include "pp_quad_copy.h"
extern "C" M_ED0 cSkeleton_GetBoneToWorldMatrix(Mdl_ED0* self, int idx)
{
    if (self->hasSkel) {
        Node_ED0* r = self->root;
        if (r->dirty) r->Update();
        M_ED0* mm = &r->m;
        Node_ED0* n = &self->nodes[idx];
        if (n->dirty) n->Update();
        M_ED0 p; const M_ED0* fs; M_ED0* pp; M_ED0* fd; __int128 qa; __int128 qb; {
        fs = &n->m;
        __asm__ volatile("lq %0, 0x0(%1)" : "=r"(qa) : "r"(fs));
        fd = &p;
        __asm__ volatile("lq %0, 0x10(%1)" : "=r"(qb) : "r"(fs));
        pp = &p;
        __asm__ volatile("sq %0, 0x0(%1)" : : "r"(qa), "r"(fd) : "memory");
        __asm__ volatile("lq %0, 0x20(%1)" : "=r"(qa) : "r"(fs));
        __asm__ volatile("sq %0, 0x10(%1)" : : "r"(qb), "r"(fd) : "memory");
        __asm__ volatile("lq %0, 0x30(%1)" : "=r"(qb) : "r"(fs));
        __asm__ volatile("sq %0, 0x20(%1)" : : "r"(qa), "r"(fd) : "memory");
        __asm__ volatile("sq %0, 0x30(%1)" : : "r"(qb), "r"(fd) : "memory"); }
        asm {
            lqc2 vf4, 0x0(mm)
            lqc2 vf5, 0x10(mm)
            lqc2 vf6, 0x20(mm)
            lqc2 vf7, 0x30(mm)
            lqc2 vf8, 0x0(pp)
            lqc2 vf9, 0x10(pp)
            lqc2 vf10, 0x20(pp)
            lqc2 vf11, 0x30(pp)
            vmulax.xyzw ACC, vf4, vf8x
            vmadday.xyzw ACC, vf5, vf8y
            vmaddaz.xyzw ACC, vf6, vf8z
            vmaddw.xyzw vf12, vf7, vf8w
            vmulax.xyzw ACC, vf4, vf9x
            vmadday.xyzw ACC, vf5, vf9y
            vmaddaz.xyzw ACC, vf6, vf9z
            vmaddw.xyzw vf13, vf7, vf9w
            vmulax.xyzw ACC, vf4, vf10x
            vmadday.xyzw ACC, vf5, vf10y
            vmaddaz.xyzw ACC, vf6, vf10z
            vmaddw.xyzw vf14, vf7, vf10w
            vmulax.xyzw ACC, vf4, vf11x
            vmadday.xyzw ACC, vf5, vf11y
            vmaddaz.xyzw ACC, vf6, vf11z
            vmaddw.xyzw vf15, vf7, vf11w
            sqc2 vf12, 0x0(pp)
            sqc2 vf13, 0x10(pp)
            sqc2 vf14, 0x20(pp)
            sqc2 vf15, 0x30(pp)
        }
        return *pp;
    }
    Node_ED0* r = self->root;
    if (r->dirty) r->Update();
    { M_ED0* w = &r->m; return *w; }
}
static inline void merge_flush_func_00133ED0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00133ED0 */

/* merge_units: begin func_00134080 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma opt_common_subs off
V4 cVector_opAdd(V4* b, V4* c) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(q1)
    }
    return l0;
}
#pragma pop
static inline void merge_flush_func_00134080(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00134080 */

/* merge_units: begin func_001340B0 */
#pragma push /* merge_units */
void* Physical_GetPositionPtr(char* self) {
    return self + 16;
}

void cArray_cHumanPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* cArray_cHumanPtr_ConstIterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void cArray_cHumanPtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void* cObjList_cHumanPtr_GetList(char* self) {
    return self + 4;
}
static inline void merge_flush_func_001340B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001340B0 */

/* merge_units: begin func_00134110 */
#pragma push /* merge_units */
#pragma cplusplus on
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
static inline void merge_flush_func_00134110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00134110 */
