#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int _nextBit();                       
int _extensionAndUserData(char * );                            

void _groupOfPicturesHeader(char * arg0) {
    F_(arg0, 0x100, int) = 0;
    F_(arg0, 0x86C, int) = 1;
    F_(arg0, 0x864, int) = (int) (F_(arg0, 0x868, int) + 1);
    _nextBit(arg0, 1);
    _nextBit(arg0, 5);
    _nextBit(arg0, 6);
    _nextBit(arg0, 1);
    _nextBit(arg0, 6);
    _nextBit(arg0, 6);
    F_(arg0, 0x1BC, int) = _nextBit(arg0, 1);
    F_(arg0, 0x1C0, int) = _nextBit(arg0, 1);
    _extensionAndUserData(arg0);
}
