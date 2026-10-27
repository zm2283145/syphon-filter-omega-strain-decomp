#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int _ExecOSD(int, char*);                          
int SetArg(int *, int, int);                       
void TerminateLibrary();                                  
extern char *D_004865E0;
extern int D_00498C30;

void ExecOSD_2(int arg0, int arg1) {
    SetArg(&D_00498C30, arg0, arg1);
    TerminateLibrary();
    _ExecOSD(arg0, D_004865E0 + 4);
}
