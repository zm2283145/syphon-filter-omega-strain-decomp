#pragma cplusplus on
#include "types.h"
struct W_002AC070 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void SetCount(int n, int a);
};
struct It_002AC070 { int id; int idx; int fl; };
struct Vec_002AC070 { int f0; int count; It_002AC070* data; int f118; };
struct L_002AC070 { int f0; int count; };
struct E_002AC070 { int id; };
struct S_002AC070 : W_002AC070 {
    char pad4[0x48 - 4]; int f48; char pad4C[0xC0 - 0x4C];
    int fC0; int fC4; int fC8; int fCC; char padD0[0x10C - 0xD0];
    Vec_002AC070 list; L_002AC070* p11C;
};
extern "C" {
static int D_0048BCB0 = -1;
void func_002AD770(Vec_002AC070* v);
void* DME_GetLobby(void);
E_002AC070* LobbyArray_At(L_002AC070* l, int i);
int func_002AC470(S_002AC070* self, E_002AC070* e);
void func_002AD1F0(Vec_002AC070* v, It_002AC070* pos, int n, It_002AC070* it);
void func_002AC6F0(S_002AC070* self);
}
static inline int Size_002AC070(Vec_002AC070* v) { return v->count; }
static inline It_002AC070* At_002AC070(Vec_002AC070* v, int i) { return &v->data[i]; }
static inline void Upd_(S_002AC070* s, int n) { s->SetCount(s->f48, n); }
#pragma opt_strength_reduction off
#pragma opt_dead_assignments off
extern "C" void func_002AC070(S_002AC070* self)
{
    void* g;
    int n;
    int i;
    int sel;
    func_002AD770(&self->list);
    g = DME_GetLobby();
    if (!self->p11C || !g)
        return;
    n = self->p11C->count;
    for (i = 0; i < n; i++) {
        E_002AC070* e = LobbyArray_At(self->p11C, i);
        if (e) {
            int fl = func_002AC470(self, e);
            if (fl & 2) {
                It_002AC070 it;
                if ((fl & 4) && e->id == 0) {
                    e->id = D_0048BCB0;
                    D_0048BCB0 = D_0048BCB0 - 1;
                }
                it.id = e->id;
                it.idx = i;
                it.fl = fl;
                func_002AD1F0(&self->list, &self->list.data[self->list.count], 1, &it);
            }
        }
    }
    func_002AC6F0(self);
    sel = -1;
    if (self->fC0 != -1) {
        int j;
        for (j = 0; j < *(volatile int*)&self->list.count; j++) {
            if (self->fC0 == At_002AC070(&self->list, j)->id) {
                self->fCC = j;
                sel = j;
                break;
            }
        }
    }
    Upd_(self, self->list.count);
    if (sel == -1) {
        if (self->fCC == -1)
            self->fCC = 0;
        if (self->fCC >= self->list.count)
            self->fCC = self->list.count - 1;
    }
    if (self->fCC == -1) {
        self->fC0 = self->fC4 = self->fCC = -1;
    } else {
        int k = At_002AC070(&self->list, self->fCC)->idx;
        E_002AC070* e = LobbyArray_At(self->p11C, k);
        if (e) {
            self->fC0 = e->id;
            self->fC4 = k;
        } else {
            self->fC0 = self->fC4 = self->fCC = -1;
        }
    }
    if (self->fCC >= self->list.count)
        self->fCC = self->list.count - 1;
    if (self->fCC < 0)
        self->fCC = 0;
}








