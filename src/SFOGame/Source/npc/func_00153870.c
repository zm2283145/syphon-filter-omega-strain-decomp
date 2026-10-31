static inline void ScaleV(void* rp, const void* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
/* score 39 (w5) */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
__declspec(weak) __declspec(DROPDTOR) float k6_ctx(unsigned long a) { return (float)a; }
#include "alloc_guard.h"
#pragma inline_depth(8)
extern "C" double SoftFloat_FloatToDouble(float);
struct V {
    float x, y, z, w;
    V() {}
    V(const V& v, float ww) { V* t = this; const V* s = &v; *t = *s; w = ww; }
    V(int, const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(&o)); *(__int128*)this = t; }
    V(short, const V& o) { __int128* d; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(&o)); d = (__int128*)this; *d = t; }
    V(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    static void VU0Subtract(V& vecOut, const V& vecIn0, const V& vecIn1) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&vecOut), "r"(&vecIn0), "r"(&vecIn1) : "memory"); }
    V operator-(const V& vector) const { V result; VU0Subtract(result, *this, vector); return result; }
    static void VU0Add(V& vecOut, const V& vecIn0, const V& vecIn1) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&vecOut), "r"(&vecIn0), "r"(&vecIn1) : "memory"); }
    V operator+(const V& vector) const { V result; VU0Add(result, *this, vector); return result; }
    V operator*(float k) const { V r; ScaleV(&r, this, k); return r; }
    V& operator+=(const V& o) { V* d = this; V* a = this; const V* b = &o; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(a), "r"(b), "r"(d) : "memory"); return *this; }
    int IsZero() const {
        int m, f, r = 0;
        asm {
            .set noreorder
            lqc2 vf1, 0(this)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori m, zero, 0xE
            vnop
            vnop
            vnop
            vnop
            cfc2.ni f, vi17
            bne m, f, done
            nop
            ori r, zero, 1
        done:
            .set reorder
        }
        return (unsigned char)r;
    }
    void Normalize(float* out) {
        int t; V* p; float* o; o = out; p = this;
        asm {
            lqc2 vf1, 0x0(p)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vsqrt Q, vf3w
            vwaitq
            vaddq.x vf4, vf0, Q
            vdiv Q, vf0w, vf4x
            vwaitq
            vmulq.xyz vf1, vf1, Q
            sqc2 vf1, 0x0(p)
            qmfc2.ni t, vf4
            sw t, 0x0(o)
        }
    }
    float Length() const {
        float r; int t;
        asm { mtc1 $zero, r }
        asm {
            lqc2 vf1, 0x0(this)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vsqrt Q, vf3w
            vwaitq
            vaddq.x vf4, vf0, Q
            qmfc2.ni t, vf4
            mtc1 t, r
        }
        return r;
    }
} __attribute__((aligned(16)));
struct Mtx { V r0, r1, r2, t; V& T() { return t; } V& R1() { return r1; } };
static inline void XformAsm(void* p, const void* mp)
{
    asm {
        lqc2 vf8, 0x0(p)
        lqc2 vf4, 0x0(mp)
        lqc2 vf5, 0x10(mp)
        lqc2 vf6, 0x20(mp)
        lqc2 vf7, 0x30(mp)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(p)
    }
}
static inline V Xform(const Mtx& m, const V& v)
{
    V r = v;
    V* p = &r;
    XformAsm(p, &m);
    return *p;
}
static inline float Dot(const V* a, const V* b) { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $zero, 0x6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a), "r"(b) : "memory"); return r; }

struct OId { int v; OId(int i) { v = i; } };
struct Area { char pad[0x30]; V pos; V& Pos() { return pos; } };
struct RouteBits { unsigned long long b0 : 1; unsigned long long b1 : 1; unsigned long long b2 : 1; unsigned long long b3 : 1; };
struct PathBuf {
    char d[0x30];

