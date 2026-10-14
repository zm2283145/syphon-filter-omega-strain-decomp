/*
 * lib/libkernl: 2 files, 0010FFD0-001100A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010FFD0 */
typedef struct { char p0[0x10]; unsigned int x10; int x14; char p1[4]; int x1C; unsigned int x20; int x24; int x28; int x2C; } RFFD0;
extern RFFD0 *func_0010FE50(int);
extern RFFD0 *func_0010FE80(int, unsigned int);
extern int func_0010F988(unsigned int, void *, int, int, int, int);
extern void func_00117F48(int, void *, void *);
extern void func_0010FF90(void);
void func_0010FFD0(RFFD0 *p, int b)
{
    RFFD0 *r;
    if (p->x10 & 4) r = func_0010FE80(b, p->x10 >> 16);
    else r = func_0010FE50(b);
    { int t14 = p->x14; int t1C = p->x1C; r->x14 = t14; r->x1C = t1C; }
    r->x20 = 0x8000000C;
    r->x24 = p->x20;
    r->x28 = p->x24;
    r->x2C = p->x28;
    if (func_0010F988(0x80000008, r, 0x40, p->x20, p->x24, p->x28) == 0) func_00117F48(0x800, func_0010FF90, r);
}
/* merge_units: end func_0010FFD0 */

/* merge_units: begin func_001100A0 */
extern char D_004E4780[];
extern int *func_0010FD88(void *);
extern void func_0010FE30(void *),DeleteSema(int),WaitSema(int);
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
   func_0010FE30(packet);DeleteSema(client[2]);return -2;
  }
  WaitSema(client[2]);DeleteSema(client[2]);return 0;
 }else{
  client[2]=-1;
  if(!func_0010F948(0x8000000c,packet,64,0,0,0)){func_0010FE30(packet);return -2;}
  return 0;
 }
}
/* merge_units: end func_001100A0 */
