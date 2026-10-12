extern void func_00303AA0(void *o, int a, int b);
extern void func_00303B30(void *o, int a, int b);
extern void func_00303BB8(void *o, int a, int b);
extern void func_00303D90(void *o, int a, int b);
extern void func_00303D98(void *o, int a, int b);
extern void func_00304140(void *o, int a, int b);
extern void func_003041B0(void *o, int a, int b);
extern void func_00304388(void *o, int a, int b);
extern void func_003043A8(void *o, int a, int b);
extern void func_003043C8(void *o, int a, int b);

void func_003039B8(int unused, int a, int code, int b, void *o)
{
    if (o == 0) return;
    switch (code) {
    case 0: func_00303AA0(o, a, b); break;
    case 1: func_00303B30(o, a, b); break;
    case 2: func_00303BB8(o, a, b); break;
    case 3: func_00303D90(o, a, b); break;
    case 4: func_00303D98(o, a, b); break;
    case 5: func_00304140(o, a, b); break;
    case 6: func_003041B0(o, a, b); break;
    case 7: func_00304388(o, a, b); break;
    case 8: func_003043A8(o, a, b); break;
    case 9: func_003043C8(o, a, b); break;
    }
}
