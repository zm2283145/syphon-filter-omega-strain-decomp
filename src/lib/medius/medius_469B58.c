/*
 * lib/medius: 5 files, 00469B58-00469E68
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00469B58 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_0059856C;
unsigned int D_00497D38[1] = { 0x0 };
extern int Medius_TerminateString(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int MediusCreateChannel(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x30, 0x40);
    Medius_TerminateString(a + 0x70, 0x20);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497D38) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 0x4, D_0059856C, 0x94, a) ? -5 : 0;
}
/* merge_units: end func_00469B58 */

/* merge_units: begin func_00469C10 */
int D_00497D3C = 0;
extern int D_0059857C;
extern int NetSetDefaultResolveAddrParams(char *);
extern void MediusGetNatServiceAddress(char *);
extern void MediusResolveAddrCallback(void);
extern void MediusSetProcessingState(int);
extern void MediusSetQueuedRequest(int, char *);
extern int NetResolveAddr(char *, char *);
int MediusJoinGame(char *a, int b)
{
    char buf[0x20];
    char buf2[0x10];
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x30, 0x20);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D3C = b;
    if (*(int *)(a + 0x50) == 2) {
        if (NetSetDefaultResolveAddrParams(buf)) return -2;
        MediusGetNatServiceAddress(buf + 8);
        *(void (**)(void))(buf + 4) = MediusResolveAddrCallback;
        MediusSetProcessingState(3);
        MediusSetQueuedRequest(0x2C, a);
        if (NetResolveAddr(buf, buf2)) {
            MediusSetProcessingState(0);
            return -2;
        }
        return 0;
    }
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_0059857C, 0xC4, a) ? -5 : 0;
}
/* merge_units: end func_00469C10 */

/* merge_units: begin func_00469D20 */
extern int D_00598584;
unsigned int D_00497D40[1] = { 0x0 };
int MediusJoinChannel(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x2C, 0x20);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497D40) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598584, 0x4C, a) ? -5 : 0;
}
/* merge_units: end func_00469D20 */

/* merge_units: begin func_00469DC8 */
extern int D_00598594;
int D_00497D44 = 0;
int MediusGetGames(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D44 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598594, 0x30, a) ? -5 : 0;
}
/* merge_units: end func_00469DC8 */

/* merge_units: begin func_00469E68 */
extern int D_0059859C;
unsigned int D_00497D48[1] = { 0x0 };
int MediusGetChannels(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497D48) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_0059859C, 0x2A, a) ? -5 : 0;
}
/* merge_units: end func_00469E68 */
