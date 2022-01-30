#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<long long>> VVLL;

long long M = 1e17 + 7;

VVLL A, B, C, A_N;

#ifdef __TIMESTAMP__
    long long n;
    string s = __TIMESTAMP__;
#endif

#ifdef __TIME__
    string ss = __TIME__;
#endif


VVLL mul(VVLL A, VVLL B, long long M)
{
    if (A.size() != B[0].size()) return {};

    VVLL ret(A[0].size(), vector<long long>(B.size()));

    for (int y = 0; y < A[0].size(); ++y)
    {
        for (int x = 0; x < A.size(); ++x)
        {
            for (int i = 0; i < A[0].size(); ++i)
            {
                ret[y][x] = (ret[y][x] + A[y][i] * B[i][x]) % M;
            }

            //ret[y][x] = (ret[y][x] + A[y][x] * B[x][y]) % M;
        }
    }

    return ret;
}

VVLL bin_pow(VVLL A, long long n, long long M)
{
    //Выход рекурсии
    if (n == 1) return A;

    //Тело рекурсии
    VVLL C = bin_pow(A, n / 2, M);
    VVLL ret = mul(C, C, M);
    if (n % 2 == 1)
    {
        ret = mul(ret, A, M);
    }

    return ret;
}

int main()
{
#ifdef _DEBUG
    FILE* IN, * OUT;
    freopen_s(&IN, "input.txt", "r", stdin);
    freopen_s(&OUT, "output.txt", "w", stdout);
#endif
    
    cout << ss <<"\n444";

    cin >> n; 

    A = { {0, 1}, {1, 1} }; // f_n = f_n-1  + f_n-2

    B = { {1, 1} }; // f0 = 1, f1 =1
    // [y][x]
    // W = 1 = B.size();
    // H = 2 = B[0].size()


    A_N = bin_pow(A , n - 2, M);


    cout << A_N.back().back();
   


}