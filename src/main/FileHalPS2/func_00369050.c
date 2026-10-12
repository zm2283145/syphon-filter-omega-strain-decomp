#include "types.h"
typedef struct { int f0; char f4[4]; int f8; char pad[0x1C]; int f28; int f2c; char pad2[0xC]; int f3c; char f40; char path[0x83]; int fc4; } F369;
extern int sprintf(char*, const char*, ...);
extern char func_0012B290(int);
extern int func_00119708(int);
extern int func_003A6DA0(char*, char*);
int func_00369050(F369* f, char* name, int mode) {
    int i, r;
    f->f28 = mode;
    f->fc4 = 0;
    f->f3c = 0;
    f->f2c = 0;
    sprintf(f->path, "\\%s;1", name);
    for (i = 0; f->path[i]; i++) f->path[i] = func_0012B290(f->path[i]);
    i = 0;
    r = 0;
    while (i++ < 0xFF && r != 2) r = func_00119708(0);
    f->f0 = func_003A6DA0(f->f4, f->path);
    f->f2c = f->f8;
    if (!f->f0) f->f0 = -1;
    if (f->f0 < 0) {
        f->f2c = 0;
        return 0;
    }
    return 1;
}
