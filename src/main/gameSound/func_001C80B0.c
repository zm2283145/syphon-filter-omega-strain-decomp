#include "types.h"
typedef struct { char pad[0xC]; unsigned char on; } S1C80B0;
extern void snd_PauseAllSoundsInGroup(int);
extern void snd_ContinueAllSoundsInGroup(int);
void func_001C80B0(S1C80B0* s) { if (s->on) snd_PauseAllSoundsInGroup(2); else snd_ContinueAllSoundsInGroup(2); }