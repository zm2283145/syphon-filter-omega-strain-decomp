#include "types.h"
extern int* D_0055CA78;
int Loc_GetTextById(int id)
{
    return id >= 0 ? D_0055CA78[id] : 0;
}
