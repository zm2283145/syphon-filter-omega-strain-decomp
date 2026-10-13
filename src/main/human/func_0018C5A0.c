#include "types.h"

typedef struct { int node; } MapIter;
typedef struct { char pad[0x24]; char map[0x18]; int** values; } MotionSet;
extern void ModelCtx_FindNodeById(MapIter* out, void* map, int key);  /* map.find(key) */
extern void NodeMap_End(MapIter* out, void* map);           /* map.end() */
extern int NodeMapIter_NotEqual(MapIter* a, MapIter* b);             /* a != b */
extern int* NodeMapIter_Value(MapIter* it);                       /* &it->second */

/* Returns the motion for key (index 0 when the key is not in the map). */
int* Motion_Lookup(MotionSet* self, int key)
{
    MapIter end;
    MapIter it;
    int index;
    ModelCtx_FindNodeById(&it, self->map, key);
    NodeMap_End(&end, self->map);
    if (NodeMapIter_NotEqual(&it, &end))
        index = *NodeMapIter_Value(&it);
    else
        index = 0;
    return self->values[index];
}
