#include "types.h"
typedef struct { char pad[0x10]; int count; } E2List;
extern void func_0036E5D0(void*);
extern void func_0036E140(void*, void*, int, int);
extern int func_00380A40(E2List*, void*);
extern void func_0036E220(void*, int);
extern char D_004BC2E0[];
int func_00381000(E2List* s) {
    char buf[0xA0];
    int r;
    func_0036E5D0(buf);
    func_0036E140(buf, D_004BC2E0, 0, 0);
    r = func_00380A40(s, buf);
    if (r == -1) r = s->count - 1;
    func_0036E220(buf, -1);
    return r;
}