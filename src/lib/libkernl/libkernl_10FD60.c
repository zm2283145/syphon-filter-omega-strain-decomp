extern void sceSifExitCmd(void);
extern int D_004861B0;
void sceSifExitRpc(void)
{
    sceSifExitCmd();
    D_004861B0 = 0;
}