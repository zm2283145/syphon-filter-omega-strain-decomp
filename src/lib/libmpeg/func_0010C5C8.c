#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_00107ED8();                       

void func_0010C5C8(char * arg0) {
    func_00107ED8(arg0, 3);
    if (func_00107ED8(arg0, 1) != 0) {
        func_00107ED8(arg0, 8);
        func_00107ED8(arg0, 8);
        F_(arg0, 0x15C, int) = func_00107ED8(arg0, 8);
    }
    F_(arg0, 0x160, int) = func_00107ED8(arg0, 0xE);
    func_00107ED8(arg0, 1);
    F_(arg0, 0x164, int) = func_00107ED8(arg0, 0xE);
}
