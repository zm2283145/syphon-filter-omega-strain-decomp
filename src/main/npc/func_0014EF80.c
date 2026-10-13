typedef struct It8 { int* p; } It8;
typedef struct It4 { int* p; } It4;
typedef struct Raw4 { int* p; } Raw4;
typedef struct PNode { char pad[0x7C]; int kind; } PNode;
typedef struct Self14 { char pad[0x160]; int f160; } Self14;
typedef struct Grp { char pad[0x8]; char* arr; } Grp;
extern char* NpcPath_GetNode(int id);
extern int* func_0014F230(void* c);
extern int* func_0014F200(void* c);
extern void func_0014F220(It8* out, void* c, int** raw);
extern void func_0014F1F0(Raw4* out, void* c);
extern void func_0014F1C0(Raw4* out, void* c);
extern void func_0014F1E0(It4* out, Raw4* raw);
extern void func_0014F240(Self14* self, PNode* n, int x, float f);
extern Grp* D_004FFBE8;
static inline unsigned char ne8(It8 a, It8 b) { return !(a.p == b.p); }
static inline unsigned char ne4(It4 a, It4 b) { return !(a.p == b.p); }
void func_0014EF80(Self14* self, int kind, int path, int skip, float f) {
    It8 it1;
    It4 it2;
    It8 t84;
    It4 t80;
    It4 end2;
    It8 b78;
    It8 end1;
    int* raw70;
    int* raw6C;
    Raw4 raw68;
    Raw4 raw64;
    if (path >= 0) {
        void* c = NpcPath_GetNode(path) + 0x68;
        raw70 = func_0014F230(c);
        func_0014F220(&b78, c, &raw70);
        t84.p = b78.p;
        it1 = t84;
        while ((raw6C = func_0014F200(c), func_0014F220(&end1, c, &raw6C), !(it1.p == end1.p))) {
            int id = *it1.p;
            if (id != skip) {
                PNode* n = (PNode*)NpcPath_GetNode(id);
                if (kind < 0 || kind == n->kind) func_0014F240(self, n, self->f160, f);
            }
            it1.p += 2;
        }
    } else if (kind >= 0) {
        void* c = D_004FFBE8->arr + kind * 16;
        func_0014F1F0(&raw68, c);
        func_0014F1E0(&t80, &raw68);
        it2 = t80;
        while ((func_0014F1C0(&raw64, c), func_0014F1E0(&end2, &raw64), !(it2.p == end2.p))) {
            func_0014F240(self, (PNode*)NpcPath_GetNode(*it2.p), self->f160, f);
            it2.p += 1;
        }
    }
}


