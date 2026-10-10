#include "types.h"

typedef struct { char pad[0x6A4]; void* xa; } SoundMgr;

extern SoundMgr* D_004FFC2C;
extern void func_0045CE10(void* xa, int track, int channel, int flag);

/* Plays an XA audio track when the sound manager and its XA player exist. */
void Global_PlayXA(int track, int channel)
{
    if (D_004FFC2C && D_004FFC2C->xa)
        func_0045CE10(D_004FFC2C->xa, track, channel, 1);
}
