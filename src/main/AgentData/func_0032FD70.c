#include "types.h"

typedef struct { int key; int a; char b; int c; int d; int e; } Medal;
extern int Loc_FindKeyThunk(const char* name);

/* Medal constructor: resolves the name key and stores the fields; id is 10000 + index. */
Medal* func_0032FD70(Medal* self, const char* name, int a, char b, int c, int d, unsigned char index)
{
    self->key = Loc_FindKeyThunk(name);
    self->a = a;
    self->b = b;
    self->c = c;
    self->d = d;
    self->e = index + 10000;
    return self;
}
