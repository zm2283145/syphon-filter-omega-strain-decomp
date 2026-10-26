/*
 * main/hotbox: range (2 files, 00171260-001714C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00171260 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ent171260 {
    char pad0[0x2C];
    unsigned char f2C;
    unsigned char f2D;
    unsigned char f2E;
    char pad2F[0x90 - 0x2F];
    int type;
    char pad94[8];
    int prio;
    bool Usable() { return f2D && f2C && !f2E; }
};
struct N171260 { int m0; N171260* next; Ent171260* data; };
struct Own171260 { char pad[0x320C]; int state; };
struct Hb171260 { char pad[0x20]; Own171260* owner; float f24; char list[4]; };
extern "C" {
void List_Begin(int* out, void* list);
void std_list_cHotboxPtr_generic_iterator_ctor(N171260** out, int* in);
void std_list_cHotboxPtr_end_void(int* out, void* list);
void cLListIterator_cHotboxPtr_ctor_listR(N171260** out, int* in);
}

extern "C" Ent171260* Hotbox_SelectInteraction(Hb171260* h, int mode)
{
    Ent171260* best = 0;
    if (h->f24 <= 0.0f) {
        N171260* e1;
        N171260* e2;
        N171260* it;
        int t0;
        int t1;
        int t2;
        int bp;
        N171260* n;
        List_Begin(&t0, h->list);
        std_list_cHotboxPtr_generic_iterator_ctor(&it, &t0);
        n = it;
        bp = -1;
        if (mode) {
            while (std_list_cHotboxPtr_end_void(&t1, h->list), cLListIterator_cHotboxPtr_ctor_listR(&e1, &t1), n != e1) {
                Ent171260* o = n->data;
                n = n->next;
                if (o->Usable() && o->type == 0x12 && bp < o->prio) {
                    bp = o->prio;
                    best = o;
                }
            }
        } else {
            while (std_list_cHotboxPtr_end_void(&t2, h->list), cLListIterator_cHotboxPtr_ctor_listR(&e2, &t2), n != e2) {
                Ent171260* o = n->data;
                n = n->next;
                if (o->Usable() && o->type == 0xC) {
                    int s = h->owner->state;
                    if (!(s != 8 && s != 7 && s != 0xA))
                        return 0;
                }
                if (o->Usable()) {
                    int ty = o->type;
                    if ((ty == 8 || ty == 0x12 || ty == 0xC) && bp < o->prio) {
                        bp = o->prio;
                        best = o;
                    }
                }
            }
        }
    }
    return best;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00171260(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00171260 */

/* merge_units: begin func_001714C0 */
#pragma push /* merge_units */
#pragma cplusplus on
class IObj_f4;

class IObj_f4 { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void Interact(void*); char pad4[0x8C]; int kind; };
typedef struct { void* vt; char base[0x1C]; unsigned char mode; char pad21[3]; int action; int kind; int zero; void* actor; char pad34[4]; } IMsg_f4;
struct Act_f4 { char pad[0x20]; void* actor; float timer; };
extern "C" unsigned char g_IsMultiplayer;
extern "C" char D_004EE698[];
extern "C" char D_004D9940[];
#if 0 /* merge_units */
extern "C" IObj_f4* Hotbox_SelectInteraction(Act_f4*, int);
#endif /* merge_units */
#define Hotbox_SelectInteraction(a0, a1) ((IObj_f4 *)Hotbox_SelectInteraction((Hb171260 *)(a0), (a1))) /* merge_units */

extern "C" void Event_Construct(void*, void*);
extern "C" void Event_Send(void*, void*, int);
extern "C" void cMessage_dtor(void*, int);
extern "C" int Actor_TryObjectInteraction(Act_f4* self, void* who, int setTimer, int id)
{
    IObj_f4* obj = Hotbox_SelectInteraction(self, id);
    if (obj) {
        if (g_IsMultiplayer) {
            void* actor;
            int kind = obj->kind;
            if (kind == 12) {
                actor = self->actor;
                IMsg_f4 msg;
                Event_Construct(&msg, D_004EE698);
                msg.vt = D_004D9940;
                msg.kind = kind;
                msg.action = 3;
                msg.actor = actor;
                msg.mode = 2;
                msg.zero = 0;
                Event_Send(&msg, obj, 0);
                msg.vt = D_004D9940;
                cMessage_dtor(&msg, 0);
            } else {
                obj->Interact(who);
            }
        } else {
            obj->Interact(who);
        }
        if (setTimer) {
            self->timer = 10.0f;
        }
    }
    return obj != 0;
}
#undef Hotbox_SelectInteraction /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001714C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001714C0 */
