#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_0010CE10(int, int *);                            
unsigned int D_00486598[2] = { 0x0, 0x0 };
extern int func_00115E40;

int func_001158F8(int arg0) {
    (*(int*)D_00486598) = arg0;
    func_0010CE10(1, &func_00115E40);
    func_0010CE10(2, &func_00115E40);
    func_0010CE10(3, &func_00115E40);
    return arg0;
}
