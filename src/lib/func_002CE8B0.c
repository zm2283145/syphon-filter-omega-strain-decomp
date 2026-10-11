#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002CE748(int);                                 
int func_002CE768(int );                            

void func_002CE8B0(int arg0) {
    if (F_(arg0, 0x4, int) != 0) {
        func_002CE748(3);
        return;
    }
    if (F_(arg0, 0x0, int) == 0) {
        func_002CE748(3);
        return;
    }
    func_002CE768(arg0 + 8);
    func_002CE748(1);
}
