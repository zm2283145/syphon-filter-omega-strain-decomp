#include "types.h"
typedef struct { unsigned char retries; unsigned char speed; unsigned char pattern; unsigned char pad; } M368F60;
typedef struct { int pad0; int lsn; char pad8[0x20]; int status; int pad2C; int a30; int a34; int a38; int cap; char pad40[0x84]; void* buf; } S368F60;
extern int g_FrameCounter;
extern int D_00533860;
extern int func_003A6F70(int mode);
extern int func_003A7060(int lsn, int sectors, void* buf, M368F60* mode);
extern void func_003A6D50(void* cb);
extern void func_003698A0(void);
int func_00368F60(S368F60* o, int pos)
{
    M368F60 mode;
    int sector;
    int i;
    mode.retries = 0xFF;
    mode.pattern = 0;
    sector = pos / 2048;
    mode.speed = 1;
    i = 0;
    while (func_003A6F70(0) && i++ < 10000) ;
    func_003A7060(o->lsn + sector, o->cap / 2048, o->buf, &mode);
    func_003A6D50(func_003698A0);
    o->a30 = o->a34 = g_FrameCounter;
    o->a38 = 200;
    D_00533860 = -1;
    if (o->status != 0x8000) func_003A6F70(0);
    return o->cap;
}
