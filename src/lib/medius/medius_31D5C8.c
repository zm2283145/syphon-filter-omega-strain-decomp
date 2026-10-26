extern float NellyQuadRoot(float x);
void ScaleAndCompress(float *in, int n, float *out, float scale)
{
    float prev, x, y;
    prev = *in++ * scale; *out++ = NellyQuadRoot(prev); n--; while (n-- > 0) {
        x = *in++ * scale;
        if (x != prev) y = NellyQuadRoot(x);
        else y = out[-1];
        prev = x;
        *out++ = y;
    }
}
