#include "types.h"
typedef struct { char pad[0x24C]; int level; } Cfg_F630;
typedef struct { char pad[0xB4]; Cfg_F630* cfg; } O_F630;
void func_003CBA90(char* buf);
int sprintf(char*, const char*, ...);
void func_00127358(char*, int);
void func_0036B3B0(int, int, int);
extern float D_004ACC90[];
extern char D_0049A8A0[];
extern char D_0049A8C0[];
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
    sprintf(buf, D_0049A8A0, size);
    func_00127358(D_0049A8C0, size);
    func_0036B3B0(1, size, 16);
}
