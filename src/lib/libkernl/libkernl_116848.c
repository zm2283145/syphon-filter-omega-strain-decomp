#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int Exit(int);                               
int TerminateLibrary();                                  

void Newlib_SysExit(int arg0) {
    TerminateLibrary();
    Exit(arg0);
}
