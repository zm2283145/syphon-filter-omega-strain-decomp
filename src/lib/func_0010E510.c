typedef struct { int size; int count; unsigned char* rd; unsigned char* wr; unsigned char buf[1]; } Ring_0010E510;
void func_0010E510(Ring_0010E510* r)
{
    r->count++;
    r->wr++;
    if (r->wr == r->buf + r->size) r->wr = r->buf;
}