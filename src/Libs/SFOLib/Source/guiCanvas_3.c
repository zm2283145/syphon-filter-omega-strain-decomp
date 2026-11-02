/*
 * Libs/SFOLib/Source/guiCanvas: 18 files, 00415870-00415F00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00415870 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_0055A300[];
extern char D_0055A700[];
extern int GuiCanvas_ProcessInput_cUSBKeybdR(Unk415870*, void*);
extern int GuiCanvas_ProcessInput_cJoystickR(Unk415870*, void*);

/* If flag bit 2 is set, calls GuiCanvas_ProcessInput_cJoystickR and, when byte +0x51 is set, GuiCanvas_ProcessInput_cUSBKeybdR. */
void GuiCanvas_ProcessInput_void(Unk415870* self) {
    if ((self->flags & 4) != 0) {
        GuiCanvas_ProcessInput_cJoystickR(self, D_0055A300);
        if (self->unk51 != 0) {
            GuiCanvas_ProcessInput_cUSBKeybdR(self, D_0055A700);
        }
    }
}
static inline void merge_flush_func_00415870(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00415870 */

/* merge_units: begin func_004158C0 */
#pragma push /* merge_units */
typedef struct { char p[0x14]; unsigned short flags; char p16[0x3B]; unsigned char b51; unsigned char b52; } W4158C0;
extern void cUSBKeybd_Init(void* p);
extern void cUSBKeybd_SetKeyMode(void* p);
void GuiCanvas_Activate(W4158C0* w, int on)
{
    if ((unsigned char)on == ((w->flags & 4) != 0)) return;
    if (on) w->flags |= 4; else w->flags &= ~4;
    if (w->b52 && (w->flags & 4) && w->b51) {
        cUSBKeybd_Init(D_0055A700);
        cUSBKeybd_SetKeyMode(D_0055A700);
    }
}
static inline void merge_flush_func_004158C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004158C0 */

/* merge_units: begin func_00415950 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"

struct LNode_415950 { LNode_415950* prev; LNode_415950* next; struct W_415950* value; };
struct LIt_415950 { LNode_415950* node; };
struct List_415950 { int size; LNode_415950* a; LNode_415950* head; };
struct W_415950 {
    VPAD16(p) VPAD4(q) VPAD2(r) VPAD1(s)
    virtual void Detach(int h, int x);
    virtual void Release(int h);
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x12];
    char children[0xC];
    char pad34[0x14];
    int h48;
    int h4C;
    unsigned char b50;
    char pad51[3];
    List_415950 queue;
    unsigned char busy;
    char pad61[3];
    float dt;
};
struct U_415950 {
    VPAD8(p) VPAD4(q)
    virtual void Update(float dt);
};
extern "C" {
#if 0 /* merge_units */
void std_list_deleter_voidPtr_begin_void(LIt_415950* out, void* list);
#endif /* merge_units */
void std_list_deleter_voidPtr_begin_void(void*, void*); /* merge_units */
#define std_list_deleter_voidPtr_begin_void(a0, a1) (std_list_deleter_voidPtr_begin_void((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void std_list_GuiWidgetPtr_generic_iterator_ctor(LIt_415950* out, LIt_415950* in);
#endif /* merge_units */
void std_list_GuiWidgetPtr_generic_iterator_ctor(void*, void*); /* merge_units */
#define std_list_GuiWidgetPtr_generic_iterator_ctor(a0, a1) (std_list_GuiWidgetPtr_generic_iterator_ctor((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void std_list_GuiWidgetPtr_end(LIt_415950* out, void* list);
#endif /* merge_units */
void std_list_GuiWidgetPtr_end(void*, void*); /* merge_units */
#define std_list_GuiWidgetPtr_end(a0, a1) (std_list_GuiWidgetPtr_end((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cLListIterator_GuiWidgetPtr_ctor_listR(LIt_415950* out, LIt_415950* in);
#endif /* merge_units */
void cLListIterator_GuiWidgetPtr_ctor_listR(void*, void*); /* merge_units */
#define cLListIterator_GuiWidgetPtr_ctor_listR(a0, a1) (cLListIterator_GuiWidgetPtr_ctor_listR((void *)(a0), (void *)(a1))) /* merge_units */

void std_list_GuiWidgetPtr_push_back_GuiWidgetPR(List_415950* list, W_415950** v);
void std_list_deleter_voidPtr_erase_listdeleter(LIt_415950* out, List_415950* list, LIt_415950* pos);
#if 0 /* merge_units */
W_415950** func_00415B20(List_415950* list);
#endif /* merge_units */
int* func_00415B20(L4Node** self); /* merge_units */
#define func_00415B20(a0) ((W_415950 * *)func_00415B20((L4Node * *)(a0))) /* merge_units */

}

