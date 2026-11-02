/*
 * SFOGame/Source/main: 7 files, 0013C570-0013CF60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013C570 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "tree_insert_obj.h"
struct Val_1C4F20 { int a, b, c; int d; };
extern "C" {
void std_basic_string_char_char_traits_char_ctor_basicstringR(void* d, const void* s);
#if 0 /* merge_units */
void std_red_black_tree_1_balance_insert(void* node, void* root);
#endif /* merge_units */
struct N; /* merge_units */
void std_red_black_tree_1_balance_insert(N* x, N* root); /* merge_units */
#define std_red_black_tree_1_balance_insert(a0, a1) (std_red_black_tree_1_balance_insert((N *)(a0), (N *)(a1))) /* merge_units */

}
extern "C" TONode* std_tree_pair_cString_value_compare_insert_node_at_nodeP_bool_bool_pairR(TOTree* tree, TONode* parent, int left, int first, const Val_1C4F20* src)
{
    if (tree->count > 0xFFFFFFFFU - 1) {
        Libc_Fprintf(D_00489738->stream, "tree::insert length error\n");
        Libc_Abort();
    }
    TONode* node = (TONode*)TStr_Alloc(0x1C, "allocator.hh", 0x5C);
    Val_1C4F20* v = (Val_1C4F20*)node->value;
    if (v) {
        std_basic_string_char_char_traits_char_ctor_basicstringR(v, src);
        v->d = src->d;
    }
    node->right = 0;
    node->left = 0;
    node->parentAndColor = (unsigned int)parent | (node->parentAndColor & 1);
    if (left)
        parent->left = node;
    else
        parent->right = node;
    tree->count++;
    std_red_black_tree_1_balance_insert(node, tree->root);
    if (first)
        tree->leftmost = node;
    return node;
}
#undef std_red_black_tree_1_balance_insert /* merge_units */
static inline void merge_flush_func_0013C570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013C570 */

/* merge_units: begin func_0013C6F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct N_C6F0 { void* l; void* r; int p; char val[4]; };
struct T_C6F0 { int count; void* root; int pad8; N_C6F0* head; };
extern "C" {
extern char D_0049ADD0[];
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
#if 0 /* merge_units */
void std_red_black_tree_1_increment(N_C6F0** it);
#endif /* merge_units */
void std_red_black_tree_1_increment(void*); /* merge_units */
#define std_red_black_tree_1_increment(a0) (std_red_black_tree_1_increment((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void std_red_black_tree_1_balance_erase(N_C6F0* n, void* root);
#endif /* merge_units */
struct RbNode; /* merge_units */
void std_red_black_tree_1_balance_erase(RbNode* z, RbNode* root); /* merge_units */
#define std_red_black_tree_1_balance_erase(a0, a1) (std_red_black_tree_1_balance_erase((RbNode *)(a0), (RbNode *)(a1))) /* merge_units */

void String_Dtor(void* v, short f);
}
extern "C" void std_tree_pair_cString_value_compare_erase(T_C6F0* t, N_C6F0** it)
{
    N_C6F0* n = *it;
    N_C6F0** hp = &t->head;
    if (n == t->head) {
        std_red_black_tree_1_increment(it);
        *hp = *it;
    }
    std_red_black_tree_1_balance_erase(n, t->root);
    if (n->val) {
        if (n->val)
            String_Dtor(n->val, 0);
    }
    if (n) {
        AllocGuard g;
        cMemMan_Deallocate(0, n, D_0049ADD0, 0x64);
    }
    t->count--;
}
#undef std_red_black_tree_1_increment /* merge_units */
#undef std_red_black_tree_1_balance_erase /* merge_units */
static inline void merge_flush_func_0013C6F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013C6F0 */

/* merge_units: begin game_13C800 */
#pragma push /* merge_units */
#pragma cplusplus on

struct RbNode {
    RbNode *left;
    RbNode *right;
    RbNode *pp;

