float func_001D1080(float x)
{
    float r;
    asm { sqrt.s r, x }
    return r;
}
