#include "types.h"
typedef struct { int type; char pad[0x3C]; void* ptr; unsigned char flag; } G3S_001C7D80;
typedef struct { char pad[0x50]; G3S_001C7D80 s; char pad2[0x1B0 - 0x50 - sizeof(G3S_001C7D80)]; } G3E_001C7D80;
extern void snd_StopSound(void* p);
extern void snd_FlushSoundCommands(void);
void func_001C7D80(G3E_001C7D80* arg) {
    int i;
    G3S_001C7D80* s;
    G3E_001C7D80* e = arg;
    for (i = 0; i < 50; i++, e++) {
        s = &e->s;
        if (s->type == 5) {
            if (s->ptr) {
                snd_StopSound(s->ptr);
                s->ptr = 0;
            }
            s->flag = 0;
        }
    }
    snd_FlushSoundCommands();
}