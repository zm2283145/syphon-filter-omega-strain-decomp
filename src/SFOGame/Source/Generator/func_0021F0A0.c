#pragma cplusplus on
#include "types.h"
#define V5(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4();
struct Ctl {
    V5(a) V5(b) V5(c)
    virtual int IsA();      /* +0x44 */
    virtual void d3(); virtual void d4(); virtual void e0(); virtual void e1();
    virtual int IsPlayer(); /* +0x58 */
};
struct Tgt {
    V5(a) virtual void b0();
    virtual void Activate();   /* +0x20 */
    virtual void Deactivate(); /* +0x24 */
    V5(c) V5(d) virtual void e0(); virtual void e1(); virtual void e2();
    virtual void ActivateNet(int f); /* +0x5C */
    virtual void Kill(int f);        /* +0x60 */
    V5(f) V5(g) V5(h) V5(i) V5(j) V5(k) V5(l) V5(m) virtual void n0();
    virtual unsigned char State(); /* +0x108 */
    int magic;
    int pad8;
    int id;
    int x10;
    char pad14[0x18];
    unsigned char b2C; unsigned char b2D; unsigned char b2E;
    char pad2F[0x29];
    Ctl* ctl;
    char pad5C[0x3584 - 0x5C];
    int x3584;
};
struct Hnd { Tgt* p; int id; };
struct LNode { LNode* prev; LNode* next; Hnd h; };
struct It { void* n; };
struct LHead { LNode* prev; LNode* next; };
struct NIt { LNode* p; };
struct FIt { void* p; };
struct GList { int size; LHead head; };
struct Gen {
    void* vt;
    char pad4[8];
    int key;
    char pad10[0x1C];
    unsigned char b2C; unsigned char b2D; unsigned char b2E;
    char pad2F[0x61];
    GList list90;
    GList list9C;
    char padA8[0x18];
    int nC0;
    char padC4[8];
    int maskCC;
    char padD0[2];
    unsigned char bD2;
    unsigned char bD3;
};
struct EvA { void* vt; char pad4[0x1C]; unsigned char kind; char p21[3]; Tgt* obj; };
struct EvB { void* vt; char pad4[0x18]; int x1C; unsigned char kind; char p21[0xB]; int id; int x10; };
extern "C" {
extern char D_004A4A80[];
extern char D_004DB640[];
extern char D_004DB660[];
extern char D_004DE260[];
extern char D_0051F068[];
extern char D_00555070[];
extern int D_00494178;
extern int g_ActorList;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
int cMessage_ctor_cMessageNameR(void*, char*);
int QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
int cMessage_dtor(void*, int);
int cNetObj_GetNetSystem(int);
int cNetObj_GetPlayer(int);
void std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(It* ret, GList* l, It* a, It* b);
int cNetObj_GetOwner(int);
void cHuman_SetupNetworkFields(Tgt*, int);
LNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(LHead* n);
void* std_list_deleter_cSafePtr_cGOBJ_tail(GList* l);
It* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(It* it, void* n);
void cGenerator_CheckForOwnershipChange(Gen* g);
void* cLListIterator_cSafePtr_cGOBJ_ctor_void(It* it);
void cLList_cSafePtr_cGOBJ_Begin(It* out, GList* l);
It* cLListIterator_cSafePtr_cGOBJ_opAssign(It* dst, It* src);
void cLList_cSafePtr_cGOBJ_End(It* out, GList* l);
int opNe_cLListIteratorR_cLListIteratorR_3(It* a, It* b);
Hnd* cLListIterator_cSafePtr_cGOBJ_opMul(It* it);
int cSafePtr_cGOBJ_opEq(Hnd* a, Hnd* b);
It* cLListIterator_cSafePtr_cGOBJ_opInc(It* it);
It* cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(It* dst, It* src);
void std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(It* ret, GList* l, It* pos);
int NetGetMyClientIndex(int*, int);
void cSystem_ActualScheduleDelete(Tgt*, float);
void cScriptInterpreter_RemoveFromAllGroups(void*, Tgt*);
void cNetObj_SetOwner(int, int);
void cBaseObjList_Remove(int, Tgt*);
int cNPCInfoObject_IsActiveOnRemote(void*, int*);
void cNPCInfoObject_SetActive(void*, int*);
int cNPCInfoObject_GetOwner_cObjectIdR(void*, int*);
void cNPCInfoObject_dtor(void*, int);
void cNPCInfoObject_ctor(void*);
int cGenInfoObject_GetOwner(void*, int*);
void cGenInfoObject_SetOwner(void*, int*, int);
int cGenInfoObject_HasOwner(void*, int*);
int cGenInfoObject_IsActive(void*, int*, int);
void cGenInfoObject_ctor(void*);
void cGenerator_v11(Gen* self);
}
static inline Tgt* HGet(Hnd* h) {
    unsigned char valid = 1;
    Tgt* p = h->p;
    int n = (p != 0) ^ 1;
    if (!n && p->id != h->id)
        valid = 0;
    return valid ? p : 0;
}
static inline Tgt* HGetN(LNode* n) { Hnd* h = &n->h; return HGet(h); }
static inline void MkEv(EvB* e, int x10, int id) { cMessage_ctor_cMessageNameR(e, D_0051F068); e->vt = D_004DE260; e->id = id; e->x10 = x10; e->x1C = 0x40; e->kind = 4; }
static inline bool GActive(Gen* g) { return g->b2D && g->b2C && !g->b2E; }
static inline bool TActive(Tgt* t) { return t->b2D && t->b2C && !t->b2E; }
static inline bool IsPl(Tgt* t) { bool r = 0; if (t->ctl && t->ctl->IsPlayer()) r = 1; return r; }
static inline bool IsDying(Tgt* o) { unsigned char s = o->State(); return s == 2 || s == 3; }
static inline int IsAuth(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
static inline int LocalId(void) {
    int a = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
        return D_00494178;
    }
    return 0;
}

