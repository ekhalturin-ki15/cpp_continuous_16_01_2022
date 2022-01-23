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


using namespace std;

#define PI std::atan2(0, -1)

template <typename T>
void Out(T v)
{
	for (auto it : v)
		cout << it << " ";


	cout << "\n";
}


bool Cmp2(int l, int r)
{
	return l > r;
}


struct Cmp
{
	bool operator() (int l, int r) const
	{
		// x  = 5;
		return (l < r);
	}

	int x;

};

int main()
{	
#ifdef _DEBUG
	FILE* IN, * OUT;
	freopen_s(&IN, "input.txt", "r", stdin);
	freopen_s(&OUT, "output.txt", "w", stdout);
#endif

	multiset<int, Cmp> ms;

	//abs();

	

	ms.insert(10);

	ms.insert(9);

	ms.insert(11);

	ms.insert(11);

	ms.insert(11);

	ms.insert(11);

	ms.insert(11);

	ms.insert(9);

	ms.insert(9);

	ms.insert(9);

	ms.insert(9);

	ms.insert(9);

	ms.count(9);

	Out(ms);

	set< int >  s;

	s.insert(10);

	s.insert(9);

	s.insert(11);

	s.insert(11);

	s.insert(11);

	s.insert(11);

	s.insert(11);





	Out(s);

	vector<int> v;

	v.push_back(10);
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);


	Out(v);

	//cout <<  s.erase(15);








}