#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_00107ED8();                       
int func_00108318(char * );                            
int func_00108630(char * );                            
int func_00108678(char * , int);                       

void func_00108250(char * arg0) {
    int temp_s1;

    temp_s1 = func_00107ED8(arg0, 0xA);
    F_(arg0, 0x168, int) = func_00107ED8(arg0, 3);
    func_00107ED8(arg0, 0x10);
    if ((unsigned int) (F_(arg0, 0x168, int) - 2) < 2U) {
        F_(arg0, 0x16C, int) = func_00107ED8(arg0, 1);
        F_(arg0, 0x170, int) = func_00107ED8(arg0, 3);
    }
    if (F_(arg0, 0x168, int) == 3) {
        F_(arg0, 0x174, int) = func_00107ED8(arg0, 1);
        F_(arg0, 0x178, int) = func_00107ED8(arg0, 3);
    }
    func_00108630(arg0);
    func_00108318(arg0);
    func_00108678(arg0, temp_s1);
}
