
extern void* Service_Lookup(void* a, void* b);
extern void func_001450F0(int);
extern char* func_001698C0(void);
extern void func_001C9710(void*);
extern void func_002C9C80(void*, int);
extern void func_002C9E20(void*);
extern void func_003D1700(void*);
extern unsigned char* func_004294C0(void);
extern char* strncpy(char*, const char*, int);
extern char D_004ACF48[];
extern char D_004F2CC0[];
extern char D_004FFB50[];
extern char D_004FFC90[];
extern int D_004FFD30;
extern unsigned char D_0051EF68;
extern char D_0055A700[];

typedef struct {
    char pad0[0x28];
    unsigned char f28;
    char pad29[0xE];
    unsigned char f37;
    unsigned char f38;
} Obj9860;

typedef struct {
    signed char len;
    char text[0x80];
} PStr;

static inline void Copy(PStr* buf, const char* s)
{
    char* d;
    const char* p;
    int n;
    n = 0;
    d = buf->text;
    p = s;
    while ((*d++ = *p++) != 0) {
        if (++n >= 0x7E) {
            n++;
            d[0] = '\n';
            d[1] = 0;
            break;
        }
    }
    buf->len = n;
}

void func_002C9860(Obj9860* self, unsigned char mode)
{
    if (self->f37 == 0) {
        { char* q = func_001698C0(); q[0x278] = 1; }
        func_003D1700(D_0055A700);
        switch (mode) {
        case 0: {
            void* svc;
            D_0051EF68 = 0;
            svc = Service_Lookup(D_004FFB50, D_004F2CC0);
            if (svc) {
                PStr save;
                unsigned char* g;
                Copy(&save, D_004FFC90);
                strncpy(D_004FFC90, D_004ACF48, 0x80);
                func_001C9710(svc);
                strncpy(D_004FFC90, save.text, 0x80);
                g = func_004294C0();
                if (g && g[0x2409] == 0) {
                    D_0051EF68 = 1;
                    g[0x2409] = 1;
                }
            }
            break;
        }
        case 1:
            break;
        }

        func_002C9E20(self);
        func_001450F0(D_004FFD30);
        func_002C9C80(self, 1);
        self->f37 = 1;
        self->f28 = 0;
        self->f38 = mode;
    }
}

