typedef struct {
    int sock;
    char pad4[4];
    void *ext;
    char padC[0x18];
    void *buf1;
    void *buf2;
    char pad2C[0x1C];
    unsigned int idx;
} ScfSock;
extern void func_002F5DB0(int sock);
extern void func_002FB3C0(void *pp);
extern void func_0030DED8(void *p);
extern int D_00491310;
extern unsigned short D_00491314;
extern void *D_00491318;
extern void *D_0049131C;
extern void *D_00491320;
extern unsigned char D_00491324;
extern ScfSock *D_00529860[8];

/* Closes an RT UDP socket; the shared socket is torn down when its last user goes. */
int func_0030B220(ScfSock *s)
{
    int last = 1;
    unsigned int i;

    if (s->idx < 8) {
        D_00529860[s->idx] = 0;
        for (i = 0; i < 8; i++) {
            if (D_00529860[i] != 0) last = 0;
        }
        if (last) {
            func_002F5DB0(D_00491310);
            D_00491310 = 0;
            D_00491314 = 0;
            func_002FB3C0(&D_00491318);
            D_00491318 = 0;
            func_002FB3C0(&D_0049131C);
            D_0049131C = 0;
            if (D_00491320 != 0) {
                func_0030DED8(D_00491320);
                D_00491320 = 0;
                D_00491324 = 0;
            }
        }
    } else {
        func_002F5DB0(s->sock);
        func_002FB3C0(&s->buf1);
        func_002FB3C0(&s->buf2);
        if (s->ext != 0) {
            func_0030DED8(s->ext);
            s->ext = 0;
        }
    }
    return 0;
}

