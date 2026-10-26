extern int func_00106B08(int *,int,int *,int *,int *),_waitBdecOut(int *),_peepBit(int *,int),_mbAddressIncrement(int *);
extern int _decMB0(int *,int *,int *,int *,int *,int *,int *),_skipMB0(int *,int *,int *,int *,int *);
extern int func_00104730(int *,int,int,int,int,int *,int *,int *);
extern void func_001054A8(int *,int),func_0010BD90(int *,void *);
int _slice0(int *m,int limit){
 int state[8],vec0[4],vec1[4],n=0,skip=0,a,b,c;
 int result=func_00106B08(m,limit,&n,&skip,state);
 if(result)return result;
 m[0x134/4]=0;
 for(;;){
  if(n>=limit)return 0;
  ((int *)((char *)m+m[0x828/4]*0x140))[0x6e4/4]=0;
  if(!_waitBdecOut(m)){if(m[0x10a0/4])return 4;return 2;}
  if(!skip){
   if(!_peepBit(m,23)||m[0x134/4]){m[0x134/4]=0;return 3;}
   skip=_mbAddressIncrement(m);
   if(m[0x134/4]){m[0x134/4]=0;return 1;}
  }
  if(n>=limit){func_0010BD90(m,"Too many macroblocks in picture");return 2;}
  if(skip==1){
   if(!_decMB0(m,&a,&b,&c,state,vec0,vec1)){m[0x134/4]=0;return 1;}
  }else{
   if(!_skipMB0(m,state,&b,vec0,&a)){m[0x134/4]=0;return 2;}
  }
  if(!func_00104730(m,n,skip,a,b,state,vec0,vec1)){m[0x134/4]=0;return 2;}
  if(n)func_001054A8(m,m[0x828/4]^1);
  n++;m[0x828/4]^=1;skip--;
 }


}



