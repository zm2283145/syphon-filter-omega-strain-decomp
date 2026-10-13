typedef struct E2E5BA8 {
    unsigned char state;
    char name[0x11];
    unsigned short port;
    int x14[2];
    int x1C;
    void (*cb)(int, char *, int);
} E2E5BA8;
extern E2E5BA8 D_00520358[];
extern unsigned char D_0048C4A4;
extern int func_002FB8F0(void);
extern int func_002E5008(int, int);
extern void *memset(void *, int, unsigned int);

int func_002E5BA8(void)
{
    unsigned int i;
    int r;

    for (i = 0; i < 0x100; i++) {
        if (D_00520358[i].state == 1 || D_00520358[i].state == 2)
            D_00520358[i].state = 4;
        if (D_00520358[i].state == 4) {
            if (D_00520358[i].cb != 0) {
                D_00520358[i].cb(0xE, D_00520358[i].name, 0);
                D_00520358[i].cb = 0;
            }
            D_00520358[i].state = 0;
        }
    }
    if (D_0048C4A4 == 1) {
        r = func_002E5008(func_002FB8F0(), 0x18);
        if (r != 0)
            return r;
        D_0048C4A4 = 0;
    }
    memset(D_00520358, 0, 0x2400);
    return 0;
}
