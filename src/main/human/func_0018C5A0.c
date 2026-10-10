#include "types.h"

typedef struct { int node; } MapIter;
typedef struct { char pad[0x24]; char map[0x18]; int** values; } MotionSet;
extern void func_0018C740(MapIter* out, void* map, int key);  /* map.find(key) */
extern void func_0018C730(MapIter* out, void* map);           /* map.end() */
extern int func_0018C710(MapIter* a, MapIter* b);             /* a != b */
extern int* func_0018C700(MapIter* it);                       /* &it->second */

/* Returns the motion for key (index 0 when the key is not in the map). */
int* Motion_Lookup(MotionSet* self, int key)
{
    MapIter end;
    MapIter it;
    int index;
    func_0018C740(&it, self->map, key);
    func_0018C730(&end, self->map);
    if (func_0018C710(&it, &end))
        index = *func_0018C700(&it);
    else
        index = 0;
    return self->values[index];
}
