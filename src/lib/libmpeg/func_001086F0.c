#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_00107ED8();                       
int func_00108318(char * );                            

void func_001086F0(char * arg0) {
    F_(arg0, 0x100, int) = 0;
    F_(arg0, 0x86C, int) = 1;
    F_(arg0, 0x864, int) = (int) (F_(arg0, 0x868, int) + 1);
    func_00107ED8(arg0, 1);
    func_00107ED8(arg0, 5);
    func_00107ED8(arg0, 6);
    func_00107ED8(arg0, 1);
    func_00107ED8(arg0, 6);
    func_00107ED8(arg0, 6);
    F_(arg0, 0x1BC, int) = func_00107ED8(arg0, 1);
    F_(arg0, 0x1C0, int) = func_00107ED8(arg0, 1);
    func_00108318(arg0);
}
