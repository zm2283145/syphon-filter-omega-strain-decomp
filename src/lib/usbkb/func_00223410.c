typedef int (*Fn223410)(void);
typedef struct { char pad[0x90]; int mode; int f94; int f98; } G223410;
extern G223410 D_004F5780;
extern void func_00223478();
extern void func_002234D0();
extern void func_00223A48();
extern void func_00223A98();
extern void func_00223AB8();
static void * const dat_0048AB00[6] = { (void*)0x0, (void*)func_00223478, (void*)func_002234D0, (void*)func_00223A48, (void*)func_00223A98, (void*)func_00223AB8 };
int func_00223410(void)
{
    int r = 0;
    int m = D_004F5780.mode;
    if (m >= 1 && m <= 5) r = ((Fn223410*)dat_0048AB00)[m]();
    D_004F5780.mode = 0;
    D_004F5780.f98 = 0;
    return r;
}