#pragma cplusplus on
#include "types.h"
struct E_183C00 { int words[28]; };
struct V_183C00 { int capacity; int count; E_183C00* data; };
extern "C" E_183C00* std_msl_copy_cCollisionFace_copy(E_183C00* first, E_183C00* last, E_183C00* dest);
extern "C" E_183C00* std_vector_imp_cCollisionFace_erase(V_183C00* self, E_183C00* first, E_183C00* last)
{
    if (first == last)
        return first;
    E_183C00* end = self->data + self->count;
    if (end - last)
        std_msl_copy_cCollisionFace_copy(last, end, first);
    self->count -= last - first;
    return first;
}