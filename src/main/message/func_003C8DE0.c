#pragma cplusplus on
#include "types.h"
#define CMSG_NO_PROTOS
#include "cmessage.h"
#include "alloc_guard.h"
struct MessageV { virtual void Destroy(int); virtual CMsg* Clone(); };
struct TargetV {
 virtual void v0(); virtual void Handle(CMsg*);
 virtual void v2(); virtual void v3(); virtual int IsNet();
 virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual int Filter(CMsg*);
 unsigned int magic; int pad8; int id; int netid;
};
struct QEntry { int mode; CMsg* msg; TargetV* target; };
struct QNode { QNode* prev; QNode* next; QEntry entry; };
extern "C" {
void Mem_Free(int,void*,char*,int);
void MsgQueue_Insert(void*,void*,void*,QEntry*);
extern char D_004BD118[];
extern int D_005435C0,D_005435E0;
extern QNode D_005435C4,D_005435E4;
extern QNode* D_005435C8; extern QNode* D_005435E8;
extern unsigned char D_005721C0,D_005721C8;
QEntry* func_003C92D0(QNode**);
void func_003C92E0(QNode**,int);
void func_003C9340(QNode**,int*);
void func_003C9EA0(int*,int*,int*,int*);
}
static inline QEntry* PendAt2(int i) { QNode* it; func_003C9340(&it, &D_005435C0); func_003C92E0(&it, i); return func_003C92D0(&it); }
static inline QEntry* PendAt(int i) { return PendAt2(i); }
/* pos is assigned twice: the first assignment orders the hoisted &D_005435E4
   ahead of &e->target in the loop preheader, the second keeps its stack store
   after the target store (in the jal delay slot), as in retail. */
static inline void PushActive(QEntry* e, TargetV* dst) {
 int result; int pos;
 pos = (int)&D_005435E4;
 { TargetV** pt = &e->target; *pt = dst; }
 pos = (int)&D_005435E4;
 MsgQueue_Insert(&result, &D_005435E0, &pos, e);
}
static inline void ClearPend() { int r; int first; int last; last = (int)&D_005435C4; first = (int)D_005435C8; func_003C9EA0(&r, &D_005435C0, &first, &last); }
static inline void ClearActive() { int r; int first; int last; last = (int)&D_005435E4; first = (int)D_005435E8; func_003C9EA0(&r, &D_005435E0, &first, &last); }

extern "C" int MsgQueue_Pump(void) {
 int i;
 int n = D_005435C0;
 for (i = 0; i < n; i++) {
  int k = i; QNode* p = D_005435C8;
  if (k >= 0) { while (k > 0) { p = p->next; k--; } }
  else { while (k < 0) { p = p->prev; k++; } }
  CMsg* msg = p->entry.msg;
  CMsg* copy; TargetV* dst = PendAt(i)->target;
  copy = ((MessageV*)msg)->Clone();
  QEntry entry;
  entry.mode = PendAt(i)->mode;
  /* The two-use body-local pointer to a member of a local aggregate keeps MW
     from rotating this loop; it hoists &entry.msg / &entry.target into an
     out-of-line guarded preheader at the function end, as in retail. */
  { CMsg** pm = &entry.msg; CMsg** pm2 = pm; *pm2 = copy; }
  PushActive(&entry, dst);
  msg->magic = 0;
  { AllocGuard g; ((MessageV*)msg)->Destroy(-1); Mem_Free(0, msg, D_004BD118, 0x183); }
 }
 ClearPend();
 int m = D_005435E0;
 for (i = 0; i < m; i++) {
  int k = i; QNode* p = D_005435E8;
  if (k >= 0) { while (k > 0) { p = p->next; k--; } }
  else { while (k < 0) { p = p->prev; k++; } }
  TargetV* dst = p->entry.target;
  int k2 = i; QNode* q = D_005435E8;
  if (k2 >= 0) { while (k2 > 0) { q = q->next; k2--; } }
  else { while (k2 < 0) { q = q->prev; k2++; } }
  CMsg* msg = q->entry.msg;
  if (D_005721C8) {
   if (msg->magic == 0xBEBAAFDE && dst && dst->magic == 0xBEBAAFDE) {
    int local = D_005721C8 ? D_005721C0 : 1;
    if (!local) dst->Handle(msg); else if (!dst->Filter(msg)) dst->Handle(msg);
   }
  } else if (dst->magic == 0xBEBAAFDE && !dst->Filter(msg)) dst->Handle(msg);
  msg->magic = 0;
  { AllocGuard g; ((MessageV*)msg)->Destroy(-1); Mem_Free(0, msg, D_004BD118, 0x1AE); }
 }
 ClearActive();
 return 1;
}
