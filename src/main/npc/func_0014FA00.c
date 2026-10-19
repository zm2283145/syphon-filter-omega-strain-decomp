#pragma cplusplus on
#pragma opt_propagation off
#include "types.h"
#include "vslot_pad.h"

struct HObj4FA {
    char pad[0xC];
    int id;
};

struct Handle4FA {
    HObj4FA* obj;
    int id;
};

struct Node4FA {
    int unk0;
    Node4FA* next;
    Handle4FA* h;
};

class Ctl4FA {
public:
    VPAD32(p) VPAD32(q)
    virtual unsigned char GetMode();
};

struct Inner4FA {
    char pad[0x58];
    int owner;
};

class Npc4FA {
public:
    VPAD32(p)
    virtual unsigned char GetState();
    char pad[0x2C];
    Ctl4FA* ctl;
    char pad34[0xE0 - 0x34];
    int resA;
    int resB;
    char padE8[0x1B0 - 0xE8];
    Inner4FA* inner;
};

struct Obj4FA {
    char pad[0x58];
    Npc4FA* npc;
};

extern "C" {
extern Tree g_NpcThinkList;
extern void func_0014FC10(Iter* out, Tree* t);
extern Word* func_0014AB70(Word* dst, Word* src);
extern void func_0014AB80(Iter* out, Tree* t);
}

static inline void FCopy4FA(float* d, float* s) { float* ss = s; float* dd = d; *dd = *ss; }

extern "C" Ctl4FA* NpcAi_NodeReservedBy(int node)
{
    Node4FA* it;
    int tmp;
    Word w;
    Word w2;
    Iter b;
    Iter end;
    Ctl4FA* result = 0;

    func_0014FC10(&b, &g_NpcThinkList);
    func_0014AB70(&w, (Word*)&b);
    { int v = w.value; tmp = v; }
    FCopy4FA((float*)&it, (float*)&tmp);
    func_0014AB80(&end, &g_NpcThinkList);
    func_0014AB70(&w2, (Word*)&end);
    while (*(int*)&it != w2.value) {
        unsigned char valid;
        Handle4FA* h;
        HObj4FA* o;
        int isnull;
        h = it->h;
        o = h->obj;
        isnull = (o != 0) ^ 1;
        valid = 1;
        if (!isnull && o->id != h->id) {
            valid = 0;
        }
        if (valid ? o : 0) {
            if (o && o->id != h->id) {
                o = 0;
            }
            if (((Obj4FA*)o)->npc->GetState() == 1) {
                Npc4FA* npc;
                unsigned char v3;
                Handle4FA* h3;
                HObj4FA* o3;
                int n3;
                h3 = it->h;
                o3 = h3->obj;
                n3 = (o3 != 0) ^ 1;
                v3 = 1;
                if (!n3 && o3->id != h3->id) {
                    v3 = 0;
                }
                npc = ((Obj4FA*)(v3 ? o3 : 0))->npc;
                if (npc->ctl->GetMode() != 3) {
                    if (node == npc->resB || node == npc->resA || node == npc->inner->owner) {
                        result = npc->ctl;
                        break;
                    }
                }
            }
        }
        it = it->next;
        func_0014AB80(&end, &g_NpcThinkList);
        func_0014AB70(&w2, (Word*)&end);
    }
    return result;
}
