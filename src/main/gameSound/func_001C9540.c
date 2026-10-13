#include "types.h"
extern void snd_SetMasterVolume(int, int);
void func_001C9540(void* self, unsigned char kind, int v)
{
    switch (kind) {
    case 0: snd_SetMasterVolume(0, v); snd_SetMasterVolume(3, v); break;
    case 1: snd_SetMasterVolume(1, v); break;
    case 2: snd_SetMasterVolume(2, v); snd_SetMasterVolume(14, v); break;
    }
}