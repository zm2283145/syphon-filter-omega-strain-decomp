typedef struct { unsigned char a, b, min, hour; } T326638;
extern void func_003264D8(T326638* t);
void func_00326638(T326638* t)
{
    if (++t->hour == 24) {
        t->hour = 0;
        func_003264D8(t);
    }
}