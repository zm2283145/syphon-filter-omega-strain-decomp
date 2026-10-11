#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_00357150(int);                             

void func_00358500(int *arg0, int arg1) {
    *arg0 = func_00357150(F_(arg1, 0x4, int));
}
