#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_001161A0();                                
int func_001161F8();                                  
int func_001173B0();                                

int func_00117420(void) {
    int temp_s0;
    int temp_s1;

    temp_s0 = func_001161A0();
    temp_s1 = func_001173B0();
    if (temp_s0 != 0) {
        func_001161F8();
    }
    return temp_s1;
}
