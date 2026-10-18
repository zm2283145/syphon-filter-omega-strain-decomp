/* func_00436380: teardown of five object lists and one tree (free every element, erase/clear),
 * then reset of the module globals. Shape follows the matched func_0043ACE0 (GenInfoObject). */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct LNode { LNode* prev; LNode* next; void* data; };
struct LIt { LNode* p; __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~LIt() {} };
struct LIt2 { LNode* p; };
/* One list iterator shared by all five list loops. As a union its copies are block moves, so it stays in
 * memory; MW splits it into one live range per loop and gives loops 2-5 their own slots at the frame bottom. */
union LItU { LNode* p; };
struct TNode { char pad[0xC]; void* data; };
struct TIt { TNode* node; TIt() {} };

extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
void ObjectList_EraseRange(int* out, void* list, LNode** first, LNode** last);
LIt List_Begin(void* list);
void func_00432740(LIt* out, const LIt& in);
LIt func_00432730(void* list);
void func_00432720(LIt* out, const LIt& in);
LIt func_00436B90(void* list);
void func_00432F40(TIt* out, void* tree);
TIt func_00432F30(void* tree);
void func_00432F20(TIt* out, const TIt& in);
void Tree_Successor(TIt* it);
void func_00436C50(void* tree);
void func_00433760(void* self);
extern char D_004BFCA0[];
extern char D_00582AB0[];
extern char D_00582AB4[];
extern LNode* D_00582AB8;
extern char D_00582AD0[];
extern char D_00582AD4[];
extern LNode* D_00582AD8;
extern char D_00582AF0[];
extern char D_00582AF4[];
extern LNode* D_00582AF8;
extern char D_00582B10[];
extern char D_00582B14[];
extern LNode* D_00582B18;
extern char D_00582B30[];
extern char D_00582B34[];
extern LNode* D_00582B38;
extern char D_00582B50[];
extern unsigned char D_00582778;
extern unsigned char D_00582780;
extern unsigned char D_00582788;
extern unsigned char D_00582790;
extern unsigned char D_00582798;
extern int D_005827F0;
extern int D_005827F8;
extern int D_00582800;
extern int D_00582808;
extern int D_00582810;
extern int D_00582B60;
extern int D_00582B68;
extern int D_00582B70;
extern int D_00582B78;
extern int D_00582B80;
}

static inline void LB1(LIt* o, void* L) { func_00432740(o, List_Begin(L)); }
static inline void LB2(LIt* o, void* L) { func_00432720(o, func_00436B90(L)); }
static inline void LE(LIt* o, void* L) { func_00432720(o, func_00432730(L)); }
static inline void TE(TIt* o, void* T) { func_00432F20(o, func_00432F30(T)); }
static inline void LB1x(LIt* o, void* L) { LB1(o, L); }
static inline void LB2x(LIt* o, void* L) { LB2(o, L); }
static inline void LEx(LIt* o, void* L) { LE(o, L); }
static inline void TEx(TIt* o, void* T) { TE(o, T); }
static inline void Erase(void* L, void* LH, LNode* LF) { int res; LNode* first; LNode* last; last = (LNode*)LH; first = LF; ObjectList_EraseRange(&res, L, &first, &last); }
static inline unsigned char Ne(TIt* a, TIt* b) { return !(a->node == b->node); }

extern "C" void func_00436380(void* self)
{
    LItU itx;
    TIt it;
    LIt end1;
    LIt2 bB, endB, bC, endC;
    TIt tend;
    LIt2 bE, endE, bF, endF;

    LIt b1;
    LB1x(&b1, D_00582AB0);
    itx.p = b1.p;
    while (LEx(&end1, D_00582AB0), itx.p != end1.p) {
        void* e = itx.p->data;
        {
            AllocGuard g;
            Mem_Free(0, e, D_004BFCA0, 0x7B);
        }
        itx.p = itx.p->next;
    }
    Erase(D_00582AB0, D_00582AB4, D_00582AB8);
    LB2x((LIt*)&bB, D_00582AD0);
    {
        itx = *(LItU*)&bB;
        while (LEx((LIt*)&endB, D_00582AD0), itx.p != endB.p) {
            void* e = itx.p->data;
            {
                AllocGuard g;
                Mem_Free(0, e, D_004BFCA0, 0x86);
            }
            itx.p = itx.p->next;
        }
    }
    Erase(D_00582AD0, D_00582AD4, D_00582AD8);
    LB2x((LIt*)&bC, D_00582AF0);
    {
        itx = *(LItU*)&bC;
        while (LEx((LIt*)&endC, D_00582AF0), itx.p != endC.p) {
            void* e = itx.p->data;
            {
                AllocGuard g;
                Mem_Free(0, e, D_004BFCA0, 0x91);
            }
            itx.p = itx.p->next;
        }
    }
    Erase(D_00582AF0, D_00582AF4, D_00582AF8);
    TIt tb;
    func_00432F40(&tb, D_00582B50);
    it = tb;
    while (TEx(&tend, D_00582B50), Ne(&it, &tend)) {
        void* e = it.node->data;
        {
            AllocGuard g;
            Mem_Free(0, e, D_004BFCA0, 0x9C);
        }
        Tree_Successor(&it);
    }
    func_00436C50(D_00582B50);
    LB2x((LIt*)&bE, D_00582B30);
    {
        itx = *(LItU*)&bE;
        while (LEx((LIt*)&endE, D_00582B30), itx.p != endE.p) {
            void* e = itx.p->data;
            {
                AllocGuard g;
                Mem_Free(0, e, D_004BFCA0, 0xA7);
            }
            itx.p = itx.p->next;
        }
    }
    Erase(D_00582B30, D_00582B34, D_00582B38);
    LB2x((LIt*)&bF, D_00582B10);
    {
        itx = *(LItU*)&bF;
        while (LEx((LIt*)&endF, D_00582B10), itx.p != endF.p) {
            void* e = itx.p->data;
            {
                AllocGuard g;
                Mem_Free(0, e, D_004BFCA0, 0xB1);
            }
            itx.p = itx.p->next;
        }
    }
    Erase(D_00582B10, D_00582B14, D_00582B18);
    if (D_00582780) {
        D_005827F0 = 0;
        D_005827F8 = 0;
        D_00582800 = 0;
        D_00582808 = 0;
        D_00582810 = 0;
    } else {
        func_00433760(self);
    }
    D_00582778 = 0;
    D_00582780 = 0;
    D_00582788 = 0;
    D_00582790 = 0;
    D_00582798 = 0;
    D_00582B60 = 0;
    D_00582B68 = 0;
    D_00582B70 = 0;
    D_00582B78 = 0;
    D_00582B80 = 0;
}
