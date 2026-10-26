#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int _sendIpuCommand(char * , int);                         
int _waitIpuIdle(char * );                            
int _nextBit();                       
int func_0010BD90(char * , char *);                       

void _quantMatrixExtension(char * arg0) {
    int temp_v0;
    int temp_v0_2;

    temp_v0 = _nextBit(arg0, 1);
    F_(arg0, 0x858, int) = temp_v0;
    if (temp_v0 != 0) {
        _waitIpuIdle(arg0);
        _sendIpuCommand(arg0, 0x50000000);
        _waitIpuIdle(arg0);
    }
    temp_v0_2 = _nextBit(arg0, 1);
    F_(arg0, 0x85C, int) = temp_v0_2;
    if (temp_v0_2 != 0) {
        _waitIpuIdle(arg0);
        _sendIpuCommand(arg0, 0x58000000);
        _waitIpuIdle(arg0);
    }
    if (_nextBit(arg0, 1) != 0) {
        func_0010BD90(arg0, "load_chroma_intra_quantizer_matrix == 1");
    }
    if (_nextBit(arg0, 1) != 0) {
        func_0010BD90(arg0, "load_chroma_non_intra_quantizer_matrix == 1");
    }
}
