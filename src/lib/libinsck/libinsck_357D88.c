#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_001253C0();                                  
extern int (*D_005335DC)();

void func_00357D88(void) {
    if (D_005335DC == NULL) {
        func_001253C0();
        return;
    }
    D_005335DC();
}
