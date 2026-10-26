/*
 * lib/medius: 2 files, 00323458-003234B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00323458 */
extern void fftCore4CFGV(int, int, int);
extern void unpack2G(int, int, int);
void nvuRealFft(int a, int b, int n)
{
    int h = n / 2;
    fftCore4CFGV(a, b, h);
    unpack2G(a, b, h);
}
/* merge_units: end func_00323458 */

/* merge_units: begin func_003234B0 */
extern void pack2G(int, int, int);
void nvuInverseRealFft(int a, int b, int n)
{
    int h = n / 2;
    pack2G(a, b, h);
    fftCore4CFGV(b, a, h);
}
/* merge_units: end func_003234B0 */
