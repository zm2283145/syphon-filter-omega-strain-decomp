#pragma cplusplus on
#include "types.h"
extern "C" int strcmp(const char* a, const char* b);
struct C5SkelEntry { const char* name; void* skel; };
struct C5SkelNode { struct C5SkelNode* prev; struct C5SkelNode* next; C5SkelEntry* entry; };
struct C5RawIt { C5SkelNode* n; };
struct C5RawIt2 { C5SkelNode* n; C5RawIt2() {} C5RawIt2(const C5RawIt2& o) : n(o.n) {} };
struct C5It { C5SkelNode* n; C5It() {} C5It(const C5It& o) : n(o.n) {} };
struct C5SkelMap;
extern "C" C5RawIt func_0016E880(C5SkelMap* m);
extern "C" C5It func_003AA270(C5RawIt r);
extern "C" C5RawIt2 func_003AA240(C5SkelMap* m);
extern "C" C5It func_003AA230(C5RawIt2 r);
extern "C" char D_005429B0[];
inline C5It C5End(C5SkelMap* m) { return func_003AA230(func_003AA240(m)); }
inline C5It C5Begin(C5SkelMap* m) { return func_003AA270(func_0016E880(m)); }
inline bool operator!=(const C5It& a, const C5It& b) { return a.n != b.n; }
extern "C" void* Skel_Find(C5SkelMap* m, const char* name) {
    for (C5It it = C5Begin(m); it != C5End(m); it.n = it.n->next) {
        if (strcmp(it.n->entry->name, name) == 0)
            return it.n->entry->skel;
    }
    return D_005429B0;
}