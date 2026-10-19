extern int func_00358890(int a, int b);
extern int Insck_Recvfrom(int a, int b, int c, int d, int e, int f);
int func_0045AD10(int a, int b, int c, int d, int e, int f)
{
    func_00358890(a, 600000);
    return Insck_Recvfrom(a, b, c, d, e, f);
}