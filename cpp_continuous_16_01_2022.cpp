#include <iostream>

using namespace std;

//#pragma comment(linker, "/STACK:100000000")


template <int T>
struct Fib
{
	static const unsigned __int64 Value = Fib<T - 1>::Value + Fib<T - 2>::Value;
};

template <>
struct Fib<0>
{
	static const unsigned __int64 Value = 1;
};

template <>
struct Fib<1>
{
	static const unsigned __int64 Value = 1;
};



void main()
{
#ifdef _DEBUG
	FILE* IN, * OUT;
	freopen_s(&IN, "input.txt", "r", stdin);
	freopen_s(&OUT, "output.txt", "w", stdout);
#endif
	cout << Fib<499>::Value;

}
