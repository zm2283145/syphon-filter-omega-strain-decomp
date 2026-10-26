int D_00491344 = 0;
extern int KM_GetLocalPublicKey(int, int);
int GetUDPSecurityMode(void)
{
    if (D_00491344 == 0) {
        if (KM_GetLocalPublicKey(-1, 0) == 0) D_00491344 = 1;
        else D_00491344 = 2;
    }
    return D_00491344;
}
