#include "types.h"
typedef struct { char pad[0x10]; int idx; char pad2[0x58]; int table[1]; } Obj34;
extern int GuiWidget_FocusFirst(Obj34* o);
/* Returns the table entry for the current index, or the fallback lookup. */
int GuiRatings_First(Obj34* o) { if (o->idx != -1) return o->table[o->idx]; return GuiWidget_FocusFirst(o); }
