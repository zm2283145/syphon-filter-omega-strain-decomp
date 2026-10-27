#include "types.h"

typedef struct { int node; } MapIter;
typedef struct { char pad[0x24]; char map[0x18]; int** values; } MotionSet;
extern void cAssocArray_cString16N_3_int_Find(MapIter* out, void* map, int key);  /* map.find(key) */
extern void cAssocArray_cString16N_3_int_End(MapIter* out, void* map);           /* map.end() */
extern int cAssocArray_cString16N_3_int_ConstIterator_opNe(MapIter* a, MapIter* b);             /* a != b */
extern int* cAssocArray_cString16N_3_int_ConstIterator_opMul(MapIter* it);                       /* &it->second */

/* Returns the motion for key (index 0 when the key is not in the map). */
int* cSkaAnimationSet_GetNode_cString16NR(MotionSet* self, int key)
{
    MapIter end;
    MapIter it;
    int index;
    cAssocArray_cString16N_3_int_Find(&it, self->map, key);
    cAssocArray_cString16N_3_int_End(&end, self->map);
    if (cAssocArray_cString16N_3_int_ConstIterator_opNe(&it, &end))
        index = *cAssocArray_cString16N_3_int_ConstIterator_opMul(&it);
    else
        index = 0;
    return self->values[index];
}
