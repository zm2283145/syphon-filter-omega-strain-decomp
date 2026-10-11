#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00467DD0(int);                                 
int func_00467DF0(int );                            

void func_00467F38(int arg0) {
    if (F_(arg0, 0x4, int) != 0) {
        func_00467DD0(2);
        return;
    }
    if (F_(arg0, 0x0, int) == 0) {
        func_00467DD0(2);
        return;
    }
    func_00467DF0(arg0 + 8);
    func_00467DD0(1);
}
