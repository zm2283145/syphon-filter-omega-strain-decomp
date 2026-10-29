typedef struct { float nf; char pad[0xE]; signed char cnt; signed char flag; } VadNf;

void nemVadUpdateNoiseFlr(VadNf *s, float e)
{
    float nf = s->nf;
    float t;

    if (nf < 160000.0f) {
        float u = nf + 1.125f;
        float w = nf * 1.00547f;
        if (u <= w) nf = w; else nf = u;
    } else if (nf < 500000.0f) {
        nf = nf * 1.001367f;
    } else {
        nf = nf * 1.000684f;
    }
    if (e < s->nf) {
        if (s->cnt <= 0) {
            float w = s->nf * 0.1f + (e + 1.0f) * 0.9f;
            if (!(w <= nf)) w = nf;
            nf = w;
        }
        if (e <= s->nf * 0.001f) {
            if (e < 1.0f) {
                float w = s->nf * 0.65f + (e + 1.0f) * 0.35f;
                nf = (w <= nf) ? w : nf;
            } else {
                float w = s->nf * 0.4f + e * 0.6f;
                nf = (w <= nf) ? w : nf;
            }
        } else if (e <= s->nf * 0.01f) {
            float w = s->nf * 0.3f + e * 0.7f;
            nf = (w <= nf) ? w : nf;
        } else {
            float w = s->nf * 0.2f + e * 0.8f;
            nf = (w <= nf) ? w : nf;
        }
    } else if (s->flag == 0) {
        float w = s->nf * 0.75f + e * 0.25f;
        nf = (nf <= w) ? w : nf;
    }
    if (5059644.0f < nf) nf = 5059644.0f;
    if (s->cnt <= 0) s->cnt++;
    s->nf = nf;
}