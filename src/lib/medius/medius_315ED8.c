typedef struct { unsigned int x; unsigned int y; char data[0x1F8]; } G4Ent;
typedef struct { int a; unsigned int b; int c; G4Ent e[64]; } G4Tbl;
extern void *memcpy(void *, const void *, unsigned int);
void AddVSequence(G4Tbl *t, unsigned int seq, void *data, unsigned int len)
{
    unsigned int i = seq & 0x3F;
    unsigned int s = seq & 0x1FFFFFFF;
    G4Ent *e;
    if (t == 0) return;
    e = &t->e[i];
    if (e->y != 0) {
        i = (e->x & 0x3F);
        i = (i - s) & 0x1FFFFFFF;
        if (i - 1 <= 0xFFFFFFD) return;
        e->y = 0;
        t->c--;
    }
    if (seq & 0x40000000) {
        i = t->b & 0x1FFFFFFF;
        i = (s - i) & 0x40;
        if (i) t->b = seq;
    }
    e->x = seq;
    if (len == 0) return;
    if (len > 0x1F8) return;
    memcpy(e->data, data, len);
    e->y = len;
    t->c++;
}







