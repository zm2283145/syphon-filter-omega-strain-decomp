#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
unsigned char func_003263B8(unsigned char);                               

void func_00326470(int arg0) {
    F_(arg0, 0x7, unsigned char) = func_003263B8(F_(arg0, 0x7, unsigned char));
    F_(arg0, 0x6, unsigned char) = func_003263B8(F_(arg0, 0x6, unsigned char));
    F_(arg0, 0x5, unsigned char) = func_003263B8(F_(arg0, 0x5, unsigned char));
    F_(arg0, 0x3, unsigned char) = func_003263B8(F_(arg0, 0x3, unsigned char));
    F_(arg0, 0x2, unsigned char) = func_003263B8(F_(arg0, 0x2, unsigned char));
    F_(arg0, 0x1, unsigned char) = func_003263B8(F_(arg0, 0x1, unsigned char));
}
