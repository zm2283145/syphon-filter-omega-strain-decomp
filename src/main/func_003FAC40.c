extern unsigned char D_00493A10[];
extern unsigned char D_0055C780[];
extern unsigned int D_0055C990;
extern unsigned char D_005721D0;
extern unsigned int func_0042B1A0(int);
extern void func_003FA940(int i);

void func_003FAC40(unsigned char* flag)
{
    unsigned char f = flag ? *flag : 0;
    unsigned int t = D_0055C990;
    int i;
    if (t > func_0042B1A0(1)) return;
    D_0055C990 = func_0042B1A0(1) + 100;
    for (i = 0; i != 4; i++) {
        unsigned char s = D_00493A10[i];
        if (s == 0 || (f && s == 1)) {
            if (D_005721D0) {
                D_00493A10[i] = 1;
                func_003FA940(i);
                if (flag) *flag = 0;
                break;
            }
            if (!flag) D_0055C780[i] = 1;
        }
    }
}


