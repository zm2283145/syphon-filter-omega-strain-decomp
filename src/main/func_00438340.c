typedef struct { char pad[0x1C]; int f1C; } P_438340;
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern unsigned char D_005721D0;
extern int D_00582CF0;
extern int D_00583868;
extern int D_00583870;
extern char D_004BFD20[];
extern unsigned char D_00497568;
extern int D_00497548;
extern unsigned char D_00582B88;
extern unsigned char D_00582B90;
extern char sfo_malloc_2CA9B0;
extern char func_002CAA70;
int func_002EAF28(int* key, int a, int b, int c, int d, int e, int f, int g, char* h, int i);
int func_002EB650(P_438340** out, int key);
int lgAudInit(void* a, void* b);
int lgAudEnumHint(int* hint);
unsigned char func_004384C0(void);

static inline int NetOk_438340(void) { return D_005721C8 ? D_005721C0 : 1; }

unsigned char func_00438340(void)
{
    int hint;
    int key;
    P_438340* p;
    unsigned char ok = 1;
    if (NetOk_438340() && D_00582CF0 == 0) {
        int v = 0;
        if (D_005721D0) {
            if (!func_002EAF28(&key, 2, 4, 1000, 0, 0, 0, 0, D_004BFD20, D_00583868)) {
                D_00583870 = key;
                if (!func_002EB650(&p, key)) v = p->f1C;
            }
        }
        D_00582CF0 = v;
    }
    if (D_00497568) {
        D_00497568 = 0;
        D_00497548 = -1;
        D_00582B88 = 0;
        if (!lgAudInit(&func_002CAA70, &sfo_malloc_2CA9B0)) D_00582B90 = 1;
    }
    if (D_00582B90) {
        lgAudEnumHint(&hint);
        if (hint == 1 || !D_00582B88) {
            if (!func_004384C0()) ok = 0;
        }
    }
    return ok;
}

