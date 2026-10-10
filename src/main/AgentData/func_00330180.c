#include "types.h"

typedef struct { int text; int unk4; int unk8; int unkC; int unk10; int unk14; } ObjectiveRow;
extern int Loc_FindKeyThunk(const char* key);

/* Initialises an objective row: looks up the text key and stores the parameters. */
ObjectiveRow* ObjectiveRow_Construct(ObjectiveRow* row, const char* key, int a, int b)
{
    row->text = Loc_FindKeyThunk(key);
    row->unk14 = a;
    row->unk4 = b;
    row->unk8 = -1;
    row->unkC = 0;
    return row;
}
