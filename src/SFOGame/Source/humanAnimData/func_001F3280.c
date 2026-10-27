#include "types.h"
typedef struct { void* node; } It1F3280;
extern void std_list_deleter_voidPtr_end_void(It1F3280* out, void* list);
extern void std_list_deleter_voidPtr_insert(It1F3280* out, void* list, It1F3280* pos, void* value);
#pragma optimization_level 1
void std_list_imp_voidPtr_push_back(void* list, void* value)
{
    It1F3280 r;
    It1F3280 pos;
    std_list_deleter_voidPtr_end_void(&pos, list);
    std_list_deleter_voidPtr_insert(&r, list, &pos, value);
}
#pragma optimization_level reset