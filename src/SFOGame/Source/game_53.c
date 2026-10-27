/*
 * SFOGame/Source/game: 7 files, 001387C0-00138B70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001387C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "game_types.h"

extern char D_004DFD80[]; /* cMessage vtable */

/* Copy constructor: sets the vtable and copies the payload fields from src. */
cMessage* cMessage_ctor_cMessageR(cMessage* self, cMessage* src) {
    self->vtable = D_004DFD80;
    self->args[0] = src->args[0];
    self->args[1] = src->args[1];
    self->args[2] = src->args[2];
    self->args[3] = src->args[3];
    self->args[4] = src->args[4];
    self->args[5] = src->args[5];
    self->args[6] = src->args[6];
    self->flag = src->flag;
    return self;
}
static inline void merge_flush_func_001387C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001387C0 */

/* merge_units: begin func_00138820 */
#pragma push /* merge_units */
#pragma cplusplus on
struct M_00138820 { char pad[0x24]; signed char b24; char pad2[3]; int x28; unsigned char b2C; unsigned char b2D; };
extern "C" { extern char* D_005061D0; void cAgentData_NetPackStats(int x); void cAgentData_NetPack(int x); }
static inline void WriteByte(char v) { *D_005061D0 = v; D_005061D0++; }
extern "C" void cNetAgentUpdateMsg_Pack(M_00138820* m)
{
    WriteByte(m->b24);
    WriteByte(m->b2C);
    WriteByte(m->b2D);
    if (m->b2C) cAgentData_NetPackStats(m->x28);
    else cAgentData_NetPack(m->x28);
}
static inline void merge_flush_func_00138820(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00138820 */

/* merge_units: begin func_001388D0 */
#pragma push /* merge_units */
extern int D_004EA0A0;

/* Returns the value of global D_004EA0A0. */
int cNetAgentUpdateMsg_GetMsgId(void) {
    return D_004EA0A0;
}
static inline void merge_flush_func_001388D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001388D0 */

/* merge_units: begin func_001388E0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "net_msg_clone.h"
#pragma pop

#pragma cplusplus on

#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
/* Clone a network message. */
DEFINE_NET_MSG_CLONE(cNetAgentUpdateMsg_Clone, 0x30, D_0049A890, 0xC68, D_004D91A0,
                     NMC_B(0x24); NMC_W(0x28); NMC_UB(0x2C); NMC_UB(0x2D))
static inline void merge_flush_func_001388E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001388E0 */

/* merge_units: begin func_00138A10 */
#pragma push /* merge_units */
extern int* cMessage_Name(void*);
extern int cSystem_HandleMessage(void*, void*);
extern int cLosManager_cCollisionModelList_Game_NextFrame(void*);
extern int cLosManager_cCollisionModelList_Game_HandleRequest(void*, void*);
extern int g_LosRequestMsgClass;
extern int D_005436B0;
int cLosManager_cCollisionModelList_Game_HandleMessage(void* self, void* event)
{
    int type = *cMessage_Name(event);
    if (type == D_005436B0)
        return cLosManager_cCollisionModelList_Game_NextFrame(self);
    type = *cMessage_Name(event);
    if (type == g_LosRequestMsgClass)
        return cLosManager_cCollisionModelList_Game_HandleRequest(self, event);
    return cSystem_HandleMessage(self, event);
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
extern "C" void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(AIter*, AList*, AIter*, AIter*);

extern "C" void std_list_imp_voidPtr_remove_if(AList* l, APred pred)
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
                std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&r, l, &a, &b);
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

/* merge_units: begin game_138B70 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"
extern "C" { char D_0049AE90[] = "allocator.hh"; }

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(String_Dtor)
static inline void merge_flush_game_138B70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end game_138B70 */
