typedef struct { int n; char pad[0xFC]; } G7Slot;
typedef struct { int a; int b; int head; int c; int d; G7Slot slot[64]; } G7Ring;
int func_00313870(G7Ring* r)
{
    int sum = 0;
    int ret = 0;
    int start, i, n;
    if (r != 0) {
        start = r->head & 0x3F;
        i = start;
        do {
            n = r->slot[i].n;
            if (n == 0) break;
            sum += n;
            i = (i + 1) & 0x3F;
        } while (i != start);
        ret = sum;
    }
    return ret;
}