typedef struct { char pad[0x20]; int f20; char name[0x10]; int f34; } Msg_F1C8;
extern short D_0048C414;
extern int D_0048C3D8;
extern int D_0048C3E0;
extern int D_0048C38C;
extern char D_004AD218[];
extern char D_004AD220[];
extern int func_002D0EB8(void *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
extern void func_002CEBD0(int);
extern void func_002CEBF0(int);
extern int strcmp(const char *, const char *);
extern char *strncpy(char *, const char *, unsigned int);
int func_002CF1C8(Msg_F1C8 *a, int b)
{
    if (D_0048C414 != 1) return -0xC;
    D_0048C3E0 = b;
    func_002CEBD0(a->f20);
    if (a->f20 == 0 || a->f20 == 4) {
        func_002CEBF0(a->f34);
    } else {
        a->f34 = 0;
    }
    if (strcmp(a->name, D_004AD218) == 0 || a->name == 0) {
        strncpy(a->name, D_004AD220, 0x10);
    }
    func_002D0EB8(a, 0x15);
    func_002D0EB8(a->name, 0x10);
    return Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C38C, 0x38, a) ? -5 : 0;
}
