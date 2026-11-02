/*
 * SFOGame/Source/taser: 10 files, 00266200-002666D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00266200 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "cmessage.h"
#include "vslot_pad.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    V r0, r1, r2, t;
    M() {}
};
// VU0 macro-mode matrix * vector (COP2)
static inline void MulV(V* v, M* m) { __asm__ volatile("lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }

struct Tgt {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45();
    virtual V GetPos(int k);
};
struct Iface {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22();
    virtual void GetMatrix(M* m, int a, bool b);
};
struct Sub { char pad[0xF4]; float fF4; };
struct Actor { char pad[0x58]; Iface* p58; char pad5C[0x3524 - 0x5C]; Sub* p3524; };
struct Def { char pad[0x3C]; int i3C; };
struct HeldItem { Def* def; Actor* actor; unsigned char state; };

extern "C" {
extern unsigned char g_IsMultiplayer;
extern char D_00504050[];
extern char D_004DCDA0[];
extern char D_004DCF10[];
}
struct DartMsg {
    CMSG_HEADER;
    unsigned char b24;
    char pad25[3];
    Tgt* tgt;
    int pad2C;
    unsigned char b30;
    char pad31[3];
    int i34;
    int pad38[2];
    V v;
    DartMsg(Tgt* tgt, bool a, int b, V v) {
        DartMsg* m = this;
        cMessage_ctor_cMessageNameR(m, D_00504050);
        m->vtable = D_004DCF10;
        m->vtable = D_004DCDA0;
        m->b24 = 0;
        m->tgt = tgt;
        m->b30 = a;
        m->i34 = b;
        m->v = v;
    }
};

extern "C" {
void cAirTaser_Shoot_cGOBJP_bool_int_cVector(HeldItem* self, Tgt* tgt, bool a, int b, V v);
}

extern "C" bool cAirTaser_Shoot_cGOBJP_bool_int(HeldItem* self, Tgt* tgt, bool a, int b) {
    bool fired = false;
    if (!self->state) {
        V v(0.0f, 0.0f, 0.0f, 1.0f);
        if (!tgt || a) {
            float f;
            M m;
            if (a) f = self->actor->p3524->fF4;
            else f = (float)self->def->i3C;
            self->actor->p58->GetMatrix(&m, 0, a);
            v.y = f;
            MulV(&v, &m);
        } else {
            v = tgt->GetPos(b);
        }
        cAirTaser_Shoot_cGOBJP_bool_int_cVector(self, tgt, a, b, v);
        fired = true;
        if (g_IsMultiplayer) {
            DartMsg msg(tgt, a, b, v);
            msg.kind = 4;
            msg.flags = 0x40;
            QueueMessage_cMessageR_cSystemP_int(&msg, self->actor, 0);
            msg.vtable = D_004DCF10;
            cMessage_dtor(&msg, 0);
        }
    }
    return fired;
}
static inline void merge_flush_func_00266200(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00266200 */

/* merge_units: begin func_00266410 */
#pragma push /* merge_units */
#pragma cplusplus on
class O266 { public: int pad; virtual ~O266(); };
typedef struct { int a; int b; unsigned char flag; char pad[3]; O266* child; char sub[4]; } S266;
#if 0 /* merge_units */
extern "C" void cAirTaser_Release(S266*);
#endif /* merge_units */
extern "C" void cAirTaser_Release(void*); /* merge_units */
#define cAirTaser_Release(a0) (cAirTaser_Release((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern "C" void std_vector_deleter_TaserPoint_clear(void*);
#endif /* merge_units */
extern "C" void std_vector_deleter_TaserPoint_clear(PtrVec* v); /* merge_units */
#define std_vector_deleter_TaserPoint_clear(a0) (std_vector_deleter_TaserPoint_clear((PtrVec *)(a0))) /* merge_units */

