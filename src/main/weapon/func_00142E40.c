#include "types.h"

typedef struct { char pad[4]; unsigned char visible; char pad2[11]; } Hardpoint;
typedef struct { Hardpoint points[8]; char pad[8]; char* model; } HardpointSet;

extern unsigned char D_00489D70[]; /* hardpoint index -> model node index */

/* Sets a hardpoint's visibility and the matching hidden flag in the model (+0x2498 table). */
void Global_SetHardpointVis(HardpointSet* self, unsigned char index, int visible)
{
    ((Hardpoint*)self)[index].visible = visible;
    self->model[D_00489D70[index] + 0x2498] = !(unsigned char)visible;
}
