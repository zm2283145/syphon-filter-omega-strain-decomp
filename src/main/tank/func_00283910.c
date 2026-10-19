#pragma cplusplus on
#include "types.h"
typedef struct { void* vtable; char pad4[0x18]; int flags; unsigned char cls; char pad21[3]; unsigned char type; char pad25[3]; int w; float f; } M_00283910;
extern "C" {
extern char* D_005061D0;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
void func_00282160(int* p);
void cTank_SetEnemy(void* t, int w);
void cNIEventOBJ_SetSpeedRecursive(float f, void* o);
void cTank_Fire(void* x);
void Event_Construct(M_00283910* m, void* type);
void Event_Send(M_00283910* m, void* target, int flags);
void cMessage_dtor(M_00283910* m, int flags);
}
struct A_00283910 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); virtual int v30(); virtual int v31(); virtual int v32(); virtual int v33(); virtual int v34(); virtual int v35(); virtual int v36(); virtual int v37(); virtual int v38(); virtual int v39(); virtual int v40(); virtual int v41(); virtual int v42(); virtual int v43(); virtual int v44(); virtual int v45(); virtual int v46(); virtual int v47(); virtual int v48(); virtual int v49(); virtual int v50(); virtual int v51(); virtual int v52(); virtual int v53(); virtual int v54(); virtual int v55(); virtual int v56(); virtual int v57(); virtual int v58(); virtual int v59(); virtual int v60(); virtual int v61(); virtual int v62(); virtual int v63(); virtual int v64(); virtual int v65(); virtual int v66(); virtual void v67(); };
struct B_00283910 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); virtual int v30(); virtual int v31(); virtual int v32(); virtual int v33(); virtual int v34(); virtual int v35(); virtual int v36(); virtual int v37(); virtual int v38(); virtual int v39(); virtual int v40(); virtual int v41(); virtual int v42(); virtual int v43(); virtual int v44(); virtual int v45(); virtual int v46(); virtual int v47(); virtual int v48(); virtual int v49(); virtual int v50(); virtual int v51(); virtual int v52(); virtual int v53(); virtual int v54(); virtual int v55(); virtual int v56(); virtual int v57(); virtual int v58(); virtual int v59(); virtual int v60(); virtual int v61(); virtual int v62(); virtual int v63(); virtual int v64(); virtual int v65(); virtual int v66(); virtual int v67(); virtual void v68(int a); };
typedef struct { B_00283910* obj; char pad[0x50]; unsigned char b54; } X_00283910;
typedef struct { char pad[0x60]; A_00283910* a; char pad64[8]; X_00283910* x; unsigned char b70; } T_00283910;
static inline short R16_00283910(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_00283910(void) { unsigned short lo = R16_00283910(); return lo + ((unsigned short)R16_00283910() << 16); }
static inline char R8_00283910(void) { return *D_005061D0++; }
static inline float RF_00283910(void) { int i = R32_00283910(); return *(float*)&i; }
static inline int Ok_00283910(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
static inline void Send_00283910(T_00283910* t, int type, int w, float f) {
    M_00283910 m;
    Event_Construct(&m, D_00506260);
    m.vtable = D_004DCF50;
    m.type = type; m.cls = 4; m.flags = 0x40; m.f = f; m.w = w;
    Event_Send(&m, t, 0);
    m.vtable = D_004DCF10;
    cMessage_dtor(&m, 0);
}
extern "C" void func_00283910(M_00283910* p, T_00283910* t) {
    p->type = R8_00283910();
    func_00282160(&p->w);
    p->f = RF_00283910();
    if (t) {
        switch (p->type) {
        case 0:
            cTank_SetEnemy(t, p->w);
            break;
        case 1: {
            float f = p->f;
            A_00283910* a = t->a;
            cNIEventOBJ_SetSpeedRecursive(f, a);
            a->v67();
            if (t->x) t->x->obj->v68(1);
            if (g_IsMultiplayer && Ok_00283910()) Send_00283910(t, 1, 0, f);
            break;
        }
        case 2:
            if (t->x) t->x->b54 = 0;
            t->b70 = 1;
            if (g_IsMultiplayer && Ok_00283910()) Send_00283910(t, 2, 0, 0.0f);
            break;
        case 3:
            if (t->x) {
                t->x->b54 = 0;
                cTank_Fire(t->x);
            }
            break;
        case 4:
            if (t->x) t->x->b54 = 1;
            if (g_IsMultiplayer && Ok_00283910()) Send_00283910(t, 4, 0, 0.0f);
            break;
        }
    }
}