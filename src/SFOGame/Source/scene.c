/*
 * SFOGame/Source/scene: 1 file, 0013D770
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin game_13D770 */
#pragma push /* merge_units */
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

extern "C" E3ZIt* std_list_deleter_voidPtr_end_void_2(E3ZIt* out, E3ZList* l);
extern "C" E3ZIt* std_list_cScenePtr_generic_iterator_1_ctor(E3ZIt* out, E3ZNode* n);
extern "C" E3ZIt* std_list_cScenePtr_begin(E3ZIt* out, E3ZList* l);
extern "C" E3ZIt* cConstLListIterator_cScenePtr_ctor(E3ZIt* out, E3ZIt* src);

/* Finds the list entry whose key matches. */
extern "C" E3ZItem* cSceneManager_GetSceneBelongingTo(E3ZList* l, int key) {
    E3ZIt it;
    E3ZIt c;
    E3ZIt e;
    E3ZIt a;
    E3ZIt b;
    E3ZNode* end;
    std_list_deleter_voidPtr_end_void_2(&a, l);
    std_list_cScenePtr_generic_iterator_1_ctor(&e, a.p.n);
    end = e.p.n;
    std_list_cScenePtr_begin(&b, l);
    cConstLListIterator_cScenePtr_ctor(&c, &b);
    for (it = c; it.p.n != end; ++it) {
        E3ZItem* d = *it;
        if (d->key == key) {
            return d;
        }
    }
    return 0;
}
static inline void merge_flush_game_13D770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end game_13D770 */