extern "C" void cAirTaser_Reset(S266* p) {
    p->flag = 0;
    cAirTaser_Release(p);
    std_vector_deleter_TaserPoint_clear(&p->sub);
    if (p->child) {
        delete p->child;
        p->child = 0;
    }
}
#undef cAirTaser_Release /* merge_units */
#undef std_vector_deleter_TaserPoint_clear /* merge_units */
static inline void merge_flush_func_00266410(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00266410 */

/* merge_units: begin func_00266470 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" void operator_delete(void* allocation);
struct Vec266 { int cap; int count; int* data; };
struct VObj266 { int head; virtual ~VObj266(); };
struct Obj266 {
    int f0, f4;
    char f8;
    char pad9[3];
    VObj266* fC;
    char m10[0x10];
    char m20[0x10];
};
extern "C" {
extern Vec266 D_004F8350; extern int D_004F8354; extern int* D_004F8358;
void std_vector_pod_int_resize(Vec266* v, int n, int* fill);
#if 0 /* merge_units */
void cAirTaser_Release(Obj266* self);
#endif /* merge_units */
#define cAirTaser_Release(a0) (cAirTaser_Release((void *)(a0))) /* merge_units */



#if 0 /* merge_units */
void std_vector_deleter_TaserPoint_clear(void* p);
#endif /* merge_units */
#define std_vector_deleter_TaserPoint_clear(a0) (std_vector_deleter_TaserPoint_clear((PtrVec *)(a0))) /* merge_units */



#if 0 /* merge_units */
void std_list_TaserPulse_dtor(void* p, short flag);
#endif /* merge_units */
struct TreeHolder; /* merge_units */
TreeHolder* std_list_TaserPulse_dtor(TreeHolder* self, short deleteFlag); /* merge_units */
#define std_list_TaserPulse_dtor(a0, a1) ((void)std_list_TaserPulse_dtor((TreeHolder *)(a0), (a1))) /* merge_units */


void std_vector_deleter_TaserPoint_dtor(void* p, short flag);
}
#pragma opt_strength_reduction off
extern "C" Obj266* cAirTaser_dtor(Obj266* self, short deleteFlag) {
    if (self) {
        self->f8 = 0;
        cAirTaser_Release(self);
        std_vector_deleter_TaserPoint_clear(self->m10);
        {
            VObj266* m = self->fC;
            if (m) {
                delete m;
                self->fC = 0;
            }
        }
        {
            int i;
            int last = D_004F8354 - 1;
            int fill;
            for (i = 0; last >= i; i++) {
                int* e = &D_004F8358[i];
                if (*e == (int)self) {
                    *e = D_004F8358[last];
                    last--;
                }
            }
            fill = 0;
            std_vector_pod_int_resize(&D_004F8350, last + 1, &fill);
        }
        {
            void* a = self->m20;
            if (a) std_list_TaserPulse_dtor(a, 0);
        }
        {
            void* b = self->m10;
            if (b) { if (b) { if (b) std_vector_deleter_TaserPoint_dtor(b, 0); } }
        }
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
#pragma opt_strength_reduction reset
#undef cAirTaser_Release /* merge_units */
#undef std_vector_deleter_TaserPoint_clear /* merge_units */
#undef std_list_TaserPulse_dtor /* merge_units */
static inline void merge_flush_func_00266470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00266470 */

/* merge_units: begin func_002665B0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct TreeNode2;
struct TreeHolder { int head; int header; TreeNode2* first; };
#if 0 /* merge_units */
extern "C" void std_list_deleter_TaserPulse_erase_listdeleter_listdeleter(TreeNode2** result, TreeHolder* self, TreeNode2** first, TreeNode2** last);
#endif /* merge_units */
struct EraseListNode; /* merge_units */
struct EraseList; /* merge_units */
extern "C" void std_list_deleter_TaserPulse_erase_listdeleter_listdeleter(EraseListNode** result, EraseList* list, EraseListNode** first, EraseListNode** last); /* merge_units */
#define std_list_deleter_TaserPulse_erase_listdeleter_listdeleter(a0, a1, a2, a3) (std_list_deleter_TaserPulse_erase_listdeleter_listdeleter((EraseListNode * *)(a0), (EraseList *)(a1), (EraseListNode * *)(a2), (EraseListNode * *)(a3))) /* merge_units */

extern "C" TreeHolder* std_list_TaserPulse_dtor(TreeHolder* self, short deleteFlag) {
    if (self) {
        if (self) {
            if (self) {
                TreeNode2* result;
                TreeNode2* first;
                TreeNode2* last;
                last = (TreeNode2*)&self->header;
                first = self->first;
                std_list_deleter_TaserPulse_erase_listdeleter_listdeleter(&result, self, &first, &last);
            }
        }
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
#undef std_list_deleter_TaserPulse_erase_listdeleter_listdeleter /* merge_units */
static inline void merge_flush_func_002665B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002665B0 */

/* merge_units: begin func_00266630 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char ready; } Sub_00266630;
typedef struct {
    int unk0;           /* 0x00 */
    int owner;          /* 0x04 */
    unsigned char flag; /* 0x08 */
    char pad9[3];
    int unkC;           /* 0x0C */
    Sub_00266630 sub;            /* 0x10 */
    char pad1D[3];
    char list[0xC];     /* 0x20 */
    int count;          /* 0x2C */
    int state;          /* 0x30 */
    char pad34[0x8C];
    int unkC0;          /* 0xC0 */
} S;
#if 0 /* merge_units */
extern char D_004F8350[];
#endif /* merge_units */
#define D_004F8350 ((char*)&D_004F8350) /* merge_units */


#if 0 /* merge_units */
extern void std_vector_TaserPoint_ctor(Sub_00266630*);
#endif /* merge_units */
Rel * std_vector_TaserPoint_ctor(); /* merge_units */

#if 0 /* merge_units */
extern void std_list_deleter_TaserPulse_ctor(void*);
#endif /* merge_units */
List * std_list_deleter_TaserPulse_ctor(); /* merge_units */

#if 0 /* merge_units */
extern void std_vector_cAirTaserPtr_push_back(void* registry, S** self);
#endif /* merge_units */
int std_vector_cAirTaserPtr_push_back(); /* merge_units */

/* Constructor: initialises members and registers the object in the global registry. */
S* cAirTaser_ctor(S* self, int owner)
{
    Sub_00266630* sub = &self->sub;
    std_vector_TaserPoint_ctor(sub);
    sub->ready = 1;
    std_list_deleter_TaserPulse_ctor(self->list);
    self->state = -2;
    self->count = 0;
    self->owner = owner;
    self->flag = 0;
    self->unk0 = 0;
    self->unkC = 0;
    self->unkC0 = 0;
    std_vector_cAirTaserPtr_push_back(D_004F8350, &self);
    return self;
}
#undef D_004F8350 /* merge_units */
static inline void merge_flush_func_00266630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00266630 */

/* merge_units: begin func_002666D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern int std_vector_pod_int_insert(PtrVec*, int*, int, int*);

/* push_back */
int std_vector_cAirTaserPtr_push_back(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

Rel* std_vector_TaserPoint_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

void std_vector_deleter_TaserPoint_clear(PtrVec* v) {
    v->count = 0;
}
static inline void merge_flush_func_002666D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002666D0 */

/* merge_units: begin func_00266720 */
#pragma push /* merge_units */
#pragma cplusplus on
#define D_0049AE80 D_004A8280
#include "object_list_erase_range.h"
extern "C" { char D_004A8280[] = "allocator.hh"; }

DEFINE_OBJECT_LIST_ERASE_RANGE(std_list_deleter_TaserPulse_erase_listdeleter_listdeleter)
static inline void merge_flush_func_00266720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00266720 */

/* merge_units: begin func_00266860 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "object_list_erase_file.h"

DEFINE_OBJECT_LIST_ERASE_ONE_FILE(std_list_deleter_TaserPulse_erase_listdeleter, D_004A8280)
static inline void merge_flush_func_00266860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00266860 */

/* merge_units: begin func_00266960 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#include "alloc_guard.h"

extern "C" {
extern char D_004A8270[];
extern char D_004A8280[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
}
inline void* operator new(unsigned int, void* p) { return p; }
struct M_66960 {
    float m[4][4];
    M_66960(const M_66960& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
} __attribute__((aligned(16)));
struct Val_66960 { int a; float b; M_66960 m; };
struct Node_66960 { Node_66960* prev; Node_66960* next; Val_66960 value; };
struct List_66960 { int count; int alloc; };
struct Flag_66960 {
    char c;
    Flag_66960() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Flag_66960() {}
};
struct E_66960 {};
struct Ptr_66960 : E_66960 { Node_66960* p; Ptr_66960(const E_66960& e, Node_66960* n) : E_66960(e), p(n) {} };
struct Holder_66960;
#if 0 /* merge_units */
extern "C" void details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_6(Holder_66960* h);
#endif /* merge_units */
extern "C" void* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_6(char* self); /* merge_units */
#define details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_6(a0) ((void)details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_6((char *)(a0))) /* merge_units */


struct Holder_66960 {
    int* alloc;
    Node_66960* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Holder_66960()
    {
        if (node) {
            details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_6(this);
            Node_66960* p = node;
            if (p) {
                AllocGuard guard;
                cMemMan_Deallocate(0, p, D_004A8280, 0x64);
            }
        }
    }
};

static inline Node_66960* NewNode() { AllocGuard guard; return (Node_66960*)cMemMan_Allocate(0, 0x60, D_004A8270, 0x5C); }
#pragma push
#pragma opt_propagation off
extern "C" int std_list_deleter_TaserPulse_insert(Node_66960** result, List_66960* list, Node_66960** pos, const Val_66960* value)
{
    Node_66960* n;
    int* alloc = &list->alloc;
    Flag_66960 flag;
    E_66960 f1 = *(E_66960*)&flag;
    n = NewNode();
    {
    Holder_66960 h;
    Ptr_66960 t(f1, n);
    h.node = t.p;
    h.alloc = alloc;
    Val_66960* v = &h.node->value;
    new (v) Val_66960(*value);
    Node_66960* m = h.node;
    Node_66960* p;
    h.node = 0;
    p = *pos;
    p->prev->next = m;
    m->prev = p->prev;
    p->prev = m;
    m->next = p;
    list->count++;
    *result = m;
    }
    return 0;
}
#pragma pop
#undef details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_6 /* merge_units */
static inline void merge_flush_func_00266960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00266960 */

/* merge_units: begin func_00266B70 */
#pragma push /* merge_units */
void* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_6(char* self) {
    return self + 4;
}

List* std_list_deleter_TaserPulse_ctor(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
static inline void merge_flush_func_00266B70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00266B70 */
