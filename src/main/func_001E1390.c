#pragma cplusplus on
#include "types.h"
#pragma opt_common_subs off
struct It1E1390 { char* p; };
extern "C" {
char* std_vector_imp_cCollisionEdgePtr_1_begin(void* v);
char* std_vector_imp_cCollisionEdgePtr_1_end(void* v);
void std_vector_cCollisionEdgePtr_pointer2iterator(It1E1390* out, void* v, char** p);
void std_vector_cCollisionEdgePtr_push_back(void* self, char* elem);
}
static inline bool It1E1390_eq(char* a, char* b) { return a == b; }
static inline bool It1E1390_ne(char* a, char* b) { return !It1E1390_eq(a, b); }
extern "C" void cEdgeGroup_Append(void* self, void* v)
{
    It1E1390 it;
    It1E1390 end;
    char* p;
    char* e;
    {
        char* t = std_vector_imp_cCollisionEdgePtr_1_begin(v);
        std_vector_cCollisionEdgePtr_pointer2iterator(&it, v, &t);
    }
    p = it.p;
    {
        char* t = std_vector_imp_cCollisionEdgePtr_1_end(v);
        std_vector_cCollisionEdgePtr_pointer2iterator(&end, v, &t);
    }
    e = end.p;
    for (; It1E1390_ne(p, e); p += 4)
        std_vector_cCollisionEdgePtr_push_back(self, p);
}