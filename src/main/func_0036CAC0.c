#include "types.h"
typedef struct { char p0[0x10]; int base; } B36CAC0;
typedef struct { char p0[0x80]; char io[0xC8]; B36CAC0* p148; unsigned char state; char p14D[0x13]; int* offs; } S36CAC0;
extern void FileHal_Reopen(void* io, S36CAC0* s, int mode);
extern void FileHal_Read(void* io, void* dst, int size, int pos);
/* Starts reading entry idx of the archive into dst (4 when the archive is not open). */
int func_0036CAC0(S36CAC0* s, int idx, void* dst, int big)
{
    int size; int start; int* t;
    if (s->state != 2) return 4;
    if (big) FileHal_Reopen(s->io, s, 0x8000);
    else FileHal_Reopen(s->io, s, 1);
    t = &s->offs[idx];
    start = t[0];
    if (s->state) size = t[1] - start;
    else size = 0;
    FileHal_Read(s->io, dst, size, s->p148->base + start);
    return 0;
}
