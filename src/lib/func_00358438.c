#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_003581C0();                                  
int func_003581E0(int);                               
extern int D_00492CE8;

int func_00358438(void) {
    int temp_v0;

    temp_v0 = func_003581E0(1);
    if (temp_v0 == 0) {
        return &D_00492CE8;
    }
    func_003581C0();
    return temp_v0 + 0x10;
}
