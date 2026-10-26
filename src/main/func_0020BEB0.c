#include "types.h"
#pragma optimization_level 1
typedef struct { char d[0x24]; } E_20BEB0;
typedef struct { int a; int n; } V_20BEB0;
extern E_20BEB0** std_vector_deleter_cSkaTransBLEND_data_void_2(V_20BEB0* v);
E_20BEB0* std_vector_imp_cSkaTransBLEND_end_void_2(V_20BEB0* v)
{
    return *std_vector_deleter_cSkaTransBLEND_data_void_2(v) + v->n;
}
#pragma optimization_level reset