#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int Exit(int);                               
int TerminateLibrary();                                  

void Exit_2(int arg0) {
    TerminateLibrary();
    Exit(arg0);
}