    RbNode *parent() const { return (RbNode *)((unsigned int)pp & ~1); }
    void set_parent(RbNode *p) { pp = (RbNode *)((unsigned int)p | ((unsigned int)pp & 1)); }
    bool red() const { return ((unsigned int)pp & 1) ? true : false; }
    void set_red() { pp = (RbNode *)((unsigned int)pp | 1); }
    void set_black() { pp = (RbNode *)((unsigned int)pp & ~1); }
    void set_color(bool c)
    {
        if (c)
            set_red();
        else
            set_black();
    }
};

#define RED(n) ((unsigned int)(n)->pp & 1 ? true : false)
#define PARENT(n) ((n)->parent())

extern "C" {
#if 0 /* merge_units */
void std_red_black_tree_1_increment(RbNode **it);
#endif /* merge_units */
#define std_red_black_tree_1_increment(a0) (std_red_black_tree_1_increment((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void std_red_black_tree_1_rotate_left(RbNode *x, RbNode **root);
#endif /* merge_units */
struct N_CF60; /* merge_units */
void std_red_black_tree_1_rotate_left(N_CF60* x, N_CF60** root); /* merge_units */
#define std_red_black_tree_1_rotate_left(a0, a1) (std_red_black_tree_1_rotate_left((N_CF60 *)(a0), (N_CF60 * *)(a1))) /* merge_units */

#if 0 /* merge_units */
void std_red_black_tree_1_rotate_right(RbNode *x, RbNode **root);
#endif /* merge_units */
struct N_CFF0; /* merge_units */
void std_red_black_tree_1_rotate_right(N_CFF0* x, N_CFF0** root); /* merge_units */
#define std_red_black_tree_1_rotate_right(a0, a1) (std_red_black_tree_1_rotate_right((N_CFF0 *)(a0), (N_CFF0 * *)(a1))) /* merge_units */

void std_red_black_tree_1_balance_erase(RbNode *z, RbNode *root);
}

void std_red_black_tree_1_balance_erase(RbNode *z, RbNode *root)
{
    RbNode *y = z;
    RbNode *x;
    RbNode *x_parent;
    bool x_is_left;
    bool rebalance;

    if (z->left != 0 && z->right != 0)
        std_red_black_tree_1_increment(&y);
    {
        RbNode *t = y;
        x = t->left ? t->left : t->right;
        x_parent = t->parent();
    }
    if (x != 0)
        x->set_parent(x_parent);
    if (y == y->parent()->left) {
        y->parent()->left = x;
        x_is_left = true;
    } else {
        y->parent()->right = x;
        x_is_left = false;
    }
    rebalance = y->red() == false;
    if (y != z) {
        y->set_parent(z->parent());
        if (z == y->parent()->left)
            y->parent()->left = y;
        else
            y->parent()->right = y;
        y->left = z->left;
        if (y->left != 0)
            y->left->set_parent(y);
        else
            x_parent = y;
        y->right = z->right;
        if (y->right != 0)
            y->right->set_parent(y);
        else
            x_parent = y;
        y->set_color(z->red());
        if (root == z)
            root = y;
    } else if (x == 0 && z == root) {
        rebalance = false;
    }
    if (rebalance) {
        while (x != root && (x == 0 || !RED(x))) {
            if (x_is_left) {
                RbNode *w = x_parent->right;
                if ((bool)((unsigned int)w->pp & 1) == true) {
                    w->set_black();
                    (x_parent->set_red());
                    std_red_black_tree_1_rotate_left(x_parent, &root);
                    w = x_parent->right;
                }
                if ((w->left == 0 || !RED(w->left)) && (w->right == 0 || !RED(w->right))) {
                    (w->set_red());
                    x = x_parent;
                    x_parent = PARENT(x_parent);
                    x_is_left = x == x_parent->left;
                } else {
                    if (w->right == 0 || !RED(w->right)) {
                        (w->left->set_black());
                        (w->set_red());
                        std_red_black_tree_1_rotate_right(w, &root);
                        w = x_parent->right;
                    }
                    if (RED(x_parent)) w->set_red(); else w->set_black();
                    (x_parent->set_black());
                    (w->right->set_black());
                    std_red_black_tree_1_rotate_left(x_parent, &root);
                    x = root;
                }
            } else {
                RbNode *w = x_parent->left;
                if ((bool)((unsigned int)w->pp & 1) == true) {
                    w->set_black();
                    (x_parent->set_red());
                    std_red_black_tree_1_rotate_right(x_parent, &root);
                    w = x_parent->left;
                }
                if ((w->left == 0 || !RED(w->left)) && (w->right == 0 || !RED(w->right))) {
                    (w->set_red());
                    x = x_parent;
                    x_parent = PARENT(x_parent);
                    x_is_left = x == x_parent->left;
                } else {
                    if (w->left == 0 || !RED(w->left)) {
                        (w->right->set_black());
                        (w->set_red());
                        std_red_black_tree_1_rotate_left(w, &root);
                        w = x_parent->left;
                    }
                    if (RED(x_parent)) w->set_red(); else w->set_black();
                    (x_parent->set_black());
                    (w->left->set_black());
                    std_red_black_tree_1_rotate_right(x_parent, &root);
                    x = root;
                }
            }
        }
        if (x != 0)
            (x->set_black());
    }
}
#undef std_red_black_tree_1_increment /* merge_units */
#undef std_red_black_tree_1_rotate_left /* merge_units */
#undef std_red_black_tree_1_rotate_right /* merge_units */
static inline void merge_flush_game_13C800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end game_13C800 */

