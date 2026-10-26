/*
 * lib/libkernl: 2 files, 0010FFD0-001100A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010FFD0 */
typedef struct { char p0[0x10]; unsigned int x10; int x14; char p1[4]; int x1C; unsigned int x20; int x24; int x28; int x2C; } RFFD0;
extern RFFD0 *_sceRpcGetFPacket(int);
extern RFFD0 *_sceRpcGetFPacket2(int, unsigned int);
extern int isceSifSendCmd(unsigned int, void *, int, int, int, int);
extern void iSetTimerAlarm(int, void *, void *);
extern void _alarm_rdata(void);
void _request_rdata(RFFD0 *p, int b)
{
    RFFD0 *r;
    if (p->x10 & 4) r = _sceRpcGetFPacket2(b, p->x10 >> 16);
    else r = _sceRpcGetFPacket(b);
    { int t14 = p->x14; int t1C = p->x1C; r->x14 = t14; r->x1C = t1C; }
    r->x20 = 0x8000000C;
    r->x24 = p->x20;
    r->x28 = p->x24;
    r->x2C = p->x28;
    if (isceSifSendCmd(0x80000008, r, 0x40, p->x20, p->x24, p->x28) == 0) iSetTimerAlarm(0x800, _alarm_rdata, r);
}
/* merge_units: end func_0010FFD0 */

/* merge_units: begin func_001100A0 */
extern char D_004E4780[];
extern int *_sceRpcGetPacket_void(void *);
extern void _sceRpcFreePacket_void(void *),DeleteSema(int),WaitSema(int);
extern int CreateSema(void *),sceSifSendCmd(unsigned,void *,int,void *,int,int);
int sceSifGetOtherData(int *client,int src,int dst,int len,int mode){
 int sem[8],*packet;

 packet=_sceRpcGetPacket_void(D_004E4780);
 if(!packet)return -1;
 {int token=packet[6];client[0]=(int)packet;client[1]=token;}
 packet[8]=src;packet[9]=dst;packet[10]=len;packet[5]=(int)packet;packet[7]=(int)client;
 if(!(mode&1)){
  sem[2]=0;sem[1]=1;
  client[2]=CreateSema(sem);
  if(client[2]<0){_sceRpcFreePacket_void(packet);return -3;}
  if(!sceSifSendCmd(0x8000000c,packet,64,0,0,0)){
   _sceRpcFreePacket_void(packet);DeleteSema(client[2]);return -2;
  }
  WaitSema(client[2]);DeleteSema(client[2]);return 0;
 }else{
  client[2]=-1;
  if(!sceSifSendCmd(0x8000000c,packet,64,0,0,0)){_sceRpcFreePacket_void(packet);return -2;}
  return 0;
 }
}
/* merge_units: end func_001100A0 */
