#include "types.h"
typedef struct { float t; float pad; } Key3F3FC0;
typedef struct { char pad[0x24]; int count; Key3F3FC0* keys; } List3F3FC0;
float func_003F3FC0(List3F3FC0* l)
{
    int n = l->count;
    unsigned int off = n * sizeof(Key3F3FC0);
    if (n > 0)
        return ((Key3F3FC0*)((char*)l->keys + off))[-1].t;
    return 0.0f;
}