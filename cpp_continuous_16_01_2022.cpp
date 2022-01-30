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


int main()
{
#ifdef _DEBUG
    FILE* IN, * OUT;
    freopen_s(&IN, "input.txt", "r", stdin);
    freopen_s(&OUT, "output.txt", "w", stdout);
#endif

    VI v = {1, 5, 4, 3, 2, 10};
    int count = 1;
    while (std::next_permutation(v.begin(), v.end())) // next_permutation возврат true если отсортировано
    {
        Out(v, count++);
    }




    //return 0;



    // n =  0 .. 10
    // n < 10^6 O(n)   O(n * log(n))
    // n < 2 * 10^5  O(n * log(n))
    // n < 10^3 O(10^3)     1 сек 10^6 
    // 
    // 
    // n < 12  O(!n)

    int n = v.size();





    VI buf(n);
    // step , buf, v








    set<int> s;


    //cin >> K;
    K = 3;
    count = 1;
    bool flag = true;
    permutation(0, buf, v, s, count, *std::min_element(v.begin(), v.end()), flag);




    count = 10;
    for (int i = 0; i < factor(n); ++i)
    {
        Out(v, count+=10);
        std::next_permutation(v.begin(), v.end());
    }


}