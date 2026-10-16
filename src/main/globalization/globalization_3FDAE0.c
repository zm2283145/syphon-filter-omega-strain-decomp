#include "types.h"
typedef struct { int a; int b; char* items; } T3FDAE0;
extern char D_004BE400[];
extern int D_0055CA80;
extern char* D_0055CA48;
extern T3FDAE0* D_0055CA50;
char* Loc_GetStoredKey(int i)
{
    if (i < 0) return D_004BE400;
    if (i < D_0055CA80) return D_0055CA48 + i * 16;
    return D_0055CA50->items + (i - D_0055CA80) * 16;
}