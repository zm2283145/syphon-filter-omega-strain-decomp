#include "types.h"

extern int* std_list_deleter_voidPtr_sz_void_2(void* obj);

/* Returns the int pointed to by std_list_deleter_voidPtr_sz_void_2's result. */
int std_list_imp_voidPtr_size(void* obj) {
    return *std_list_deleter_voidPtr_sz_void_2(obj);
}
