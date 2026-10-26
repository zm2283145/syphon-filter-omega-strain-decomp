/*
 * lib/libkernl: 3 files, 00110288-00110498
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00110288 */
typedef struct { char p0[0x14]; int x14; char p1[4]; int x1C; unsigned int x20; int x24; int x28; } R0288;
typedef struct { int x0; int x4; int x8; } S0288;
extern R0288 *_sceRpcGetFPacket(int);
extern S0288 *_search_svdata(unsigned int, int);
extern int isceSifSendCmd(unsigned int, void *, int, int, int, int);
extern void iSetTimerAlarm(int, void *, void *);
extern void _alarm_bind(void);
void _request_bind(R0288 *p, int b)
{
    R0288 *r = _sceRpcGetFPacket(b);
    S0288 *s;
    { int t14 = p->x14; int t1C = p->x1C; r->x1C = t1C; r->x14 = t14; }
    r->x20 = 0x80000009;
    s = _search_svdata(p->x20, b);
    if (s == 0) {
        r->x24 = 0;
        r->x28 = 0;
    } else {
        r->x24 = (int)s;
        r->x28 = s->x8;
    }
    if (isceSifSendCmd(0x80000008, r, 0x40, 0, 0, 0) == 0) iSetTimerAlarm(0x800, _alarm_bind, r);
}
/* merge_units: end func_00110288 */

/* merge_units: begin func_00110358 */
extern char D_004E4780[];
extern int *_sceRpcGetPacket_void(void *);
extern void _sceRpcFreePacket_void(void *),DeleteSema(int),WaitSema(int);
extern int CreateSema(void *),sceSifSendCmd(unsigned,void *,int,void *,int,int);
int sceSifBindRpc(int *client,int sid,int mode){
 int sem[8],*packet;
 client[4]=0;client[9]=0;
 packet=_sceRpcGetPacket_void(D_004E4780);
 if(!packet)return -1;
 {int token=packet[6];client[0]=(int)packet;client[1]=token;}
 packet[8]=sid;packet[5]=(int)packet;packet[7]=(int)client;
 if(!(mode&1)){
  sem[2]=0;sem[1]=1;
  client[2]=CreateSema(sem);
  if(client[2]<0){_sceRpcFreePacket_void(packet);return -3;}
  if(!sceSifSendCmd(0x80000009,packet,64,0,0,0)){
   _sceRpcFreePacket_void(packet);DeleteSema(client[2]);return -2;
  }
  WaitSema(client[2]);DeleteSema(client[2]);return 0;
 }else{
  client[2]=-1;
  if(!sceSifSendCmd(0x80000009,packet,64,0,0,0)){_sceRpcFreePacket_void(packet);return -2;}
  return 0;
 }
}
/* merge_units: end func_00110358 */

/* merge_units: begin func_00110498 */
typedef struct Srv Srv;
typedef struct { int tid; int active; int x8; int start; int end; } Queue;
struct Srv { int x0; int x4; int x8; int s0C; int x10; int x14; int x18; int s1C; int s20; int s24; int s28; int s2C; int s30; int s34; int x38; Srv *link; Queue *base; };
typedef struct { int x0; int x4; int x8; int xC; int r10; int r14; int x18; int r1C; int r20; int r24; int r28; int r2C; int r30; Srv *server; } CallPkt;
extern void iWakeupThread(int);
void _request_call(CallPkt *req, void *data)
{
    Srv *server = req->server;
    Queue *base = server->base;
    if (!base->start)
        base->start = (int)server;
    else
        ((Srv *)base->end)->link = server;
    base->end = (int)server;
    { int a = req->r14; int b = req->r1C; server->s20 = a; server->s1C = b; }
    server->s24 = req->r20;
    server->s0C = req->r24;
    server->s28 = req->r28;
    server->s2C = req->r2C;
    server->s30 = req->r30;
    server->s34 = req->r10;
    if (base->tid >= 0 && base->active == 0)
        iWakeupThread(base->tid);
}
/* merge_units: end func_00110498 */
