#include "types.h"
typedef struct { char pad[0x255C]; int mode; } G2CA640;
typedef struct { char pad[0x264]; unsigned char b264; } S2CA640;
extern void func_002CA160(S2CA640* s);
extern G2CA640* func_004294C0(void);
extern void func_00445850(G2CA640* g);
extern void func_002C8090(S2CA640* s);
extern void func_00453B00(G2CA640* g, int a);
extern void func_00429500(int a);
int func_002CA640(S2CA640* s, int a)
{
    func_002CA160(s);
    if (func_004294C0()) {
        if (s->b264 && func_004294C0()->mode != 10)
            func_00445850(func_004294C0());
        s->b264 = 0;
        func_002C8090(s);
        func_00453B00(func_004294C0(), a);
        func_00429500(0);
        return 1;
    }
    return 0;
}