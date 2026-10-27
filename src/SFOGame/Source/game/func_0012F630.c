#include "types.h"
typedef struct { char pad[0x24C]; int level; } Cfg_F630;
typedef struct { char pad[0xB4]; Cfg_F630* cfg; } O_F630;
void cSFOini_GetKeyValue(char* buf);
int sprintf(char*, const char*, ...);
void printf(char*, int);
void cMemMan_Init_int_uint_uint(int, int, int);
extern float D_004ACC90[];
/* size a memory pool from the configured level (MB table), log it and create it */
void cGameSystem_InitMEM(O_F630* o)
{
    char buf[0x40];
    int size;
    int lvl = o->cfg->level;
    if (lvl < 0) lvl = 0;
    cSFOini_GetKeyValue(buf);
    size = (int)(1024.0f * (1024.0f * D_004ACC90[lvl]));
    if (!size) size = 0x800000;
    sprintf(buf, "streamBufSize: 0x%x", size);
    printf("streamBufSize: 0x%x\n\n", size);
    cMemMan_Init_int_uint_uint(1, size, 16);
}
