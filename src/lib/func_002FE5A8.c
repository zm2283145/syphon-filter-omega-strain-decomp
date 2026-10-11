typedef struct { char p[0x3C]; void *h3C; char q[0x38]; void *conn[2]; } S2FE5A8;
extern unsigned char D_004908EC;
extern unsigned short D_004908F0;
extern S2FE5A8 **D_004908F4;
extern int func_002F5348(void *);
extern int func_002FB3C0(void *);
extern void *memset(void *, int, unsigned int);
extern void func_002F94D0(int);
int func_002FE5A8(unsigned short id)
{
    unsigned int i;
    char *e;
    if (D_004908EC != 1) return 5;
    if (id >= D_004908F0) return 2;
    if (D_004908F4[id] != 0) {
        for (i = 0; i < 2; i++) {
            e = ((struct { char pad[0x70]; char *arr[2]; } *)((char *)D_004908F4[id] + 8))->arr[i];
            if (e) {
                func_002F5348(e + 0x50);
                func_002F5348(((struct { char pad[0x70]; char *arr[2]; } *)((char *)D_004908F4[id] + 8))->arr[i] + 0x68);
                func_002FB3C0(&D_004908F4[id]->conn[i]);
            }
        }
        if (D_004908F4[id]->h3C) func_002FB3C0(&D_004908F4[id]->h3C);
        memset(D_004908F4[id], 0, 0x98);
        func_002FB3C0(&D_004908F4[id]);
        D_004908F4[id] = 0;
    }
    func_002F94D0(id);
    return 0;
}