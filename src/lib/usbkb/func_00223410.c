typedef int (*Fn223410)(void);
typedef struct { char pad[0x90]; int mode; int f94; int f98; } G223410;
extern G223410 D_004F5780;
extern Fn223410 D_0048AB00[];
int func_00223410(void)
{
    int r = 0;
    int m = D_004F5780.mode;
    if (m >= 1 && m <= 5) r = D_0048AB00[m]();
    D_004F5780.mode = 0;
    D_004F5780.f98 = 0;
    return r;
}