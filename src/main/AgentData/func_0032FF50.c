#include "types.h"
typedef struct { int name; int unk4; int desc; int value; int id; int extra; } Rec0032FF50;
extern int Loc_FindKeyThunk(int key);
/* Fill a rating record. */
Rec0032FF50* func_0032FF50(Rec0032FF50* rec, int nameKey, int extra, int descKey, int value, unsigned char id)
{
    rec->name = Loc_FindKeyThunk(nameKey);
    rec->extra = extra;
    rec->desc = Loc_FindKeyThunk(descKey);
    rec->value = value;
    rec->id = id + 10000;
    return rec;
}
