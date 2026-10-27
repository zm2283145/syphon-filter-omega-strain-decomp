const unsigned int D_00498C30[2] = { 0x0, 0x0 };
extern char *D_004865E0;
extern int SetArg(void *, int, int);
extern void TerminateLibrary(void);
extern int _ExecPS2(int, int, int, char *);

int ExecPS2_2(int a0, int a1, int a2, int a3)
{
    SetArg(((char*)D_00498C30), a2, a3);
    TerminateLibrary();
    return _ExecPS2(a0, a1, a2, D_004865E0 + 4);
}