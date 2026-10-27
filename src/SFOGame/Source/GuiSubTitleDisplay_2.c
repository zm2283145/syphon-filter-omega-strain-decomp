/*
 * SFOGame/Source/GuiSubTitleDisplay: 4 files, 00457FB0-00458030
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00457FB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiSubTitleDisplay.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int GuiWidget_onAdvanceTime(void* self, float dt);

int* std_list_deleter_TextAtom_generic_iterator_ctor(int* self, int value) {
    *self = value;
    return self;
}

void* std_list_deleter_TextAtom_tail(char* self) {
    return self + 4;
}

void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_12(void* self) {
    return self;
}

/* Update: calls the base update, then advances the timer at +0x54 by dt/30. */
int GuiSubTitleDisplay_onAdvanceTime(char* self, float dt) {
    int result = GuiWidget_onAdvanceTime(self, dt);

    *(float*)(self + 84) = *(float*)(self + 84) + dt / 30.0f;
    return result;
}
static inline void merge_flush_func_00457FB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00457FB0 */

/* merge_units: begin func_00458030 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* True when the queue at +0x6C/+0x70 is empty or its last entry is earlier than the time at +0x54. */
typedef struct S458030 {
    char pad[0x54];
    float t;
    char pad2[0x14];
    int n;
    float* arr;
} S458030;

#pragma opt_common_subs off

static inline float* End458030(S458030* s) { return s->arr + s->n; }

int GuiSubTitleDisplay_IsFinishedPlaying(S458030* s)
{
    return s->n == 0 || End458030(s)[-1] < s->t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00458030(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00458030 */

/* merge_units: begin func_00458080 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Release the owned record at +0xA0 (string member at +0x14) under the allocator guard, clear +0xA0/+0xA4. */
extern "C" {
void* String_Dtor(void* self, short flags);
void GuiWidget_onSleep(void* self);
}
struct O348AD0 { char pad[0x48]; char* aA0; int aA4; };
extern "C" void GuiSubTitleDisplay_onSleep(O348AD0* o)
{
    char* p;
    GuiWidget_onSleep(o);
    p = o->aA0;
    {
        AllocGuard guard;
        if (p) {
            char* s = p + 0x14;
            if (s)
                String_Dtor(s, 0);
        }
        cMemMan_Deallocate(0, p, "GuiSubTitleDisplay.cc", 0x15E);
    }
    o->aA0 = 0;

}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00458080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00458080 */

/* merge_units: begin func_00458140 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x10]; unsigned char b10; char pad2[0x47]; unsigned char b58; } C458;
typedef struct { char pad[0x3C]; float f3c; float f40; char pad2[4]; C458* f48; int f4c; char pad3[0x28]; int f78; } W458;
extern "C" {
extern void GuiWidget_onWake(W458*);
extern int Gui_Manager(void);
extern int GuiManager_GetFont(int, char*);
extern void* cMemMan_Allocate(int, int, char*, int);
extern char D_004C1EB0[];
extern char D_00587D70[];
extern C458* cTextArea_ctor(void*, int, int, int, int, int, char*);
extern int cFont_GetCharH(int);
}
extern "C" void GuiSubTitleDisplay_onWake(W458* w) {
    C458* obj;
    GuiWidget_onWake(w);
    w->f4c = GuiManager_GetFont(Gui_Manager(), "callout");
    {
        AllocGuard g;
        obj = (C458*)cMemMan_Allocate(0, 0x60, D_004C1EB0, 0x154);
    }
    if (obj) obj = cTextArea_ctor(obj, 0, 0, (int)w->f3c, (int)w->f40, w->f4c, D_00587D70);
    w->f48 = obj;
    w->f48->b10 = 0;
    w->f48->b58 = 1;
    w->f78 = (int)(w->f40 / (float)cFont_GetCharH(w->f4c));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00458140(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00458140 */
