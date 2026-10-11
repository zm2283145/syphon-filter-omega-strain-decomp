#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Copy(int, int);                                 
extern int D_00497E30;

int func_00468830(int arg0) {
    int var_v0;

    var_v0 = -0x12;
    if (arg0 != 0) {
        String_Copy(arg0, D_00497E30);
        var_v0 = 0;
    }
    return var_v0;
}
