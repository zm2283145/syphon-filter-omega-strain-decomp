#pragma cplusplus on

#include "types.h"
#include "nested_null_dtor.h"

/* Deleting destructor around an out-of-line base destructor. */
DEFINE_NESTED_NULL_DTOR2(cArray_void_cSystem_dtor, std_vector_imp_void_cSystem_1_dtor)