    static void* operator new(unsigned int sz, int line);
};
struct Route {
    char pad0[0x4C];
    int f4C;
    char pad50[4];
    int f54;
    char pad58[4];
    int f5C;
    RouteBits bits60;
    char pad68[0x74 - 0x68];
    PathBuf* f74;
    int f78;
};
struct Ctl {
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsPlayer();
    virtual int IsAi();
    VPAD4(d) VPAD2(e)
    virtual V* GetVel();
    char pad4[0x1B0 - 4];
    Route* route;
};
extern "C" int g_HumanActorClassKey[];
struct Speed { char pad[0x3C]; float f3C; };
struct Act {
    VPAD32(a) VPAD16(b) VPAD8(c)
    virtual Area GetArea();
    VPAD2(d)
    virtual Mtx GetMtx();
    char pad4[0x10];
    unsigned char b14;
    char pad15[0x2C - 0x15];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x4C - 0x2F];
    int type;
    char pad50[0x58 - 0x50];
    Ctl* ctl;
    char pad5C[0x30E0 - 0x5C];
    float f30E0;
    char pad30E4[0x3584 - 0x30E4];
    Speed* f3584;
    float GetSpeed() { return f3584 ? f3584->f3C : f30E0; }
    bool Engaged() { bool r = false; if (b2D && b2C) r = true; return r; }
    bool Clear() { return !b2E; }
    bool IsMan() { int* p = g_HumanActorClassKey; int t = p[0]; return type == t; }
};
struct Bits141 { unsigned char lo : 6; unsigned char b6 : 1; unsigned char b7 : 1; };
struct Self {
    VPAD32(a) VPAD16(b) VPAD4(c)
    virtual float GetCurSpeed();
    VPAD1(d)
    virtual void Lost();
    VPAD4(e) VPAD2(f)
    virtual void Stop(int a, float x, float y);
    VPAD16(g) VPAD2(h)
    virtual float GetF(int a);
    char pad4[0x2C];
    Act* obj;
    char pad34[0x60 - 0x34];
    float f60;
    int f64;
    char pad68[0xE8 - 0x68];
    int fE8;
    int fEC;
    int fF0;
    int fF4;
    char padF8[8];
    V f100;
    char pad110[0x13C - 0x110];
    unsigned char b13C;
    char pad13D[4];
    Bits141 bits141;
    char pad142[0x1B0 - 0x142];
    Route* route;
    void SetSpeed(float f) { if (f64 < 51) { f60 = f; f64 = 50; bits141.b6 = 0; } }
};
struct Ev { char pad[0x24]; char kind; };
extern "C" {
extern int D_004EE550;
extern int D_004ED9B8;
extern int g_NpcRegionTable[];
extern char D_0049C080[];
extern char g_Game[];
extern char g_NpcRouteMgr[];
extern char g_TargetVisMgr[];
int* cMessage_Name(Ev* ev);
Act* nGobjManager_LookupGOBJ_cObjectIdR(const OId& id);
int cGOBJ_Team(Act* a);
int cAIPathData_GetGroupIndex(const V& v, int z);
void cNetNPCMsgs_SendMessage(Act* o, int a, int b, int c, int d, int e, int f);
void* cSystemContainer_GetSystem(void* a, void* b);
int cTargetManager_IsLosBlocked(void* mgr, Act* a, Act* b, int c, int d);
void cPathNavigator_ForceDestination(Route* r, const V& v, int z);
void cPathSystem_RequestPath(void* svc, Act* a, int start, int prev, int cur, int dst, int region, V* pos, long long buf);
unsigned char cPathNavigator_Request_cVectorR_int(Route* r, V* v, int z);
void cPathSystem_ClearRequests(void* svc, Act* a);
void cNPC_SetMoveMode(Self* self, int a, int b);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
PathBuf* cPath_ctor(void* p, int n);
}
inline void* PathBuf::operator new(unsigned int sz, int line)
{
    void* p;
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    p = cMemMan_Allocate(0, sz, D_0049C080, line);
    if (g_ProfileLockEnabled) EnableIntc(9);
    g_ProfileLockDepth--;
    return p;
}

