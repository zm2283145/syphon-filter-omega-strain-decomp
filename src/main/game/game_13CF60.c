/*
 * main/game: 3 files, 0013CF60-0013D080
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013CF60 */
#pragma push /* merge_units */
#include "types.h"
typedef struct N_CF60 { struct N_CF60* left; struct N_CF60* right; unsigned int parent; } N_CF60;
void std_red_black_tree_1_rotate_left(N_CF60* x, N_CF60** root)
{
    N_CF60* y = x->right;
    N_CF60* p;
    if (*root == x)
        *root = y;
    x->right = y->left;
    if (y->left)
        y->left->parent = (unsigned int)x | (y->left->parent & 1);
    y->parent = (x->parent & ~1) | (y->parent & 1);
    p = (N_CF60*)(x->parent & ~1);
    if (x == p->left)
        p->left = y;
    else
        p->right = y;
    y->left = x;
    x->parent = (unsigned int)y | (x->parent & 1);
}
#pragma pop /* merge_units */
/* merge_units: end func_0013CF60 */

/* merge_units: begin func_0013CFF0 */
#pragma push /* merge_units */
typedef struct N_CFF0 { struct N_CFF0* left; struct N_CFF0* right; unsigned int parent; } N_CFF0;
void std_red_black_tree_1_rotate_right(N_CFF0* x, N_CFF0** root)
{
    N_CFF0* y = x->left;
    N_CFF0* p;
    if (*root == x)
        *root = y;
    x->left = y->right;
    if (y->right)
        y->right->parent = (unsigned int)x | (y->right->parent & 1);
    y->parent = (x->parent & ~1) | (y->parent & 1);
    p = (N_CFF0*)(x->parent & ~1);
    if (x == p->left)
        p->left = y;
    else
        p->right = y;
    y->right = x;
    x->parent = (unsigned int)y | (x->parent & 1);
}
#pragma pop /* merge_units */
/* merge_units: end func_0013CFF0 */

/* merge_units: begin func_0013D080 */
#pragma push /* merge_units */
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
extern char g_Game[];
extern signed char g_GameState;
extern signed char g_PrevGameState;
extern StrObj D_004FFBA4;
extern signed char D_004FFBB0;
extern signed char D_004FFBB2;
extern signed char D_004FFBB4;
extern signed char D_004FFBB5;
extern int D_004FFC04;
extern char g_LevelDirName[];
extern unsigned char g_IsMultiplayer;
extern signed char D_005723C0;
extern char D_005724A0[];
extern unsigned char D_005724B0;

extern void StaticInit_RunAll(void);
extern char *strrchr(const char *, int);
extern StrObj *String_CtorCStr_13B480(StrObj *, const char *);
extern void String_AssignString(StrObj *, StrObj *);
extern void String_Dtor(void *, short);
extern char *strncpy(char *, const char *, int);
extern void printf(char *, ...);
extern void LevelSelect_FindByName(int, char *);
extern int String_ToLower(int);
extern void cScriptInterpreter_SetGenerateSyms(int);
extern void ScriptFilter_SetGate(int);
extern void *opNew_uint_int_charP_int(int, int, char *, int);
extern char *cDME_tServer_ctor(void *);
extern void cArray_tServerPtr_PushBackActual(void *, char **);
extern void cGameSystem_SetPlayerFilename(char *, char *);
extern void DME_InstallTimer(void);
extern int App_GetInstance(void);
extern void StringPool_Load(int);
extern void App_BindIopRpc(int);
extern void App_InitSystemsOnce(void);
extern void Net_RetryConnect(char *);
extern void DME_Update(void);
extern int Game_MainUpdate(int);

static inline void Game_SetState(int s)
{
    g_PrevGameState = g_GameState;
    g_GameState = s;
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
    String_AssignString(&D_004FFBA4, &tmp);
    String_Dtor(&tmp, 0);
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
                        strncpy(g_LevelDirName, val, 0x80);
                        printf(D_0049AF10, val);
                    }
                    break;
                case 'f':
                    break;
                case 'l':
                    strncpy(g_LevelDirName, val, 0x80);
                    LevelSelect_FindByName(D_004FFC04 + 0x188, val);
                    printf(D_0049AF30, val);
                    run = 0;
                    break;
                case 'r':
                    D_004FFBB5 = 0;
                    printf(D_0049AF50, arg);
                    break;
                case 's':
                    if (String_ToLower(val[0]) == 'g') {
                        cScriptInterpreter_SetGenerateSyms(1);
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
                    g_IsMultiplayer = 1;
                    run = 0;
                    named = host;
                    break;
                case 'n':
                    if (*val) {
                        D_00494170 = 1;
                        t = (char *)opNew_uint_int_charP_int(0x14, 0, D_0049AFF8, 0xB7);
                        if (t) t = cDME_tServer_ctor(t);
                        pv = t;
                        strncpy(t, val, 0x10);
                        D_005723C0 = 1;
                        cArray_tServerPtr_PushBackActual(D_005724A0, &pv);
                        Game_SetState(14);
                        strncpy(name, val, 0x10);
                        named = 1;
                    }
                    g_IsMultiplayer = 1;
                    host = 1;
                    run = 0;
                    break;
                case 'a':
                    D_00494190 = 0;
                    break;
                case 'p':
                    cGameSystem_SetPlayerFilename(g_Game, val);
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
    StringPool_Load(App_GetInstance());
    if (skip) {
        App_BindIopRpc(App_GetInstance());
    } else {
        if (g_IsMultiplayer && host) {
            App_BindIopRpc(App_GetInstance());
            App_InitSystemsOnce();
            if (named) {
                Net_RetryConnect(name);
                while (D_005724B0 == 5) DME_Update();
            }
        }
        while (Game_MainUpdate(App_GetInstance())) {
        }
    }
    /* Exit(0) is an inlined EE kernel syscall */
    asm {
        addi v1, zero, 4
        syscall 0
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013D080 */
