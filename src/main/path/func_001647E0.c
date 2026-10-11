#pragma cplusplus on
#include "types.h"
struct E_47E0 { int a[8]; };
struct V_47E0 {
    int cap; unsigned int count; E_47E0* data;
    unsigned int size() const { return count; }
    E_47E0* begin() { return data; }
    E_47E0* end() { return data + count; }
};
extern "C" void func_00164CA0(V_47E0* v, E_47E0* pos, unsigned int n, void* val);
extern "C" void func_00164BD0(V_47E0* v, E_47E0* first, E_47E0* last);
extern "C" void func_001647E0(V_47E0* v, unsigned int n, void* val)
{
    if (v->size() < n)
        func_00164CA0(v, v->end(), n - v->size(), val);
    else if (n < v->size())
        func_00164BD0(v, v->begin() + n, v->end());
}