/* merge_units: begin game_13CD40 */
#pragma push /* merge_units */
#pragma cplusplus on

struct N {
    N* left_;
    N* right_;
    N* parent_;
    N* parent() const { return (N*)((unsigned int)parent_ & ~1); }
    bool is_red() const { return bool((unsigned int)parent_ & 1) == true; }
    void set_red() { parent_ = (N*)((unsigned int)parent_ | 1); }
    void set_black() { parent_ = (N*)((unsigned int)parent_ & ~1); }
};

#if 0 /* merge_units */
extern "C" void std_red_black_tree_1_rotate_left(N* x, N** root);
#endif /* merge_units */
struct N_CF60; /* merge_units */
#define std_red_black_tree_1_rotate_left(a0, a1) (std_red_black_tree_1_rotate_left((N_CF60 *)(a0), (N_CF60 * *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern "C" void std_red_black_tree_1_rotate_right(N* x, N** root);
#endif /* merge_units */
struct N_CFF0; /* merge_units */
#define std_red_black_tree_1_rotate_right(a0, a1) (std_red_black_tree_1_rotate_right((N_CFF0 *)(a0), (N_CFF0 * *)(a1))) /* merge_units */



extern "C" void std_red_black_tree_1_balance_insert(N* x, N* root)
{
    x->set_red();
    while (x != root && x->parent()->is_red()) {
        N* xpp = x->parent()->parent();
        if (x->parent() == xpp->left_) {
            N* y = xpp->right_;
            if (y != 0 && y->is_red()) {
                x->parent()->set_black();
                y->set_black();
                x = x->parent()->parent();
                x->set_red();
            } else {
                if (x == x->parent()->right_) {
                    x = x->parent();
                    std_red_black_tree_1_rotate_left(x, &root);
                }
                x->parent()->set_black();
                x->parent()->parent()->set_red();
                std_red_black_tree_1_rotate_right(x->parent()->parent(), &root);
            }
        } else {
            N* y = xpp->left_;
            if (y != 0 && y->is_red()) {
                x->parent()->set_black();
                y->set_black();
                x = x->parent()->parent();
                x->set_red();
            } else {
                if (x == x->parent()->left_) {
                    x = x->parent();
                    std_red_black_tree_1_rotate_right(x, &root);
                }
                x->parent()->set_black();
                x->parent()->parent()->set_red();
                std_red_black_tree_1_rotate_left(x->parent()->parent(), &root);
            }
        }
    }
    root->set_black();
}
#undef std_red_black_tree_1_rotate_left /* merge_units */
#undef std_red_black_tree_1_rotate_right /* merge_units */
static inline void merge_flush_game_13CD40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end game_13CD40 */

