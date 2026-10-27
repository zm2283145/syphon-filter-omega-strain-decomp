#include "types.h"
typedef struct { int name; int unk4; int desc; int value; int id; int extra; } Rec0032FF50;
extern int nGlobalization_GetStringIndex(int key);
/* Fill a rating record. */
Rec0032FF50* cAgentData_Record_ctor_charP_int_charP_int_etc(Rec0032FF50* rec, int nameKey, int extra, int descKey, int value, unsigned char id)
{
    rec->name = nGlobalization_GetStringIndex(nameKey);
    rec->extra = extra;
    rec->desc = nGlobalization_GetStringIndex(descKey);
    rec->value = value;
    rec->id = id + 10000;
    return rec;
}
