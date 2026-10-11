#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_0010BB90(void *);                            
int func_0010BC80(void *);                            

int func_0010B398(int arg0) {
    int temp_s0;

    temp_s0 = F_(arg0, 0x40, int);
    F_(temp_s0, 0x10A0, int) = 0;
    F_(temp_s0, 0x0, int) = 0;
    F_(temp_s0, 0x4, int) = 0;
    F_(temp_s0, 0x8, int) = 0;
    F_(arg0, 0x8, int) = 0;
    F_(temp_s0, 0xC4, int) = 0;
    F_(temp_s0, 0x98, int) = -1;
    func_0010BC80(temp_s0);
    F_(temp_s0, 0x130, int) = 0;
    func_0010BB90(temp_s0);
    return 1;
}
