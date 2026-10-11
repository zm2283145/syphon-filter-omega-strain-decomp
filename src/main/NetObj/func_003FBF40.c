#include "types.h"
#include "int_map_subscript.h"
/* map<int, {int, int}>::operator[] with value {0, -2} */
typedef struct { int key; int a; int b; } PBF40;
DEFINE_INT_MAP_SUBSCRIPT(func_003FBF40, PBF40, func_003FC520, (v.a = 0, v.b = -2))