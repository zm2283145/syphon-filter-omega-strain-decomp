float SQRT(float x)
{
    float r;
    asm { sqrt.s r, x }
    return r;
}
