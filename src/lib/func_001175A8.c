#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_001161A0();                                
int func_001161F8();                                  
int func_00117558(int, int);                          

int func_001175A8(int arg0, int arg1) {
    int temp_s0;
    int temp_s2;

    temp_s2 = func_001161A0();
    temp_s0 = func_00117558(arg0, arg1);
    if (temp_s2 != 0) {
        func_001161F8();
    }
    return temp_s0;
}
