extern char D_004E4780[];
extern int *func_0010FD88(void *);
extern void func_0010FE30(void *),func_0010D170(int),func_0010D1A0(int);
extern int CreateSema(void *),func_0010F948(unsigned,void *,int,void *,int,int);
int func_001100A0(int *client,int src,int dst,int len,int mode){
 int sem[8],*packet;
 
 packet=func_0010FD88(D_004E4780);
 if(!packet)return -1;
 {int token=packet[6];client[0]=(int)packet;client[1]=token;}
 packet[8]=src;packet[9]=dst;packet[10]=len;packet[5]=(int)packet;packet[7]=(int)client;
 if(!(mode&1)){
  sem[2]=0;sem[1]=1;
  client[2]=CreateSema(sem);
  if(client[2]<0){func_0010FE30(packet);return -3;}
  if(!func_0010F948(0x8000000c,packet,64,0,0,0)){
   func_0010FE30(packet);func_0010D170(client[2]);return -2;
  }
  func_0010D1A0(client[2]);func_0010D170(client[2]);return 0;
 }else{
  client[2]=-1;
  if(!func_0010F948(0x8000000c,packet,64,0,0,0)){func_0010FE30(packet);return -2;}
  return 0;
 }
}

