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

int main()
{
#ifdef _DEBUG
    FILE* IN, * OUT;
    freopen_s(&IN, "input.txt", "r", stdin);
    freopen_s(&OUT, "output.txt", "w", stdout);
#endif

    cin >> n;
    v.resize(n);

    for (auto& it : v) cin >> it;

    cin >> k;
    buf.resize(k);

    C = 1;

    permutation(0, 0);




}