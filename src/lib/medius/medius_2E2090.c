typedef struct { unsigned char state; char name[0x11]; unsigned short port; int x14[2]; int x1C[2]; } E2E2090;
extern E2E2090 D_00520358[];
extern unsigned char D_0048C4A4;
extern int strlen(const char *);
extern char *strncpy(char *, const char *, int);
extern void *memset(void *, int, int);
extern int func_002E5BA8(void);
extern int func_002E5008(int, int);
extern int func_002FC5F8(void *);
extern int func_002FB968(void *);
extern int func_002E5AA8(char *, unsigned int *, unsigned short *);
extern int func_002FBF08(unsigned char *, char *, unsigned short);
extern void func_003060D8(int *);
extern void func_002E5770(char *, unsigned short);

int func_002E2090(char *name, int arg)
{
    unsigned short cnt;
    unsigned char res;
    void *cb;
    unsigned int idx;
    int ret;

    if (name == 0 || strlen(name) == 0)
        return func_002E5BA8();
    ret = 0x17;
    if (strlen(name) != 0 && arg != 0) {
        if (D_0048C4A4 != 1) {
            ret = func_002E5008(func_002FC5F8(&cb), 0x18);
            if (ret != 0) return ret;
            cb = (void *)func_002E5770;
            ret = func_002E5008(func_002FB968(&cb), 0x18);
            if (ret != 0) return ret;
            memset(D_00520358, 0, 0x2400);
            D_0048C4A4 = 1;
        }
        ret = func_002E5AA8(name, &idx, &cnt);
        if (ret != 0) return ret;
        D_00520358[idx].state = 1;
        D_00520358[idx].port = cnt;
        D_00520358[idx].x1C[1] = arg;
        strncpy(D_00520358[idx].name, name, 0x10);
        ret = func_002E5008(func_002FBF08(&res, D_00520358[idx].name, D_00520358[idx].port), 0x18);
        if (ret != 0) return ret;
        if (res == 1) {
            D_00520358[idx].state = 2;
            func_003060D8(D_00520358[idx].x14);
        }
        return 0;
    }
    return ret;
}


