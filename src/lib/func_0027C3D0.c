#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int sceNetcnfifSetup();                                
int memset(int *, int, int);                                
extern int D_005040C0;

int sceNetcnfifInit(void) {
    int temp_s0;

    temp_s0 = sceNetcnfifSetup();
    memset(&D_005040C0, 0, 0x310);
    return temp_s0;
}
