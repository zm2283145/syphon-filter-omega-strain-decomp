extern unsigned func_00107ED8(int *,int);
extern void func_00107748(int *),func_00107718(int *,unsigned),func_0010C3B8(int *,unsigned,void *),func_00108318(int *),func_0010C030(int),func_0010BD90(int *,void *);
extern char D_004987D8[],D_00486080[],D_004860C0[];
void func_0010BF08(int *m){
 unsigned bits;
 m[0xec/4]=0;
 bits=func_00107ED8(m,32);
 m[0x13c/4]=bits>>20;m[0x140/4]=(bits>>8)&0xfff;
 if(m[0x140/4]>2800)func_0010BD90(m,D_004987D8);
 bits=func_00107ED8(m,30);
 m[0x14c/4]=bits>>12;m[0x150/4]=(bits>>1)&0x3ff;
 m[0x858/4]=func_00107ED8(m,1);
 if(m[0x858/4]){func_00107748(m);func_00107718(m,0x50000000);func_00107748(m);}
 else func_0010C3B8(m,0x50000000,D_00486080);
 m[0x85c/4]=func_00107ED8(m,1);
 if(m[0x85c/4]){func_00107748(m);func_00107718(m,0x58000000);func_00107748(m);}
 else func_0010C3B8(m,0x58000000,D_004860C0);
 func_00108318(m);func_0010C030(m[0x870/4]);
}
