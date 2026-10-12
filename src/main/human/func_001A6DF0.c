#pragma cplusplus on
#include "types.h"
extern "C" {
#include "root_mark_dirty_tree.h"
}
struct It { int* p; };
struct Vec { int pad; int count; int* data; };
struct RNode {
    char pad[0xA0];
    unsigned char dirty0;
    unsigned char dirty1;
    unsigned char dirty2;
    char padA3[0x11];
    Vec kids;               /* 0xB4 */
};
extern "C" {
RNode** func_001A7060(Vec* v);
RNode** func_001A7040(Vec* v);
unsigned char func_001A7030(Vec* v);
It* func_001A7020(It* out, Vec* v);
It* func_001A7010(It* d, It* s);
It* func_001A6FF0(It* out, Vec* v);
unsigned char func_001A6FC0(It* a, It* b);
RNode** func_001A6FE0(It* it);
}
static inline bool NotEmpty(Vec* v) { return !(v->count == 0); }
static inline bool NotEmpty2(Vec* v) { return !(func_001A7030(v) != 0); }
static inline bool NotEnd(It* a, It* b) { return !(func_001A6FC0(a, b) != 0); }
static inline bool Neq(RNode** a, RNode** b) { return !(a == b); }
/* Marks each child (and each grandchild's subtree) dirty. */
extern "C" void Root_PropagateChildren(RNode* self)
{
    if (NotEmpty(&self->kids)) {
        RNode* n;
        RNode** end;
        RNode** it;
        it = func_001A7060(&self->kids);
        end = func_001A7040(&self->kids);
        for (; Neq(it, end); it++) {
            n = *it;
            n->dirty0 = 1;
            n->dirty1 = 1;
            n->dirty2 = 1;
            if (NotEmpty2(&n->kids)) {
                It cur;
                It last;
                It t0;
                It t1;
                func_001A7020(&t0, &n->kids);
                func_001A7010(&cur, &t0);
                func_001A6FF0(&t1, &n->kids);
                func_001A7010(&last, &t1);
                for (; NotEnd(&cur, &last); cur.p++) {
                    RootDirtyNode* c = (RootDirtyNode*)*func_001A6FE0(&cur);
                    RootDirtyIt ci;
                    RootDirtyIt ce;
                    c->dirty0 = 1;
                    c->dirty1 = 1;
                    c->dirty2 = 1;
                    if (func_001913E0(c)) {
                        func_001913C0(&ci, func_001913D0(c));
                        func_001913A0(&ce, func_001913D0(c));
                        for (; func_001912A0(&ci, &ce); func_001912C0(&ci))
                            func_001912E0(*func_00191390(&ci));
                    }
                }
            }
        }
    }
}






