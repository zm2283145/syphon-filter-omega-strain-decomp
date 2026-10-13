typedef struct { unsigned char a; unsigned char n; } HgPair;
typedef struct { char pad0[2]; HgPair p[1]; } HgDef;
typedef struct {
    char pad0[7];
    unsigned char count;
    HgDef* def;
    char padC[4];
} HgEnt;
typedef struct {
    char pad0[0x1EC0];
    HgEnt ents[32];
    char pad20C0[0x2340 - 0x20C0];
    unsigned char* items[32];
    unsigned short count;
    char pad23c2[0x2C08 - 0x23C2];
    unsigned int age;
} HitGore;

void HitGore_Age(HitGore* self)
{
    unsigned int i;
    unsigned int cnt;
    HgPair* pr;
    unsigned char* p;
    unsigned int k;
    unsigned char* q;
    unsigned int n;
    unsigned int b;
    unsigned char* buf;
    if (self->age) {
        for (i = 0; i < self->count; i++) {
            p = self->items[i];
            buf = p;
            if (buf) {
                cnt = self->ents[i].count;
                pr = (HgPair*)self->ents[i].def; pr++;
                for (k = 0; k < cnt; k++) {
                    n = pr->n;
                    q = buf;
                    buf += 0x20;
                    pr++;
                    for (b = 0; b < n; b++, q++) {
                        unsigned int v = *q;
                        if (v) {
                            v += self->age;
                            if (v > 0x5A) v = 0x5A;
                            *q = v;
                        }
                    }
                }
            }
        }
        self->age = 1;
    }
}

