#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int Exit(int);                               
int func_00116788();                                  

void Newlib_SysExit(int arg0) {
    func_00116788();
    Exit(arg0);
}