extern "C" unsigned char cNPC_Follow_cMessageR(Self* self, Ev* ev)
{
    unsigned char handled = 0;
    Act* a = nGobjManager_LookupGOBJ_cObjectIdR(OId(self->fF4));
    if (a) {
        V pos = Xform(a->GetMtx(), self->f100);
        pos += a->GetMtx().T();
        int region = -1;
        bool player = false;
        Ctl* c = a->ctl;
        if (c && c->IsPlayer())
            player = true;
        if (player) {
            region = g_NpcRegionTable[cGOBJ_Team(a)];
        } else if (a->ctl && a->ctl->IsAi()) {
            Route* r = a->ctl->route;
            int n = r->f4C;
            region = r->f5C;
            if (n >= 0) {
                Route* mr = self->route;
                if (n != mr->f4C && n != mr->f54) {
                    mr->f4C = n;
                    Act* o = self->obj;
                    if (o->b14)
                        cNetNPCMsgs_SendMessage(o, 0x2D, 4, n, 0, 0, 0);
                }
            }
        } else {
            int z = self->route->f5C;
            region = cAIPathData_GetGroupIndex(a->GetArea().Pos(), z);
        }
        int t = *cMessage_Name(ev);
        if (t == D_004EE550) {
                #define K ((unsigned char)ev->kind)
            if (K == 2) {
                unsigned char stop = 0;
                float distance = 0.0f;
                V dir(pos - self->obj->GetMtx().T(), 1.0f);
                if (!dir.IsZero())
                    dir.Normalize(&distance);
                float speedTargetGobj = 0.0f;
                float spd2;
                if (a->IsMan()) {
                    speedTargetGobj = a->GetSpeed();
                    spd2 = self->obj->GetSpeed();
                } else {
                    V vel((short)0, *a->ctl->GetVel());
                    if (!vel.IsZero())
                        vel.Normalize(&speedTargetGobj);
                    spd2 = self->obj->ctl->GetVel()->Length();
                }
                unsigned char vis;
                {
                    bool chk = false;
                    if (a->Engaged() && a->Clear())
                        chk = true;
                    if (chk)
                        vis = !cTargetManager_IsLosBlocked(g_TargetVisMgr, self->obj, a, 0, 0);
                    else
                        vis = true;
                }
                if (self->fEC != 3 && (speedTargetGobj > 0.0f || !self->route->bits60.b3)) {
                    cPathNavigator_ForceDestination(self->route, pos + a->GetMtx().R1() * 10.0f, region);
                }
                if (distance <= 1.0f) {
                    self->fEC = 0;
                    self->fF0 = region;
                } else if (distance > 6.0f + self->f100.Length() && self->fEC != 3) {
                    if (!vis) {
                        self->fEC = 3;
                        void* svc = cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr);
                        self->fF0 = cAIPathData_GetGroupIndex(self->obj->GetArea().Pos(), self->fF0);
                        Route* r = self->route;
                        Act* o;
                        int n = r->f4C;
                        o = self->obj;
                        if (!r->f74)
                            { PathBuf* p = (PathBuf*)PathBuf::operator new(sizeof(PathBuf), 0x1CC); if (p) p = cPath_ctor(p, r->f78); r->f74 = p; }
                        cPathSystem_RequestPath(svc, o, n, -1, self->fF0, -1, region, &pos, (long long)(int)r->f74);
                    } else {
                        self->fEC = 2;
                    }
                } else if (speedTargetGobj > 0.0f && vis) {
                    if (Dot(&dir, &a->GetMtx().R1()) < -0.5f)
                        self->fEC = 1;
                    else
                        self->fEC = 2;
                }
                float lim = speedTargetGobj;
                if (self->fEC == 2 || self->fEC == 3)
                    lim = 2.0f * lim + self->GetF(2);
                if (self->fEC == 1) {
                    lim = 0.5f * (lim - self->GetF(1));
                    if (lim < 0.0f)
                        lim = 0.0f;
                }
                if (speedTargetGobj <= 0.00001f) {
                    if (self->fEC == 0 || self->fEC == 1) {
                        stop = true;
                    } else if ((double)distance > 6.0) {
                        if (self->GetCurSpeed() < self->GetF(2))
                            self->SetSpeed(self->GetF(3));
                    } else {
                        self->SetSpeed(self->GetF(1));
                    }
                } else if (spd2 <= 0.00001f) {
                    self->SetSpeed(self->GetF(1));
                } else {
                    float ratio = spd2 / lim;
                    if (ratio < 0.9f) {
                        self->SetSpeed(0.025f + self->GetCurSpeed());
                        if (self->GetCurSpeed() > 1.0f)
                            self->SetSpeed(1.0f);
                    }
                    if (ratio > 1.1f && (self->fEC != 2 || self->fEC != 3)) {
                        self->SetSpeed(self->GetCurSpeed() - 0.025f);
                        if (self->GetCurSpeed() < 0.0f)
                            self->SetSpeed(0.5f * self->GetF(1));
                    }
                }
                if (stop) {
                    if (self->b13C)
                        cNPC_SetMoveMode(self, 0, 20);
                } else if (!self->b13C) {
                    cNPC_SetMoveMode(self, 1, 20);
                }
                handled = 1;
            } else if (K == 3) {
                handled = cPathNavigator_Request_cVectorR_int(self->route, &pos, region);
            } else if (K == 0) {
                self->fEC = 0;
                self->fE8 = -1;
                cPathSystem_ClearRequests(cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr), self->obj);
                handled = 1;
                self->fF0 = self->route->f5C;
            } else if (K == 1) {
                if (self->f64 < 51)
                    self->f64 = 50;
                self->Stop(0, 0.0f, 0.0f);
                handled = 1;
            }
        } else {
            int t2 = *cMessage_Name(ev);
            if (t2 == D_004ED9B8) {

                if (K == 5 || K == 6) {
                    if (self->fEC == 3)
                        handled = cPathNavigator_Request_cVectorR_int(self->route, &pos, region);
                } else if (K == 1 || K == 3) {
                    self->fE8 = 30;
                }
            }
        }
    } else {
        self->Lost();
    }
    return handled;
}

