extern int *func_00457FB0(int *self, int value);
extern int func_00457FC0(char *self);
extern char *func_00457FD0(char *self);
extern void func_00458A10(void *v, float *value);

static inline char *At(char *self, int i) { return (*(char ***)(self + 0x60))[i]; }
#pragma opt_strength_reduction off
void func_00458900(char *self)
{
    float sum;
    int end;
    int i;
    char *list;
    char *n;

    *(int *)(self + 0x6C) = 0;
    sum = 0.0f;
    for (i = 0; i < *(int *)(self + 0x5C); i++) {
        list = At(self, i);
        for (n = *(char **)(func_00457FD0(list + 4) + 4); func_00457FB0(&end, func_00457FC0(list)), n != (char *)end; n = *(char **)(n + 4)) {
            sum += *(float *)(n + 0x10);
            sum += *(int *)(n + 0x3C) / 20.0f;
        }
        func_00458A10(self + 0x68, &sum);
    }
}
#pragma opt_strength_reduction reset

