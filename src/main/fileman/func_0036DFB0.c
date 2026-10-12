#include "types.h"
typedef struct { unsigned int flags; char name[0x80]; char pad[0x14]; char* a98; } F36DFB0;
char* strncpy(char*, const char*, int);
static inline int Kind(F36DFB0* f)
{
    if (f->flags & 2) return 2;
    if (f->flags & 1) return 1;
    return 0;
}
static inline char* Data(F36DFB0* f)
{
    if (*(int*)f & 2) return f->a98 + 0x80;
    if (*(int*)f & 1) return f->a98;
    return 0;
}
int func_0036DFB0(F36DFB0* d, const char* name, F36DFB0* s)
{
    if ((unsigned char)Kind(s) == 1) {
        int c = (*(int*)s & 4) != 0;
        char* p = Data(s);
        d->flags = 0;
        strncpy(d->name, name, 0x80);
        d->a98 = p;
        d->flags |= 1;
        if (c) d->flags |= 4;
    } else if ((unsigned char)Kind(s) == 2) {
        int c = (*(int*)s & 4) != 0;
        strncpy(d->name, name, 0x80);
        d->a98 = s->a98;
        d->flags = 0;
        d->flags |= 2;
        if (c) d->flags |= 4;
    } else return 5;
    return 0;
}

