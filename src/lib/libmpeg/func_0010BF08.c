extern unsigned _nextBit(int *,int);
extern void _waitIpuIdle(int *),_sendIpuCommand(int *,unsigned),_setDefaultQM(int *,unsigned,void *),_extensionAndUserData(int *),_initSeq(int),func_0010BD90(int *,void *);
extern char D_004987D8[];
static const unsigned int dat_00486080[16] = { 0x13101008, 0x16161310, 0x16161616, 0x1B1A181A, 0x1A1A1B1B, 0x1B1B1A1A, 0x1D1D1D1B, 0x1D222222, 0x1B1B1D1D, 0x20201D1D, 0x26252222, 0x22232325, 0x28262623, 0x30302828, 0x38382E2E, 0x5345453A };
static const unsigned int dat_004860C0[20] = { 0x10101010, 0x10101010, 0x10101010, 0x10101010, 0x10101010, 0x10101010, 0x10101010, 0x10101010, 0x10101010, 0x10101010, 0x10101010, 0x10101010, 0x10101010, 0x10101010, 0x10101010, 0x10101010, 0x49497350, 0x6962696C, 0x20207570, 0x30303832 };
void _sequenceHeader(int *m){
 unsigned bits;
 m[0xec/4]=0;
 bits=_nextBit(m,32);
 m[0x13c/4]=bits>>20;m[0x140/4]=(bits>>8)&0xfff;
 if(m[0x140/4]>2800)func_0010BD90(m,D_004987D8);
 bits=_nextBit(m,30);
 m[0x14c/4]=bits>>12;m[0x150/4]=(bits>>1)&0x3ff;
 m[0x858/4]=_nextBit(m,1);
 if(m[0x858/4]){_waitIpuIdle(m);_sendIpuCommand(m,0x50000000);_waitIpuIdle(m);}
 else _setDefaultQM(m,0x50000000,((char*)dat_00486080));
 m[0x85c/4]=_nextBit(m,1);
 if(m[0x85c/4]){_waitIpuIdle(m);_sendIpuCommand(m,0x58000000);_waitIpuIdle(m);}
 else _setDefaultQM(m,0x58000000,((char*)dat_004860C0));
 _extensionAndUserData(m);_initSeq(m[0x870/4]);
}
