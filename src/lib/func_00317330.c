typedef struct {
    int pad[2];
    float v[2];
    float gain;
} A;

typedef struct {
    float x;
    float y;
    float *cep;
} B;

extern void func_00317550(float *lpc, float gain, float *cep, float *err, float *dist, int p);

int func_00317330(A *a, B *b, float *lpc, int p)
{
    float err, dist;
    float x = b->x, y = b->y;
    float *v;
    float h;
    int r = 0;
    v = a->v;
    func_00317550(lpc, a->gain, b->cep, &err, &dist, p);
    if (x < v[0] && 0x1.999998p-3f <= v[1]) {
        h = v[0] * 0.5f;
        if (h * 0x1.bd70a2p-1f < x && x < h * 0x1.266666p+0f) r = 1;
    }
    if (r == 1 && err <= 2.0f && ((dist <= 0.5f && y >= 3.5f) || (dist <= 0x1.999998p-2f && y >= 2.5f) || (dist <= 0x1.999998p-4f && y >= 1.5f)))
        r = 1;
    else
        r = 0;
    return r;
}
