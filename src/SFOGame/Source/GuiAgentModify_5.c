/*
 * SFOGame/Source/GuiAgentModify: 6 files, 00340700-00340C00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00340700 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "member_dtor_chain.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop

#pragma cplusplus on

/* Deleting destructor that runs the member destructor. */
DEFINE_MEMBER_DTOR_CHAIN(func_00340700, func_00299360)
static inline void merge_flush_func_00340700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00340700 */

/* merge_units: begin func_00340770 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00340770, func_00299360)
static inline void merge_flush_func_00340770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00340770 */

/* merge_units: begin func_003407D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentModify.cc. Functions are named by address
 * until real names are known.
 */


Rel* func_003407D0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_003407D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003407D0 */

/* merge_units: begin func_003407F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_DIRECT_BASE_DTOR(func_003407F0, func_00299360)
static inline void merge_flush_func_003407F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003407F0 */

/* merge_units: begin func_00340850 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"

class Vis {
public:
    VPAD2(a) virtual void v2(); virtual void Show(); virtual void Hide();
};
struct Wid { char pad[0x44]; Vis* vis; };
typedef struct { __int128 q; char pad[0x10]; } Ent;
typedef struct { char pad[0xE0]; Ent e[1]; } Tbl;
struct Self {
    char pad0[0x8C];
    Tbl* tbl;
    char pad90[0x114 - 0x90];
    int idx[6];
    Wid* w[6];
    char pad144[0x14C - 0x144];
    Wid* grp[2];
};
extern "C" {
extern __int128 g_AgentPartCache;
extern __int128 D_0055DE00;
void GuiAgentModify_TattooPatchesLockout(Self* self);
}

static inline long KEq(__int128 b, __int128 a, __int128 m)
{
    __int128 t, r;
    asm {
        pand t, m, b
        pand r, m, a
        pceqw r, r, t
        ppach r, r, r
    }
    return r;
}

static inline long Match(Self* self, int k)
{
    return KEq(g_AgentPartCache, self->tbl->e[self->idx[k]].q, D_0055DE00);
}

void GuiAgentModify_TattooPatchesLockout(Self* self)
{
    int n = 0;
    if (Match(self, 0) == -1) self->w[0]->vis->Hide(); else { self->w[0]->vis->Show(); n++; }
    if (Match(self, 1) == -1) self->w[1]->vis->Hide(); else { self->w[1]->vis->Show(); n++; }
    if (Match(self, 2) == -1) self->w[2]->vis->Hide(); else { self->w[2]->vis->Show(); n++; }
    if (n) self->grp[0]->vis->Show(); else self->grp[0]->vis->Hide();
    n = 0;
    if (Match(self, 3) == -1) self->w[3]->vis->Hide(); else { self->w[3]->vis->Show(); n++; }
    if (Match(self, 4) == -1) self->w[4]->vis->Hide(); else { self->w[4]->vis->Show(); n++; }
    if (Match(self, 5) == -1) self->w[5]->vis->Hide(); else { self->w[5]->vis->Show(); n++; }
    if (n) self->grp[1]->vis->Show(); else self->grp[1]->vis->Hide();
}
static inline void merge_flush_func_00340850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00340850 */

/* merge_units: begin func_00340C00 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char g_AgentPartCache[];
#endif /* merge_units */
#define g_AgentPartCache ((char*)&g_AgentPartCache) /* merge_units */

extern char D_004B9ED0[];
extern char D_004B9EE8[];
extern void Monster_RestoreLockedPartsTex(void* a);
extern void cMotionManager_FlushUpdateList(void);
extern void* Gui_Manager(void);
extern int GuiManager_OpenGui(void* a, const char* b, const char* c);
extern void* Gui_Canvas(void);
extern void GuiCanvas_Transition(void* a, int b, int c);
/* Look up an entry and register it with `arg`. */
void GuiAgentModify_NextScreen(int arg)
{
    int entry;
    Monster_RestoreLockedPartsTex(g_AgentPartCache);
    cMotionManager_FlushUpdateList();
    entry = GuiManager_OpenGui(Gui_Manager(), D_004B9ED0, D_004B9EE8);
    GuiCanvas_Transition(Gui_Canvas(), arg, entry);
}
#undef g_AgentPartCache /* merge_units */
static inline void merge_flush_func_00340C00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00340C00 */
