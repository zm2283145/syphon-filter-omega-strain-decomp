typedef struct { unsigned char a, b, min, hour; } T326668;
extern void func_00326590(T326668* t);
void func_00326668(T326668* t)
{
    if (t->hour == 0) {
        t->hour = 23;
        func_00326590(t);
    } else {
        t->hour--;
    }
}