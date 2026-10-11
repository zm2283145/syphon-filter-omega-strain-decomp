#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int func_00102A18();                              
int func_0010CE40(int, int, int);                       
int func_0010CE60(int, int);                            

int func_00103AC0(int arg0) {
    int temp_s2;
    int temp_s0;

    temp_s0 = func_00102A18();
    temp_s2 = F_(temp_s0, 0x8, int);
    if (arg0 == 0) {
        Alloc_Lock(2);
        func_0010CE60(2, F_(temp_s0, 0xC, int));
        F_(temp_s0, 0xC, int) = 0;
        F_(temp_s0, 0x8, int) = 0;
    } else {
        if (temp_s2 != 0) {
            Alloc_Lock(2);
            func_0010CE60(2, F_(temp_s0, 0xC, int));
        }
        F_(temp_s0, 0x8, int) = arg0;
        F_(temp_s0, 0xC, int) = func_0010CE40(2, arg0, -1);
        Alloc_Unlock(2);
    }
    return temp_s2;
}
