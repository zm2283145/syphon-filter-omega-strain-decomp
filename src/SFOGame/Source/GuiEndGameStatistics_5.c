/*
 * SFOGame/Source/GuiEndGameStatistics: 6 files, 00463310-004637B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00463310 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of Manager: only the slots used here are named (vtable offset in comments). */
struct Manager {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Method68(int value); /* +0x68 */
};

typedef struct Screen { char pad[0x250]; int unk250; /* +0x250 */ } Screen;

extern char D_004C2780[];
extern char D_004C2798[];
extern "C" Manager* Gui_Canvas(void);
extern "C" void* Gui_Manager(void);
extern "C" void* GuiManager_OpenGui(void* root, const char* a, const char* b);
extern "C" void GuiCanvas_Transition(Manager* mgr, Screen* screen, void* item);

/* Passes +0x250 to the manager's virtual +0x68, looks up an item by the two names and hands it to GuiCanvas_Transition. */
extern "C" void GuiEndGameStatistics_NextScreen(Screen* self)
{
    void* item;
    Gui_Canvas()->Method68(self->unk250);
    item = GuiManager_OpenGui(Gui_Manager(), D_004C2780, D_004C2798);
    GuiCanvas_Transition(Gui_Canvas(), self, item);
}
static inline void merge_flush_func_00463310(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00463310 */

/* merge_units: begin func_00463390 */
#pragma push /* merge_units */
typedef struct {
    char voice[8];
    int duration;
} Line_463390;

typedef struct {
    char pad0[0xB70];
    unsigned char bB70;
    char padB71[3];
    unsigned char bB74;
} Agent_463390;

typedef struct {
    int unk0;
    int count;
    int* data;
    unsigned char owned;
} IntVec_463390;

typedef struct {
    char pad0[0x254];
    unsigned char b254;
    unsigned char b255;
    char pad256[0x260 - 0x256];
    char lines[0xC];        /* 0x260 */
} Self_463390;

extern char g_Game[];
extern unsigned char g_IsMultiplayer;
extern char D_004C27A0[];
extern char D_004C27A8[];
extern char D_004C2610[];
extern char D_004C2608[];
extern char D_004C25F8[];
extern int D_00497BD8[];
extern Agent_463390* cGameSystem_GetAgentData(void* mgr, int idx);
extern int cAgentData_GetStat(Agent_463390* agent, int stat);
extern int sprintf(char* buf, const char* fmt, ...);
extern Line_463390* cQuipList_tQuip_ctor(Line_463390* line, char* voice, int duration);
extern void cArray_tQuip_PushBackActual(void* vec, Line_463390* line);
extern void std_vector_int_ctor_void(IntVec_463390* v);
extern void std_vector_int_push_back(IntVec_463390* v, int* value);
extern int func_00460B50(IntVec_463390* v);
extern int* func_00460B40(IntVec_463390* v, int i);
extern void cQuipList_QueueUp(void* vec, char* name, float seconds);
extern void func_0013A040(IntVec_463390* v, int flags);

static inline int Pct_463390(Agent_463390* ag, int total, int part)
{
    int r = 0;
    int d = cAgentData_GetStat(ag, total);
    int v = cAgentData_GetStat(ag, part);
    if (d) r = v * 100 / d;
    return r;
}

void GuiEndGameStatistics_PlayQuips(Self_463390* self)
{
    char buf[32];
    IntVec_463390 list;
    char name[32];
    int n;

    if (g_IsMultiplayer) {
        int bestA = 0;
        int bestB = 0;
        int idxA = -1;
        int idxB = -1;
        int i;
        for (i = 0; i < 4; i++) {
            Agent_463390* a = cGameSystem_GetAgentData(g_Game, i);
            if (a->bB70 && a->bB74) {
                int pa = Pct_463390(cGameSystem_GetAgentData(g_Game, i), 0x1D, 0x1E);
                int pb = Pct_463390(cGameSystem_GetAgentData(g_Game, i), 0x1B, 0x1C);
                if (bestA < pa) {
                    bestA = pa;
                    idxA = i;
                }
                if (bestB < pb) {
                    bestB = pb;
                    idxB = i;
                }
            }
        }
        if (!self->b254) {
            self->b254 = 1;
            if (-1 < idxA) {
                Line_463390 line;
                sprintf(buf, D_004C27A0, idxA + 1);
                cQuipList_tQuip_ctor(&line, buf, 0x1E);
                cArray_tQuip_PushBackActual(self->lines, &line);
            }
        }
        if (!self->b255) {
            self->b255 = 1;
            if (-1 < idxB) {
                Line_463390 line;
                sprintf(buf, D_004C27A8, idxB + 1);
                cQuipList_tQuip_ctor(&line, buf, 0x1E);
                cArray_tQuip_PushBackActual(self->lines, &line);
            }
        }
    }
    std_vector_int_ctor_void(&list);
    list.owned = 1;
    if (g_IsMultiplayer) {
        int i;
        for (i = 0; i < 4; i++) {
            Agent_463390* a = cGameSystem_GetAgentData(g_Game, i);
            if (a->bB70 && a->bB74 && !cAgentData_GetStat(cGameSystem_GetAgentData(g_Game, i), 0x1A))
                std_vector_int_push_back(&list, &i);
        }
    } else {
        if (cGameSystem_GetAgentData(g_Game, -1)->bB74 && !cAgentData_GetStat(cGameSystem_GetAgentData(g_Game, -1), 0x1A))
            std_vector_int_push_back(&list, D_00497BD8);
    }
    n = func_00460B50(&list);
    if (n) {
        if (n > 1) {
            int j;
            for (j = 0; j < func_00460B50(&list); j++) {
                sprintf(name, D_004C2610, *func_00460B40(&list, j) + 1);
                cQuipList_QueueUp(self->lines, name, 0.0f);
            }
            sprintf(name, D_004C2608, 5);
            cQuipList_QueueUp(self->lines, name, 1.0f);
        } else {
            sprintf(name, D_004C25F8, 5, *func_00460B40(&list, 0) + 1);
            cQuipList_QueueUp(self->lines, name, 1.0f);
        }
    }
    func_0013A040(&list, -1);
}
static inline void merge_flush_func_00463390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00463390 */

/* merge_units: begin func_004637B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */


extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* Appends one value at the end of the vector. */
int func_004637B0(PtrVec* v, int value) {
    int count;
    int* data;

    count = v->count;
    data = v->data;
    return std_vector_pod_int_insert(v, data + count, 1, value);
}
static inline void merge_flush_func_004637B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004637B0 */

/* merge_units: begin func_004637D0 */
#pragma push /* merge_units */
#include "fam5_timed_retry.h"
extern void GuiScoresEquip_onAdvanceTime(char*, float);
DEFINE_TIMED_RETRY(GuiEndGameStatistics_onAdvanceTime, 0x410, 0x260, GuiScoresEquip_onAdvanceTime)
static inline void merge_flush_func_004637D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004637D0 */

/* merge_units: begin func_004638A0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* cGameSystem_GetAgentData(void* registry, int agent);
#endif /* merge_units */
#define cGameSystem_GetAgentData(a0, a1) ((void *)cGameSystem_GetAgentData((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int cAgentData_GetStat(void* data, int stat);
#endif /* merge_units */
#define cAgentData_GetStat(a0, a1) (cAgentData_GetStat((Agent_463390 *)(a0), (a1))) /* merge_units */


/* Returns stat `part` as a percentage of stat `total` for the agent (0 when total is 0). */
int StatPercent(int agent, int part, int total) {
    void* data = cGameSystem_GetAgentData(g_Game, agent);
    int percent = 0;
    int totalValue = cAgentData_GetStat(data, total);
    int partValue = cAgentData_GetStat(data, part);
    if (totalValue) {
        percent = partValue * 100 / totalValue;
    }
    return percent;
}
#undef cGameSystem_GetAgentData /* merge_units */
#undef cAgentData_GetStat /* merge_units */
static inline void merge_flush_func_004638A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004638A0 */

/* merge_units: begin func_00463940 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

extern GuiWidget* GuiWidget_FindFirstFocus(GuiWidget* self);

/* Hides the widget returned by GuiWidget_FindFirstFocus unless it is this widget. */
GuiWidget* GuiEndGameStatistics_FindFirstFocus(GuiWidget* self) {
    GuiWidget* other;

    other = GuiWidget_FindFirstFocus(self);
    if (other != self) {
        other->flags &= ~0x2;
    }
    return self;
}
static inline void merge_flush_func_00463940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00463940 */
