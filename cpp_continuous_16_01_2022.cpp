#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <bitset>
#include <map>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <forward_list>
#include <unordered_set>
#include <memory>
#include <stack>


#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

using namespace std;

#define PI std::atan2(0, -1)

long long a, k, b, m, x;
double P, Pa, Pb;


long long ceil(long long a, long long b)
{
	return (a) / b;
}


long long f(long long d)
{
	long long q = (d - ceil(d,k));
	long long u = (d - ceil(d, m));

	double Pq = logl(q) + Pa;
	double Pu = logl(q) + Pb;

	if ((P < Pq) || (P < Pu)) return true;

	long long res = q * a + u * b;
	return (res >= x);

}


const long long M = 1e9 + 9;

// a ^ (p - 1) = 1 (mod p)    | /a
// 
// a * x - 1 = 0 (mod M)
// a * x  = 1 (mod M)
// a * a^-1  = 1 (mod M)
// 
// a ^ (p - 2) = a^-1  (mod p) 
// 
// 
// 
// 5^ 2 = 1 (3)


long long bin_pow(long long a, long long p, long long m)
{
	if (p == 1) return a;

	long long x = bin_pow(a, p / 2, m);

	x = (x * x) % m;

	if (p % 2 == 1) x = (x * a) % m;

	return x;

}



int main()
{	
#ifdef _DEBUG
	FILE* IN, * OUT;
	freopen_s(&IN, "input.txt", "r", stdin);
	freopen_s(&OUT, "output.txt", "w", stdout);
#endif


	list<int> l;

	list<int>::iterator mid = l.begin(); // size/2 в меньшую
	int dist = 0;


	mid++;
	

	mid--;

	int val;

	l.insert(mid, val);

	l.push_back(val);

	l.pop_front();




}