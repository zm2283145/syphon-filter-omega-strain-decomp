#pragma push
#pragma cplusplus on

typedef struct { char c[0x30]; } __attribute__((aligned(16))) Name_S7;
typedef struct { float v[4]; } __attribute__((aligned(16))) Q_S7;
typedef struct { char pad[0xEF]; unsigned char bEF; } Sub3524_S7;
typedef struct { char pad[0x415]; unsigned char b415; } Ob2_S7;
typedef struct {
    char pad0[0x14]; unsigned char b14; char pad15[0x3210 - 0x15]; int f3210; char pad3214[0x324C - 0x3214]; int f324C; char pad3250[0x3314 - 0x3250];
    Ob2_S7* s3314; char pad3318[0x33CC - 0x3318];
    int f33CC; Q_S7 q33D0; float f33E0; unsigned char b33E4; char pad33E5[0x3524 - 0x33E5];
    Sub3524_S7* f3524;
} SA_S7;

#define MSG_HDR_S7 \
    void* vtable; int f04; int f08; int f0C; int f10; int f14; int f18; int f1C; signed char f20; char pad21[3]
typedef struct { MSG_HDR_S7; int f24; unsigned char f28; char pad29[3]; int f2C; unsigned char f30; char pad31[3]; float f34; char pad38[8]; } AEv_S7;
typedef struct { MSG_HDR_S7; int id; char pad28[8]; Q_S7 pos; float f40; } MsgT_S7;

extern "C" {
extern char D_00542B60[]; extern char D_004DA930[];
extern char D_004EEED0[]; extern char D_004DA8D0[]; extern char D_004DCF10[];
extern char D_0049E000[]; extern char D_00504068[]; extern char D_004DCDC0[]; extern unsigned char D_005721C8;
void Event_Construct(void* m, void* t);
void Event_Send(void* m, void* t, int f);
void cMessage_dtor(void* m, int f);
unsigned char Secondary_RequestOneShot(Ob2_S7* o, Name_S7* n, unsigned char kind, AEv_S7* p);
}

#define NAME_COPY_S7(dst, src) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i = 0; \
        char ckc_c; \
        char* ckc_s = (src); \
        for (; ckc_i < 0x2F; ckc_i++) { \
            if (ckc_s[ckc_i] == 0) ckc_end = 1; \
            ckc_c = 0; if (ckc_end) asm { .set reorder } else ckc_c = ckc_s[ckc_i]; (dst)[ckc_i] = ckc_c; \
        } \
        (dst)[ckc_i] = 0; \
    }

static inline void QCp_S7(Q_S7* d, const Q_S7* s) { __int128 q; asm volatile { lq q, 0(s)
 sq q, 0(d) } }

extern "C" void Actor_StartGrenadeThrow(SA_S7* a, int* id, Q_S7* pos, float f)
{
    if ((a->f3210 >> 24) & 1) {
        if (a->b14) return;
        if ((a->f324C >> 9) & 1) return;
    }
    if (a->s3314) {
        MsgT_S7 m;
        Name_S7 n;
        AEv_S7 e;
        unsigned char ok;
        AEv_S7* pe = &e;
        Event_Construct(pe, D_00542B60);
        pe->vtable = D_004DA930;
        pe->f24 = 2;
        pe->f28 = 0;
        pe->f2C = (int)a;
        pe->f30 = 0;
        pe->f34 = 0.0f;
        NAME_COPY_S7(n.c, D_0049E000)
        ok = Secondary_RequestOneShot(a->s3314, &n, 3, &e);
        e.vtable = D_004DA930;
        cMessage_dtor(&e, 0);
        if (ok) {
            a->f33CC = *id;
            QCp_S7(&a->q33D0, pos);
            a->f33E0 = f;
            a->b33E4 = 1;
            { Sub3524_S7* sp = a->f3524; sp->bEF = 1; }
            if (D_005721C8 && a->b14) {
                MsgT_S7* pm = &m;
                Event_Construct(pm, D_00504068);
                pm->vtable = D_004DCF10;
                pm->vtable = D_004DCDC0;
                pm->id = -1;
                pm->id = *id;
                QCp_S7(&pm->pos, pos);
                pm->f40 = f;
                m.f20 = 4;
                Event_Send(&m, a, 0);
                m.vtable = D_004DCF10;
                cMessage_dtor(pm, 0);
            }
        }
    }
}

#pragma pop



