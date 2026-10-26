typedef struct { char pad[0x10]; unsigned short s10; unsigned short buf[4]; char pad2[2]; int wr; int rd; int count; } Q223B90;
typedef struct { int f0; int f4; int f8; int fc; Q223B90 q; } E223B90;extern E223B90* D_004F5784;
int push_repbuf(int i, unsigned short v)
{
    Q223B90* q = &D_004F5784[i].q;
    if (q->count >= 4) return -1;
    q->buf[q->wr++] = v;
    if (q->wr >= 4) q->wr = 0;
    q->count++;
    return 0;
}