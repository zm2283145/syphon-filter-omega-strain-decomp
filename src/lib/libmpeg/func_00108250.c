#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int _nextBit();                       
int _extensionAndUserData(char * );                            
int _extrainfo(char * );                            
int _updateTempTackData(char * , int);                       

void _pictureHeader(char * arg0) {
    int temp_s1;

    temp_s1 = _nextBit(arg0, 0xA);
    F_(arg0, 0x168, int) = _nextBit(arg0, 3);
    _nextBit(arg0, 0x10);
    if ((unsigned int) (F_(arg0, 0x168, int) - 2) < 2U) {
        F_(arg0, 0x16C, int) = _nextBit(arg0, 1);
        F_(arg0, 0x170, int) = _nextBit(arg0, 3);
    }
    if (F_(arg0, 0x168, int) == 3) {
        F_(arg0, 0x174, int) = _nextBit(arg0, 1);
        F_(arg0, 0x178, int) = _nextBit(arg0, 3);
    }
    _extrainfo(arg0);
    _extensionAndUserData(arg0);
    _updateTempTackData(arg0, temp_s1);
}
