#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Libc_Strcpy(int, int);                                 
extern char D_004C2C00[];
static void * const dat_00497E30[1] = { (void*)D_004C2C00 };

int MediusVersionClient(int arg0) {
    int var_v0;

    var_v0 = -0x12;
    if (arg0 != 0) {
        Libc_Strcpy(arg0, (*(int*)dat_00497E30));
        var_v0 = 0;
    }
    return var_v0;
}
