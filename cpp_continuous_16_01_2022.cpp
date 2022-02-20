#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <regex>
#include <set>
#include <map>
#include <unordered_set>

using namespace std;

vector<int> answer; //[2] [3]  [4] 
vector<vector< pair<int,int> > > descript_answer; //[2] 1-2 [3] 1-2-3  [4]  1-2 3-4

enum Type
{
	sum = 1,
	update = 2
};
/// <summary>
/// 
/// </summary>
/// <returns>
/// 
/// </returns>
template <typename T>
ostream& operator<<(ostream& out, vector<T> v)
{
	for (const auto& it : v)
	{
		out << it << " ";
	}
	out << "\n";
	return out;
}

template <typename T>
ostream& operator<<(ostream& out, deque<T> v)
{
	for (const auto& it : v)
	{
		out << it << " ";
	}
	out << "\n";
	return out;
}

//bool rec(int step)
//{
//	if (step == n)
//	{
//
//	}
//
//	if (rec(step + 1)) return true;
//
//
//	return false;
//}
vector<int> fenvec;
vector<int> v;

void UpdateFenvic(int pos, int new_num)
{
	//pos =		10011011011
	//new_pos = 10011011111
	//new_pos = 10011111111
	//new_pos = 10111111111

	int n = fenvec.size();
	for (int  i = pos; i < n; i |= i + 1 )
	{
		fenvec[i] += new_num;
	}

}

int PrefSum(int pos)
{

	int sum = 0;
	for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
	{
		sum += fenvec[i];
	}
	return sum;
}


int main()
{
#ifdef _DEBUG
	FILE* IN, * OUT;
	freopen_s(&IN, "input.txt", "r", stdin);
	freopen_s(&OUT, "output.txt", "w", stdout);
#endif


	// M*Log(N)
	// M
	int n;
	bool bIsEmpty;


	cin >> n;
	v.resize(n);
	

	for (auto& it : v) 
		cin >> it;

	vector<int> cached = v;

	///for ()
	map<pair<int, int>, int > s;


	// N^2
	for (int l = 0; l < n; ++l)
	{
		int pred = 0;
		for (int r = l; r < n; ++r)
		{
			pred += v[r];
			s[{l, r}] = pred;
		}
	}

	



	vector<int> pref_sum(n + 1);
	int pred = 0;
	for (int r = 1; r <= n; ++r)
	{
		pred += v[r-1];
		pref_sum[r] = pred;
	}

	int m; cin >> m;

	vector<tuple<Type, int, int>> req(m);
	for (int i = 0; i < m; ++i)
	{
		auto& [type, l, r] = req[i];
		int j;
		cin >> j >> l >> r;
		type = static_cast<Type>(j);

	}

	//В лоб
	cout << "----------Brute-------------------\n";
	for (int i = 0; i < m; ++i)
	{
		auto& [type, l, r] = req[i];

		int sum = 0;

		switch (type)
		{
		case Type::sum:
			
			// O(n * m)
			for (int i = l; i <= r; ++i) sum += v[i]; // (O(n))

			cout << sum << "\n";
			break;

		case Type::update:

			v[l] = r;
			cout << "Update\n";
			break;
		}

	}

	cout << "----------Pref-------------------\n";
	v = cached;
	//Префикс суммы
	for (int i = 0; i < m; ++i)
	{
		auto& [type, l, r] = req[i];

		switch (type)
		{
		case Type::sum:
			cout << pref_sum[r + 1] - pref_sum[l] << "\n";
			break;

		case Type::update:

			// O(n * m)
			for (int i = l; i < n; ++i)
				pref_sum[i + 1] +=  r - v[l];// не v[i];
			cout << "Update\n";
			break;
		}
	}

	cout << "----------Sqrt-------------------\n";
	v = cached;
	//Корневая декомпозиция

	int size_group = sqrt(n); // Кол-во эл внутри каждой группы
	vector<int> sqrt_v(n / size_group);

	for (int i = 0; i < sqrt_v.size() * size_group; ++i)
	{
		sqrt_v[i / size_group] += v[i];
	}


	for (int i = 0; i < m; ++i)
	{
		auto& [type, l, r] = req[i];

		int sum = 0;
		switch (type)
		{
		case Type::sum:
			
			// O(sqrt(N) + sqrt(N) * m = O(sqrt(N) * m) против O(N * m)

			for (int i = l; 
				i < min(r + 1, 
					((l / size_group) + 1) * size_group);
				++i)
				sum += v[i];

			int group;
			for (group = ((l / size_group) + 1); group< (r / size_group); ++group)
				sum += sqrt_v[group];

			for (int i = group * size_group; i <= r; ++i)
				sum += v[i];

			cout << sum << "\n";
			break;

		case Type::update:

			// O(n * m)
			
			sqrt_v[l / size_group] += r - v[l];
			v[l] = r;

			cout << "Update\n";
			break;
		}
	}


	cout << "----------Fenvic-------------------\n";
	v = cached;
	//Дерево Фенвика

	fenvec.resize(n);

	for (int i = 0; i < n; ++i)
	{
		UpdateFenvic(i, v[i]);
	}

	for (int i = 0; i < m; ++i)
	{
		auto& [type, l, r] = req[i];

		switch (type)
		{
		case Type::sum:
			// O(logn * m)
			cout << PrefSum(r) - PrefSum(l - 1) << "\n";
			break;

		case Type::update:

			// O(logn * m)
			UpdateFenvic(l, r - v[l]);
			v[l] = r;
			cout << "Update\n";
			break;
		}
	}




	// 2 0		0 0 0 0 0 0 0 0 0 0 0
	// 2 0		-1000
	// -1000	0 0 0 0 0 0 0 0 0 0 0 0

	// O(logN)
	// O(log(N))


	// N^2
	///for ()








	//i = i | (i + 1)
	//i = (i & (i + 1)) - 1)

	/*std::string s = "Some people, when confronted with a problem, think "
		"\"I know, I'll use regular expressions.\" "
		"Now they have two problems.";

	std::regex long_word_regex("(\\w{7,})");
	std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
	std::cout << new_s << '\n';*/
}
