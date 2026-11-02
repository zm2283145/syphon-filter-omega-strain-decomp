/*
 * SFOGame/Source/hotbox: 8 files, 00170160-00170650
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00170160 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(e, 0x24); MP_I(b, 0xC) = MP_I(e, 0x28); MP_I(b, 0x10) = MP_I(e, 0x2C); MP_I(b, 0x14) = MP_I(MP_P(e, 0x30), 0xC);

DEFINE_MESSAGE_PACK(cHotboxMsg_Pack, 0x18, D_004EE6A0, PACK_BODY)
static inline void merge_flush_func_00170160(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00170160 */

/* merge_units: begin func_00170200 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { int f0; int f4; int f8; int fC; int f10; int f14; } Pk70200;
typedef struct { void* vt; char p4[0x20]; int f24; int f28; int f2C; void* f30; } Msg70200;
typedef struct { char p0[0x24]; unsigned char action; } Hb70200;
typedef struct { char p0[0x98]; int f98; } Obj70200;
extern "C" {
extern unsigned char D_005723C8;
extern unsigned char D_005721D0;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_004EE698[], D_004D9940[];
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg70200* e, void* type);
#endif /* merge_units */
void cMessage_ctor_cMessageNameR(void* msg, void* type); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

extern Obj70200* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
extern void QueueMessage_cMessageR_cSystemP_int_int(Msg70200*, void*, int, int);
#if 0 /* merge_units */
extern void cMessage_dtor(Msg70200*, int);
#endif /* merge_units */
void cMessage_dtor(void* msg, int flags); /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

}
#pragma define_section GUARD_70200_DTOR ".dtors_drop" far_absolute RX
struct Guard_70200 {
    Guard_70200() { if (!D_005723C8) D_005723C8 = 1; }
    __declspec(weak) __declspec(GUARD_70200_DTOR) ~Guard_70200() { D_005723C8 = 0; }
};
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" int cHotboxMsg_HotBoxMsgCallback(int a0, int a1, int a2, Pk70200* arg) {
    Guard_70200 g;
    if (D_005721D0) {
        Msg70200 msg;
        int id1;
        int id0;
        Obj70200* obj;
        Pk70200* p = arg;
        Msg70200* m;
        m = &msg;
        cMessage_ctor_cMessageNameR(m, D_004EE698);
        msg.vt = D_004D9940;
        msg.f24 = p->f8;
        msg.f28 = p->fC;
        msg.f2C = p->f10;
        id0 = p->f14;
        m->f30 = nGobjManager_LookupGOBJ_cObjectIdR(&id0);
        id1 = p->f4;
        obj = nGobjManager_LookupGOBJ_cObjectIdR(&id1);
        if (obj) {
            QueueMessage_cMessageR_cSystemP_int_int(&msg, obj, 0, 0);
            if (g_IsMultiplayer ? D_005721C0 : 1) {
                int act = (unsigned char)msg.f24;
                if (act == 0) {
                    obj->f98++;
                    if (obj->f98 > 3) obj->f98 = 3;
                } else if (act == 2) {
                    obj->f98--;
                    if (obj->f98 < 0) obj->f98 = 0;
                }
            }
        }
        msg.vt = D_004D9940;
        cMessage_dtor(&msg, 0);
    }
    return 0x18;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00170200(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00170200 */

/* merge_units: begin func_00170360 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int idC; int id10; char pad14[0x7C]; int f90; } Obj_0360;
int cNetObj_AddSystem(int, int, Obj_0360*);
#if 0 /* merge_units */
Obj_0360* cHotboxMan_CreateInteractBox(int, int, int, int);
#endif /* merge_units */
int cHotboxMan_CreateInteractBox(void* owner, void* gobj, int a2, int a3); /* merge_units */
#define cHotboxMan_CreateInteractBox(a0, a1, a2, a3) ((Obj_0360 *)cHotboxMan_CreateInteractBox((void *)(a0), (void *)(a1), (a2), (a3))) /* merge_units */

int NetGetMyClientIndex(int*, int);
int NetGetPeerToPeerHostClientIndex(int, int*);
extern int D_00494178;
extern int g_HotboxTracker;
extern int D_005721A8;
#pragma inline_depth(10)
static inline int LocalId_0360(void)
{
    int r;
    int a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */
    if (g_IsMultiplayer) {
        if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
        r = D_00494178;
    } else r = 0;
    return r;
}
static inline int NetId_0360(void)
{
    int id;
    int ok = g_IsMultiplayer ? D_005721C0 : 1;
    if (ok) {
        id = LocalId_0360();
    } else {
        int tmp[1];
        NetGetPeerToPeerHostClientIndex(D_005721A8, tmp);
        id = tmp[0];
    }
    return id;
}
void MakeNPCNetInteractable(int arg0, int* arg1)
{
    Obj_0360* o = cHotboxMan_CreateInteractBox(g_HotboxTracker, arg0, 1, 0);
    o->idC = *arg1;
    o->id10 = *arg1;
    if (g_IsMultiplayer) {
        int t = o->id10;
        cNetObj_AddSystem(t, NetId_0360(), o);
    }
    o->f90 = 3;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00170360(void) {}
#undef cHotboxMan_CreateInteractBox /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00170360 */

/* merge_units: begin func_00170460 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int id; char pad10[0x80]; int mode; } T_0460;
typedef struct { char pad[0xC]; int id; } O_0460;
typedef struct { char pad[0x30]; O_0460* obj; } S_0460;
#if 0 /* merge_units */
extern void* g_HotboxTracker;
#endif /* merge_units */
#define g_HotboxTracker (*(void **)&g_HotboxTracker) /* merge_units */



extern char g_RuntimeHotboxes[];
#if 0 /* merge_units */
T_0460* cHotboxMan_CreateInteractBox(void* mgr, O_0460* obj, int a, int b);
#endif /* merge_units */
#define cHotboxMan_CreateInteractBox(a0, a1, a2, a3) ((T_0460 *)cHotboxMan_CreateInteractBox((a0), (void *)(a1), (a2), (a3))) /* merge_units */



#if 0 /* merge_units */
void std_vector_cHotboxPtr_push_back(void* list, T_0460** pt);
#endif /* merge_units */
int std_vector_cHotboxPtr_push_back(); /* merge_units */


void cNetNPCMsgs_SendMessage(O_0460* obj, int type, int size, int a, int b, int c, int d);
T_0460* Global_MakeNPCInteractable(S_0460* self)
{
    T_0460* t = cHotboxMan_CreateInteractBox(g_HotboxTracker, self->obj, 1, 0);
    t->mode = 3;
    std_vector_cHotboxPtr_push_back(g_RuntimeHotboxes, &t);
    if (g_IsMultiplayer)
        cNetNPCMsgs_SendMessage(self->obj, 0x2A, 4, self->obj->id, t->id, 0, 0);
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00170460(void) {}
#undef g_HotboxTracker /* merge_units */
#undef cHotboxMan_CreateInteractBox /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00170460 */

/* merge_units: begin func_00170500 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "hotbox_types.h"

#if 0 /* merge_units */
extern PtrVec g_RuntimeHotboxes;  /* list of created hotboxes */
#endif /* merge_units */
#define g_RuntimeHotboxes (*(PtrVec*)&g_RuntimeHotboxes) /* merge_units */


#if 0 /* merge_units */
extern void* g_HotboxTracker;
#endif /* merge_units */
#define g_HotboxTracker (*(void **)&g_HotboxTracker) /* merge_units */


extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int* value);
extern int cHotboxMan_CreateInteractBox(void* owner, void* gobj, int a2, int a3);


/* push_back on a pointer vector. */
int std_vector_cHotboxPtr_push_back(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

/* Creates a hotbox for a game object and records it in g_RuntimeHotboxes. */
int Global_MakeGOBJInteractable(void* gobj) {
    int hotbox = cHotboxMan_CreateInteractBox(g_HotboxTracker, gobj, 0, 0);

    std_vector_cHotboxPtr_push_back(&g_RuntimeHotboxes, &hotbox);
    return hotbox;
}
#undef g_RuntimeHotboxes /* merge_units */
#undef g_HotboxTracker /* merge_units */
static inline void merge_flush_func_00170500(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00170500 */

/* merge_units: begin func_00170570 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Eq_0570 {};
struct Pred_0570 { Eq_0570 op; int* ref; Pred_0570(const Eq_0570& e, int* r) : op(e), ref(r) {} };
struct M_0570 { char pad[0x28]; char list[4]; };
extern "C" {
extern char g_HotboxList[];

extern int D_004EE6E4;
#if 0 /* merge_units */
extern M_0570* g_HotboxTracker;
#endif /* merge_units */
#define g_HotboxTracker (*(M_0570 **)&g_HotboxTracker) /* merge_units */



void std_list_imp_voidPtr_remove_if(void* list, Pred_0570 p);
#if 0 /* merge_units */
int* func_00170650(void* v, int i);
#endif /* merge_units */
int* func_00170650(PtrVec* v, int i); /* merge_units */
#define func_00170650(a0, a1) (func_00170650((PtrVec *)(a0), (a1))) /* merge_units */

}
extern "C" void ResetInteractBoxes(void)
{
    int key;
    Eq_0570 e1;
    Eq_0570 e2;
    M_0570* mgr = g_HotboxTracker;
    int i;
    for (i = 0; i < D_004EE6E4; i++) {
        key = *func_00170650(g_RuntimeHotboxes, i);
        std_list_imp_voidPtr_remove_if(g_HotboxList, Pred_0570(e1, &key));
        std_list_imp_voidPtr_remove_if(mgr->list, Pred_0570(e2, &key));
    }
    D_004EE6E4 = 0;
}
#undef g_HotboxTracker /* merge_units */
#undef func_00170650 /* merge_units */
static inline void merge_flush_func_00170570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00170570 */

/* merge_units: begin func_00170650 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int* func_00170650(PtrVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_00170650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00170650 */

/* merge_units: begin func_00170660 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "sfo_common_types.h"
#include "cmessage.h"
#include "vslot_pad.h"
union TrackerIter { HotboxListNode* p; };
struct HotMsg { CMSG_HEADER; int action; int code; int value; int who; };
struct HotboxV { VPAD32(a) VPAD32(b) VPAD2(c) virtual int Test(void*); };
extern "C" {
void std_list_deleter_voidPtr_erase_listdeleter(void*,void*,void*);
void std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(void*,void*);
void std_list_cHotboxPtr_push_back(void*,void*);
void cLListIterator_cHotboxPtr_ctor_cLListIteratorR(void*,void*);
int opNe_cLListIteratorR_cLListIteratorR_2(void*,void*);
void cLList_cHotboxPtr_End(void*,void*);
void cLListIterator_cHotboxPtr_opInc(void*);
int* cLListIterator_cHotboxPtr_opMul(void*);
void cLListIterator_cHotboxPtr_opAssign(void*,void*);
void cLList_cHotboxPtr_Begin(void*,void*);
void cLListIterator_cHotboxPtr_ctor_void(void*);
void std_list_cHotboxPtr_generic_iterator_ctor(void*,void*);
void std_list_cHotboxPtr_generic_iterator_opCast(void*,void*);
void std_list_cHotboxPtr_begin(void*,void*);
void cLListIterator_cHotboxPtr_ctor_listR(void*,void*);
void std_list_cHotboxPtr_end_void(void*,void*);
extern char D_004D9940[],g_HotboxList[],D_004EE698[];
extern unsigned char D_005721C0,g_IsMultiplayer;
}
#pragma push
#pragma bool off
static inline int Active(SfGameObject* p){return p->activated && p->enabled && !p->removed;}
#pragma pop
extern "C" void cHotboxMan_Update(HotboxReceiver* arg0, void* arg1, void* arg2) {
    TrackerIter sp17C;
    TrackerIter sp178;
    cHotbox* sp174;
    HotboxListNode* sp170;
    TrackerIter sp16C;
    TrackerIter sp168;
    HotboxListNode* sp164;
    TrackerIter sp160;
    TrackerIter sp15C;
    HotboxListNode* sp158;
    TrackerIter sp154;
    HotboxListNode* sp150;
    HotboxListNode* sp14C;
    HotboxListNode* sp148;
    void* sp144;
    void* sp140;
    void* sp13C;
    void* sp138;
    void* sp134;
    void* sp130;
    void* sp12C;
    void* sp128;
    void* sp124;
    void* sp120;
    void* sp11C;
    void* sp118;
    TrackerIter sp114;
    HotMsg spE0;
    HotMsg spA0;
    float temp_f1;
    int temp_a0;
    int temp_a1;
    cHotbox* temp_s2;
    int temp_s1;
    int temp_s0;
    int temp_s2_2;
    int temp_s1_2;
    int var_v0;
    int var_v1;
    signed char var_v0_4;
    int var_v0_2;
    int var_v0_3;
    HotboxListNode* temp_a0_2;

    HotboxListNode* var_a0;

    temp_f1 = *(float*)&arg0->unk24 - 0.3f;
    *(float*)&arg0->unk24 = temp_f1;
    if (temp_f1 < 0.0f) {
        *(float*)&arg0->unk24 = 0.0f;
    }
    if (arg2 == 0) {
        arg2 = arg0->unk28;
    }
    std_list_cHotboxPtr_end_void(&sp140, &g_HotboxList);
    cLListIterator_cHotboxPtr_ctor_listR(&sp170, &sp140);
    std_list_cHotboxPtr_begin(&sp13C, arg2);
    cLListIterator_cHotboxPtr_ctor_listR(&sp16C, &sp13C);
    sp17C = sp16C;
    std_list_cHotboxPtr_end_void(&sp138, arg2);
    cLListIterator_cHotboxPtr_ctor_listR(&sp164, &sp138);
    sp168.p = sp164;
    sp178 = sp168;
    if (sp178.p != sp17C.p) {
        do {
            temp_s2 = (cHotbox*)sp17C.p->value;
            if (((HotboxV*)temp_s2)->Test(arg1) == 0 || (var_v0=Active((SfGameObject*)temp_s2), var_v0==0)) {

                if (g_IsMultiplayer != 0) {
                    if (g_IsMultiplayer != 0) {
                        var_v0_2 = D_005721C0;
                    } else {
                        var_v0_2 = 1;
                    }
                    if (var_v0_2 != 0) {
                        goto block_19;
                    }
                } else {
block_19:
                    temp_s2->occupants = (int) (temp_s2->occupants - 1);
                    if (temp_s2->occupants < 0) {
                        temp_s2->occupants = 0;
                    }
                }
                temp_s1 = arg0->unk20;
                temp_s0 = temp_s2->type;
                cMessage_ctor_cMessageNameR(&spE0, &D_004EE698);
                spE0.vtable = D_004D9940;
                spE0.action = 2;
                spE0.code = temp_s0;
                spE0.who = temp_s1;
                spE0.value = 0;
                temp_a1 = temp_s2->type;
                if ((temp_a1 == 5) || (temp_a1 == 0x12)) {
                    spE0.kind = 1;
                } else {
                    spE0.kind = 2;
                }
                spE0.flags = 0x40;
                QueueMessage_cMessageR_cSystemP_int(&spE0, temp_s2, 0);
                spE0.vtable = D_004D9940;
                cMessage_dtor(&spE0, 0);
                std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&sp144, &sp17C);
                std_list_cHotboxPtr_generic_iterator_opCast(&sp130, &sp144);
                std_list_deleter_voidPtr_erase_listdeleter(&sp134, arg2, &sp130);
                std_list_cHotboxPtr_generic_iterator_ctor(&sp148, &sp134);
                sp160.p = sp148;
                sp17C = sp160;
            } else {
                sp17C.p = sp17C.p->next;
            }
        } while (sp178.p != sp17C.p);
    }
    std_list_cHotboxPtr_end_void(&sp12C, &g_HotboxList);
    cLListIterator_cHotboxPtr_ctor_listR(&sp158, &sp12C);
    sp15C.p = sp158;
    sp114 = sp15C;
    std_list_cHotboxPtr_begin(&sp128, &g_HotboxList);
    cLListIterator_cHotboxPtr_ctor_listR(&sp154, &sp128);
    sp17C = sp154;
    var_a0 = sp17C.p;
    if (var_a0 != sp114.p) {
        do {
            sp174 = (cHotbox*)var_a0->value;
            var_v1 = Active((SfGameObject*)sp174);
            if ((var_v1 != 0) && (((HotboxV*)sp174)->Test(arg1) != 0)) {
                std_list_cHotboxPtr_end_void(&sp124, arg2);
                cLListIterator_cHotboxPtr_ctor_listR(&sp14C, &sp124);
                cLListIterator_cHotboxPtr_ctor_void(&sp120);
                cLList_cHotboxPtr_Begin(&sp11C, arg2);
                cLListIterator_cHotboxPtr_opAssign(&sp120, &sp11C);
                cLList_cHotboxPtr_End(&sp118, arg2);
                if (opNe_cLListIteratorR_cLListIteratorR_2(&sp120, &sp118) != 0) {
loop_40:
                    int found=*cLListIterator_cHotboxPtr_opMul(&sp120);
                    if (found != (int)sp174) {
                        cLListIterator_cHotboxPtr_opInc(&sp120);
                        cLList_cHotboxPtr_End(&sp118, arg2);
                        if (opNe_cLListIteratorR_cLListIteratorR_2(&sp120, &sp118) != 0) {
                            goto loop_40;
                        }
                    }
                }
                cLListIterator_cHotboxPtr_ctor_cLListIteratorR(&sp150, &sp120);
                if (sp150 == sp14C) {
                    if (g_IsMultiplayer != 0) {
                        if (g_IsMultiplayer != 0) {
                            var_v0_3 = D_005721C0;
                        } else {
                            var_v0_3 = 1;
                        }
                        if (var_v0_3 != 0) {
                            goto block_49;
                        }
                    } else {
block_49:
                        cHotbox* occupied=sp174;
                        occupied->occupants = occupied->occupants + 1;
                        if (3 < occupied->occupants) {
                            occupied->occupants = 3;
                        }
                    }
                    std_list_cHotboxPtr_push_back(arg2, &sp174);
                    temp_s2_2 = arg0->unk20;
                    temp_s1_2 = sp174->type;
                    cMessage_ctor_cMessageNameR(&spA0, &D_004EE698);
                    spA0.vtable = D_004D9940;
                    spA0.action = 0;
                    spA0.code = temp_s1_2;
                    spA0.who = temp_s2_2;
                    spA0.value = 0;
                    temp_a0 = sp174->type;
                    if (temp_a0 == 5 || temp_a0 == 0x12) {
                        spA0.kind=1;
                    } else {
                        spA0.kind=2;
                    }
                    spA0.flags = 0x40;
                    QueueMessage_cMessageR_cSystemP_int(&spA0, sp174, 0);
                    spA0.vtable = D_004D9940;
                    cMessage_dtor(&spA0, 0);
                }
            }
            temp_a0_2 = sp17C.p->next;
            sp17C.p = temp_a0_2;
            var_a0 = ((TrackerIter volatile*)&sp17C)->p;
        } while (var_a0 != sp114.p);
    }
}
static inline void merge_flush_func_00170660(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00170660 */
