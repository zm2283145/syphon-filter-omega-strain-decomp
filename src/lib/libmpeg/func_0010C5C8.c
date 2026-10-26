#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int _nextBit();                       

void _sequenceDisplayExtension(char * arg0) {
    _nextBit(arg0, 3);
    if (_nextBit(arg0, 1) != 0) {
        _nextBit(arg0, 8);
        _nextBit(arg0, 8);
        F_(arg0, 0x15C, int) = _nextBit(arg0, 8);
    }
    F_(arg0, 0x160, int) = _nextBit(arg0, 0xE);
    _nextBit(arg0, 1);
    F_(arg0, 0x164, int) = _nextBit(arg0, 0xE);
}
