typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;

typedef struct { u8 pad[0x40D]; u8 n; } Grip_38B530;
typedef struct { s8 a[0x18]; s8 b[0x18]; } GripTab_38B530;

typedef struct {
    u8 pad0[0x23D0];
    float w0;
    float w0b;
    int pad23D8;
    int k0;
    float w1;
    float w1b;
    int pad23E8;
    int k1;
    float vals[8];
    Grip_38B530* g0;
    Grip_38B530* g1;
    u8 pad2418[0x2BC1 - 0x2418];
    u8 count;
    u8 ids[8];
    u8 pad2BCA[0x2C0C - 0x2BCA];
    u8 type;
    u8 pad2C0D[0x2D90 - 0x2C0D];
    u8 s0;
    u8 s1;
    u8 s2;
    u8 pad2D93;
    s16 timer;
    s16 pad2D96;
    u16 limit;
} Equip_38B530;

extern GripTab_38B530 D_00571510[];
extern u8 D_0053B340[];
extern u8 D_0053B348[];
extern char D_00493360[], D_00493380[], D_004933A0[];
extern float KeyTrack_Sample(int frame, char* track);
extern int Random_Next(void);

void Equip_UpdateGrip(Equip_38B530* e)
{
    u8 s;
    int i;
    float f;
    s = e->s0;
    if (s && e->g0) {
        if (s == 1) {
            i = e->g0->n + 1;
            e->w0b = 0.0f;
            if (i >= 0) {
                e->k0 = D_00571510[e->type].a[i];
                e->w0 = 1.0f;
            } else {
                e->w0 = 0.0f;
            }
        }
        f = KeyTrack_Sample(e->s0, D_00493360);
        e->w0 = f;
        e->w0b = 1.0f - f;
    }
    s = e->s1;
    if (s && e->g1) {
        if (s == 1) {
            i = e->g1->n + 1;
            e->w1b = 0.0f;
            if (i >= 0) {
                e->k1 = D_00571510[e->type].b[i];
                e->w1 = 1.0f;
            } else {
                e->w1 = 0.0f;
            }
        }
        f = KeyTrack_Sample(e->s1, D_00493360);
        e->w1 = f;
        e->w1b = 1.0f - f;
    }
    s = e->s2;
    if (s) {
        if (s == 1) {
            e->timer = 300;
            e->limit = 3000;
        }
        if (e->count < 8) {
            e->ids[e->count] = D_0053B340[e->type];
            e->vals[e->count] = KeyTrack_Sample(e->s2, D_00493380);
            if (!e->vals[e->count]) {
            } else {
                e->count++;
            }
        }
        e->s2++;
        if (e->s2 > 72) {
            e->s2 = 0;
        }
    } else if (e->timer >= 0) {
        if (e->timer >= e->limit) {
            e->timer = 0;
            e->limit = (Random_Next() & 0x3FF) + 300;
        }
        if (e->count < 8) {
            e->ids[e->count] = D_0053B348[e->type];
            e->vals[e->count] = KeyTrack_Sample(e->timer, D_004933A0);
            if (!e->vals[e->count]) {
            } else {
                e->count++;
            }
        }
        e->timer++;
    }
}
