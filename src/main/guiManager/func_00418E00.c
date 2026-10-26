#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

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
void GuiManager_RemoveWidget(M_418E00* m, W_418E00* w);
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_004BF138[];
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

extern "C" void GuiManager_UnloadRoot(M_418E00* m, W_418E00* w, int del)
{
    char* pos;
    char* end;

    Find_418(&pos, m, w);
    End_418(&end, m);
    if (pos != end) {
        if (!(w->f14 & 0x40) || del) {
            w->f14 |= 0x40;
            if (del) {
                GuiManager_RemoveWidget(m, w);
                {
                    W_418E00* p = w;
                    AllocGuard g;
                    p->~W_418E00();
                    Mem_Free(0, p, D_004BF138, 0xDB);
                }
            } else {
                std_list_GuiWidgetPtr_push_back_GuiWidgetPR(m->pending, &w);
            }
        }
    }
}
