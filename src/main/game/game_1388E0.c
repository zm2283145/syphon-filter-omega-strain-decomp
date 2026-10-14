/*
 * main/game: range (3 files, 001388E0-00138AB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "net_msg_clone.h"
#pragma pop

/* merge_units: begin func_001388E0 */
#pragma push /* merge_units */
#pragma cplusplus on

#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
/* Clone a network message. */
DEFINE_NET_MSG_CLONE(cNetAgentUpdateMsg_v01, 0x30, D_0049A890, 0xC68, D_004D91A0,
                     NMC_B(0x24); NMC_W(0x28); NMC_UB(0x2C); NMC_UB(0x2D))
#pragma pop /* merge_units */
/* merge_units: end func_001388E0 */

/* merge_units: begin func_00138A10 */
#pragma push /* merge_units */
extern int* Event_GetType(void*);
extern int Receiver_HandleEventBase(void*, void*);
extern int LosMgr_Update(void*);
extern int LosReceiver_HandleRequest(void*, void*);
extern int D_005435A0;
extern int D_005436B0;
int LosReceiver_HandleEvent(void* self, void* event)
{
    int type = *Event_GetType(event);
    if (type == D_005436B0)
        return LosMgr_Update(self);
    type = *Event_GetType(event);
    if (type == D_005435A0)
        return LosReceiver_HandleRequest(self, event);
    return Receiver_HandleEventBase(self, event);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00138A10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00138A10 */

/* merge_units: begin func_00138AB0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct ANode { ANode* prev; ANode* next; int val; };
struct APred { int pad; int* p; bool operator()(const int& x) const { return x == *p; } };
struct AIter {
    ANode* n;
    AIter() {}
    AIter(ANode* q) : n(q) {}
    int& operator*() const { return n->val; }
    AIter& operator++() { n = n->next; return *this; }
    bool operator==(const AIter& o) const { return n == o.n; }
    bool operator!=(const AIter& o) const { return n != o.n; }
};
struct AList {
    int size; ANode head;
    AIter begin() { return AIter(head.next); }
    AIter end() { return AIter(&head); }
};
extern "C" void ObjectList_EraseRange(AIter*, AList*, AIter*, AIter*);

extern "C" void ActiveList_EraseMatching(AList* l, APred pred)
{
    AIter e = l->end();
    for (AIter i = l->begin(); i != e;) {
        if (pred(*i)) {
            AIter j = i;
            for (++j; j != e; ++j)
                if (!pred(*j)) break;
            {
                AIter r, a, b;
                a = i; b = j;
                ObjectList_EraseRange(&r, l, &a, &b);
                i = r;
            }
            if (i == e) break;
        }
        ++i;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00138AB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00138AB0 */
