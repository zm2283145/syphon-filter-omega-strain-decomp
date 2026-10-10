#pragma cplusplus on
#include "types.h"
struct C5IdVec { int cap; int count; };
struct C5PtrVec { int a[4]; };
struct C5Terrain { char pad[0x1F4]; C5PtrVec objs; C5IdVec ids; char pad2[0x250 - 0x20C]; unsigned char resolved; };
struct C5IdIt { int* p; };
inline bool operator==(const C5IdIt& a, const C5IdIt& b) { return a.p == b.p; }
inline bool operator!=(const C5IdIt& a, const C5IdIt& b) { return !(a == b); }
inline int C5Deref(const C5IdIt& a) { return *a.p; }
extern "C" int** func_001741A0(C5IdVec* v);
extern "C" void func_001396D0(C5PtrVec* v, int n);
extern "C" void* Object_LookupById(const int& id);
extern "C" void func_00171C70(C5PtrVec* v, void* const& o);
extern "C" void Actor_VirtualLeaf175230(C5IdVec* v);
#pragma opt_common_subs off
extern "C" void Terrain_ResolveIdList(C5Terrain* t) {
    C5IdIt it;
    C5IdIt end;
    it.p = *func_001741A0(&t->ids);
    end.p = *func_001741A0(&t->ids) + t->ids.count;
    func_001396D0(&t->objs, t->ids.count);
    for (; it != end; it.p++) {
        func_00171C70(&t->objs, Object_LookupById(C5Deref(it)));
    }
    Actor_VirtualLeaf175230(&t->ids);
    t->resolved = 1;
}