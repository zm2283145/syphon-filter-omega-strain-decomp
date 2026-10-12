extern int func_00106B08(int *,int,int *,int *,int *),func_001064A0(int *),func_00107CA8(int *,int),func_001068E0(int *);
extern int func_00106EF8(int *,int *,int *,int *,int *,int *,int *),func_00106E38(int *,int *,int *,int *,int *);
extern int func_00104730(int *,int,int,int,int,int *,int *,int *);
extern void func_001054A8(int *,int),func_0010BD90(int *,void *);
extern char D_004984D8[];
int func_00106C38(int *m,int limit){
 int state[8],vec0[4],vec1[4],n=0,skip=0,a,b,c;
 int result=func_00106B08(m,limit,&n,&skip,state);
 if(result)return result;
 m[0x134/4]=0;
 for(;;){
  if(n>=limit)return 0;
  ((int *)((char *)m+m[0x828/4]*0x140))[0x6e4/4]=0;
  if(!func_001064A0(m)){if(m[0x10a0/4])return 4;return 2;}
  if(!skip){
   if(!func_00107CA8(m,23)||m[0x134/4]){m[0x134/4]=0;return 3;}
   skip=func_001068E0(m);
   if(m[0x134/4]){m[0x134/4]=0;return 1;}
  }
  if(n>=limit){func_0010BD90(m,D_004984D8);return 2;}
  if(skip==1){
   if(!func_00106EF8(m,&a,&b,&c,state,vec0,vec1)){m[0x134/4]=0;return 1;}
  }else{
   if(!func_00106E38(m,state,&b,vec0,&a)){m[0x134/4]=0;return 2;}
  }
  if(!func_00104730(m,n,skip,a,b,state,vec0,vec1)){m[0x134/4]=0;return 2;}
  if(n)func_001054A8(m,m[0x828/4]^1);
  n++;m[0x828/4]^=1;skip--;
 }


}



