extern const float D_004E1C90;
extern const float D_004E1C98;

void func_0031CF58(float *x, int v, int *list, int *n, int *best)
{
    int cnt = *n;
    int i = 0;
    int b = *best;
    int found = 0;
    int j;
    float xv, tb, t0;

    for (j = 0; j < cnt; j++) {
        if (v == list[j])
            found = 1;
        if (list[j] < v)
            break;
    }
    i = j;
    if (!found) {
        xv = x[v];
        t0 = x[list[0]] * D_004E1C98;
        tb = x[list[b]] * D_004E1C90;        if ((i == cnt && t0 <= xv) || (b < i && tb <= xv)) {
            for (j = cnt; j > i; j--)
                list[j] = list[j - 1];
            list[i] = v;
            if (tb <= xv)
                b = i;
            cnt++;
        }
    }
    *best = b;
    *n = cnt;
}


