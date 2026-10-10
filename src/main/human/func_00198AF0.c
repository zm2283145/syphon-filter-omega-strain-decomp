#include "types.h"
typedef struct { char pad[0x40]; int key; } MotionGroup;
typedef struct { MotionGroup* group; int key; } MotionKey;
/* Build a key handle: the group is set only when its key is unassigned (-1). */
MotionKey* MotionGroup_GetKey(MotionKey* out, MotionGroup* group)
{
    out->group = group->key == -1 ? group : 0;
    out->key = group->key;
    return out;
}
