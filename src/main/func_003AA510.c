#pragma cplusplus on

#include "types.h"

/* Resize an array of 0x1D0-byte elements: grow with fill, or erase the tail. */
struct Elem_3AA510 { unsigned char b[0x1D0]; };
struct Arr_3AA510;
extern "C" {
void func_003AA7B0(Arr_3AA510* a, Elem_3AA510* pos, unsigned int n, const Elem_3AA510& fill);
void func_003AA640(Arr_3AA510* a, Elem_3AA510* first, Elem_3AA510* last);
}
struct Arr_3AA510 {
    int pad0;
    unsigned int count;
    Elem_3AA510* data;
    unsigned int size() const { return count; }
    Elem_3AA510* begin() { return data; }
    Elem_3AA510* end() { return data + count; }
};

extern "C" void func_003AA510(Arr_3AA510* a, unsigned int n, const Elem_3AA510& fill)
{
    if (a->size() < n)
        func_003AA7B0(a, a->end(), n - a->size(), fill);
    else if (n < a->size())
        func_003AA640(a, a->begin() + n, a->end());
}