typedef struct { int a; int b; } P;
extern int D_00497CC4;
extern void *func_00468480(void);
void func_00468420(P *p)
{
    if (p->b == 1) D_00497CC4 = p->a;
    else D_00497CC4 = p->a;
    if (func_00468480() == 0) return;
    ((void (*)(int))func_00468480())(D_00497CC4);
}
