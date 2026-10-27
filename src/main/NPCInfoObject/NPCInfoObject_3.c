/*
 * main/NPCInfoObject: 2 files, 004361C0-00436380
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004361C0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int key; unsigned char b4; unsigned char state; unsigned char a6[4]; unsigned char aA[4]; } NpcInfoRec;
extern NpcInfoRec* D_005827F0;
extern NpcInfoRec* D_005827F8;
extern NpcInfoRec* D_00582800;
extern NpcInfoRec* D_00582808;
extern NpcInfoRec* D_00582810;
extern int D_00582A78;
extern int D_00582A80;
extern int D_00582A88;
extern int D_00582A90;
extern int D_00582A98;

static inline int Eq_61C0(int* a, int* b) { return *a == *b; }
NpcInfoRec* cNPCInfoObject_Find(int* key, int* out)
{
    int i;
    for (i = 0; i != 29; i++) {
        if (D_005827F0 && Eq_61C0(&D_005827F0[i].key, key)) {
            if (out) *out = D_00582A78;
            return &D_005827F0[i];
        }
        if (D_005827F8 && Eq_61C0(&D_005827F8[i].key, key)) {
            if (out) *out = D_00582A80;
            return &D_005827F8[i];
        }
        if (D_00582800 && Eq_61C0(&D_00582800[i].key, key)) {
            if (out) *out = D_00582A88;
            return &D_00582800[i];
        }
        if (D_00582808 && Eq_61C0(&D_00582808[i].key, key)) {
            if (out) *out = D_00582A90;
            return &D_00582808[i];
        }
        if (D_00582810 && Eq_61C0(&D_00582810[i].key, key)) {
            if (out) *out = D_00582A98;
            return &D_00582810[i];
        }
    }
    if (out) *out = -1;
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_004361C0 */

/* merge_units: begin func_00436380 */
#pragma push /* merge_units */
/* cNPCInfoObject_Clear: teardown of five object lists and one tree (free every element, erase/clear),
 * then reset of the module globals. Shape follows the matched cGenInfoObject_Clear (GenInfoObject). */
#pragma cplusplus on
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
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(int* out, void* list, LNode** first, LNode** last);
LIt std_list_deleter_voidPtr_begin_void(void* list);
void std_list_tNPCInfoPtr_generic_iterator_ctor(LIt* out, const LIt& in);
LIt std_list_tNPCInfoPtr_end(void* list);
void cLListIterator_tNPCInfoPtr_ctor(LIt* out, const LIt& in);
LIt std_list_tNPCInfoPtr_begin(void* list);
void std_tree_pair_tNPCInfoPtr_value_compare_begin(TIt* out, void* tree);
TIt std_map_tNPCInfoPtr_bool_end(void* tree);
void cAssocArray_tNPCInfoPtr_bool_Iterator_ctor(TIt* out, const TIt& in);
void std_red_black_tree_1_increment(TIt* it);
void std_tree_pair_tNPCInfoPtr_value_compare_clear(void* tree);
void cNPCInfoObject_DestroyNPCInfoStruct(void* self);
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
#if 0 /* merge_units */
extern int D_005827F0;
#endif /* merge_units */
#define D_005827F0 (*(int*)&D_005827F0) /* merge_units */

#if 0 /* merge_units */
extern int D_005827F8;
#endif /* merge_units */
#define D_005827F8 (*(int*)&D_005827F8) /* merge_units */

#if 0 /* merge_units */
extern int D_00582800;
#endif /* merge_units */
#define D_00582800 (*(int*)&D_00582800) /* merge_units */

#if 0 /* merge_units */
extern int D_00582808;
#endif /* merge_units */
#define D_00582808 (*(int*)&D_00582808) /* merge_units */

#if 0 /* merge_units */
extern int D_00582810;
#endif /* merge_units */
#define D_00582810 (*(int*)&D_00582810) /* merge_units */

extern int D_00582B60;
extern int D_00582B68;
extern int D_00582B70;
extern int D_00582B78;
extern int D_00582B80;
}

static inline void LB1(LIt* o, void* L) { std_list_tNPCInfoPtr_generic_iterator_ctor(o, std_list_deleter_voidPtr_begin_void(L)); }
static inline void LB2(LIt* o, void* L) { cLListIterator_tNPCInfoPtr_ctor(o, std_list_tNPCInfoPtr_begin(L)); }
static inline void LE(LIt* o, void* L) { cLListIterator_tNPCInfoPtr_ctor(o, std_list_tNPCInfoPtr_end(L)); }
static inline void TE(TIt* o, void* T) { cAssocArray_tNPCInfoPtr_bool_Iterator_ctor(o, std_map_tNPCInfoPtr_bool_end(T)); }
static inline void LB1x(LIt* o, void* L) { LB1(o, L); }
static inline void LB2x(LIt* o, void* L) { LB2(o, L); }
static inline void LEx(LIt* o, void* L) { LE(o, L); }
static inline void TEx(TIt* o, void* T) { TE(o, T); }
static inline void Erase(void* L, void* LH, LNode* LF) { int res; LNode* first; LNode* last; last = (LNode*)LH; first = LF; std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&res, L, &first, &last); }
static inline unsigned char Ne(TIt* a, TIt* b) { return !(a->node == b->node); }

extern "C" void cNPCInfoObject_Clear(void* self)
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
            cMemMan_Deallocate(0, e, D_004BFCA0, 0x7B);
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
                cMemMan_Deallocate(0, e, D_004BFCA0, 0x86);
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
                cMemMan_Deallocate(0, e, D_004BFCA0, 0x91);
            }
            itx.p = itx.p->next;
        }
    }
    Erase(D_00582AF0, D_00582AF4, D_00582AF8);
    TIt tb;
    std_tree_pair_tNPCInfoPtr_value_compare_begin(&tb, D_00582B50);
    it = tb;
    while (TEx(&tend, D_00582B50), Ne(&it, &tend)) {
        void* e = it.node->data;
        {
            AllocGuard g;
            cMemMan_Deallocate(0, e, D_004BFCA0, 0x9C);
        }
        std_red_black_tree_1_increment(&it);
    }
    std_tree_pair_tNPCInfoPtr_value_compare_clear(D_00582B50);
    LB2x((LIt*)&bE, D_00582B30);
    {
        itx = *(LItU*)&bE;
        while (LEx((LIt*)&endE, D_00582B30), itx.p != endE.p) {
            void* e = itx.p->data;
            {
                AllocGuard g;
                cMemMan_Deallocate(0, e, D_004BFCA0, 0xA7);
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
                cMemMan_Deallocate(0, e, D_004BFCA0, 0xB1);
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
        cNPCInfoObject_DestroyNPCInfoStruct(self);
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
#undef D_005827F0 /* merge_units */
#undef D_005827F8 /* merge_units */
#undef D_00582800 /* merge_units */
#undef D_00582808 /* merge_units */
#undef D_00582810 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00436380 */
