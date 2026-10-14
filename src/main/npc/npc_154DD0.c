/*
 * main/npc: range (2 files, 00154DD0-001552B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00154DD0 */
#pragma push /* merge_units */
/* NpcAi_ModeSearch: search-mode message handler (look around, walk the search route, resume) */
#pragma cplusplus on
struct Bits60 { unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char hi : 4; };
struct Route_S { char pad[0x4C]; int f4C; char pad50[0xC]; int f5C; Bits60 bits60; };
struct Target_S { char pad[0x18]; int f18; char pad1C[4]; Bits60 bits20; };
struct Obj_S { char pad[0x4C]; int f4C; };
struct Slot_S { int f0; unsigned char b4; char pad5[0xF]; };
struct Self_S {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void LookFor(float t, int n); virtual void Resume();
    char pad4[0x2C]; int f30; char pad34[0x10]; char brain[0x28]; float aggression; char pad70[0x30];
    int fA0; char padA4[0x18]; int bitsBC[8]; int fDC_pad; int fE0; int fE4; int fE8; int fEC;
    char padF0[0x68]; unsigned char b158; char pad159[7]; int f160; unsigned char b164; char pad165;
    unsigned char b166; char pad167; unsigned char b168; char pad169[0xF]; Slot_S slots[1];
    char padSlots[0x1AC - 0x178 - 0x14]; Target_S* target; Route_S* route; char pad1B4[0x1C]; Obj_S* facing;
};
struct Ev_S { char pad[0x24]; unsigned char kind; char pad25[3]; int f28; };
extern "C" {
extern int D_004EE550;
extern int D_004ED9B8;
extern int D_004EA770;
extern char D_004FFB50[];
extern char g_NpcRouteMgr[];
int* Event_GetType(Ev_S* ev);
void* Service_Lookup(void* a, void* b);
int NpcRoute_IsHeadPending(void* svc, int id);
void NpcPath_RequestRoute(Route_S* r, Target_S* t, int node);
void NpcAi_ApproachSearch(Self_S* self);
void NpcAi_RequestMode(void* brain, int mode, int arg);
void NpcAi_SetMovementState(Self_S* self, int a, int b);
Obj_S* NpcLook_FindFacingObject(Self_S* self);
void NpcLook_Begin(Self_S* self, int a, int b, int c);
void NpcLook_AddNodePoints(Self_S* self, int node, int a, int b, float t);
}

static inline bool Idle(Self_S* self) { return !self->b166; }
static inline bool Reached(Target_S* t) { return t->bits20.b0 && t->bits20.b2; }
static inline bool Visited(Self_S* self, int i)
{
    bool r = 1;
    if (i >= 0)
        r = (self->bitsBC[i / 32] >> (i & 31)) & 1;
    return r;
}

extern "C" unsigned char NpcAi_ModeSearch(Self_S* self, Ev_S* ev)
{
    unsigned char handled = 0;
    int t = *Event_GetType(ev);
    if (t == D_004EE550) {
        unsigned char k = ev->kind;
        if (k == 3) {
            if (self->fEC == 2) {
                self->fE8 = 1;
                if (Idle(self)) {
                    self->fEC = 0;
                    self->fE8 = -1;
                    if (self->fA0 < 100) {
                        if (self->route->bits60.b3) {
                            Obj_S* o;
                            self->facing = 0;
                            o = NpcLook_FindFacingObject(self);
                            if (o && o->f4C == D_004EA770)
                                self->facing = o;
                            NpcAi_RequestMode(self->brain, 0, 0);
                        } else {
                            self->Resume();
                        }
                    }
                }
            }
        } else if (k == 4) {
            if (Reached(self->target)) {
                NpcAi_SetMovementState(self, 0, 20);
                if (self->aggression < 0.9f)
                    NpcAi_RequestMode(self->brain, 3, 0);
                else
                    NpcAi_RequestMode(self->brain, 4, 0);
            }
        } else if (k == 7) {
            NpcAi_RequestMode(self->brain, 1, 0);
        } else if (k == 0) {
            if (Reached(self->target)) {
                if (self->aggression < 0.9f)
                    NpcAi_RequestMode(self->brain, 3, 0);
                else
                    NpcAi_RequestMode(self->brain, 4, 0);
            } else {
                self->fE8 = -1;
                self->fEC = 0;
                self->fE0 = -1;
                self->fE4 = -1;
                if (self->route->f5C >= 0) {
                    int node;
                    Target_S* t = self->target;
                    node = t->f18;
                    if (Visited(self, node)) {
                        if (self->b158) {
                            void* svc = Service_Lookup(D_004FFB50, g_NpcRouteMgr);
                            if (node >= 0 && !NpcRoute_IsHeadPending(svc, self->f30))
                                NpcPath_RequestRoute(self->route, t, node);
                        }
                    } else {
                        NpcAi_ApproachSearch(self);
                    }
                }
            }
            self->fEC = 0;
            handled = 1;
        } else if (k == 1) {
            if (self->fEC == 2) {
                if (self->slots[self->b164].f0 < 21) {
                    int* t = &self->slots[self->b164].f0;
                    if (*t < 21) { self->slots[self->b164].b4 = 0; *t = 0; }
                    self->b166 = 0;
                    self->f160 = 0;
                    if (self->b168)
                        self->Resume();
                }
            }
        }
    } else {
      int t2 = *Event_GetType(ev);
      if (t2 == D_004ED9B8) {
        unsigned char k = ev->kind;
        if (k == 6) {
            self->fE8 = 1;
            self->fEC = 2;
            NpcLook_Begin(self, 1, 1, 20);
            NpcLook_AddNodePoints(self, self->route->f5C, -1, -1, 3.0f);
        } else if (k == 5) {
            if (self->fEC == 1) {
                int n = self->route->f4C;
                if (n >= 0) {
                    self->fE8 = 1;
                    self->fEC = 2;
                    self->LookFor(10.0f, 10);
                    NpcLook_Begin(self, 1, 1, 20);
                    NpcLook_AddNodePoints(self, self->route->f5C, n, -1, 2.0f);
                } else {
                    self->fEC = 0;
                }
            }
        } else if (k == 7) {
            if (ev->f28 == 10 && self->fEC == 0)
                self->fEC = 1;
        }
      }
    }
    return handled;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00154DD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00154DD0 */

/* merge_units: begin func_001552B0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int serial; char pad10[0x3C]; int type; } Tgt_552B0;
typedef struct { Tgt_552B0* target; int serial; } Hdl_552B0;
typedef struct { char pad[0x40]; Hdl_552B0 h; } Ai_552B0;
typedef struct { char pad[0x158]; unsigned char f158; char pad159[0x53]; Ai_552B0* ai; } Npc_552B0;
extern int D_0049D010;
extern Tgt_552B0* ActorRef_Copy(Hdl_552B0* h);
unsigned char NpcAlert_SearchAllowed(Npc_552B0* self)
{
    unsigned char r = 1;
    unsigned char ok;
    int isNull;
    Tgt_552B0* t;
    Ai_552B0* ai;
    if (!self->f158)
        r = 0;
    ai = self->ai;
    t = ai->h.target;
    isNull = !t;
    ok = 1;
    if (!isNull)
        if (t->serial != ai->h.serial)
            ok = 0;
    if (ok ? t : 0) {
        Tgt_552B0* p = ActorRef_Copy(&ai->h);
        if (p->type != D_0049D010)
            r = 0;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001552B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001552B0 */
