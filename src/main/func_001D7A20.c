#pragma cplusplus on
#include "types.h"
struct It1D7A20 { char* p; };
extern "C" {
char* std_vector_imp_cBone_begin(void* v);
char* std_vector_imp_cBone_end(void* v);
void std_vector_cBone_pointer2iterator(It1D7A20* out, void* v, char** p);
extern char* UpperBodyNodeTable[];
}
struct O1D7A20 { int pad; char* list; };
static inline bool It1D7A20_eq(char* a, char* b) { return a == b; }
static inline bool It1D7A20_ne(char* a, char* b) { return !It1D7A20_eq(a, b); }
extern "C" void cHumanIkRoutine_InitializeWorkspaceAtStartOfNextFrame(O1D7A20* o)
{
    void* v = o->list + 0x18;
    It1D7A20 it;
    It1D7A20 end;
    char* p;
    {
        char* t = std_vector_imp_cBone_begin(v);
        std_vector_cBone_pointer2iterator(&it, v, &t);
    }
    p = it.p;
    {
        char* t = std_vector_imp_cBone_end(v);
        std_vector_cBone_pointer2iterator(&end, v, &t);
    }
    char** out = UpperBodyNodeTable;
    char* e = end.p;
    for (; It1D7A20_ne(p, e); p += 0x1D0) {
        *out = p;
        out += 0x40;
    }
}