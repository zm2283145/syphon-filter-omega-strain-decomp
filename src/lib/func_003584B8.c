#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00357150(int);                             
int memset(int, int, int);                                     

void func_003584B8(int arg0, int *arg1) {
    memset(arg0, 0, 0x10);
    F_(arg0, 0x4, int) = func_00357150(*arg1);
}