void cGenerator_v11(Gen* self)
{
    char ctx[4];
    char ctx2[4];
    It found1;
    It found2;
    It found3;
    It ret1;
    It arg1;
    It ret2;
    It arg2;
    It ret3;
    It arg3;
    It ret4;
    It arg4;
    It ret5;
    It arg5;
    It ret6;
    It arg6;
    It ret7;
    It arg7;
    It ret8;
    It arg8;
    It end1;
    It endc2;
    It end2;
    It end3;
    It endc4;
    It end4;
    It ret9;
    It arg9a;
    It arg9b;
    int none1;
    int none2;
    int none3;
    It it1;
    It beg1;
    It ie1;
    It it2;
    It beg2;
    It ie2;
    It it3;
    It beg3;
    It ie3;
    Hnd h1;
    Hnd h2;
    Hnd h3;
    EvA ev1;
    EvB ev2;
    EvB ev3;
    EvA ev4;

    if (g_IsMultiplayer) {
        int me;
        NIt n;
        cGenInfoObject_ctor(ctx);
        cNPCInfoObject_ctor(ctx2);
        me = cGenInfoObject_GetOwner(ctx, &self->key);
        n.p = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(&self->list90.head)->next;
        std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end1, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
        while (n.p != end1.n) {
            Hnd* h = &n.p->h;
            Tgt* t = (Tgt*)HGet(h);
            LNode* cur = n.p;
            n.p = n.p->next;
            if (t) {
                bool atEnd;
                bool kill;
                FIt f;
                f.p = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(&self->list9C.head);
                if (self->list9C.size > 0) {
                    int* pid = &h1.id;
                    *pid = -1;
                    h1.p = t;
                    *pid = *(t ? &t->id : (none1 = -1, &none1));
                    cLListIterator_cSafePtr_cGOBJ_ctor_void(&it1);
                    cLList_cSafePtr_cGOBJ_Begin(&beg1, &self->list9C);
                    cLListIterator_cSafePtr_cGOBJ_opAssign(&it1, &beg1);
                    for (; cLList_cSafePtr_cGOBJ_End(&ie1, &self->list9C), opNe_cLListIteratorR_cLListIteratorR_3(&it1, &ie1); cLListIterator_cSafePtr_cGOBJ_opInc(&it1)) if (cSafePtr_cGOBJ_opEq(cLListIterator_cSafePtr_cGOBJ_opMul(&it1), &h1)) break; //
                    cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(&found1, &it1);
                    f.p = found1.n;
                }
                atEnd = f.p == (void*)((char*)self + 0xA0);
                kill = 0;
                if (me >= 0 && !atEnd) {
                    if (me == cNPCInfoObject_GetOwner_cObjectIdR(ctx2, &t->id)) {
                        cMessage_ctor_cMessageNameR(&ev1, D_004A4A80);
                        ev1.obj = t;
                        ev1.vt = D_004DB640;
                        ev1.kind = 1;
                        QueueMessage_cMessageR_cSystemP_int(&ev1, self, 0);
                        arg1.n = f.p;
                        std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret1, &self->list9C, &arg1);
                        if (TActive(t))
                            cNPCInfoObject_SetActive(ctx2, &t->id);
                        ev1.vt = D_004DB660;
                        cMessage_dtor(&ev1, 0);
                    } else if (t->ctl && !t->ctl->IsA()) {
                        arg2.n = f.p;
                        std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret2, &self->list9C, &arg2);
                    }
                }
                if (me < 0) {
                    if (atEnd) {
                        if (TActive(t)) {
                            if (IsPl(t))
                                t->Kill(0);
                            else
                                t->Deactivate();
                        }
                        if (IsPl(t) && !cNPCInfoObject_IsActiveOnRemote(ctx2, &t->id))
                            kill = 1;
                    }
                } else if (!GActive(self)) {
                    if (TActive(t)) {
                        if (IsPl(t))
                            t->Kill(0);
                        else
                            t->Deactivate();
                    } else if (atEnd) {
                        if (t->ctl && !t->ctl->IsA())
                            kill = 1;
                    }
                } else if (!TActive(t)) {
                    if (t->ctl && t->ctl->IsA()) {
                        if (IsPl(t)) {
                            t->ActivateNet(0);
                        } else {
                            t->Activate();
                            if (t->x3584 == 0) {
                                int m = cNetObj_GetNetSystem(t->x10);
                                if (m)
                                    cHuman_SetupNetworkFields(t, m);
                            }
                        }
                    } else if (atEnd) {
                        kill = 1;
                    }
                }
                if (kill && me == LocalId()) {
                    int x10 = t->x10;
                    int id = t->id;
                    cMessage_ctor_cMessageNameR(&ev2, D_0051F068);
                    ev2.vt = D_004DE260;
                    ev2.id = id;
                    ev2.x10 = x10;
                    ev2.x1C = 0x40;
                    ev2.kind = 4;
                    QueueMessage_cMessageR_cSystemP_int(&ev2, self, 0);
                    if (!IsDying(t) && !self->bD2)
                        self->nC0--;
                    arg3.n = cur;
                    std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret3, &self->list90, &arg3);
                    cBaseObjList_Remove(g_ActorList, t);
                    cScriptInterpreter_RemoveFromAllGroups(D_00555070, t);
                    if (t->magic == (int)0xBEBAAFDE)
                        cSystem_ActualScheduleDelete(t, 1.0f);
                    ev2.vt = D_004DE260;
                    cMessage_dtor(&ev2, 0);
                }
            } else {
                arg4.n = cur;
                std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret4, &self->list90, &arg4);
            }
            std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end1, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
        }
        cGenerator_CheckForOwnershipChange(self);
        if (me == LocalId()) {
            bool purge = 0;
            if (GActive(self)) {
                self->bD3 = 1;
            } else if (self->bD3) {
                int sel = -1;
                int i;
                for (i = 0; i < 4; i++) {
                    if ((self->maskCC & (1 << i)) && cGenInfoObject_IsActive(ctx, &self->key, i) && cNetObj_GetPlayer(i)) {
                        sel = i;
                        break;
                    }
                }
                if (sel >= 0) {
                    cGenInfoObject_SetOwner(ctx, &self->key, sel);
                } else {
                    cGenInfoObject_SetOwner(ctx, &self->key, -1);
                    purge = 1;
                }
            } else if (IsAuth() && (!cGenInfoObject_IsActive(ctx, &self->key, -1) || !(self->maskCC & 1))) {
                int sel = -1;
                int i;
                for (i = 1; i < 4; i++) {
                    if ((self->maskCC & (1 << i)) && cGenInfoObject_IsActive(ctx, &self->key, i) && cNetObj_GetPlayer(i)) {
                        sel = i;
                        break;
                    }
                }
                if (sel >= 0) {
                    cGenInfoObject_SetOwner(ctx, &self->key, sel);
                } else {
                    cGenInfoObject_SetOwner(ctx, &self->key, -1);
                    purge = 1;
                }
            }
            if (purge) {
                NIt n2;
                n2.p = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(&self->list90.head)->next;
                std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end2, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
                while (n2.p != end2.n) {
                    Hnd* h = &n2.p->h;
                    Tgt* t = HGet(h);
                    NIt cur; cur.p = n2.p;
                    n2.p = n2.p->next;
                    if (t) {
                        if (self->list9C.size > 0) {
                            FIt f2;
                            int* pid = &h2.id;
                            *pid = -1;
                            h2.p = t;
                            *pid = *(t ? &t->id : (none2 = -1, &none2));
                            cLListIterator_cSafePtr_cGOBJ_ctor_void(&it2);
                            cLList_cSafePtr_cGOBJ_Begin(&beg2, &self->list9C);
                            cLListIterator_cSafePtr_cGOBJ_opAssign(&it2, &beg2);
                            for (; cLList_cSafePtr_cGOBJ_End(&ie2, &self->list9C), opNe_cLListIteratorR_cLListIteratorR_3(&it2, &ie2); cLListIterator_cSafePtr_cGOBJ_opInc(&it2)) if (cSafePtr_cGOBJ_opEq(cLListIterator_cSafePtr_cGOBJ_opMul(&it2), &h2)) break; //
                            cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(&found2, &it2);
                            f2.p = found2.n;
                            std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&endc2, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list9C));
                            if (f2.p != endc2.n) {
                                arg5.n = f2.p;
                                std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret5, &self->list9C, &arg5);
                            }
                        }
                        {
                            int x10 = t->x10;
                            MkEv(&ev3, x10, t->id);
                            QueueMessage_cMessageR_cSystemP_int(&ev3, self, 0);
                            if (!IsDying(t) && !self->bD2)
                                self->nC0--;
                            arg6.n = cur.p;
                            std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret6, &self->list90, &arg6);
                            cBaseObjList_Remove(g_ActorList, t);
                            cScriptInterpreter_RemoveFromAllGroups(D_00555070, t);
                            if (t->magic == (int)0xBEBAAFDE)
                                cSystem_ActualScheduleDelete(t, 1.0f);
                            ev3.vt = D_004DE260;
                            cMessage_dtor(&ev3, 0);
                        }
                    }
                    std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end2, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
                }
            }
        } else {
            self->bD3 = 0;
        }
        if (IsAuth() && cGenInfoObject_HasOwner(ctx, &self->key)) {
            NIt n3;
            n3.p = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(&self->list90.head)->next;
            std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end3, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
            int* k; int tid;
            while (n3.p != end3.n) {
                k = &self->key;
                if (cNetObj_GetOwner(HGetN(n3.p)->id) != cGenInfoObject_GetOwner(ctx, k)) {
                    k = &self->key;
                    tid = HGetN(n3.p)->id;
                    cNetObj_SetOwner(tid, cGenInfoObject_GetOwner(ctx, k));
                }
                n3.p = n3.p->next;
                std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end3, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
            }
        }
        if (self->bD2 && !cGenInfoObject_HasOwner(ctx, &self->key) && self->list90.size == 0)
            self->nC0 = 0;
        {
            int i;
            for (i = 0; i < 4; i++) {
                if (!cNetObj_GetPlayer(i)) {
                    if (self->maskCC & (1 << i))
                        self->maskCC ^= (1 << i);
                }
            }
        }
        cNPCInfoObject_dtor(ctx2, -1);
    } else {
        NIt n4;
        n4.p = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(&self->list90.head)->next;
        std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end4, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
        while (n4.p != end4.n) {
            Hnd* h = &n4.p->h;
            Tgt* t = HGet(h);
            NIt cur; cur.p = n4.p;
            n4.p = n4.p->next;
            if (t) {
                FIt f3;
                {
                    int* pid = &h3.id;
                    *pid = -1;
                    h3.p = t;
                    *pid = *(t ? &t->id : (none3 = -1, &none3));
                }
                cLListIterator_cSafePtr_cGOBJ_ctor_void(&it3);
                cLList_cSafePtr_cGOBJ_Begin(&beg3, &self->list9C);
                cLListIterator_cSafePtr_cGOBJ_opAssign(&it3, &beg3);
                for (; cLList_cSafePtr_cGOBJ_End(&ie3, &self->list9C), opNe_cLListIteratorR_cLListIteratorR_3(&it3, &ie3); cLListIterator_cSafePtr_cGOBJ_opInc(&it3)) if (cSafePtr_cGOBJ_opEq(cLListIterator_cSafePtr_cGOBJ_opMul(&it3), &h3)) break; //
                cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(&found3, &it3);
                f3.p = found3.n;
                std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&endc4, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list9C));
                if (f3.p != endc4.n) {
                    cMessage_ctor_cMessageNameR(&ev4, D_004A4A80);
                    ev4.obj = t;
                    ev4.vt = D_004DB640;
                    ev4.kind = 1;
                    QueueMessage_cMessageR_cSystemP_int(&ev4, self, 0);
                    arg7.n = f3.p;
                    std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret7, &self->list9C, &arg7);
                    ev4.vt = D_004DB660;
                    cMessage_dtor(&ev4, 0);
                }
                if (!GActive(self)) {
                    if (TActive(t))
                        t->Kill(1);
                } else if (!TActive(t)) {
                    if (t->ctl && t->ctl->IsA())
                        t->ActivateNet(1);
                }
                if (!TActive(t)) {
                    if (!IsDying(t) && !self->bD2)
                        self->nC0--;
                    arg8.n = cur.p;
                    std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret8, &self->list90, &arg8);
                    cBaseObjList_Remove(g_ActorList, t);
                    cScriptInterpreter_RemoveFromAllGroups(D_00555070, t);
                    if (t->magic == (int)0xBEBAAFDE)
                        cSystem_ActualScheduleDelete(t, 1.0f);
                }
            }
            std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end4, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
        }
        if (self->bD2) {
            if (!GActive(self) && self->list90.size == 0)
                self->nC0 = 0;
        }
    }
    if (self->list90.size == 0 && self->list9C.size > 0) {
        arg9b.n = &self->list9C.head;
        arg9a.n = self->list9C.head.next;
        std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(&ret9, &self->list9C, &arg9a, &arg9b);
    }
}
