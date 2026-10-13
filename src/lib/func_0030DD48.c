typedef struct {
    char pad[0xC];
    int xC;
    char pad2[0x2023];
    unsigned char b2033;
} TDD48;

typedef struct {
    char pad[0x58];
    TDD48 *x58;
} SDD48;

void func_0030DD48(SDD48 *s, int x)
{
    if (s == 0) {
        return;
    }
    if (x == 0) {
        s->x58->xC = 8;
        return;
    }
    if (s->x58->b2033 == 0) {
        s->x58->b2033 = 1;
        s->x58->xC = 3;
        return;
    }
    s->x58->xC = 8;
}
