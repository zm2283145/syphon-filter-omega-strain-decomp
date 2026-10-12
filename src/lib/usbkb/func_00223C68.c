typedef struct { int a,mode,table; char pad[44]; } Map3C68;
extern Map3C68 *D_004F5784;
extern unsigned short func_00223DB8(int,unsigned char,unsigned char,unsigned short);
int func_00223C68(int map,unsigned char a,unsigned char b,int count,unsigned short *src,unsigned short *dst)
{
 Map3C68 *p=&D_004F5784[map];
 int n=0,i;
 switch(p->mode){
 case 0:
  for(i=0;i<count && src[i];i++)dst[i]=src[i];
  n=i;break;
 case 1:
  for(i=0;i<count && src[i];i++)dst[i]=func_00223DB8(p->table,a,b,src[i]);
  n=i;break;
 }
 return n;
}
