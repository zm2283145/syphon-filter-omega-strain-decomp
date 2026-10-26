#pragma cplusplus on

#include "types.h"
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cArray_cBaseObjListPtr_dtor, std_vector_imp_cBaseObjListPtr_1_dtor)