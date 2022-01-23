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


#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

using namespace std;

#define PI std::atan2(0, -1)



template <typename T>
T sum(T first)
{
	return first;
}

template <typename T, typename ...Arg>
T sum(T first, Arg... other)
{
	return first + sum(other...);
}


template <typename T>
auto sum2(T v)
{
	auto ret = v.front();
	for (auto it : v)
	{
		ret += it;
	}
	return ret;
}


int f(int t)
{
	return (t * 13 + 10) % 20;
}

struct node
{
	int val;


	node* l = 0;
	node* r = 0;
};



struct tree
{
	node* root = 0;


	void insert(int val)
	{
		insert_rec(root, val);
	}

private:
	void insert_rec(node* n, int val)
	{
		if (n == 0)
		{
			n = new node;
			n->val = val;
			return;
		}

		if (val == n->val) return;

		if (val < n->val)
		{
			insert_rec(n->l, val);
			return;
		}
		else
		{
			insert_rec(n->r, val);
			return;
		}

	}




};



int main()
{	
#ifdef _DEBUG
	FILE* IN, * OUT;
	freopen_s(&IN, "input.txt", "r", stdin);
	freopen_s(&OUT, "output.txt", "w", stdout);
#endif

	//printf("", 2, 3, 3, 2, 2 );

	//2 + sum(3, 4, 3, 43, 43, 4, 343, 4, 34)
	cout << sum(2,3,4,3,43,43,4,343,4,34) << "\n";

	cout << sum(2,3,4,3,43,43,4,343,4,34, 214, 34, 34.20, 43,1) << "\n";

	cout << sum2<vector<int>> ({ 2, 3, 4, 3, 43, 43, 4, 343, 4, 34, 214, 34, 34, 43, 1 } ) << "\n";

	cout << sum2 (  vector<int>{ 2, 3, 4, 3, 43, 43, 4, 343, 4, 34, 214, 34, 34, 43, 1 } ) << "\n";

	//int a = 67534;

	//double d = 725.63;

	//string s = "404";

	//const char ch = 75;

	////const_cast<char>(ch) = 10;

	////cout << ch <<"\n";

	////reinterpret_cast<int> 

	////dynamic_cast

	////safe_cast

	//double* dd = &d;

	//int* i = &a;

	//void* v = i;

	//v = dd;

	//cout << i << "\n" << v << "\n";

	//cout << *i << "\n" << *((int*)v) 
	//	<< "\n" << *((__int64*)v) 
	//	<< "\n" << *((double*)v) << "\n" << *(static_cast<double*>(v))


	//	<< "\n" << *((float*)v);

	//memory

	// Одиночное исп
	unique_ptr<int> pt;

	{
		int* ii = new int;

		shared_ptr<int> spt(ii);


		shared_ptr<int> q2(new int);



		//delete ii;
	}

	{
		int timer;

		// Одновременное 
		

		timer = 10;
	}
	//timer = 10;

	_CrtDumpMemoryLeaks();

	int i = 10;

	set<int> s;

	int T = 0;
	while (!s.count(i)) // Когда найден период
	{
		++T;
		s.insert(i);
		i = f(i);
	}

	cout << "\n" << T;

	//pair<string, int>
	map<string, int> dir = { {"zzz", 99}, {"asas", 10}, {"www", 3} ,  {"ieoe", 4},  {"zzz", 94324324} };

	map<int, string> rev;

	for (auto it : dir)
	{
		rev[it.second] = it.first;
	}


	





}