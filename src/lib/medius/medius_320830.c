extern int nciTripleDecodeVoicePropSase3200(int a, int b, int c, int d, int e, int f, int g, int h, int i);
int nciTripleDecodeSase3200(int a, int b, int c, int d, int e, int f)
{
    return nciTripleDecodeVoicePropSase3200(a, b, c, d, e, f, 0, 0, 0);
}