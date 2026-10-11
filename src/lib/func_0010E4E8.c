typedef struct { int size; int count; unsigned char* rd; unsigned char* wr; unsigned char buf[1]; } Ring_0010E4E8;
extern Ring_0010E4E8 D_004E2840;
Ring_0010E4E8* func_0010E4E8(int size)
{
    Ring_0010E4E8* r = &D_004E2840;
    r->count = 0;
    r->wr = r->buf;
    r->rd = r->buf;
    r->size = size;
    return r;
}