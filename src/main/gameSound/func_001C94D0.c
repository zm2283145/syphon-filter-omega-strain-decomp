#include "types.h"
extern int snd_GetMasterVolume(int);
int func_001C94D0(void* self, unsigned char kind)
{
    int r = 0;
    switch (kind) {
    case 0: r = snd_GetMasterVolume(0); break;
    case 1: r = snd_GetMasterVolume(1); break;
    case 2: r = snd_GetMasterVolume(2); break;
    }
    return r;
}