extern "C" void GuiCanvas_NextFrame(W_415950* o, float dt)
{
    if (o->flags & 4) {
        LIt_415950 last;
        LIt_415950 it;
        LIt_415950 res1;
        LIt_415950 pos1;
        LIt_415950 res2;
        LIt_415950 pos2;
        LIt_415950 beginTmp;
        LIt_415950 endTmp;
        LNode_415950* n;
        o->dt = dt;
        dt *= 30.0f;
        if (o->b50) {
            o->Release(o->h48);
            o->h48 = 0;
            if (o->h4C) {
                o->Detach(o->h4C, 0);
                o->h4C = 0;
            }
            o->b50 = 0;
        }
        std_list_deleter_voidPtr_begin_void(&beginTmp, o->children);
        std_list_GuiWidgetPtr_generic_iterator_ctor(&it, &beginTmp);
        n = it.node;
        std_list_GuiWidgetPtr_end(&endTmp, o->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&last, &endTmp);
        if (n != last.node) {
            do {
                std_list_GuiWidgetPtr_push_back_GuiWidgetPR(&o->queue, &n->value);
                n = n->next;
                std_list_GuiWidgetPtr_end(&endTmp, o->children);
                cLListIterator_GuiWidgetPtr_ctor_listR(&last, &endTmp);
            } while (n != last.node);
        }
        o->busy = 1;
        while (o->queue.size) {
            if ((*func_00415B20(&o->queue))->flags & 4) {
                W_415950* w = o->queue.head->value;
                ((U_415950*)w)->Update(dt);
                if (o->queue.size && w == o->queue.head->value) {
                    pos1.node = o->queue.head;
                    std_list_deleter_voidPtr_erase_listdeleter(&res1, &o->queue, &pos1);
                }
            } else {
                pos2.node = o->queue.head;
                std_list_deleter_voidPtr_erase_listdeleter(&res2, &o->queue, &pos2);
            }
        }
        o->busy = 0;
    }
}
#undef std_list_deleter_voidPtr_begin_void /* merge_units */
#undef std_list_GuiWidgetPtr_generic_iterator_ctor /* merge_units */
#undef std_list_GuiWidgetPtr_end /* merge_units */
#undef cLListIterator_GuiWidgetPtr_ctor_listR /* merge_units */
#undef func_00415B20 /* merge_units */
static inline void merge_flush_func_00415950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00415950 */

/* merge_units: begin func_00415B20 */
#pragma push /* merge_units */
extern L4Iter* std_list_deleter_voidPtr_insert(L4Iter* out, void* list, L4Iter* pos, int value);

/* Address of the value in the node referenced by the word at +8. */
int* func_00415B20(L4Node** self) {
    return &self[2]->value;
}

/* push_back on a list whose sentinel node is at +4. */
L4Iter* std_list_GuiWidgetPtr_push_back_GuiWidgetPR_2(void* list, int value) {
    L4Iter it[2];

    it[0].node = (L4Node*)((char*)list + 4);
    return std_list_deleter_voidPtr_insert(&it[1], list, &it[0], value);
}
static inline void merge_flush_func_00415B20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00415B20 */

/* merge_units: begin func_00415B60 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned short flags; } Ent415B60;
extern void GuiWidget_SendChildrenMessage(Ent415B60* e, int kind, int v, int z);
void GuiCanvas_AdvanceAnimations(Ent415B60* e, float v)
{
    if (e->flags & 4) {
        v = v * 30.0f;
        GuiWidget_SendChildrenMessage(e, 7, (int)&v, 0);
    }
}
static inline void merge_flush_func_00415B60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00415B60 */

/* merge_units: begin func_00415BB0 */
#pragma push /* merge_units */
#pragma opt_rebuildconditionals off
#pragma cplusplus on

typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct M4 { float m[16]; } __attribute__((aligned(16))) M4;
typedef struct Slot { char pad0[0xF0]; float fF0; float fF4; float fF8; char padFC[0x104 - 0xFC]; char b104; char b105; char b106; char pad107[0x110 - 0x107]; } Slot;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;

struct LNode { LNode* prev; LNode* next; struct W* value; };
struct LIt { LNode* node; };
struct Draw {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); 
    virtual void Paint();
};
struct W { char pad0[0x14]; unsigned short flags; char pad16[0x44 - 0x16]; Draw* d; };
struct Self { char pad0[0x14]; unsigned short flags; char pad16[0x28 - 0x16]; char children[0xC]; };

