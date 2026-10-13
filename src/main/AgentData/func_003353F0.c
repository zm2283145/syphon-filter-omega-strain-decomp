#pragma cplusplus on
struct E { void *name; int pad[5]; };
struct V { int a; int count; E *data; };
struct Item { char *text; void *name; char state; int a; int b; int c; int agent; };
struct IV { int a; int count; Item *data; };
extern "C" {
extern char D_00532990[];
extern char D_00532991[];
extern char D_00532992[];
extern char D_00499C71[];
extern char D_00532998[];
extern char D_004B92B8[];
extern char D_004B92C0[];
extern V D_005329F0;
int strlen(const char *s);
int sprintf(char *buf, const char *fmt, ...);
E **func_003305C0(V *v);
void *Loc_GetStoredKey(void *name);
int Awards_MatchKeyPattern(void *agent, char *a, void *name, int c);
unsigned char AgentData_IsObjectiveComplete(void *agent, void *name);
void func_00299500(IV *v);
char *Loc_LookupText(void *name);
int Loc_FindKeyThunk(int k);
int func_003337A0(int k);
void func_00337F90(IV *v, Item *pos, int n, Item *val);
}
static inline bool Neq(E *a, E *b) { return !(a == b); }
extern "C" void func_003353F0(void *agent, char *s, IV *out)
{
    int i;
    int len;
    char c;
    char *pat;
    void *name;
    E *it;
    E *end;
    if (s == 0 || out == 0) return;
    func_00299500(out);
    i = 0;
    len = strlen(s) - 1;
    D_00532990[0] = s[0];
    D_00532991[0] = s[1];
    D_00532992[0] = s[2];
    i += 3;
    c = s[len];
    if (D_00499C71[c] & 4) {
        D_00532990[i++] = c;
    }
    D_00532990[i] = 0;
    sprintf(D_00532998, D_004B92B8, D_00532990);
    pat = D_00532998;
    it = *func_003305C0(&D_005329F0);
    end = *func_003305C0(&D_005329F0) + D_005329F0.count;
    for (; Neq(it, end); it++) {
        name = Loc_GetStoredKey(it->name);
        if (Awards_MatchKeyPattern(agent, pat, name, '*') && !Awards_MatchKeyPattern(agent, D_004B92C0, name, '*')) {
            Item item;
            char st = AgentData_IsObjectiveComplete(agent, name) ? 2 : 1;
            item.text = Loc_LookupText(name);
            item.name = name;
            item.state = st;
            void* k = 0;
            item.agent = k ? func_003337A0(Loc_FindKeyThunk(0)) : -1;
            item.a = 0;
            item.b = 0;
            item.c = 0;
            func_00337F90(out, &out->data[out->count], 1, &item);
        }
    }
}

