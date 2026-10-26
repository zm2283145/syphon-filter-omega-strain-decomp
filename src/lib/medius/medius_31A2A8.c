int CalcCircBufPosition(int a, int b, int m)
{
    return (m + (b + a % m)) % m;
}