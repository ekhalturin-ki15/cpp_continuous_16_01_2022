#include <iostream>
#include <set>
#include <vector>

using namespace std;

int i;

//factor(10) ~ 3 * 10^6
long long factor(int n)
{
    long long ret = 1;
    for (int i = 2; i <= n; ++i) ret *= i;
    return ret;
}


void Out(const vector<int>& buf)
{

    for (int i = 0; i < buf.size() - 1; ++i) cout << buf[i] <<",";
    cout << buf.back() << "\n";
}


// какой шаг, буффер для вывода, откуда брать значения
void permutation(int step, vector<int>& buf, const vector<int>& v, set<int>& s)
{
    //Условие завершения рекурсии

    if (step == v.size())
    {
        //Нет вызова функции
        //buf[0] = 10;

        Out(buf);

        return;
    }
    //Тело рекурсии
    //Может произойти ещё вызов

    for (auto it : v)
    {
        if (s.count(it)) continue;

        s.insert(it);
        buf[step] = it;

        permutation(step + 1, buf, v, s);

        //buf[step] = 0;
        s.erase(it);

    }
}


int main()
{
#ifdef _DEBUG
    FILE* IN, * OUT;
    freopen_s(&IN, "input.txt", "r", stdin);
    freopen_s(&OUT, "output.txt", "w", stdout);
#endif

    vector<int> v = {1, 5, 4, 3, 2, 10};

    // n =  0 .. 10
    // n < 10^6 O(n)   O(n * log(n))
    // n < 2 * 10^5  O(n * log(n))
    // n < 10^3 O(10^3)     1 сек 10^6 
    // 
    // 
    // n < 12  O(!n)

    int n = v.size();

    vector<int> buf(n);
    // step , buf, v

    set<int> s;
    permutation(0, buf, v, s);





    /*for (int i = 0; i < factor(n); ++i)
    {

    }*/


}