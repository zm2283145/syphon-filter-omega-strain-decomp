#pragma cplusplus on
struct E { void *name; int pad[5]; };
struct V { int a; int count; E *data; };
struct Stats { char pad[0x18]; int total; int done; };
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
void *func_003FDAE0(void *name);
int func_00333890(void *agent, char *a, void *name, int c);
unsigned char AgentData_IsObjectiveComplete(void *agent, void *name);
}
static inline bool Neq(E *a, E *b) { return !(a == b); }
extern "C" void func_00335660(void *agent, char *s, Stats *st)
{
    int i;
    int len;
    char c;
    char *pat;
    E *it;
    E *end;
    st->total = 0;
    st->done = 0;
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
        void *name = func_003FDAE0(it->name);
        if (func_00333890(agent, pat, name, '*') && !func_00333890(agent, D_004B92C0, name, '*')) {
            st->total++;
            if (AgentData_IsObjectiveComplete(agent, name))
                st->done++;
        }
    }
}


