#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
unsigned int D_00492CE0[1] = { 0x1 };

void sceInsockSetErrnoMode(int arg0) {
    (*(int*)D_00492CE0) = arg0;
}
