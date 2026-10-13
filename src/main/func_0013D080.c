typedef struct StrObj {
    int a, b, c;
} StrObj;

extern signed char D_00494170;
extern signed char D_00494190;
extern char D_0049AF10[];
extern char D_0049AF30[];
extern char D_0049AF50[];
extern char D_0049AF70[];
extern char D_0049AF90[];
extern char D_0049AFF8[];
extern char D_004FFB50[];
extern signed char D_004FFBA0;
extern signed char D_004FFBA1;
extern StrObj D_004FFBA4;
extern signed char D_004FFBB0;
extern signed char D_004FFBB2;
extern signed char D_004FFBB4;
extern signed char D_004FFBB5;
extern int D_004FFC04;
extern char D_004FFC90[];
extern unsigned char D_005721C8;
extern signed char D_005723C0;
extern char D_005724A0[];
extern unsigned char D_005724B0;

extern void StaticInit_RunAll(void);
extern char *strrchr(const char *, int);
extern StrObj *String_CtorCStr_13B480(StrObj *, const char *);
extern void func_0013D680(StrObj *, StrObj *);
extern void func_00138B70(void *, short);
extern char *strncpy(char *, const char *, int);
extern void printf(char *, ...);
extern void func_002CC8E0(int, char *);
extern int String_ToLower(int);
extern void func_003E2D80(int);
extern void ScriptFilter_SetGate(int);
extern void *func_0013D5C0(int, int, char *, int);
extern char *func_0013D5B0(void *);
extern void func_0013D590(void *, char **);
extern void func_0012F3D0(char *, char *);
extern void DME_InstallTimer(void);
extern int func_001698C0(void);
extern void StringPool_Load(int);
extern void func_001694B0(int);
extern void func_00165BC0(void);
extern void Net_RetryConnect(char *);
extern void DME_Update(void);
extern int Game_MainUpdate(int);

static inline void Game_SetState(int s)
{
    D_004FFBA1 = D_004FFBA0;
    D_004FFBA0 = s;
}

int Game_ParseCommandLine(int argc, char **argv)
{
    char *pv;
    StrObj tmp;
    volatile int magic[4]; /* dead store; an array lands it on retail's 16-byte-aligned stack slot */
    char name[16];
    unsigned char run;
    unsigned char named;
    unsigned char host;
    unsigned char skip;
    char *base;
    char *t;
    int i;

    StaticInit_RunAll();
    magic[0] = 0xE4A;
    run = 1;
    named = 0;
    host = 0;
    skip = 0;
    base = strrchr(argv[0], '\\');
    if (base == 0) base = strrchr(argv[0], '/');
    if (base == 0) base = argv[0];
    else base = base + 1;
    String_CtorCStr_13B480(&tmp, base);
    func_0013D680(&D_004FFBA4, &tmp);
    func_00138B70(&tmp, 0);
    Game_SetState(9);
    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            char *arg = argv[i];
            if (arg[0] == '-') {
                char *val = arg + 2;
                switch (arg[1]) {
                case 'g':
                    D_004FFBB4 = 1;
                    if (*val) {
                        strncpy(D_004FFC90, val, 0x80);
                        printf(D_0049AF10, val);
                    }
                    break;
                case 'f':
                    break;
                case 'l':
                    strncpy(D_004FFC90, val, 0x80);
                    func_002CC8E0(D_004FFC04 + 0x188, val);
                    printf(D_0049AF30, val);
                    run = 0;
                    break;
                case 'r':
                    D_004FFBB5 = 0;
                    printf(D_0049AF50, arg);
                    break;
                case 's':
                    if (String_ToLower(val[0]) == 'g') {
                        func_003E2D80(1);
                        skip = 1;
                    } else if (String_ToLower(val[0]) == 'o') {
                        ScriptFilter_SetGate(String_ToLower(val[1]) == 'n');
                    }
                    run = 0;
                    break;
                case 'h':
                    D_00494170 = 0;
                    Game_SetState(14);
                    host = 1;
                    D_005721C8 = 1;
                    run = 0;
                    named = host;
                    break;
                case 'n':
                    if (*val) {
                        D_00494170 = 1;
                        t = (char *)func_0013D5C0(0x14, 0, D_0049AFF8, 0xB7);
                        if (t) t = func_0013D5B0(t);
                        pv = t;
                        strncpy(t, val, 0x10);
                        D_005723C0 = 1;
                        func_0013D590(D_005724A0, &pv);
                        Game_SetState(14);
                        strncpy(name, val, 0x10);
                        named = 1;
                    }
                    D_005721C8 = 1;
                    host = 1;
                    run = 0;
                    break;
                case 'a':
                    D_00494190 = 0;
                    break;
                case 'p':
                    func_0012F3D0(D_004FFB50, val);
                    break;
                case 'x':
                    Game_SetState(1);
                    run = 1;
                    D_004FFBB0 = 1;
                    break;
                default:
                    printf(D_0049AF70, arg);
                    break;
                }
            } else {
                printf(D_0049AF90, arg);
            }
        }
    }
    DME_InstallTimer();
    if (run) D_004FFBB2 = 1;
    StringPool_Load(func_001698C0());
    if (skip) {
        func_001694B0(func_001698C0());
    } else {
        if (D_005721C8 && host) {
            func_001694B0(func_001698C0());
            func_00165BC0();
            if (named) {
                Net_RetryConnect(name);
                while (D_005724B0 == 5) DME_Update();
            }
        }
        while (Game_MainUpdate(func_001698C0())) {
        }
    }
    /* Exit(0) is an inlined EE kernel syscall */
    asm {
        addi v1, zero, 4
        syscall 0
    }
    return 0;
}
