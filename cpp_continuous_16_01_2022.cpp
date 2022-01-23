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

int main()
{	
#ifdef _DEBUG
	FILE* IN, * OUT;
	freopen_s(&IN, "input.txt", "r", stdin);
	freopen_s(&OUT, "output.txt", "w", stdout);
#endif

	int n; cin >> n;

	vector<int> v(n);



	for (int i = 1, j = 1; j < n; ++i, j *= i) // O(log (n))
	{
		cout << "1";
	}

	//O(  n! )
	// O(log (n))


	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		auto it = (*iter);
	}


	for (const auto& it : v) // for - range based
	{
		cout << it;
	}

	// f_it   ->
	// b_it   <->
	// r_it   +x  -x
	

	

}