extern int LoadExecPS2(int, int, char*);
extern int SetArg(void);
extern void TerminateLibrary(void);
extern char *D_004865E0;
void LoadExecPS2_2(int d0, int arg1)
{
    int s0 = SetArg();
    TerminateLibrary();
    LoadExecPS2(s0, arg1, D_004865E0 + 4);
}