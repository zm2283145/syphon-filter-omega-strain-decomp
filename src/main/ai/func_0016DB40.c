#include "types.h"
typedef struct { char pad[0xC]; int serial; } Tgt_DB40;
typedef struct { Tgt_DB40* target; int serial; } Rec_DB40;
typedef struct Node_DB40 { int pad0; struct Node_DB40* next; Rec_DB40* val; } Node_DB40;
typedef struct { Node_DB40* n; } It_DB40;
typedef struct { int a; } E_DB40;
extern void func_0013B160(E_DB40* out);
extern void func_0016DB20(It_DB40* out, E_DB40* in);
extern void func_0016BB80(E_DB40* out, void* map);
extern void func_0016BBA0(E_DB40* out, void* map);
extern void func_0016BB90(It_DB40* out, E_DB40* in);
void NpcPerception_FindRecord(It_DB40* out, void* map, Tgt_DB40* key)
{
    It_DB40 it;
    It_DB40 b;
    It_DB40 end;
    It_DB40 a;
    E_DB40 t0;
    E_DB40 t1;
    E_DB40 t2;
    func_0013B160(&t0);
    func_0016DB20(&a, &t0);
    it.n = a.n;
    if (key) {
        func_0016BBA0(&t1, map);
        func_0016BB90(&b, &t1);
        it = b;
        while (func_0016BB80(&t2, map), func_0016BB90(&end, &t2), it.n != end.n) {
            unsigned char ok;
            int isNull;
            Tgt_DB40* c;
            Rec_DB40* h;
            h = it.n->val;
            c = h->target;
            isNull = !c;
            ok = 1;
            if (!isNull)
                if (c->serial != h->serial)
                    ok = 0;
            if ((ok ? c : 0) == key)
                break;
            it.n = it.n->next;
        }
    }
    out->n = it.n;
}





