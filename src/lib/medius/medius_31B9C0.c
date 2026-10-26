/*
 * lib/medius: 3 files, 0031B9C0-0031BAB8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0031B9C0 */
void BitRev(float *data, int nn)
{
    int n = nn << 1;
    int i, j = 1, m;
    float t;
    for (i = 1; i < n; i += 2) {
        if (j > i) {
            t = data[j]; data[j] = data[i]; data[i] = t;
            t = data[j - 1]; data[j - 1] = data[i - 1]; data[i - 1] = t;
        }
        m = n >> 1;
        while (m >= 2 && j > m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    }
}
/* merge_units: end func_0031B9C0 */

/* merge_units: begin func_0031BA78 */
void NellyMagSq(float *re, float *im, int n, float *out)
{
    for (; n > 0; n--) {
        *out++ = *re * *re + *im * *im;
        re++;
        im++;
    }
}
/* merge_units: end func_0031BA78 */

/* merge_units: begin func_0031BAB8 */
void NellyMagSqIL(float *c, int n, float *out)
{
    for (; n > 0; n--) {
        *out++ = c[0] * c[0] + c[1] * c[1];
        c += 2;
    }
}
/* merge_units: end func_0031BAB8 */
