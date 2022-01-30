#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int i;

typedef vector<int> VI;


//factor(10) ~ 3 * 10^6
long long factor(int n)
{
    long long ret = 1;
    for (int i = 2; i <= n; ++i) ret *= i;
    return ret;
}


void Out(const VI& buf, const int& count)
{
    cout << count << " | ";
    for (int i = 0; i < buf.size() - 1; ++i) cout << buf[i] <<", ";
    cout << buf.back() << "\n";
}


int K;


// какой шаг, буффер для вывода, откуда брать значения
void permutation(int step, VI& buf, const VI& v, 
    set<int>& s, int& count, const int& pred, bool flag)
{
    //Условие завершения рекурсии

    if (step == K)
    {
        if (flag)
        {
            cout << "Отсортировано ";
        }

        //Нет вызова функции
        //buf[0] = 10;

        Out(buf, count);
        ++count;
        return;
    }
    //Тело рекурсии
    //Может произойти ещё вызов

    for (auto it : v)
    {
        if (s.count(it)) continue;

        s.insert(it);
        buf[step] = it;

        bool tmp_flag = flag;

        if (pred > it) flag = false;
        permutation(step + 1, buf, v, s, count, it, flag);

        //buf[step] = 0;
        s.erase(it);
        flag = tmp_flag;

    }
}


VI buf;
VI v;
int n, k, C;

multiset<int> ms;
set< multiset<int> > pull;

void permutation(int step, int choose)
{
    if (choose == k)
    {

        if (pull.count(ms))
            return;

        Out(buf, C++);
        pull.insert(ms);

        return;
    }

    if (step == n)
        return;


    //Сама рекурсия
    permutation(step + 1, choose);


    ms.insert(v[step]);
    buf[choose] = v[step];

    permutation(step + 1, choose + 1);
    ms.erase(ms.find(v[step]));


}

typedef vector<vector<long long>> VVLL;

long long M = 1e9 + 7;
long long n;
VVLL A, B, C, A_N;



VVLL mul(VVLL A, VVLL B, long long M)
{
    if (A.size() != B[0].size()) return {};

    VVLL ret(A[0].size(), vector<long long>(B.size()));

    for (int y = 0; y < A[0].size(); ++y)
    {
        for (int x = 0; x < A.size(); ++x)
        {
            ret[y][x] = (ret[y][x] + A[y][x] * B[x][y]) % M;
        }
    }

    return ret;
}

VVLL bin_pow(VVLL A, long long n, long long M)
{
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

    cin >> n; 

    A = { {0, 1}, {1, 1} }; // f_n = f_n-1  + f_n-2

    B = { {1, 1} }; // f0 = 1, f1 =1
    // [y][x]
    // W = 1 = B.size();
    // H = 2 = B[0].size()


    A_N = bin_pow(A , n, M);


    cout << A_N.back().back();
   


}