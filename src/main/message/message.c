/*
 * main/message: message.cc (8 files, 003C8C70-003C99B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_003C8C70 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004BD118[];
extern int D_005435C0;
}
struct C8Obj { virtual void v0(int); int m4; int m8; };
typedef struct C8Node { struct C8Node* prev; struct C8Node* next; int key; C8Obj* data; } C8Node;
extern "C" {
extern struct C8Node D_005435C4;
extern C8Node* D_005435C8;
void func_003C9EA0(int* out, int* self, int* first, int* last);
}
extern "C" void MsgQueue_ClearPending(void)
{
    C8Obj* obj;
    int i;
    int n = D_005435C0;
    for (i = 0; i < n; i++) {
        int k = i;
        C8Node* p = D_005435C8;
        if (k >= 0) {
            while (k > 0) { p = p->next; k--; }
        } else {
            while (k < 0) { p = p->prev; k++; }
        }
        obj = p->data;
        obj->m8 = 0;
        {
            AllocGuard g;
            obj->v0(-1);
            Mem_Free(0, obj, D_004BD118, 0x1C2);
        }
    }
    {
        int r;
        int first;
        int last;
        last = (int)&D_005435C4;
        first = (int)D_005435C8;
        func_003C9EA0(&r, &D_005435C0, &first, &last);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C8C70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C8C70 */

/* merge_units: begin func_003C8DE0 */
#pragma push /* merge_units */
char* func_003C92D0(char** self); /* gsynth: defined below */
typedef struct G6N3C { struct G6N3C* prev; struct G6N3C* next; } G6N3C;
void func_003C92E0(G6N3C** pp, int n); /* gsynth: defined below */
void func_003C9340(Iter* out, PtrVec* v); /* gsynth: defined below */
#pragma cplusplus on
#define CMSG_NO_PROTOS
#include "cmessage.h"
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
void MsgQueue_Insert(void*,void*,void*,QEntry*);
extern int D_005435E0;
#if 0 /* merge_units */
extern QNode D_005435C4;
#endif /* merge_units */
#define D_005435C4 (*(QNode*)&D_005435C4) /* merge_units */

extern QNode D_005435E4;
#if 0 /* merge_units */
extern QNode* D_005435C8;
#endif /* merge_units */
#define D_005435C8 (*(QNode **)&D_005435C8) /* merge_units */
extern QNode* D_005435E8;
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
#if 0 /* merge_units */
QEntry* func_003C92D0(QNode**);
#endif /* merge_units */
#define func_003C92D0(a0) ((QEntry *)func_003C92D0((char * *)(a0))) /* merge_units */

#if 0 /* merge_units */
void func_003C92E0(QNode**,int);
#endif /* merge_units */
#define func_003C92E0(a0, a1) (func_003C92E0((G6N3C * *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void func_003C9340(QNode**,int*);
#endif /* merge_units */
#define func_003C9340(a0, a1) (func_003C9340((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
void func_003C9EA0(int*,int*,int*,int*);
#endif /* merge_units */
#define func_003C9EA0(a0, a1, a2, a3) (func_003C9EA0((a0), (a1), (a2), (a3))) /* merge_units */

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
  if (g_IsMultiplayer) {
   if (msg->magic == 0xBEBAAFDE && dst && dst->magic == 0xBEBAAFDE) {
    int local = g_IsMultiplayer ? D_005721C0 : 1;
    if (!local) dst->Handle(msg); else if (!dst->Filter(msg)) dst->Handle(msg);
   }
  } else if (dst->magic == 0xBEBAAFDE && !dst->Filter(msg)) dst->Handle(msg);
  msg->magic = 0;
  { AllocGuard g; ((MessageV*)msg)->Destroy(-1); Mem_Free(0, msg, D_004BD118, 0x1AE); }
 }
 ClearActive();
 return 1;
}
#undef D_005435C4 /* merge_units */
#undef D_005435C8 /* merge_units */
#undef func_003C92D0 /* merge_units */
#undef func_003C92E0 /* merge_units */
#undef func_003C9340 /* merge_units */
#undef func_003C9EA0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C8DE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C8DE0 */

