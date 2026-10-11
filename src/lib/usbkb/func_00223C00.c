typedef struct { char pad[0x10]; unsigned short s10; unsigned short buf[4]; char pad2[2]; int wr; int rd; int count; } Q223C00;
typedef struct { int f0; int f4; int f8; int fc; Q223C00 q; } E223C00;extern E223C00* D_004F5784;
int func_00223C00(int i, unsigned short* out)
{
    Q223C00* q = &D_004F5784[i].q;
    if (q->count <= 0) return -1;
    *out = q->buf[q->rd++];
    if (q->rd >= 4) q->rd = 0;
    q->count--;
    return 0;
}