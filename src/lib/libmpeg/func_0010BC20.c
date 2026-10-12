#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
void func_00106478(int);                                 

static inline void init(int arg0, int base) {
    func_00106478(1);
    F_(arg0, 0x5A8, int) = base;
    F_(arg0, 0x5AC, int) = 0x70001800;
    F_(arg0, 0x6E8, int) = 0x70001B00;
    F_(arg0, 0x6EC, int) = 0x70003300;
    F_(arg0, 0x828, int) = 0;
}

void func_0010BC20(int arg0) { init(arg0,0x70000000); }


