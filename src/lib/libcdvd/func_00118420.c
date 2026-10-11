extern volatile int D_004878D8;
extern int volatile D_004878DC;
extern int volatile D_004878B4;
extern int volatile D_004878A8;
extern int volatile D_004878A0;
extern int volatile D_00487894;
extern void *D_004E9D00;
extern int func_0010D190(int);

void func_00118420(int *p)
{
    D_004878D8 = *p;
    D_004878DC = D_004878D8;
    if (D_004878D8 == 11) {
        D_004878D8 = 0;
        D_004878B4 = 0;
        return;
    }
    func_0010D190(D_004878A8);
    if (D_00487894 && D_004E9D00) {
        func_0010D190(D_004878A0);
    } else {
        D_004878B4 = 0;
    }
    D_004878D8 = 0;
}