/*
 * Libs/SFOLib/Source/guiManager: 3 files, 00418A80-00418E00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin guiManager_418A80 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x18]; unsigned short count; } E418A80;
extern E418A80* GuiManager_FindOpenGui(void* a, void* b, void* c);
extern E418A80* GuiManager_ConstructGui(void* a, void* b, void* c);
E418A80* GuiManager_OpenGui(void* a, void* b, void* c) {
    E418A80* e = GuiManager_FindOpenGui(a, b, c);
    if (e) {
        if (e->count) e->count++;
    } else {
        e = GuiManager_ConstructGui(a, b, c);
        if (e) e->count++;
    }
    return e;
}
static inline void merge_flush_guiManager_418A80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end guiManager_418A80 */

/* merge_units: begin func_00418B10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#include "alloc_guard.h"

struct PStr_418B10 {
    signed char len;
    char text[0x80];
};
static inline void Set_418B10(PStr_418B10* p, const char* s)
{
    char* d = (char*)p + 1;
    int n = 0;
    while ((*d++ = *s++) != 0) {
        if (++n < 0x7E) continue;
        n++;
        d[0] = '\n';
        d[1] = 0;
        break;
    }
    p->len = n;
}
static inline const char* ReadStr_418B10(char** cur)
{
    const char* s = *cur;
    while (*(*cur)++) {
    }
    return s;
}
struct W_418B10 {
    VPAD8(p) VPAD4(q) VPAD2(r)
    virtual void Load(char** cur);
    char pad4[0x20];
    W_418B10* f24;
};
extern "C" {
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
int strcmp(const char* a, const char* b);
W_418B10* AbstractWidgetClassRep_Create(char* name);
W_418B10* GuiInterfaceDecorator_ctor(void* p);
void GuiDecorator_Decorate(W_418B10* x, W_418B10* w);
void GuiWidget_AddChild(W_418B10* w, W_418B10* c);
extern char D_004BF110[];
extern char D_004BF120[];
extern char D_004BF138[];
}

extern "C" W_418B10* GuiManager_LoadWidget(void* ctx, char** cur, W_418B10* parent)
{
    PStr_418B10 type;
    PStr_418B10 extra;
    W_418B10* w;
    W_418B10* x;
    int i;
    int n;
    Set_418B10(&type, ReadStr_418B10(cur));
    Set_418B10(&extra, ReadStr_418B10(cur));
    w = 0;
    if (parent) {
        if (strcmp(type.text, D_004BF110) == 0) w = parent;
    } else {
        w = AbstractWidgetClassRep_Create(type.text);
    }
    if (!w) return 0;
    w->f24 = w;
    w->Load(cur);
    if (strcmp(extra.text, D_004BF120) == 0) {
        void* p;
        {
            AllocGuard g;
            p = cMemMan_Allocate(0, 0x90, D_004BF138, 0x100);
        }
        if (p) p = GuiInterfaceDecorator_ctor(p);
        x = (W_418B10*)p;
    } else {
        x = 0;
    }
    if (x) {
        GuiDecorator_Decorate(x, w);
        x->Load(cur);
    }
    n = *(unsigned short*)*cur;
    *cur += 2;
    for (i = 0; i < n; i++) {
        W_418B10* c = GuiManager_LoadWidget(ctx, cur, 0);
        if (c) {
            c->f24 = w;
            GuiWidget_AddChild(w, c);
        }
    }
    return w;
}
static inline void merge_flush_func_00418B10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00418B10 */

/* merge_units: begin func_00418E00 */
#pragma push /* merge_units */
#pragma cplusplus on

struct W_418E00 {
    virtual ~W_418E00();
    char pad4[0x10];
    unsigned short f14;
};
struct M_418E00 {
    char pad0[0x14];
    char list[0xC];
    char pending[0xC];
};
struct NI_418 { void* n; };
extern "C" {
int opNe_cLListIteratorR_cLListIteratorR_6(void* a, void* b);
void cLList_GuiWidgetPtr_End(void* out, void* list);
void cLListIterator_GuiWidgetPtr_ctor_cLListIteratorR(void* dst, void* src);
void cLListIterator_GuiWidgetPtr_opInc(void* it);
int* cLListIterator_GuiWidgetPtr_opMul(void* it);
void cLListIterator_GuiWidgetPtr_opAssign(void* dst, void* src);
void cLList_GuiWidgetPtr_Begin(void* out, void* list);
void cLListIterator_GuiWidgetPtr_ctor_void(void* it);
void std_list_GuiWidgetPtr_push_back_GuiWidgetPR(void* list, W_418E00** v);
NI_418 std_list_GuiWidgetPtr_end(void* list);
void cLListIterator_GuiWidgetPtr_ctor_listR(void* dst, const NI_418& src);
void GuiManager_Remove(M_418E00* m, W_418E00* w);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
}

/* list.end() converted to the const iterator (by-value temporary). */
static inline void End_418(char** out, M_418E00* m) { cLListIterator_GuiWidgetPtr_ctor_listR(out, std_list_GuiWidgetPtr_end(m->list)); }
/* Linear search for w; locals live at inline depth (stack slot order). */
static inline void Find_418(char** out, M_418E00* m, W_418E00*& w)
{
    int it;
    int b;
    int e;
    cLListIterator_GuiWidgetPtr_ctor_void(&it);
    cLList_GuiWidgetPtr_Begin(&b, m->list);
    cLListIterator_GuiWidgetPtr_opAssign(&it, &b);
    cLList_GuiWidgetPtr_End(&e, m->list);
    if (opNe_cLListIteratorR_cLListIteratorR_6(&it, &e) != 0) {
loopf:
        if ((W_418E00*)*cLListIterator_GuiWidgetPtr_opMul(&it) != w) {
            cLListIterator_GuiWidgetPtr_opInc(&it);
            cLList_GuiWidgetPtr_End(&e, m->list);
            if (opNe_cLListIteratorR_cLListIteratorR_6(&it, &e) != 0) goto loopf;
        }
    }
    cLListIterator_GuiWidgetPtr_ctor_cLListIteratorR(out, &it);
}

extern "C" void GuiManager_DestroyWidget(M_418E00* m, W_418E00* w, int del)
{
    char* pos;
    char* end;

    Find_418(&pos, m, w);
    End_418(&end, m);
    if (pos != end) {
        if (!(w->f14 & 0x40) || del) {
            w->f14 |= 0x40;
            if (del) {
                GuiManager_Remove(m, w);
                {
                    W_418E00* p = w;
                    AllocGuard g;
                    p->~W_418E00();
                    cMemMan_Deallocate(0, p, D_004BF138, 0xDB);
                }
            } else {
                std_list_GuiWidgetPtr_push_back_GuiWidgetPR(m->pending, &w);
            }
        }
    }
}
static inline void merge_flush_func_00418E00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00418E00 */
