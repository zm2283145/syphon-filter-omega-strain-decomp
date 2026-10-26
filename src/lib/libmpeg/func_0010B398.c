#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int _initSeqAgain(void *);                            
int _clearEach(void *);                            

int sceMpegReset(int arg0) {
    int temp_s0;

    temp_s0 = F_(arg0, 0x40, int);
    F_(temp_s0, 0x10A0, int) = 0;
    F_(temp_s0, 0x0, int) = 0;
    F_(temp_s0, 0x4, int) = 0;
    F_(temp_s0, 0x8, int) = 0;
    F_(arg0, 0x8, int) = 0;
    F_(temp_s0, 0xC4, int) = 0;
    F_(temp_s0, 0x98, int) = -1;
    _clearEach(temp_s0);
    F_(temp_s0, 0x130, int) = 0;
    _initSeqAgain(temp_s0);
    return 1;
}