extern "C" {
extern char g_Video[];
extern int D_00538318;
extern long long D_004BC1B0;
extern long long D_005392D8;
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern int g_DrawMode;
#if 0 /* merge_units */
void std_list_deleter_voidPtr_begin_void(LIt* out, void* list);
#endif /* merge_units */
#define std_list_deleter_voidPtr_begin_void(a0, a1) (std_list_deleter_voidPtr_begin_void((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void std_list_GuiWidgetPtr_generic_iterator_ctor(LIt* out, LIt* in);
#endif /* merge_units */
#define std_list_GuiWidgetPtr_generic_iterator_ctor(a0, a1) (std_list_GuiWidgetPtr_generic_iterator_ctor((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void std_list_GuiWidgetPtr_end(LIt* out, void* list);
#endif /* merge_units */
#define std_list_GuiWidgetPtr_end(a0, a1) (std_list_GuiWidgetPtr_end((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cLListIterator_GuiWidgetPtr_ctor_listR(LIt* out, LIt* in);
#endif /* merge_units */
#define cLListIterator_GuiWidgetPtr_ctor_listR(a0, a1) (cLListIterator_GuiWidgetPtr_ctor_listR((void *)(a0), (void *)(a1))) /* merge_units */

void XLib_ClearZBuffer(char* r);
}

