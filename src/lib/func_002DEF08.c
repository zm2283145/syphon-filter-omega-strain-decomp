extern int D_005227E0[];
extern int NetMsg_Dispatch(unsigned int, int, unsigned short, int, unsigned short, int);
void Net_DispatchRecv(int a, unsigned int idx, unsigned short c, int d, unsigned short e)
{
    int h = NetMsg_Dispatch(idx, a, c, d, e, 0);
    if (idx < 4) D_005227E0[idx] = h;
    if (idx == 0xFFFF) D_005227E0[0] = h;
}