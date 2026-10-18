#include "types.h"
typedef struct { char pad[0x24C]; int level; } Cfg_F630;
typedef struct { char pad[0xB4]; Cfg_F630* cfg; } O_F630;
void func_003CBA90(char* buf);
int sprintf(char*, const char*, ...);
void printf(char*, int);
void Heap_AllocSlot(int, int, int);
extern float D_004ACC90[];
/* size a memory pool from the configured level (MB table), log it and create it */
void func_0012F630(O_F630* o)
{
    char buf[0x40];
    int size;
    int lvl = o->cfg->level;
    if (lvl < 0) lvl = 0;
    func_003CBA90(buf);
    size = (int)(1024.0f * (1024.0f * D_004ACC90[lvl]));
    if (!size) size = 0x800000;
    sprintf(buf, "streamBufSize: 0x%x", size);
    printf("streamBufSize: 0x%x\n\n", size);
    Heap_AllocSlot(1, size, 16);
}
