#include "types.h"
typedef struct { int key; int value; char pad8[0x10]; } Row330;
typedef struct { Row330* p; } It330;
extern char D_005329F0[];
extern Row330* func_0032E3F0(void* v);
extern Row330* func_0032E3C0(void* v);
extern void func_0032E3E0(It330* out, void* self, It330* src);
extern int Loc_FindKeyThunk(__int128* name);
#pragma bool off
static inline int Ne330(Row330* a, Row330* b) { return (a == b) ^ 1; }
static inline int Find330(__int128* name)
{
    It330 itB;
    It330 itE;
    It330 b;
    It330 e;
    Row330* p;
    Row330* end;
    int key;
    b.p = func_0032E3F0(D_005329F0);
    func_0032E3E0(&itB, D_005329F0, &b);
    p = itB.p;
    e.p = func_0032E3C0(D_005329F0);
    func_0032E3E0(&itE, D_005329F0, &e);
    end = itE.p;
    key = Loc_FindKeyThunk(name);
    for (; Ne330(p, end); p++) {
        if (key == p->key) return p->value;
    }
    return -1;
}
int Objective_Find(__int128 name)
{
    int r = Find330(&name);
    if (r < 0) r = 0;
    return r;
}