/* Prepare model and equipped-object texture handles in EE scratchpad.
 * Local declaration order preserves CodeWarrior register allocation.
 * Volatile debug-ID reads retain the original per-entry lookup order.
 */
#pragma cplusplus on
#include "types.h"
typedef struct {
    char pad[0x50];
    long long value;
} TxEntry;
typedef struct {
    int pad[2];
    TxEntry**entries;
    char padc[10];
    unsigned char flag;
    char pad17;
    unsigned count;
    short queue[512];
} TxManager;
typedef struct {
    char pad[0x3c0];
    short cur[8],prev[8];
    char pad3e0[0x40c-0x3e0];
    unsigned char count;
    char pad40d[4];
    signed char special;
    char pad412[5];
    signed char state;
} TxEquip;
typedef struct {
    char pad[0x22c0];
    short cur[32],prev[32];
    char pad2340[0x80];
    unsigned short count;
    char pad23c2[0x2410-0x23c2];
    TxEquip* equips[8];
    char pad2430[8];
    signed char disabled[8];
    char pad2440[0x2bd0-0x2440];
    int special;
    char pad2bd4[0x2c12-0x2bd4];
    signed char extra;
    char pad2c13[0x2dd0-0x2c13];
    signed char selector[32];
} TxModel;
extern "C" {
    extern TxManager* D_00539248;
    extern int D_0053B358,D_0055DE90;
    extern short D_0053B360[],D_0053B362,D_0053B364,D_0053B366,D_0053B368;
    void func_00382910(TxManager*);
}
static inline void tx_queue(TxManager* m,int id){
    unsigned n=m->count;
    if(n<512){
        if(n==0||m->queue[n-1]!=id)m->queue[m->count++]=id;
    }
}
extern "C" long long func_0038A800(TxModel* self,int which,int override,unsigned char flag){
    long long result=0;
    int count=self->count;
    TxManager* mgr=D_00539248;
    if(override){
        int n;
        long long*p;
        long long*dst;
        TxEquip*e;
        int i;
        char*base;
        dst=(long long*)0x70000a50;
        while(count>0){
            *dst++=0x20059a019930acc0LL;
            count--;
        }
        *dst=0x20059a019930acc0LL;
        i=0;
        base=(char*)0x70000000;
        for(;i<8;i++,base+=64){
            e=self->equips[i];
            if(e){
                n=e->count;
                p=(long long*)(base+0xb50);
                while(n>0){
                    *p++=0x20059a019930acc0LL;
                    n--;
                }
            }
        }
        return 0x20059a019930acc0LL;
    }
    if(D_0053B358){
        mgr->count=0;
        mgr->flag=0;
        tx_queue(mgr,D_0053B360[0]);
        tx_queue(mgr,D_0053B362);
        tx_queue(mgr,D_0053B364);
        tx_queue(mgr,D_0053B366);
        tx_queue(mgr,D_0053B368);
        func_00382910(mgr);
        struct Scratch {
            char pad[0xa50];
            long long values[40];
        };
        int i;
        Scratch* sc=(Scratch*)0x70000000;
        for(i=0;i<count;i++)sc->values[i]=mgr->entries[D_0053B360[self->selector[i]]]->value;
        result=mgr->entries[D_0053B360[self->selector[i]]]->value;
        {
            int special;
            int k;
            Scratch*dp;
            int n;
            int j;
            TxModel*walk;
            char*base;
            TxEquip*e;
            j=0;
            walk=self;
            base=(char*)0x70000000;
            for(;j<8;j++,walk=(TxModel*)((char*)walk+4),base+=64){
                e=walk->equips[0];
                if(e){
                    n=e->count;
                    special=e->special;
                    for(k=0;k<n;k++){
                        dp=(Scratch*)(base+k*8);
                        if(k!=special)dp->values[32]=mgr->entries[*(volatile short*)&D_0053B362]->value;
                        else dp->values[32]=mgr->entries[*(volatile short*)&D_0053B368]->value;
                    }
                }
            }
        }  if(self->extra)*(long long*)0x700024d0=mgr->entries[D_0053B366]->value;
        return result;
    }
    mgr->count=0;
    mgr->flag=0;
    short* ids;
    if(which==0)ids=self->cur;
    else ids=self->prev;
    int n=count;
    while(n>0){
        tx_queue(mgr,*ids++);
        n--;
    }
    if(self->special)tx_queue(mgr,*ids);
    {
        TxEquip*e;
        int i;
        int z;
        int id;
        TxModel*walk;
        short*p;
        i=0;
        walk=self;
        for(;i<8;i++,walk=(TxModel*)((char*)walk+4)){
            e=walk->equips[0];
            if(e&&!self->disabled[i]&&!e->state){
                if(which==0)p=e->cur;
                else p=e->prev;
                z=e->count;
                while(z>0){
                    id=*p++;
                    unsigned qn=mgr->count;
                    if(qn<512){
                        if(qn==0||mgr->queue[qn-1]!=id)mgr->queue[mgr->count++]=id;
                    }z--;
                }
            }
        }
    } if(self->extra)tx_queue(mgr,D_0055DE90);
    func_00382910(mgr);
    if(which==0)ids=self->cur;
    else ids=self->prev;
    long long*dst=(long long*)0x70000a50;
    while(count>0){
        count--;
        *dst++=mgr->entries[*ids++]->value;
    }
    if(self->special)result=mgr->entries[*ids]->value;
    {
        int i;
        int n;
        TxModel*walk;
        char*base;
        TxEquip*e;
        long long*d;
        short*p;
        i=0;
        walk=self;
        base=(char*)0x70000000;
        for(;i<8;i++,walk=(TxModel*)((char*)walk+4),base+=64){
            e=walk->equips[0];
            if(e&&!self->disabled[i]&&!e->state){
                if(which==0)p=e->cur;
                else p=e->prev;
                n=e->count;
                d=(long long*)(base+0xb50);
                while(n>0){
                    n--;
                    *d++=mgr->entries[*p++]->value;
                }
            }
        }
    } if(self->extra)*(long long*)0x700024d0=mgr->entries[D_0055DE90]->value;
    return result;
}
