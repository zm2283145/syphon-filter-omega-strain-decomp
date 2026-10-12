extern int D_004878A8; extern volatile int D_004878AC;
extern char D_00487900[], D_00487980[], D_00488A50[];
extern char D_00488A80[], D_00488EC0[], D_00489400[];
int func_00119180(int cmd,int *out){
 int v;
 if(cmd!=0x8001){
  if(cmd!=0x8003){
   if(cmd!=0x8002){
    if(cmd!=0x8004){
     if(cmd!=0x8011){
      if(cmd!=0x8013){
       if(cmd!=0x8012){
        if(cmd==0x8014)v=(int)D_00489400; else v=0;
       }else v=(int)D_00488EC0;
      }else v=(int)D_00488A80;
     }else { v=D_004878AC; *out=v; goto done; }
    }else v=(int)D_00488A50;
   }else v=(int)D_00487980;
  }else v=(int)D_00487900;
 }else v=D_004878A8;
 *out=v; done: return 1;
}


