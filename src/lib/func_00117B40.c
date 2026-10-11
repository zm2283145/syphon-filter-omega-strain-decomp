#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_001161A0();                                
int func_001161F8();                                  
int func_00117A48(int, int, int, int);                    

int func_00117B40(int arg0, int arg1, int arg2, int arg3) {
    int temp_s0;
    int temp_s4;

    temp_s4 = func_001161A0();
    temp_s0 = func_00117A48(arg0, arg1, arg2, arg3);
    if (temp_s4 != 0) {
        func_001161F8();
    }
    return temp_s0;
}
