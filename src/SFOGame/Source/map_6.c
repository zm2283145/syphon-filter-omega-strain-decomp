/*
 * SFOGame/Source/map: 4 files, 0026D620-0026D720
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0026D620 */
#pragma push /* merge_units */
#include "types.h"
#include "vc_copy.h"

#pragma cplusplus on
struct Q_26D620 { float a, b, c, d; Q_26D620& operator=(const Q_26D620& o) { Q_26D620* pd = this; const Q_26D620* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; } } __attribute__((aligned(16)));
struct R2_26D620 { char pad[0x68]; int x68; };
struct R_26D620 { char pad[8]; R2_26D620* x8; };
struct S_26D620 {
    int x0;
    int x4;
    int x8;
    char padC[0x54];
    int x60;
    char pad64[0xC];
    Q_26D620 x70;
    Q_26D620 x80;
    float x90;
    float x94;
};
extern "C" {
R_26D620* cHudTargetManager_GetObjectiveTarget(int a);
void cMap_UpdateModelPerspective(S_26D620* s, float t);
void cInterface_NextFrame(int h, float t);
void cMap_NextFrame(S_26D620* s, float dt);
}
void cMap_NextFrame(S_26D620* s, float dt)
{
    if (s->x94 > 0.0f) {
        s->x94 -= dt;
        if (s->x94 <= 0.0f) {
            R_26D620* r = cHudTargetManager_GetObjectiveTarget(s->x0);
            if (r && r->x8) {
                s->x60 = r->x8->x68;
                s->x80 = s->x70;
                s->x90 = 0.0f;
            }
            s->x94 = 0.0f;
        }
    }
    cMap_UpdateModelPerspective(s, dt);
    cInterface_NextFrame(s->x8, dt);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026D620(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026D620 */

/* merge_units: begin func_0026D6D0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int c; } C_D6D0;
typedef struct { char pad[0x30]; C_D6D0* p30; } B_D6D0;
typedef struct { char pad[0x60]; int t60; int t64; char pad68[8]; __int128 q70; __int128 q80; char pad90[4]; int x94; } A_D6D0;
extern B_D6D0* g_LocalPlayer;
static inline int* ref_D6D0(C_D6D0* c) { return &c->c; }
#pragma push
#pragma peephole off
#pragma opt_propagation off
void cMap_StopSeekCountdown(A_D6D0* a) {
    __int128* s; __int128* d;
    a->x94 = 0;
    d = &a->q80; s = &a->q70;
    a->t64 = a->t60;
    *d = *s;
    { int* pc = &g_LocalPlayer->p30->c; a->t60 = *pc; }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026D6D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026D6D0 */

/* merge_units: begin func_0026D710 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "map_types.h"

void cMap_StartSeekCountdown(MapView* self) {
    self->unk94 = 0.25f;
}
static inline void merge_flush_func_0026D710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026D710 */

/* merge_units: begin func_0026D720 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Cam26D720 {
    char pad[0x100];
    char x100[0x504];
    unsigned char x604;
    char pad605[0xF];
    float x614;
    float x618;
    float x61C;
    float x620;
    float x624;
};

struct Self26D720 {
    char pad[8];
    int* x8;
    void* xC;
};

extern "C" {
extern Cam26D720* g_Hud;
extern float D_004FF030;
extern float D_004FF038;
extern float D_004FF040;
extern float D_004FF048;
extern float D_004FF050;
extern unsigned char D_004FF060;
void cIE_GOBJ_AnimateOff(void* p);
void cMap_ClearCallouts(Self26D720* self);
void cInterfaceModel_Activate(int a, int b, int c);
void cInfoBar_ClearPriorityMessages(void* p, int a, int b);
void* Gui_Canvas(void);
void GuiWidget_SendMessage(void* a, void* b, int c, int d, int e);
}

inline void SetA_26D720(Cam26D720* c, float a, float b) { c->x620 = a; c->x624 = b; }
inline void SetB_26D720(Cam26D720* c, float x, float y, float z) { c->x614 = x; c->x618 = y; c->x61C = z; }
extern "C" void cMap_Deactivate(Self26D720* self) {
    Cam26D720* cam;
    if (self->xC) {
        cIE_GOBJ_AnimateOff(self->xC);
        self->xC = 0;
    }
    cMap_ClearCallouts(self);
    cInterfaceModel_Activate(*self->x8, 0, 0);
    cam = g_Hud;
    SetA_26D720(cam, D_004FF030, D_004FF038);
    SetB_26D720(cam, D_004FF040, D_004FF048, D_004FF050);
    cam->x604 = 0;
    cInfoBar_ClearPriorityMessages(cam->x100, 2, 1);
    if (D_004FF060) {
        void* a = Gui_Canvas();
        GuiWidget_SendMessage(a, Gui_Canvas(), 0x11, 9, 0);
        D_004FF060 = 0;
    }
}
static inline void merge_flush_func_0026D720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026D720 */
