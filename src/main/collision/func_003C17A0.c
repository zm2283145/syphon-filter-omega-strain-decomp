#include "types.h"
typedef struct { int pad[7]; int f1C; } ColData_f3;
typedef struct { ColData_f3* data; unsigned char loaded; char pad[11]; int f10; } ColHolder_f3;
typedef struct { int w[11]; } ColTmp_f3;
extern int func_0036DEF0(void* f);
extern void func_0036D990(void* f, int* out, int z);
extern void func_0036DEC0(void* f);
extern void Col_Relocate(ColData_f3* d);
extern void* func_003C19A0(ColData_f3* d);
extern void func_003C18A0(ColTmp_f3* t, void* p);
extern void func_003C1880(int* dst, ColTmp_f3* t);
int Col_Load(ColHolder_f3* c, void* file)
{
    int buf[1];
    ColTmp_f3 tmp;
    if (c->data == 0) {
        buf[0] = 0;
        if ((unsigned char)func_0036DEF0(file)) {
            c->loaded = 1;
            return 0;
        }
        func_0036D990(file, buf, 0);
        func_0036DEC0(file);
        c->data = (ColData_f3*)buf[0];
        Col_Relocate(c->data);
        func_003C18A0(&tmp, func_003C19A0(c->data));
        func_003C1880(&c->f10, &tmp);
        {
            unsigned char b = 1;
            if (c->data != 0 && c->data->f1C != 0) b = 0;
            c->loaded = b;
        }
        return 1;
    }
    return 0;
}