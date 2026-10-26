#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Libc_Free();                                  
extern int (*D_005335DC)();

void my_free(void) {
    if (D_005335DC == NULL) {
        Libc_Free();
        return;
    }
    D_005335DC();
}
