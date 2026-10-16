/* Bind the texture pair, reset the batch flags, then append each id to the
 * 512-entry draw list unless it repeats the last entry. */
typedef struct Mgr {
    char pad0[0x14];
    unsigned char f14;
    unsigned char f15;
    unsigned char f16;
    char pad17;
    unsigned int count;
    short list[0x200];
} Mgr;
typedef struct Pair { int a; int b; } Pair;
extern Mgr* D_00539248;
extern void func_00382D30(Mgr*, int);
extern void TexMan_UploadSlots(Mgr*);

static inline void Push(Mgr* m, int id)
{
    if (m->count < 0x200) {
        if (m->count == 0 || m->list[m->count - 1] != id) {
            m->list[m->count++] = id;
        }
    }
}

void func_003BB060(Pair* p)
{
    Mgr* m;
    func_00382D30(D_00539248, p->a);
    if (p->b != -1) func_00382D30(D_00539248, p->b);
    m = D_00539248;
    m->f14 = 1;
    m->f15 = 1;
    m->count = 0;
    m->f16 = 0;
    Push(D_00539248, p->a);
    if (p->b != -1) Push(D_00539248, p->b);
    TexMan_UploadSlots(D_00539248);
}

