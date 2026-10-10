#include "types.h"

typedef struct { char pad[0xE8]; char map[1]; } Table198;
typedef struct { char pad[0x3C]; char ref[1]; } Obj198;

extern Table198* Deque_Back(void* ref);
extern void* func_00198D00(void* map, int key);
extern float func_00198CF0(void* entry);

/* Looks up key in the object's table and returns the entry's value, or 0. */
float func_00198CA0(Obj198* self, int key)
{
    void* entry = func_00198D00(Deque_Back(self->ref)->map, key);
    if (entry)
        return func_00198CF0(entry);
    return 0.0f;
}
