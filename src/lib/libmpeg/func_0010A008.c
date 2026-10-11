#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_00109F50();                                
int func_00109F70(int, int);                            

int func_0010A008(int arg0, int arg1) {
    int temp_s2;

    temp_s2 = func_00109F50();
    func_00109F70(arg0, arg1);
    return temp_s2;
}
