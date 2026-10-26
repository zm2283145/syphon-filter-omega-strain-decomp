#include "types.h"
typedef struct { char c; } Tag0020C110;
extern void* std_vector_deleter_cSkaTransBLEND_alloc_void_2(void* other);
extern void std_vector_deleter_cSkaTransBLEND_ctor_cAllocatorR(void* self, void* v);
extern void* std_vector_imp_cSkaTransBLEND_begin_void_2(void* other);
extern void* std_vector_imp_cSkaTransBLEND_end_void_2(void* other);
extern void std_vector_imp_cSkaTransBLEND_init(void* self, void* first, void* last, Tag0020C110 tag);
#pragma optimization_level 1
void* std_vector_imp_cSkaTransBLEND_ctor_vectorimpR(void* self, void* other)
{
    void* first;
    void* last;
    Tag0020C110 arg;
    Tag0020C110 tag;
    std_vector_deleter_cSkaTransBLEND_ctor_cAllocatorR(self, std_vector_deleter_cSkaTransBLEND_alloc_void_2(other));
    first = std_vector_imp_cSkaTransBLEND_begin_void_2(other);
    last = std_vector_imp_cSkaTransBLEND_end_void_2(other);
    arg = tag;
    std_vector_imp_cSkaTransBLEND_init(self, first, last, arg);
    return self;
}
#pragma optimization_level reset