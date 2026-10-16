#include "types.h"
typedef struct {
    void* vtable;
    int version;
    int header[6];
    int count;
    short ids[6];
    char data[0x400];
} Save7560;
extern char D_004DE148[];
extern int D_0051EE70;
extern void func_002E9A10(void);
extern int func_002E9A98(void* f, void* buf, int size, int count);
extern int func_002E9F08(int* out, void* fn);
extern void func_002C7810(void);
void func_002C7560(void)
{
    int handle;
    Save7560 f;
    f.vtable = D_004DE148;
    func_002E9A10();
    if (func_002E9A98(&f, &f.version, 4, 1) == 0 &&
        func_002E9A98(&f, f.header, 4, 6) == 0 &&
        func_002E9A98(&f, &f.count, 4, 1) == 0 &&
        func_002E9A98(&f, f.ids, 2, 6) == 0 &&
        func_002E9A98(&f, f.data, 1, 0x400) == 0 &&
        func_002E9F08(&handle, func_002C7810) == 0)
        D_0051EE70 = handle;
}