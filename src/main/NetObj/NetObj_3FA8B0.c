/*
 * main/NetObj: 3 files, 003FA8B0-003FA940
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FA8B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003FA8B0(Iter* out, Tree* t) {
    out->p = t->leftmost;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FA8B0 */

/* merge_units: begin func_003FA8C0 */
#pragma push /* merge_units */
typedef struct { char pad[8]; int a; unsigned char flag; char pad2[3]; int b; } MapEntry;

extern char D_0055C7A0[];
extern MapEntry* NetRecvMap_Insert(void* map, int* key);

/* Looks up key in the global map and stores a, b and flag in the entry. */
void func_003FA8C0(int a, int key, int b, unsigned char flag)
{
    NetRecvMap_Insert(D_0055C7A0, &key)->a = a;
    NetRecvMap_Insert(D_0055C7A0, &key)->b = b;
    NetRecvMap_Insert(D_0055C7A0, &key)->flag = flag;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FA8C0 */

/* merge_units: begin func_003FA940 */
#pragma push /* merge_units */
#pragma cplusplus on
class Peer_A940 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void Notify(int id);
    char pad4[8];
    int h;
    char pad10[4];
    unsigned char active;
};
typedef struct Node_A940 { char pad[0x10]; Peer_A940* peer; } Node_A940;
typedef struct Iter_A940 { Node_A940* p; } Iter_A940;
struct IterW_A940 { Iter_A940 i; };
extern "C" {
extern char D_0055C780[];
extern unsigned char D_00572400;
extern void DME_SendPlayGameMsg(void);
extern Peer_A940* Player_GetCached(void);
extern void func_003FAAA0(Iter_A940* out, void* map);
extern void func_0021D360(Iter_A940* out, void* map);
extern void func_0021D350(Iter_A940* out, Iter_A940* in);
extern void Tree_Successor(Iter_A940* it);
extern void func_003FAC40(int a);
void func_003FA940(int id);
}
static inline int Eq_A940(Iter_A940* a, Iter_A940* b) { return a->p == b->p; }
#pragma push
#pragma opt_propagation off
void func_003FA940(int id)
{
    Peer_A940* self;
    Iter_A940 it;
    Iter_A940 b2;
    Iter_A940 end;
    Iter_A940 b1;
    Iter_A940 e1;
    D_0055C780[id] = 2;
    if (D_00572400) {
        DME_SendPlayGameMsg();
    }
    self = Player_GetCached();
    self->Notify(id);
    func_003FAAA0(&b1, D_0055C7A0);
    func_0021D350(&b2, &b1);
    *(IterW_A940*)&it = *(IterW_A940*)&b2;
    for (func_0021D360(&e1, D_0055C7A0), func_0021D350(&end, &e1); Eq_A940(&it, &end) ^ 1; func_0021D360(&e1, D_0055C7A0), func_0021D350(&end, &e1)) {
        Peer_A940* p = it.p->peer;
        if (p && p->active && p->h != self->h) {
            p->Notify(id);
        }
        func_003FAC40(0);
        Tree_Successor(&it);
    }
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003FA940 */
