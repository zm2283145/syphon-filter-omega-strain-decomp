#pragma cplusplus on
#include "types.h"
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
extern char D_0055C7A0[];
extern void func_00429B30(void);
extern Peer_A940* func_0040BF10(void);
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
        func_00429B30();
    }
    self = func_0040BF10();
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


