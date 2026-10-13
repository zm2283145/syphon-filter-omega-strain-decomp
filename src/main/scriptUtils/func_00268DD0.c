#include "types.h"
typedef struct { float* data; int pad; int count; } ScriptArr_b6;
extern ScriptArr_b6* ScriptArray_Cast(int);
int Script_Array_Sort(int* args)
{
 ScriptArr_b6* a = ScriptArray_Cast(args[0]);
 int i, j;
 for (i = 0; i < a->count - 1; i++) {
 for (j = i; j < a->count; j++) {
 if (!(a->data[i] <= a->data[j])) { float t = a->data[i]; a->data[i] = a->data[j]; a->data[j] = t; }
 }
 }
 return 0;
}
