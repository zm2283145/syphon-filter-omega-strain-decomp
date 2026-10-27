#include "types.h"

typedef struct { char tag; } Alloc;

extern void* std_vector_imp_cSkaTransBLEND_begin_void_2(void* other);
extern void* std_vector_imp_cSkaTransBLEND_end_void_2(void* other);
extern void std_vector_imp_cSkaTransBLEND_do_assign(void* self, void* first, void* last, Alloc alloc);

#pragma optimization_level 1
/* Assigns the contents of other to self unless they are the same object; returns self (unit built at -O1). */
void* std_vector_imp_cSkaTransBLEND_opAssign(void* self, void* other)
{
    if (self != other) {
        Alloc a;
        Alloc b;
        void* first = std_vector_imp_cSkaTransBLEND_begin_void_2(other);
        void* last = std_vector_imp_cSkaTransBLEND_end_void_2(other);
        b = a;
        std_vector_imp_cSkaTransBLEND_do_assign(self, first, last, b);
    }
    return self;
}
#pragma optimization_level reset
