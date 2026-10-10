#include "types.h"
typedef struct LCNode_c7 { struct LCNode_c7* prev; struct LCNode_c7* next; int data; } LCNode_c7;
typedef struct { LCNode_c7* node; } LCIter_c7;
extern void func_0013B160(LCIter_c7* out, void* list);
extern LCIter_c7* List_InsertBefore(LCIter_c7* out, void* list, LCIter_c7* pos, int* value);
void List_CopyRange(void* list, LCIter_c7 first, LCIter_c7 last) { LCNode_c7* n; for (n = first.node; n != last.node; n = n->next) { LCIter_c7 res; LCIter_c7 pos; func_0013B160(&pos, list); List_InsertBefore(&res, list, &pos, &n->data); } }