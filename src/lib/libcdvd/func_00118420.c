extern volatile int D_004878D8;
extern int volatile D_004878DC;
extern int volatile D_004878B4;
extern int volatile D_004878A8;
unsigned int D_004878A0[1] = { 0xFFFFFFFF };
extern int volatile D_00487894;
extern void *D_004E9D00;
extern int iSignalSema(int);

void _sceCd_cd_callback(int *p)
{
    D_004878D8 = *p;
    D_004878DC = D_004878D8;
    if (D_004878D8 == 11) {
        D_004878D8 = 0;
        D_004878B4 = 0;
        return;
    }
    iSignalSema(D_004878A8);
    if (D_00487894 && D_004E9D00) {
        iSignalSema((*(int volatile*)D_004878A0));
    } else {
        D_004878B4 = 0;
    }
    D_004878D8 = 0;
}