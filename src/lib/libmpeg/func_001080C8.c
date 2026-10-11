#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_00107DC8(char * , int);                         
int func_00107ED8();                       
int func_00108630(char * );                            

int func_001080C8(char * arg0) {
    F_(arg0, 0x1CC, int) = func_00107ED8(arg0, 5);
    if (func_00107ED8(arg0, 1) != 0) {
        func_00107ED8(arg0, 1);
        func_00107DC8(arg0, 7);
        func_00108630(arg0);
    }
    return 0;
}
