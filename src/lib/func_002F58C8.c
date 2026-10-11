int func_002F58C8(unsigned int *o, unsigned int *out)
{
    int ret = 2;
    if (o != 0 && out != 0) {
        if (o[3] == o[2]) *out = 0;
        else if (o[1] >= o[0]) *out = o[2] - o[1];
        else *out = o[0] - o[1];
        ret = 0;
    }
    return ret;
}