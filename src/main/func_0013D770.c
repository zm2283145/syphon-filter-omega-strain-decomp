#include "types.h"
#pragma cplusplus on

struct E3ZItem { int key; };
struct E3ZNode { int unk0; E3ZNode* next; E3ZItem* data; };
struct E3ZList { int unk0; E3ZNode sentinel; };
struct E3ZPtr { E3ZNode* n; };
struct E3ZIt {
    E3ZPtr p;
    E3ZItem* operator*() const { return p.n->data; }
    E3ZIt& operator++() { p.n = p.n->next; return *this; }
};

extern "C" E3ZIt* func_0013D890(E3ZIt* out, E3ZList* l);
extern "C" E3ZIt* func_0013D870(E3ZIt* out, E3ZNode* n);
extern "C" E3ZIt* func_0013D840(E3ZIt* out, E3ZList* l);
extern "C" E3ZIt* func_0013D830(E3ZIt* out, E3ZIt* src);

/* Finds the list entry whose key matches. */
extern "C" E3ZItem* func_0013D770(E3ZList* l, int key) {
    E3ZIt it;
    E3ZIt c;
    E3ZIt e;
    E3ZIt a;
    E3ZIt b;
    E3ZNode* end;
    func_0013D890(&a, l);
    func_0013D870(&e, a.p.n);
    end = e.p.n;
    func_0013D840(&b, l);
    func_0013D830(&c, &b);
    for (it = c; it.p.n != end; ++it) {
        E3ZItem* d = *it;
        if (d->key == key) {
            return d;
        }
    }
    return 0;
}