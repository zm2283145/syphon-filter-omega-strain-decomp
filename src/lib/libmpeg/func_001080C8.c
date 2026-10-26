#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int _flushBuf(char * , int);                         
int _nextBit();                       
int _extrainfo(char * );                            

int _sliceB(char * arg0) {
    F_(arg0, 0x1CC, int) = _nextBit(arg0, 5);
    if (_nextBit(arg0, 1) != 0) {
        _nextBit(arg0, 1);
        _flushBuf(arg0, 7);
        _extrainfo(arg0);
    }
    return 0;
}
