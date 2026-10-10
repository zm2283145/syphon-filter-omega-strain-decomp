#include "types.h"

typedef struct { unsigned char volume; unsigned char a; unsigned char b; } PlayParams;
typedef struct { int unk0; int active; char pad[8]; int cursor; } Stream3F7;
extern void func_003A7060(int pos, int blocks, void* data, PlayParams* params);
extern void func_003A6F70(int a);

/* Submits size bytes (in 2 KB blocks) of data to the active stream and advances its cursor; returns size or 0. */
int func_003F7870(Stream3F7* s, void* data, int size)
{
    int result = 0;
    if (s->active) {
        PlayParams params;
        int blocks;
        params.volume = 100;
        params.a = 0;
        params.b = 0;
        blocks = size >> 11;
        func_003A7060(s->cursor, blocks, data, &params);
        s->cursor += blocks;
        func_003A6F70(0);
        result = size;
    }
    return result;
}

