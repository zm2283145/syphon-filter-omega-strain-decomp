/*
 * SFOGame/Source/map: 3 files, 0026BE80-0026C180
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0026BE80 */
#pragma push /* merge_units */
#include "types.h"
/* cMap_MapUserInterface: map screen stick input: the right stick's vertical
 * axis zooms (clamped to pi/12..pi/2), the left stick's vertical axis tilts
 * (clamped to D_0048B2A0..pi/4), and the map widget is told when the sticks
 * start or stop moving (events 16 / 17). */
typedef struct { float x, y; } V2_BE80;
typedef struct { int x, y; } I2_BE80; /* the sticks are cleared as words (sw zero); float stores make MW keep &v.y in a saved register */
extern float D_004FF070;
extern unsigned char D_004FF060;
extern float D_0048B2B0;
extern float D_0048B2A0;
void cJoyPad_GetStickPosition(void* pad, V2_BE80* a, V2_BE80* b, int n);
void* Gui_Canvas(void);
void GuiWidget_SendMessage(void* a, void* b, int kind, int v, int f);

void cMap_MapUserInterface(void* self, char* ply)
{
    V2_BE80 a, b, c, d;
    float lx, ly, rx, ry;
    ((I2_BE80*)&a)->x = 0;
    ((I2_BE80*)&a)->y = 0;
    ((I2_BE80*)&b)->x = 0;
    ((I2_BE80*)&b)->y = 0;
    cJoyPad_GetStickPosition(ply + 0x40, &a, &b, 0);
    lx = b.x;
    ly = b.y;
    ((I2_BE80*)&c)->x = 0;
    ((I2_BE80*)&c)->y = 0;
    ((I2_BE80*)&d)->x = 0;
    ((I2_BE80*)&d)->y = 0;
    cJoyPad_GetStickPosition(ply + 0x40, &c, &d, 0);
    ry = c.y;
    rx = c.x;
    if (ry > 0.0f) {
        D_004FF070 += 0.0004f * ry;
        if (D_004FF070 > 1.5707964f)
            D_004FF070 = 1.5707964f;
    }
    if (ry < 0.0f) {
        D_004FF070 += 0.0004f * ry;
        if (D_004FF070 < 0.2617994f)
            D_004FF070 = 0.2617994f;
    }
    if (ly < 0.0f) {
        D_0048B2B0 += 0.0001f * ly;
        if (D_0048B2B0 < D_0048B2A0)
            D_0048B2B0 = D_0048B2A0;
    }
    if (ly > 0.0f) {
        D_0048B2B0 += 0.0001f * ly;
        if (D_0048B2B0 > 0.7853982f)
            D_0048B2B0 = 0.7853982f;
    }
    if (0.0f == ry && 0.0f == ly && 0.0f == rx && 0.0f == lx) {
        if (D_004FF060) {
            GuiWidget_SendMessage(Gui_Canvas(), Gui_Canvas(), 17, 9, 0);
            D_004FF060 = 0;
        }
    } else if (!D_004FF060) {
        GuiWidget_SendMessage(Gui_Canvas(), Gui_Canvas(), 16, 9, 0);
        D_004FF060 = 1;
    }
}
static inline void merge_flush_func_0026BE80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026BE80 */

/* merge_units: begin func_0026C130 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

unsigned int D_0048B2A8[2] = { 0x3F490FDB, 0x0 };
#if 0 /* merge_units */
extern int D_004FF070;
#endif /* merge_units */
#define D_004FF070 (*(int*)&D_004FF070) /* merge_units */

extern int D_004FF074;
extern int D_004FF078;
extern int D_004FF07C;

void cMap_ResetCamera(Unk26C130* self) {
    D_004FF074 = 0;
    D_004FF078 = 0;
    D_004FF07C = 0;
    D_004FF070 = 0x3EB33333; /* 0.35f */
    D_0048B2B0 = (*(float*)D_0048B2A8);
    self->unk60 = 0;
    self->unk64 = 0;
    self->unk90 = 0;
    self->unk94 = 0;
}
#undef D_004FF070 /* merge_units */
static inline void merge_flush_func_0026C130(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026C130 */

/* merge_units: begin func_0026C180 */
#pragma push /* merge_units */
typedef struct LNode { struct LNode* prev; struct LNode* next; int data; } LNode;
typedef struct LIt { LNode* node; } LIt;
typedef struct LList { int count; LNode* last; LNode* first; } LList;
typedef struct Obj { char pad[0x24]; LList list; } Obj;

extern int cHudTargetManager_GetObjectiveTarget(Obj* o);
extern void cHudTargetManager_SetObjectiveTarget(Obj* o, int v);
extern void std_list_deleter_voidPtr_begin_void_2(LIt* out, LList* l);
extern LIt* std_list_cHudTargetInfoPtr_generic_iterator_1_ctor(LIt* out, LNode* n);
extern void std_list_cHudTargetInfoPtr_end_void(LIt* out, LList* l);
extern LIt* cConstLListIterator_cHudTargetInfoPtr_ctor(LIt* dst, LIt* src);
extern void std_list_cHudTargetInfoPtr_begin_void(LIt* out, LList* l);
extern void cMap_ObjectiveSelected(Obj** self);

int cMap_PreviousObjective(Obj** self) {
    LIt bc;
    LIt ec;
    LIt r;
    LIt a;
    LIt b;
    LIt t;
    LIt bs;
    LIt es;
    LList* l = &(*self)->list;
    LNode* n;
    if ((*self)->list.count == 0) return 0;
    if (!cHudTargetManager_GetObjectiveTarget(*self)) {
        a.node = l->first;
        b = a;
        cHudTargetManager_SetObjectiveTarget(*self, b.node->data);
    } else {
        if (l->count > 1) {
        std_list_deleter_voidPtr_begin_void_2(&t, l);
        std_list_cHudTargetInfoPtr_generic_iterator_1_ctor(&r, t.node);
        n = r.node;
        while (std_list_cHudTargetInfoPtr_end_void(&es, l), cConstLListIterator_cHudTargetInfoPtr_ctor(&ec, &es), n != ec.node) {
            if (n->data == cHudTargetManager_GetObjectiveTarget(*self)) {
                std_list_cHudTargetInfoPtr_begin_void(&bs, l);
                cConstLListIterator_cHudTargetInfoPtr_ctor(&bc, &bs);
                if (n == bc.node) {
                    cHudTargetManager_SetObjectiveTarget(*self, l->last->data);
                } else {
                    cHudTargetManager_SetObjectiveTarget(*self, n->prev->data);
                }
                break;
            }
            n = n->next;
        }
        } else {
            return 0;
        }
    }
    cMap_ObjectiveSelected(self);
    return 1;
}
static inline void merge_flush_func_0026C180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026C180 */
