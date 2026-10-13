typedef struct E2E5860 {
    unsigned char state;
    char name[0x11];
    unsigned short port;
    int x14[2];
    int x1C;
    void (*cb)(int, char *, int);
} E2E5860;
extern E2E5860 D_00520358[];
extern unsigned char D_0048C4A4;
extern int func_002FBC40(void);
extern int func_002E5008(int, int);
extern int func_002FBF08(unsigned char *, char *, unsigned short);
extern void func_003060D8(int *);
extern int func_003060F0(int *, unsigned int *);

int func_002E5860(unsigned char mode)
{
    unsigned char res;
    unsigned int t;
    unsigned int i;
    int r;

    if (D_0048C4A4 != 1)
        return 0;
    r = func_002E5008(func_002FBC40(), 0x18);
    if (r != 0)
        return r;
    for (i = 0; i < 0x100; i++) {
        switch (D_00520358[i].state) {
        case 0:
            break;
        case 1:
            res = 0;
            if (func_002FBF08(&res, D_00520358[i].name, D_00520358[i].port) != 0)
                break;
            if (res != 1)
                break;
            func_003060D8(D_00520358[i].x14);
            D_00520358[i].state = 2;
            break;
        case 2:
            func_003060F0(D_00520358[i].x14, &t);
            if (t <= 10000)
                break;
            D_00520358[i].state = 4;
            if (mode != 1)
                break;
            if (D_00520358[i].cb != 0) {
                D_00520358[i].cb(0xE, D_00520358[i].name, 0);
                D_00520358[i].cb = 0;
            }
            D_00520358[i].state = 0;
            break;
        case 4:
            if (mode != 1)
                break;
            if (D_00520358[i].cb != 0) {
                D_00520358[i].cb(0xE, D_00520358[i].name, 0);
                D_00520358[i].cb = 0;
            }
            D_00520358[i].state = 0;
            break;
        case 3:
            if (mode != 1)
                break;
            if (D_00520358[i].cb != 0) {
                D_00520358[i].cb(0, D_00520358[i].name, D_00520358[i].x1C);
                D_00520358[i].cb = 0;
            }
            D_00520358[i].state = 0;
            break;
        default:
            D_00520358[i].state = 0;
            break;
        }
    }
    return 0;
}

