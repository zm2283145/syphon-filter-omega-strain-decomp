#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(8)

/*
 * cNIEventOBJ::ProcessNextFrame (NIEvent.cc), transcribed from the prototype
 * (ProcessNextFrame__11cNIEventOBJFf) + retail-only cHuman::BulletBlood call.
 * DRAFT: the prototype's line-segment/box test is a hand-written VU0 asm
 * routine with internal branches (prototype 0x2469dc..0x246f88); here it is a
 * plain C stand-in, so the middle of the function does not match.
 */

struct V {
    float x, y, z, w;
    V() {}
    V& operator=(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
    V(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
} __attribute__((aligned(16)));

struct M { float m[4][4]; } __attribute__((aligned(16)));

struct cLineSegment {
    V endPoints[2];
    cLineSegment() {}
};

struct cBox { V min; V max; };

struct XNode {
    VPAD16(a) VPAD4(b) virtual void Update();
    char pad04[0xC];
    M mat;                  /* +0x10 */
    unsigned char dirty;    /* +0x50 */
};

struct cHuman {
    VPAD16(a) VPAD16(b) virtual cBox* GetBox();   /* +0x88 */
    char pad04[0x4C];
    XNode* xform;           /* +0x50 */
};

struct cCtrl {
    VPAD16(a) VPAD2(b) VPAD1(e) virtual int IsActive();      /* +0x54 */
    VPAD8(c) VPAD4(d) virtual unsigned char State(); /* +0x88 */
    char pad04[0x2C];
    cHuman* human;          /* +0x30 */
};

struct cPlayerObj {
    char pad00[0x58];
    cCtrl* ctrl;            /* +0x58 */
};

struct cEvBase {
    VPAD32(a) VPAD32(b) VPAD2(c) virtual void Step(float t);  /* +0x110 */
    char pad04[0x48];
    void* kind;             /* +0x4C */
};

struct cEvVec { int pad; int count; cEvBase** data; };

struct cObjX {
    VPAD16(a) virtual void Activate();  /* +0x48 */
};

struct cNIEventOBJ {
    VPAD32(a) VPAD32(b) VPAD8(c) VPAD2(d) VPAD1(e) virtual void Advance(float t);  /* +0x134 */
    char pad04[0x28];
    unsigned char mEnabled;       /* +0x2C */
    unsigned char mActiveFlag;    /* +0x2D */
    unsigned char mStreamingFlag; /* +0x2E */
    char pad2F[0x31];
    int type;                     /* +0x60 */
    char pad64[0x38];
    cEvVec events;                /* +0x9C */
    char padA8[0x34];
    unsigned char bDC;            /* +0xDC */
    char padDD[0x53];
    unsigned char playing;        /* +0x130 */
    char pad131[3];
    float speed;                  /* +0x134 */
    char pad138[8];
    cObjX* mObject;               /* +0x140 */
};

struct Msg {
    void* vtable;
    void* type;
    char pad08[0x18];
    unsigned char kind;           /* +0x20 */
    char pad21[3];
    void* who;                    /* +0x24 */
};

struct HitInfo { char pad[0x4C]; float range; };

extern "C" {
extern char D_004F7C30[];
extern char D_004DBEB0[];
extern char D_00506210[];
extern char D_004DCF10[];
extern char D_004DCF30[];
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern void* D_004F7C60;
extern void* D_004F7C98;
extern float D_0048AE20;
void cMessage_ctor_cMessageNameR(void* m, void* name);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* to, int f);
void cMessage_dtor(void* m, int f);
void cGOBJ_NextFrame(void* g, float t);
int cNIEventOBJ_GetBeamExtents(cNIEventOBJ* self, V* a, V* b);
cPlayerObj* cNetObj_GetPlayer(int i);
void cMatrix_Copy_InvertRotTrans(M* out, M* in);
int cHuman_BulletBlood(cHuman* h, V* pos, V* dir, int a, HitInfo* hit);
cEvBase** std_vector_cNIEventBasePtr_opIndex(cEvVec* v, int i);
}

static inline bool Enabled(cNIEventOBJ* o) { bool a = false; if (o->mActiveFlag && o->mEnabled) a = true; return a; }
static inline bool Streaming(cNIEventOBJ* o) { bool b = o->mStreamingFlag; return b; }
static inline bool NotStreaming(cNIEventOBJ* o) { return Streaming(o) ^ 1; }
static inline bool IsActive(cNIEventOBJ* o) { bool r = false; if (Enabled(o) && NotStreaming(o)) r = true; return r; }

struct cDoneMsg : Msg {
    cDoneMsg(void* w) { Msg* m = this; cMessage_ctor_cMessageNameR(m, D_004F7C30); m->vtable = D_004DBEB0; m->who = w; }
    void Done() { vtable = D_004DBEB0; cMessage_dtor(this, 0); }
};
struct cHitMsg : Msg {
    cHitMsg(void* w) { Msg* m = this; cMessage_ctor_cMessageNameR(m, D_00506210); m->vtable = D_004DCF10; m->vtable = D_004DCF30; m->who = w; }
    void Done() { vtable = D_004DCF10; cMessage_dtor(this, 0); }
};
static inline void Queue(const Msg& m, void* to) { QueueMessage_cMessageR_cSystemP_int((void*)&m, to, 0); }
static inline unsigned char HitKind() { unsigned char x; if (g_IsMultiplayer) x = D_005721C0; else x = 1; return x ? 1 : 2; }

static inline void Apply(V* o, M* m, V* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
static inline void SubV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline V Sub(const V& a, const V& b) { V r; SubV(&r, &a, &b); return r; }

static inline bool Intersects(const cLineSegment& l, const cBox& box)
{
    unsigned int d;
    unsigned int e;
    unsigned int f;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    int hit;
    bool res;
    unsigned int c0;
    unsigned int c1;
    unsigned int t;
    int done;
    unsigned int diff;
    unsigned int sign;
    __asm__ volatile(".set noreorder; daddu %1, $0, $0; daddu %2, $0, $0; lqc2 $vf3, 0x0(%3); lqc2 $vf4, 0x0(%4); lqc2 $vf1, 0x0(%5); addi %0, $0, 0x1; .set reorder" : "=r"(done), "=r"(c0), "=r"(c1) : "r"(&l.endPoints[0]), "r"(&l.endPoints[1]), "r"(&box.min));
    __asm__ volatile(".set noreorder; vsub.xyz $vf6, $vf3, $vf1; vnop; vnop; vnop; vnop; vnop; cfc2.ni %0, $vi17; andi %0, %0, 0xE0; vsub.xyz $vf8, $vf4, $vf1; vnop; vnop; vnop; vnop; vnop; cfc2.ni %1, $vi17; andi %1, %1, 0xE0; and %2, %0, %1; bnel %2, $0, 1f; addi %3, $0, 0x0; lqc2 $vf2, 0x0(%5); vsub.xyz $vf7, $vf2, $vf3; vnop; vnop; vnop; vnop; vnop; cfc2.ni %2, $vi17; srl %0, %0, 4; andi %2, %2, 0xE0; or %0, %0, %2; vsub.xyz $vf9, $vf2, $vf4; vnop; vnop; vnop; vnop; vnop; cfc2.ni %2, $vi17; srl %1, %1, 4; andi %2, %2, 0xE0; addi %3, $0, 0x0; or %1, %1, %2; and %2, %0, %1; bnel %2, $0, 1f; nop; or %2, %0, %1; beql %2, $0, 1f; addi %3, $0, 0x1; addi %4, $0, 0x0; 1: andi %4, %4, 0xFF; .set reorder" : "=r"(c0), "=r"(c1), "=r"(t), "=r"(res), "=r"(done) : "r"(&box.max), "4"(done), "0"(c0), "1"(c1));
    if (done) return res;
    diff = c0 ^ c1;
    __asm__ volatile(".set noreorder; vsub.xyzw $vf5, $vf4, $vf3; vnop; vnop; vnop; vnop; vnop; cfc2.ni %0, $vi17; vsub.xyz $vf6, $vf0, $vf6; .set reorder" : "=r"(sign));
    if (!(done = sign & 8) && (done = diff & 0x88)) {
        __asm__ volatile("vdiv $Q, $vf0w, $vf5x; vmulx.xyzw $vf8, $vf5, $vf6x; vmulx.xyzw $vf9, $vf5, $vf7x");
        if (done = diff & 8) {
        __asm__ volatile(".set noreorder; vmulaw.xyzw $ACC, $vf3, $vf0w; vwaitq; vmaddq.xyzw $vf8, $vf8, $Q; qmfc2.ni %0, $vf1; qmfc2.ni %1, $vf2; addi %3, $0, 0x0; qmfc2.ni %2, $vf8; prot3w %0, %0; prot3w %2, %2; prot3w %1, %1; mtc1 %2, $f0; mtc1 %0, $f1; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; prot3w %0, %0; prot3w %2, %2; mtc1 %0, $f1; prot3w %1, %1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; addi %3, $0, 0x1; nop; 1: andi %3, %3, 0xFF; .set reorder" : "=r"(c0), "=r"(c1), "=r"(t), "=r"(done));
        if (done) return true;
        }
        if (done = diff & 0x80) {
        __asm__ volatile(".set noreorder; vmulaw.xyzw $ACC, $vf3, $vf0w; vwaitq; vmaddq.xyzw $vf9, $vf9, $Q; qmfc2.ni %0, $vf1; qmfc2.ni %1, $vf2; addi %3, $0, 0x0; qmfc2.ni %2, $vf9; prot3w %0, %0; prot3w %2, %2; prot3w %1, %1; mtc1 %2, $f0; mtc1 %0, $f1; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; prot3w %0, %0; prot3w %2, %2; mtc1 %0, $f1; prot3w %1, %1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; addi %3, $0, 0x1; nop; 1: andi %3, %3, 0xFF; .set reorder" : "=r"(c0), "=r"(c1), "=r"(t), "=r"(done));
        if (done) return true;
        }
    }
    if (!(done = sign & 4) && (done = diff & 0x44)) {
        __asm__ volatile("vdiv $Q, $vf0w, $vf5y; vmuly.xyzw $vf8, $vf5, $vf6y; vmuly.xyzw $vf9, $vf5, $vf7y");
        if (done = diff & 4) {
        __asm__ volatile(".set noreorder; vmulaw.xyzw $ACC, $vf3, $vf0w; vwaitq; vmaddq.xyzw $vf8, $vf8, $Q; qmfc2.ni %0, $vf1; qmfc2.ni %1, $vf2; addi %3, $0, 0x0; qmfc2.ni %2, $vf8; prot3w %0, %0; prot3w %2, %2; prot3w %1, %1; prot3w %0, %0; prot3w %2, %2; prot3w %1, %1; mtc1 %2, $f0; mtc1 %0, $f1; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; prot3w %0, %0; prot3w %2, %2; mtc1 %0, $f1; prot3w %1, %1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; addi %3, $0, 0x1; nop; 1: andi %3, %3, 0xFF; .set reorder" : "=r"(c0), "=r"(c1), "=r"(t), "=r"(done));
        if (done) return true;
        }
        if (done = diff & 0x40) {
        __asm__ volatile(".set noreorder; vmulaw.xyzw $ACC, $vf3, $vf0w; vwaitq; vmaddq.xyzw $vf9, $vf9, $Q; qmfc2.ni %0, $vf1; qmfc2.ni %1, $vf2; addi %3, $0, 0x0; qmfc2.ni %2, $vf9; prot3w %0, %0; prot3w %2, %2; prot3w %1, %1; prot3w %0, %0; prot3w %2, %2; prot3w %1, %1; mtc1 %2, $f0; mtc1 %0, $f1; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; prot3w %0, %0; prot3w %2, %2; mtc1 %0, $f1; prot3w %1, %1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; addi %3, $0, 0x1;  1: andi %3, %3, 0xFF; .set reorder" : "=r"(c0), "=r"(c1), "=r"(t), "=r"(done));
        if (done) return true;
        }
    }
    if (!(sign & 2) && (diff & 0x22)) {
        __asm__ volatile("vdiv $Q, $vf0w, $vf5z; vmulz.xyzw $vf8, $vf5, $vf6z; vmulz.xyzw $vf9, $vf5, $vf7z");
        if (diff & 2) {
        __asm__ volatile(".set noreorder; vmulaw.xyzw $ACC, $vf3, $vf0w; vwaitq; vmaddq.xyzw $vf8, $vf8, $Q; qmfc2.ni %0, $vf1; qmfc2.ni %1, $vf2; addi %3, $0, 0x0; qmfc2.ni %2, $vf8; mtc1 %0, $f1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; prot3w %0, %0; prot3w %2, %2; mtc1 %0, $f1; prot3w %1, %1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; addi %3, $0, 0x1; nop; 1: andi %3, %3, 0xFF; .set reorder" : "=r"(a), "=r"(b), "=r"(c), "=r"(hit));
        if (hit) return true;
        }
        if (diff & 0x20) {
        __asm__ volatile(".set noreorder; vmulaw.xyzw $ACC, $vf3, $vf0w; vwaitq; vmaddq.xyzw $vf9, $vf9, $Q; qmfc2.ni %0, $vf1; qmfc2.ni %1, $vf2; addi %3, $0, 0x0; qmfc2.ni %2, $vf9; mtc1 %0, $f1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; prot3w %0, %0; prot3w %2, %2; mtc1 %0, $f1; prot3w %1, %1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; addi %3, $0, 0x1;  1: andi %3, %3, 0xFF; .set reorder" : "=r"(d), "=r"(e), "=r"(f), "=r"(hit));
        if (hit) return true;
        }
    }
    return false;
}
static inline void Play(cNIEventOBJ* self, float timeStep)
{
    unsigned char was = self->playing;
    float a = timeStep * self->speed;
    self->Advance(was ? a : 0.0f);
    if (was && !self->playing) {
        cDoneMsg msg(0);
        Queue(msg, self);
        msg.Done();
    }
}

extern "C" void cNIEventOBJ_ProcessNextFrame(cNIEventOBJ* self, float timeStep)
{
    if (self->bDC && self->mObject)
        self->mObject->Activate();

    if (self->playing || (self->type == 3 && self->bDC && IsActive(self))) {
        Play(self, timeStep);
    }

    cGOBJ_NextFrame(self, timeStep);

    if (IsActive(self) && self->type == 6) {
        V point1;
        V point2;
        if (cNIEventOBJ_GetBeamExtents(self, &point1, &point2)) {
            cLineSegment line;
            line.endPoints[0] = point1;
            line.endPoints[1] = point2;
            for (int i = 0; i < 4; i++) {
                cPlayerObj* player = cNetObj_GetPlayer(i);
                if (!player || !player->ctrl || !player->ctrl->IsActive() || player->ctrl->State() == 4)
                    continue;
                cHuman* human = player->ctrl->human;
                XNode* n = human->xform;
                if (n->dirty) n->Update();
                M invmat;
                cMatrix_Copy_InvertRotTrans(&invmat, &n->mat);
                cBox* box = human->GetBox();
                cLineSegment invLine;
                invLine.endPoints[0] = line.endPoints[0];
                invLine.endPoints[1] = line.endPoints[1];
                Apply(&invLine.endPoints[0], &invmat, &invLine.endPoints[0]);
                Apply(&invLine.endPoints[1], &invmat, &invLine.endPoints[1]);
                if (Intersects(invLine, *box)) {
                    V dir = Sub(point2, point1);
                    HitInfo hit;
                    hit.range = D_0048AE20;
                    if (cHuman_BulletBlood(human, &point1, &dir, 0, &hit)) {
                        cHitMsg msg(human); msg.kind = HitKind(); Queue(msg, self); msg.Done();

                    }
                }
            }
        }
    }

    for (int i = 0; i < self->events.count; i++) {
        void* g; void* h;
        if ((*std_vector_cNIEventBasePtr_opIndex(&self->events, i))->kind == (h = D_004F7C60))
            self->events.data[i]->Step(timeStep);
        else if ((*std_vector_cNIEventBasePtr_opIndex(&self->events, i))->kind == (g = D_004F7C98))
            self->events.data[i]->Step(timeStep);
    }
}
