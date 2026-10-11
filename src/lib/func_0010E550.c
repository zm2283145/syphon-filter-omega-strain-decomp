typedef struct { int size; int count; unsigned char* rd; unsigned char* wr; unsigned char buf[1]; } Ring_0010E550;
void ByteRing_Pop(Ring_0010E550* r)
{
    r->count--;
    r->rd++;
    if (r->rd == r->buf + r->size) r->rd = r->buf;
}