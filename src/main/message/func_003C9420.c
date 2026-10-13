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
}
extern "C" {
int Player_GetIndex(int); void Transport_Send(int,CMsg*,int,int);
void printf(char*); void func_002EBAF8(int*,int);
extern int D_00494178,D_005721A8;
extern unsigned char D_005721D0;
extern char D_004BD150[];
}
static inline int CurrentPlayer(int id) {
 if(D_005721C8) {if(D_00494178==-1)func_002EBAF8(&D_00494178,id); return D_00494178;}return 0;
}
static inline int LocalAuth(){return D_005721C8?D_005721C0:1;}
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
        if (D_005721C8 == 0) {
            return 1;
        }
    }
    temp_v0 = ((MessageV*)arg0)->Clone();
    if (temp_v0 == 0) {
        printf(D_004BD150);
        return 0;
    }
    temp_v0->magic = 0xBEBAAFDE;
    if (D_005721C8 != 0) {
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
