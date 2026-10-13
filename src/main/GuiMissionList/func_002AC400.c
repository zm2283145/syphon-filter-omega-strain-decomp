#include "types.h"
typedef struct { int x0; int x4; int x8; } I2AC400;
typedef struct { char pad[0x110]; int count; I2AC400* items; int pad118; void* w; } S2AC400;
extern int LobbyArray_At(void* w, int v);
int func_002AC400(S2AC400* s, int i)
{
    if (!s->w || i < 0 || !(i < s->count))
        return 0;
    return LobbyArray_At(s->w, ((I2AC400*)((char*)s->items + i * sizeof(I2AC400)))->x4);
}