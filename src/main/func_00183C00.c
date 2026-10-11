#pragma cplusplus on
#include "types.h"
struct E_183C00 { int words[28]; };
struct V_183C00 { int capacity; int count; E_183C00* data; };
extern "C" E_183C00* func_00183CD0(E_183C00* first, E_183C00* last, E_183C00* dest);
extern "C" E_183C00* func_00183C00(V_183C00* self, E_183C00* first, E_183C00* last)
{
    if (first == last)
        return first;
    E_183C00* end = self->data + self->count;
    if (end - last)
        func_00183CD0(last, end, first);
    self->count -= last - first;
    return first;
}