extern unsigned short D_004A4E50[2][256],D_004A5250[2][256],D_004A5650[2][256];
extern int func_0010F388(const char *,...);
extern unsigned short func_00223F10(unsigned char,unsigned char);
unsigned short func_00223DB8(int type,int mods,int locks,unsigned short key)
{
 int shift;
 unsigned short *table=0,v;
 shift=(mods&0x22)!=0;
 switch(type){
 case 0:table=D_004A4E50[shift];break;
 case 1:table=D_004A5250[shift];break;
 case 2:table=D_004A5650[shift];break;
 default:func_0010F388("Arrangement error!
");break;
 }
 if(!key)return 0;
 if(key>=256)return key;
 v=table[key];
 if(v==0x4000)v=func_00223F10(locks,key);
 if(v==0x8000)v=key|0x8000;
 if((unsigned short)(v-'a')<26 && (locks&2))v-=32;
 if((unsigned short)(v-'A')<26 && (locks&2) && shift)v+=32;
 return v;
}


