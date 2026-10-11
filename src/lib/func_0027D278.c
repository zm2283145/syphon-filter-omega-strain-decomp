#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_0010CF70(int);                               
int func_0010CFB0(int);                               
int func_001108C8(int *, int *);                          
int func_00110960(int *);                               
extern int D_00506150;
extern int D_00506198;

void func_0027D278(int arg0) {
    func_001108C8(&D_00506150, &D_00506198);
    func_00110960(&D_00506198);
    func_0010CFB0(arg0);
    func_0010CF70(arg0);
}
