#pragma cplusplus on
#include "types.h"
struct Ent_250EE0 { unsigned char a; float b; };
struct Vec_250EE0 { int cap; int count; Ent_250EE0* data; };
extern "C" Ent_250EE0* func_00250EE0(Vec_250EE0* v, Ent_250EE0* first, Ent_250EE0* last)
{
    Ent_250EE0* end;
    Ent_250EE0* s;
    Ent_250EE0* d;
    if (first == last)
        return first;
    end = v->data + v->count;
    if (end - last) {
        d = first;
        for (s = last; s < end; s++, d++)
            *d = *s;
    }
    v->count -= last - first;
    return first;
}

