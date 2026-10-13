typedef struct { void (*func)(void *); void *arg; } Cb11298;
extern void *D_004E5FC0;
void func_00111298(int a, Cb11298 *cb)
{
    void (*f)(void *) = cb->func;
    if (f != 0) {
        void *save;
        /* $gp swap: save and load $gp, only expressible in asm */
        __asm__ volatile("move %0, $gp\n\tlw $gp, %1" : "=&r"(save) : "m"(D_004E5FC0));
        f(cb->arg);
        __asm__ volatile("move $gp, %0" : : "r"(save));
    }
    __asm__ volatile("sync");
    __asm__ volatile("ei");
}

