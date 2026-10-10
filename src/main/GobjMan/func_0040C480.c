#include "GobjMan_types.h"

extern GobjScope* D_00571740;
extern int Id_IsValidCategory(unsigned int category);
extern int Id_IsValidIndex(unsigned int index);
extern GobjId* Id_Build(GobjId* id, int category, int index, int kind);
extern GobjEntry* func_0040C080(GobjScope* manager, GobjId* id);

/* Check whether a valid category and index already identify an object. */
GobjEntry* IdMgr_FindCollision(unsigned int category, unsigned int index)
{
    GobjScope* manager = D_00571740;
    GobjId id;
    if (!Id_IsValidCategory(category) || !Id_IsValidIndex(index))
        return 0;
    return func_0040C080(manager, Id_Build(&id, category, index, -1));
}