/* merge_units: begin func_003C92D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Returns the address 8 bytes into the object pointed to by *self. */
char* func_003C92D0(char** self) {
    return *self + 8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C92D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C92D0 */

/* merge_units: begin func_003C92E0 */
#pragma push /* merge_units */
void func_003C92E0(G6N3C** pp, int n)
{
    if (n >= 0) {
        while (n > 0) { *pp = (*pp)->next; n--; }
    } else {
        while (n < 0) { *pp = (*pp)->prev; n++; }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C92E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C92E0 */

/* merge_units: begin func_003C9340 */
#pragma push /* merge_units */
/* begin(): iterator at the first element. */
void func_003C9340(Iter* out, PtrVec* v) {
    out->p = v->data;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C9340(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C9340 */

/* merge_units: begin func_003C9350 */
#pragma push /* merge_units */
#pragma cplusplus on
struct MsgQC {
    virtual void v00();
    virtual MsgQC* Clone();
    int pad4;
    int magic;
};
struct EntryQC { int mode; MsgQC* msg; MsgQC* orig; EntryQC(int md, MsgQC* m, MsgQC* o) { mode = md; msg = m; orig = o; } };
struct ObjQC { virtual void v00(); virtual void Handle(MsgQC* m); };
#if 0 /* merge_units */
extern "C" char D_005435C0[];
#endif /* merge_units */
#define D_005435C0 ((char*)&D_005435C0) /* merge_units */

#if 0 /* merge_units */
extern "C" char D_005435C4[];
#endif /* merge_units */
#define D_005435C4 ((char*)&D_005435C4) /* merge_units */

extern "C" void printf(char* msg);
#if 0 /* merge_units */
extern "C" void MsgQueue_Insert(void* res, void* map, void* key, EntryQC* e);
#endif /* merge_units */
#define MsgQueue_Insert(a0, a1, a2, a3) (MsgQueue_Insert((a0), (a1), (a2), (QEntry *)(a3))) /* merge_units */

extern "C" int MsgQueue_QueueClone(MsgQC* m, ObjQC* target, int mode)
{
    if (target) {
        if (mode != 1) {
            MsgQC* c = m->Clone();
            if (!c) {
                printf("Message Clone Failed (2)!\n");
                return 0;
            }
            {
                int res;
                char* key;
                c->magic = 0xBEBAAFDE;
                EntryQC e(mode, c, (MsgQC*)target);
                key = D_005435C4;
                MsgQueue_Insert(&res, D_005435C0, &key, &e);
            }
        } else {
            target->Handle(m);
        }
    }
    return 1;
}
#undef D_005435C0 /* merge_units */
#undef D_005435C4 /* merge_units */
#undef MsgQueue_Insert /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C9350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C9350 */

/* merge_units: begin func_003C9420 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
#if 0 /* merge_units */
extern QNode D_005435C4;
#endif /* merge_units */
#define D_005435C4 (*(QNode*)&D_005435C4) /* merge_units */

#if 0 /* merge_units */
extern QNode* D_005435C8;
#endif /* merge_units */
#define D_005435C8 (*(QNode **)&D_005435C8) /* merge_units */

}
extern "C" {
int Player_GetIndex(int); void Transport_Send(int,CMsg*,int,int);
#if 0 /* merge_units */
void printf(char*);
#endif /* merge_units */
#define printf(a0) (printf((a0))) /* merge_units */
void NetGame_InitLocalSlot(int*,int);
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721D0;
extern char D_004BD150[];
}
static inline int CurrentPlayer(int id) {
 if(g_IsMultiplayer) {if(D_00494178==-1)NetGame_InitLocalSlot(&D_00494178,id); return D_00494178;}return 0;
}
static inline int LocalAuth(){return g_IsMultiplayer?D_005721C0:1;}
static inline void Enqueue(int mode,CMsg* msg,TargetV* obj) {
 int result; QNode* pos; QEntry e;
 e.mode=mode;e.msg=msg;e.target=obj;
 pos=&D_005435C4;
 MsgQueue_Insert(&result,&D_005435C0,&pos,&e);
}
extern "C" int Event_Send(CMsg *arg0, TargetV *arg1, int arg2) {
    int temp_s0;
    int temp_s0_3;
    int temp_s6;
    int var_s0;
    bool var_s2;
    int var_s2_2;
    int var_v1;
    int var_v1_2;
    unsigned int temp_s0_2;
    unsigned int temp_s0_4;
    unsigned char temp_v1;
    unsigned char temp_v1_2;
    unsigned char temp_v1_3;
    int var_v0;
    int var_v0_2;
    CMsg *temp_v0;

    var_s2 = 0;
    if ((arg2 == 1) && (arg0->kind & 1)) {
        arg1->Handle(arg0);
        var_s2 = 1;
        if (g_IsMultiplayer == 0) {
            return 1;
        }
    }
    temp_v0 = ((MessageV*)arg0)->Clone();
    if (temp_v0 == 0) {
        printf(D_004BD150);
        return 0;
    }
    temp_v0->magic = 0xBEBAAFDE;
    if (g_IsMultiplayer != 0) {
        if (arg1 != 0) {
            if ((D_005721D0 != 0) && (arg1->IsNet() != 0)) {
                temp_v1 = arg0->kind;
                if (temp_v1 & 4) {
                    arg0->stampKind = arg2;
                    Transport_Send(arg1->netid, temp_v0, -1, -1);
                } else if (temp_v1 & 8) {
                    temp_s6 = arg1->netid;
                    var_s0=CurrentPlayer(D_005721A8);
                    if (var_s0 != Player_GetIndex(temp_s6)) {
                        arg0->stampKind = arg2;
                        temp_s0 = arg1->netid;
                        Transport_Send(temp_s0, temp_v0, Player_GetIndex(temp_s0), -1);
                    } else {
                        goto block_24;
                    }
                } else {
block_24:
                    temp_v1_2 = arg0->kind;
                    if (temp_v1_2 & 2) {
                        var_v0=LocalAuth();
                        if (var_v0 == 0) {
                            arg0->stampKind = arg2;
                            Transport_Send(arg1->netid, temp_v0, -1, -1);
                        } else {
                            goto block_30;
                        }
                    } else {
block_30:
                        if (temp_v1_2 & 0x20) {
                            temp_s0_2 = (unsigned int) (arg1->id & 0x7F000000) >> 0x18;
                            var_v1=CurrentPlayer(D_005721A8);
                            if (var_v1 != (temp_s0_2 - 1)) {
                                arg0->stampKind = arg2;
                                Transport_Send(arg1->netid, temp_v0, ((unsigned int) (arg1->id & 0x7F000000) >> 0x18) - 1, -1);
                            }
                        }
                    }
                }
            }
            if ((!var_s2) && (arg0->kind & 1)) {
                Enqueue(arg2,temp_v0,arg1);
            } else if (arg0->kind & 8) {
                temp_s0_3 = arg1->id;
                var_s2_2=CurrentPlayer(D_005721A8);
                if (var_s2_2 == Player_GetIndex(temp_s0_3)) {
                    Enqueue(arg2,temp_v0,arg1);
                } else {
                    goto block_52;
                }
            } else {
block_52:
                temp_v1_3 = arg0->kind;
                if (temp_v1_3 & 2) {
                    var_v0_2=LocalAuth();
                    if (var_v0_2 != 0) {
                        Enqueue(arg2,temp_v0,arg1);
                    } else {
                        goto block_58;
                    }
                } else {
block_58:
                    if (temp_v1_3 & 0x20) {
                        temp_s0_4 = (unsigned int) (arg1->id & 0x7F000000) >> 0x18;
                        var_v1_2=CurrentPlayer(D_005721A8);
                        if (var_v1_2 == (temp_s0_4 - 1)) {
                            Enqueue(arg2,temp_v0,arg1);
                        } else {
                            goto block_67;
                        }
                    } else {
block_67:
                        temp_v0->magic = 0;
                        { AllocGuard guard;
                          ((MessageV*)temp_v0)->Destroy(-1);
                          Mem_Free(0,temp_v0,D_004BD118,0x132);
                        }
                    }
                }
            }
        }
    } else {
        Enqueue(arg2,temp_v0,arg1);
    }
    return 1;
}
#undef D_005435C4 /* merge_units */
#undef D_005435C8 /* merge_units */
#undef printf /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C9420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C9420 */

/* merge_units: begin func_003C99B0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
#if 0 /* merge_units */
int Alloc_Lock(int);
#endif /* merge_units */
#define Alloc_Lock(a0) (Alloc_Lock((a0))) /* merge_units */

#if 0 /* merge_units */
int Alloc_Unlock(int);
#endif /* merge_units */
#define Alloc_Unlock(a0) (Alloc_Unlock((a0))) /* merge_units */

}
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
struct VC003C99B0 { virtual int v0(...); };
extern "C" {
int func_003C9B20(...);
int func_003C9B30(...);
char *func_003C9B40(...);
int func_003C9FE0(...);
#if 0 /* merge_units */
extern char D_004BD118;
#endif /* merge_units */
#define D_004BD118 (*(char*)&D_004BD118) /* merge_units */

#if 0 /* merge_units */
extern char D_005435C0;
#endif /* merge_units */
#define D_005435C0 (*(char*)&D_005435C0) /* merge_units */

#if 0 /* merge_units */
extern char D_005435C4;
#endif /* merge_units */
#define D_005435C4 (*(char*)&D_005435C4) /* merge_units */

}
typedef struct { int first; void **second; } Pr3C;
#pragma push
#pragma inline_depth(10)
#pragma opt_common_subs off

typedef struct { int r; char *n; int ret[2]; } SL3C;
static inline int ite0(SL3C *s) { func_003C9B20(&s->r, func_003C9B30(&D_005435C0)); return s->r; }
static inline void er1(char *n);
static inline void er0(SL3C *s, char *n) { s->n = n; func_003C9FE0(s->ret, &D_005435C0, &s->n); }
extern "C" int MsgQueue_EraseFirstPending(int *arg0) {
    char *var_s0;
    char *temp_a0;
    void **temp_s1;
    Pr3C *pr;
    SL3C sl;

    var_s0 = (char *)(F_(func_003C9B40(&D_005435C4), 0x4, int));
    while (var_s0 != (char *)ite0(&sl)) {
        temp_a0 = (char *)(F_(var_s0, 0xC, int));
        if ((temp_a0 != NULL) && (*(int *)F_(temp_a0, 0x4, int) == *arg0)) {
            pr = (Pr3C *)(var_s0 + 8);
            if (temp_a0 != NULL) {
                F_(temp_a0, 0x8, int) = 0;
                temp_s1 = pr->second;
                if (g_ProfileLockEnabled != 0) Alloc_Lock(9); g_ProfileLockDepth += 1; ((VC003C99B0 *)(temp_s1))->v0(-1); Mem_Free(0, temp_s1, &D_004BD118, 0xCF); if (g_ProfileLockEnabled != 0) Alloc_Unlock(9); g_ProfileLockDepth -= 1;
            }
            er0(&sl, var_s0);
            return 1;
        }
        var_s0 = (char *)(F_(var_s0, 0x4, int));
    }
    return 0;
}
#pragma pop
#undef Alloc_Lock /* merge_units */
#undef Alloc_Unlock /* merge_units */
#undef D_004BD118 /* merge_units */
#undef D_005435C0 /* merge_units */
#undef D_005435C4 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C99B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C99B0 */
