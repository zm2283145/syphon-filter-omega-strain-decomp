typedef struct {
    float* h;
    float mean;
    short cnt;
} Agc;

void nemAgcMeanEngLevel(unsigned char lev, Agc* s)
{
    float* h0 = s->h;
    float* h;
    int idx = lev >> 3;
    int i;
    float sum;

    h0[idx] = (h0[idx] - 1.0f) * 0.96875f + 1.0f;
    sum = h0[idx];
    if (idx != 0) {
        float* cursor;
        h = h0;
        /* Keep the initial base and loop base as distinct compiler lifetimes. */
        __asm__("" : "+r"(h));
        cursor = h;
        i = idx;
        /* Preserve retail count initialization scheduling without emitted code. */
        __asm__("" : "+r"(i));
        do {
            *cursor *= 0.96875f;
            sum += *cursor++;
        } while (--i);
    } else {
        h = h0;
        /* Match the corresponding loop-base lifetime on the skipped-loop path. */
        __asm__("" : "+r"(h));
    }
    for (i = idx + 1; i < 33; i++) {
        h[i] *= 0.96875f;
        sum += h[i];
    }
    s->mean = 0.0f;
    for (i = 0; i < 33; i++) {
        s->mean += (float)i * h[i] / sum;
    }
    s->cnt = 0;
    s->mean *= 8.0f;
}