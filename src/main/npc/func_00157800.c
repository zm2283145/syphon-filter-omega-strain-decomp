#include "types.h"
#pragma cplusplus on
class G3Sub157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(); virtual int IsB();
};
class G3Ctl157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void SetActive(int on);
};
class G3Npc157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual int IsAlive();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47();
    virtual void Activate(int v);
    char pad4[0x2C];
    G3Ctl157* ctl;
};
typedef struct { char pad[0xC]; unsigned int id; char pad10[0x48]; G3Sub157* sub; } G3Gen157;
extern "C" {
extern unsigned char D_005721C8;
void func_00436C00(int* t);
int func_00434440(int* t, unsigned int* id);
void func_00436BA0(int* t, int f);
}
static inline unsigned char G3IsA(G3Gen157* g) { unsigned char r = 0; if (g->sub && g->sub->IsA()) r = 1; return r; }
static inline unsigned char G3IsB(G3Gen157* g) { unsigned char r = 0; if (g->sub && g->sub->IsB()) r = 1; return r; }
extern "C" void func_00157800(G3Npc157* n, G3Gen157* g)
{
    if (D_005721C8) {
        if (n->IsAlive()) {
            int v = -1;
            if (g) {
                if (G3IsA(g) || G3IsB(g)) {
                    int tmp[1];
                    func_00436C00(tmp);
                    v = func_00434440(tmp, &g->id);
                    func_00436BA0(tmp, -1);
                } else {
                    v = ((g->id & 0x7F000000) >> 24) - 1;
                }
            }
            n->Activate(v);
        }
    } else {
        n->ctl->SetActive(1);
    }
}