#pragma cplusplus on

#include "types.h"

/* Find the first list entry matching key; 0 if none. */
typedef struct { int w[1]; } It_3B0050;
typedef struct { unsigned char pad[0x6C]; int list; } Obj_3B0050;

extern "C" {
void func_003939C0(It_3B0050* out, void* list);
void func_003938D0(It_3B0050* out, void* list);
bool func_003938B0(It_3B0050* a, It_3B0050* b);
int* func_003939B0(It_3B0050* it);
void func_003938E0(It_3B0050* it);
int func_003B0120(int entry, void* key);
}

extern "C" int func_003B0050(void* key, Obj_3B0050* o)
{
    It_3B0050 it;
    It_3B0050 end;
    for (func_003939C0(&it, &o->list); (func_003938D0(&end, &o->list), func_003938B0(&it, &end)); func_003938E0(&it)) {
        if (func_003B0120(*func_003939B0(&it), key))
            return *func_003939B0(&it);
    }
    return 0;
}