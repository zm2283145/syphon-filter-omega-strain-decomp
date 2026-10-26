#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int sceNetcnfifFreeWorkarea();                                
int sce_sync(int);                                 
extern int D_0048B374;

int sceNetcnfifTerm(void) {
    int temp_s0;

    temp_s0 = sceNetcnfifFreeWorkarea();
    sce_sync(0);
    D_0048B374 = 0;
    return temp_s0;
}
