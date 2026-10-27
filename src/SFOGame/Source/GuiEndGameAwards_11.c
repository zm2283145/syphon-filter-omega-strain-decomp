/*
 * SFOGame/Source/GuiEndGameAwards: 5 files, 00460AC0-00460E00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00460AC0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Entry12 {
    int a;
    int b;
    int ticks;
} Entry12;

typedef struct Vec12 {
    int unk0;
    int count;
    Entry12* items;
} Vec12;

extern void strncpy(void* dst, const void* src, int size); /* strncpy-style copy */
extern void std_vector_imp_tQuip_insert(Vec12* vec, Entry12* pos, int count, Entry12* value);

/* Appends an entry: 8-byte name copied from `name`, ticks = seconds * 30. */
void cQuipList_QueueUp(Vec12* vec, const char* name, float seconds) {
    Entry12 entry;
    strncpy(&entry, name, 8);
    entry.ticks = (int)(30.0f * seconds);
    std_vector_imp_tQuip_insert(vec, vec->items + vec->count, 1, &entry);
}
static inline void merge_flush_func_00460AC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00460AC0 */

/* merge_units: begin GuiGameScreen_460B40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */


extern int D_004FFC04;
extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);
extern int cGameFrontEnd_CloseZeusHog(int);
extern int GuiWidget_onRemove(void* self);

int* func_00460B40(PtrVec* v, int i) {
    return v->data + i;
}

int func_00460B50(PtrVec* v) {
    return v->count;
}

/* Appends one value at the end of the vector. */
int func_00460B60(PtrVec* v, int value) {
    int count;
    int* data;

    count = v->count;
    data = v->data;
    return std_vector_pod_int_insert(v, data + count, 1, value);
}

int GuiEndGameAwards_onRemove(void* self) {
    GuiWidget_onRemove(self);
    return cGameFrontEnd_CloseZeusHog(D_004FFC04);
}
static inline void merge_flush_GuiGameScreen_460B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiGameScreen_460B40 */

/* merge_units: begin func_00460BB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#include "gui_traversal_types.h"

struct W460BB0 { VPAD16(a) VPAD4(b) virtual int IsA(const char* type); };
struct Slot460BB0 { W460BB0* w; char pad[0x14]; };
struct S460BB0 { char pad[0x48]; Slot460BB0 slots[15]; TraversalWidget* border; };

extern "C" {
#if 0 /* merge_units */
extern void* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(void **)&D_004FFC04) /* merge_units */

extern char D_004C24E8[];
extern char D_004C24F8[];
extern char D_004B88F0[];
void GuiWidget_onAdd(S460BB0*);
int cGameFrontEnd_OpenZeusHog(void*);
TraversalWidget* GuiWidget_FindChild_charP(void*, const char*);
void std_list_deleter_voidPtr_begin_void(ChildIterator* result, ChildList* list);
void std_list_GuiWidgetPtr_generic_iterator_ctor(ChildIterator* result, const ChildIterator* source);
void std_list_GuiWidgetPtr_end(ChildIterator* result, ChildList* list);
void cLListIterator_GuiWidgetPtr_ctor_listR(ChildIterator* result, const ChildIterator* source);
void GuiEndGameAwards_onAdd(S460BB0* self);
}

void GuiEndGameAwards_onAdd(S460BB0* self)
{
    W460BB0* w;
    ChildNode* node;
    GuiWidget_onAdd(self);
    if (cGameFrontEnd_OpenZeusHog(D_004FFC04)) {
        TraversalWidget* grp = GuiWidget_FindChild_charP(self, D_004C24E8);
        if (grp) {
            ChildList* list = &grp->children;
            if (list->count == 15) {
                ChildIterator end;
                ChildIterator begin;
                ChildIterator rawBegin;
                ChildIterator rawEnd;
                int i;
                std_list_deleter_voidPtr_begin_void(&rawBegin, list);
                std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
                node = begin.node;
                std_list_GuiWidgetPtr_end(&rawEnd, list);
                cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
                i = 0;
                while (node != end.node) {
                    w = (W460BB0*)node->widget;
                    self->slots[i].w = (w && w->IsA(D_004B88F0)) ? w : 0;
                    node = node->next;
                    i++;
                    std_list_GuiWidgetPtr_end(&rawEnd, list);
                    cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
                }
            }
        }
    }
    self->border = GuiWidget_FindChild_charP(self, D_004C24F8);
}
#undef D_004FFC04 /* merge_units */
static inline void merge_flush_func_00460BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00460BB0 */

/* merge_units: begin func_00460CF0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct H_60CF0 { int v; };
struct Req_60CF0 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_60CF0 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
    char pad187[9];
};
struct Slot_60CF0 { int a; int b; char pad[0x10]; };
struct Sub_60CF0 {
    char pad0[0x10];
    int x10;
    char pad14[0x20 - 0x14];
    char menu[0x1B0 - 0x20];
    int x1B0;
};
struct W_60CF0 {
    void* vt;
    char pad04[0x48 - 0x04];
    Slot_60CF0 slots[15];
    char pad1B0[0x1B4 - 0x1B0];
    int x1B4;
    int x1B8;
    char pad1BC[0x1C0 - 0x1BC];
    Req_60CF0 req;
    Sub_60CF0 sub;
};
extern "C" {
extern char D_004E1730[];
void GuiWidget_ctor(void* p);
void cFileMan_ctor_void(void* m);
void cArray_tQuip_ctor(Sub_60CF0* s);
void cSndFx_ctor_void(void* m);
}
#pragma opt_propagation off
#pragma opt_unroll_loops off
extern "C" W_60CF0* GuiEndGameAwards_ctor(W_60CF0* self)
{
    Req_60CF0* p;
    Sub_60CF0* s;
    int i;
    GuiWidget_ctor(self);
    p = &self->req;
    self->vt = D_004E1730;
    p->h24.v = -2;
    p->w20 = 0;
    cFileMan_ctor_void(p->memberA);
    cFileMan_ctor_void(p->memberB);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    { H_60CF0 h; H_60CF0* hp = &h; h.v = -1; p->h24 = *hp; }
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    s = &self->sub;
    cArray_tQuip_ctor(s);
    cSndFx_ctor_void(s->menu);
    s->x10 = 0;
    s->x1B0 = 0;
    self->x1B4 = 0;
    self->x1B8 = -1;
    i = 0;
    {
        W_60CF0* w = self;
        do {
            w->slots[0].a = 0; w->slots[0].b = 0;
            w->slots[1].a = 0; w->slots[1].b = 0;
            w->slots[2].a = 0; w->slots[2].b = 0;
            w->slots[3].a = 0; w->slots[3].b = 0;
            w->slots[4].a = 0; w->slots[4].b = 0;
            i += 5;
            w = (W_60CF0*)((char*)w + 5 * sizeof(Slot_60CF0));
        } while (i < 15);
    }
    return self;
}
static inline void merge_flush_func_00460CF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00460CF0 */

/* merge_units: begin func_00460E00 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int cFileMan_dtor(int, int);                            
int func_00461DC0(int, int);                            
int operator_delete(int);                             

int cQuipList_dtor(int arg0, long long arg1) {
    if (arg0 != 0) {
        if ((arg0 + 0x20) != 0) {
            cFileMan_dtor(arg0 + 0x104, -1);
            cFileMan_dtor(arg0 + 0x68, -1);
        }
        if ((arg0 != 0) && (arg0 != 0) && (arg0 != 0)) {
            func_00461DC0(arg0, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
static inline void merge_flush_func_00460E00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00460E00 */
