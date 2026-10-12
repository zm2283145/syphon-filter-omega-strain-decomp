typedef struct {
    char pad0[0x2188];
    int h2188;
    char s218C[0x200];
    unsigned short n238C;
    char key[0x22];
    int r23B0;
    char pad23B4[0x2570 - 0x23B4];
    int res;
} Lob;
extern char D_004C0D58[];
extern char D_004C0D70[];
extern char D_004C0D88[];
extern unsigned char D_00585E68;
void func_00443E60(char*);
void func_00452F70(Lob*, int, int);
int func_003A6670(int);
void func_00451B00(Lob*, int, char*, int);
int func_0010D050(void);
int func_0010CFF0(int, int);
void* memset(void*, int, unsigned int);
int func_1E68080(int, char*, unsigned short, int, unsigned char, char*, int*);
void DecodeKey_XorB3(char*, int);

int func_0044B7A0(Lob* self)
{
    int old;
    int r;

    self->res = 0;
    func_00443E60(D_004C0D58);
    func_00452F70(self, 2, 2);
    if (func_003A6670(2) == 0) {
        func_00451B00(self, 5, D_004C0D70, 0x27A);
        return 0;
    }
    old = func_0010CFF0(func_0010D050(), 0x7F);
    if (old < 0)
        old = 2;
    memset(self->key, 0, 0x20);
    self->r23B0 = 0;
    self->res = func_1E68080(self->h2188, self->s218C, self->n238C, 0, D_00585E68, self->key, &self->r23B0);
    if (self->res != 0) {
        func_00451B00(self, 6, D_004C0D70, 0x289);
        func_0010CFF0(func_0010D050(), old);
        if (func_003A6670(1) == 0) {
            func_00451B00(self, 5, D_004C0D70, 0x28E);
            return 0;
        }
        r = 0;
        func_00452F70(self, 3, (int)&r);
        return r == 1;
    }
    func_0010CFF0(func_0010D050(), old);
    if (func_003A6670(1) == 0) {
        func_00451B00(self, 5, D_004C0D70, 0x29B);
        return 0;
    }
    func_00443E60(D_004C0D88);
    DecodeKey_XorB3(self->key, 0);
    return 1;
}