/* merge_units: begin func_0013CF60 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_0013CF60(void) {} /* merge_units */
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
static inline void merge_flush_func_0013CFF0(void) {} /* merge_units */
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

extern void mwInit(void);
extern char *strrchr(const char *, int);
extern StrObj *std_basic_string_char_char_traits_char_ctor_charP(StrObj *, const char *);
extern void std_basic_string_char_char_traits_char_assign_basicstringR(StrObj *, StrObj *);
#if 0 /* merge_units */
extern void String_Dtor(void *, short);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((a0), (a1))) /* merge_units */

extern char *strncpy(char *, const char *, int);
extern void printf(char *, ...);
extern void MissionSelectData_SelectMissionByName(int, char *);
extern int Libc_Tolower(int);
extern void cScriptInterpreter_SetGenerateSyms(int);
extern void cScriptInterpreter_SetEnabled(int);
extern void *opNew_uint_int_charP_int(int, int, char *, int);
extern char *cDME_tServer_ctor(void *);
extern void cArray_tServerPtr_PushBackActual(void *, char **);
extern void cGameSystem_SetPlayerFilename(char *, char *);
extern void cThreadMgr_Init(void);
extern int GetMachine(void);
extern void StringPool_Load(int);
extern void App_BindIopRpc(int);
extern void cMachine_InitDME(void);
extern void Net_RetryConnect(char *);
extern void DME_Update(void);
extern int cMachine_NextFrame(int);

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

    mwInit();
    magic[0] = 0xE4A;
    run = 1;
    named = 0;
    host = 0;
    skip = 0;
    base = strrchr(argv[0], '\\');
    if (base == 0) base = strrchr(argv[0], '/');
    if (base == 0) base = argv[0];
    else base = base + 1;
    std_basic_string_char_char_traits_char_ctor_charP(&tmp, base);
    std_basic_string_char_char_traits_char_assign_basicstringR(&D_004FFBA4, &tmp);
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
                    MissionSelectData_SelectMissionByName(D_004FFC04 + 0x188, val);
                    printf(D_0049AF30, val);
                    run = 0;
                    break;
                case 'r':
                    D_004FFBB5 = 0;
                    printf(D_0049AF50, arg);
                    break;
                case 's':
                    if (Libc_Tolower(val[0]) == 'g') {
                        cScriptInterpreter_SetGenerateSyms(1);
                        skip = 1;
                    } else if (Libc_Tolower(val[0]) == 'o') {
                        cScriptInterpreter_SetEnabled(Libc_Tolower(val[1]) == 'n');
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
    cThreadMgr_Init();
    if (run) D_004FFBB2 = 1;
    StringPool_Load(GetMachine());
    if (skip) {
        App_BindIopRpc(GetMachine());
    } else {
        if (g_IsMultiplayer && host) {
            App_BindIopRpc(GetMachine());
            cMachine_InitDME();
            if (named) {
                Net_RetryConnect(name);
                while (D_005724B0 == 5) DME_Update();
            }
        }
        while (cMachine_NextFrame(GetMachine())) {
        }
    }
    /* Exit(0) is an inlined EE kernel syscall */
    asm {
        addi v1, zero, 4
        syscall 0
    }
    return 0;
}
#undef String_Dtor /* merge_units */
static inline void merge_flush_func_0013D080(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013D080 */
