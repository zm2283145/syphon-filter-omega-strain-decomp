#include "types.h"
typedef struct { char* data; unsigned short free; unsigned char used; unsigned char type; char* base; int size; } SkmEnt;
typedef struct { char* buf0; int f4; char* buf8; } SkmSrc;
extern SkmEnt D_005639B0[][2];
extern void Skm_LoadPacket(SkmEnt* b, char* buf, unsigned int size, long a, long c, char flag);
void Skm_OnLoaded(SkmSrc* src, SkmEnt* e, int ok)
{
    int id = e->free;
    int slot;
    if (ok) {
        slot = e->used;

        Skm_LoadPacket(e, src->buf8 ? src->buf8 : src->buf0, e->size, id, slot, 0);
        if (D_005639B0[id][slot ^ 1].free == 0) {
            D_005639B0[id][slot ^ 1].data = D_005639B0[id][slot].data;
            D_005639B0[id][slot ^ 1].free = D_005639B0[id][slot].free;
            D_005639B0[id][slot ^ 1].used = D_005639B0[id][slot].used;
            D_005639B0[id][slot ^ 1].type = D_005639B0[id][slot].type;
            D_005639B0[id][slot ^ 1].base = D_005639B0[id][slot].base;
            D_005639B0[id][slot ^ 1].size = D_005639B0[id][slot].size;
        }
    } else {
        e->data = 0;
        e->free = 0;
        e->used = 0;
        e->type = 0;
        e->base = 0;
        e->size = 0;
    }
}