#define SlotAt(i) ((Slot*)(g_Video + 0x1F0 + (i) * 0x110))
static inline Mtx* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline void MM(void* d, void* a, void* b)
{
    __asm__ volatile("lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf11, 0x30(%2); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}

extern "C" void GuiCanvas_Render(Self* self)
{
    if (self->flags & 4) {
        M4 m;
        LIt it;
        LIt last;
        LIt first;
        LIt beginTmp;
        LIt endTmp;
        int save;
        D_00538318 = 0;
        { long long t = D_004BC1B0; int i = D_00538C64; D_005392D8 = t; GQR(MtxAt(i + 1), MtxAt(i)); }
        D_00538C64++;
        UM(MtxAt(D_00538C64));
        D_00538C68 = 1;
        save = g_DrawMode;
        {
            Slot* s = SlotAt(D_00538C60);
            s->fF0 = 0.0f;
            s->fF8 = 1000.0f;
            s->b106 = 1;
            s->b104 = 1;
        }
        m.m[0] = 1.0f; m.m[1] = 0.0f; m.m[2] = 0.0f; m.m[3] = 0.0f;
        m.m[4] = 0.0f; m.m[5] = 0.0f; m.m[6] = 1.0f; m.m[7] = 0.0f;
        m.m[8] = 0.0f; m.m[9] = 1.0f; m.m[10] = 0.0f; m.m[11] = 0.0f;
        m.m[12] = 0.0f; m.m[13] = 0.0f; m.m[14] = 1.0f; m.m[15] = 1.0f;
        { Mtx* c = MtxAt(D_00538C64); MM(c, c, &m); }
        D_00538C68 = 1;
        g_DrawMode = save | 4;
        std_list_deleter_voidPtr_begin_void(&beginTmp, self->children);
        std_list_GuiWidgetPtr_generic_iterator_ctor(&first, &beginTmp);
        for (it = first; std_list_GuiWidgetPtr_end(&endTmp, self->children), cLListIterator_GuiWidgetPtr_ctor_listR(&last, &endTmp), it.node != last.node; it.node = it.node->next) {
            if (it.node->value->flags & 2) {
                XLib_ClearZBuffer(g_Video);
                it.node->value->d->Paint();
            }
        }
        g_DrawMode = save;
        D_00538C68 = 1;
        D_00538C64--;
    }
}
#undef std_list_deleter_voidPtr_begin_void /* merge_units */
#undef std_list_GuiWidgetPtr_generic_iterator_ctor /* merge_units */
#undef std_list_GuiWidgetPtr_end /* merge_units */
#undef cLListIterator_GuiWidgetPtr_ctor_listR /* merge_units */
static inline void merge_flush_func_00415BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00415BB0 */

/* merge_units: begin func_00415F00 */
#pragma push /* merge_units */
#pragma cplusplus on
class V415F00 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24(int);
};
typedef struct { char pad[8]; int arg; } N415F00;
typedef struct { void* vt; char p0[0x24]; int count; N415F00* head; char p1[0x54 - 0x30]; char sub[4]; } T415F00;
extern "C" {
extern "C" void GuiCanvas_GetClassName();
extern "C" void GuiCanvas_IsType();
extern "C" void GuiCanvas_onMessage();
extern "C" void GuiCanvas_PopGui();
extern "C" void GuiCanvas_PushGui();
extern "C" void GuiCanvas_onInput();
extern "C" void GuiCanvas_ProcessInputEvent();
#if 0 /* merge_units */
extern "C" void GuiCanvas_NextFrame();
#endif /* merge_units */

#if 0 /* merge_units */
extern "C" void GuiCanvas_Render();
#endif /* merge_units */

extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onSleep();
extern "C" void GuiWidget_onWake();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_onAdd();
extern "C" void GuiWidget_Load();
extern void * const D_004E08D0[];
void cLList_GuiWidgetPtr_dtor(void* p, int f);
void GuiWidget_dtor(T415F00* p, int f);
void operator_delete(void* p);
}
extern "C" T415F00* GuiCanvas_dtor(T415F00* self, short flag) {
    if (self) {
        self->vt = ((char*)D_004E08D0);
        while (self->count) ((V415F00*)self)->s24(self->head->arg);
        if (self->sub) cLList_GuiWidgetPtr_dtor(self->sub, 0);
        GuiWidget_dtor(self, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}
void * const D_004E08D0[28] = { (void*)0x0, (void*)0x0, (void*)GuiCanvas_dtor, (void*)GuiWidget_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiWidget_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiCanvas_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiCanvas_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiCanvas_GetClassName, (void*)GuiCanvas_IsType, (void*)GuiCanvas_Render, (void*)GuiCanvas_NextFrame, (void*)GuiCanvas_PushGui, (void*)GuiCanvas_PopGui, (void*)GuiCanvas_ProcessInputEvent };
static inline void merge_flush_func_00415F00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00415F00 */

/* merge_units: begin func_00415FC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00415FC0, func_00135C90)
static inline void merge_flush_func_00415FC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00415FC0 */

/* merge_units: begin func_00416020 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "obj_list_dtor_mid.h"

/* Destroy an object list, optionally delete. */
DEFINE_OBJ_LIST_DTOR_MID(func_00416020)
static inline void merge_flush_func_00416020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416020 */

/* merge_units: begin func_004160A0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char D_004E08D0[];         /* GuiWidget4160A0 vtable */
#endif /* merge_units */
#define D_004E08D0 ((char*)&D_004E08D0) /* merge_units */


extern int std_list_deleter_voidPtr_ctor_void(L4ScalarCollection*);
extern GuiWidget* GuiWidget_ctor(GuiWidget*);

/* Constructor of a GuiWidget subclass; clears flag bit 2 of the base. */
GuiWidget4160A0* GuiCanvas_ctor(GuiWidget4160A0* self) {
    unsigned int flags;

    GuiWidget_ctor(&self->base);
    self->base.vtable = D_004E08D0;
    std_list_deleter_voidPtr_ctor_void(&self->unk54);
    self->unk50 = 0;
    self->unk48 = 0;
    self->unk4C = 0;
    self->unk60 = 0;
    self->unk64 = 0;
    flags = self->base.flags; /* zero-extended load keeps the match */
    self->base.flags = flags & 0xFFFB;
    self->unk51 = 1;
    self->unk52 = 1;
    self->unk68 = 0xF000;
    return self;
}
#undef D_004E08D0 /* merge_units */
static inline void merge_flush_func_004160A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004160A0 */

/* merge_units: begin func_00416110 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00416110, std_list_GuiWidgetPtr_dtor)
static inline void merge_flush_func_00416110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416110 */

/* merge_units: begin func_00416170 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(ReceiverList_Dtor_416170)
static inline void merge_flush_func_00416170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416170 */

/* merge_units: begin func_004161F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "obj_list_dtor_shallow.h"

/* Destroy an object list, optionally delete. */
DEFINE_OBJ_LIST_DTOR_SHALLOW(func_004161F0)
static inline void merge_flush_func_004161F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004161F0 */

/* merge_units: begin func_00416260 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "object_list_erase_range.h"

/* Erase a range of nodes from a linked list. */
DEFINE_OBJECT_LIST_ERASE_RANGE(ObjectList_EraseRange_416260)
static inline void merge_flush_func_00416260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416260 */

/* merge_units: begin func_004163A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "object_list_erase_one.h"

/* Erase one node from a linked list. */
DEFINE_OBJECT_LIST_ERASE_ONE(List_Erase_4163A0)
static inline void merge_flush_func_004163A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004163A0 */

/* merge_units: begin func_004164A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "list_insert_before.h"

/* Insert an int value before a list position. */
DEFINE_LIST_INSERT_BEFORE(List_InsertBefore_4164A0)
static inline void merge_flush_func_004164A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004164A0 */

/* merge_units: begin func_00416660 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptr4_holder_dtor.h"

/* Free the owned allocation, optionally delete. */
DEFINE_PTR4_HOLDER_DTOR(func_00416660, D_0049AE80)
static inline void merge_flush_func_00416660(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416660 */

/* merge_units: begin func_00416740 */
#pragma push /* merge_units */
void* func_00416740(char* self) {
    return self + 4;
}

List* func_00416750(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
static inline void merge_flush_func_00416740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416740 */
