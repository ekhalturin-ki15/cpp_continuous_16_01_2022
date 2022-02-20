#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <regex>
#include <set>
#include <unordered_set>

using namespace std;

vector<int> answer; //[2] [3]  [4] 
vector<vector< pair<int,int> > > descript_answer; //[2] 1-2 [3] 1-2-3  [4]  1-2 3-4


deque<pair <int, int>> v;


int rect(int n)
{
	if (answer[n] != 0) return answer[n]; // Отсечка

	switch (n)
	{
	case 2:
		answer[n] = v[n].first - v[n-1].first;
		answer[n] *= ((answer[n] < 0) ? -1 : 1);
		descript_answer[n] = { { v[n - 1].second, v[n].second } };
		goto end;
	case 3:
		answer[n] = v[n].first - v[n-2].first;
		descript_answer[n] = { { v[n - 1].second, v[n].second },
			{ v[n - 2].second, v[n - 1].second } };
		goto end;
	case 4:
		answer[n] = v[n].first - v[n - 1].first + rect(n - 2);
		descript_answer[n] = { { v[n - 1].second, v[n].second },
			{ v[n - 3].second, v[n - 2].second } };
	end:
		return answer[n];
	}

	int l = v[n].first - v[n - 1].first + rect(n - 2); // сами гвоздики которые использовались Ответ
	int r = v[n].first - v[n - 2].first + rect(n - 3);

	if (l < r)
	{
		answer[n] = l;
		descript_answer[n] = descript_answer[n - 2];
		descript_answer[n].push_back({ v[n - 1].second, v[n].second  });
	}
	else
	{
		answer[n] = r;
		descript_answer[n] = descript_answer[n - 3];
		descript_answer[n].push_back({ v[n - 1].second, v[n].second });
		descript_answer[n].push_back({ v[n - 2].second, v[n - 1].second });
	}
	
	return answer[n];

	//return answer[n] = min(v[n].first - v[n - 1].first + rect(n - 2),
	//	v[n].first - v[n - 2].first + rect(n - 3));
}

int& F() 
{
	int a;
	return a;
}

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


int main()
{
#ifdef _DEBUG
	FILE* IN, * OUT;
	freopen_s(&IN, "input.txt", "r", stdin);
	freopen_s(&OUT, "output.txt", "w", stdout);
#endif

	//int l, r;

	//[l  r)
	//[l m)  F(m)  [m r)
	//

	//  <  == >
	// [l  m1) [m1 m2) [m2 r)
	// F(m1, m2)
	//Сокр в 1.5 раза

	// TTTTFTTTT
	// TTT >  TFT
	// TFT <  TTT
	// TTT == TTT

	// В 3 раза сокр


	set<int> s;

	set< set <int> > l;


	int ii = 1'000'000'000'000;

	vector < vector < int >> vv = 
	{ {29 , 3, 45, 3, 32},{2454 , 3, 45, 3, 32}, {5,33, 223, 54,3}, {43} };


	cout << (F() = 10) << "\n";

	cout << F() << "\n";
	F() = 10;

	sort(vv.begin(), vv.end() );

	cout << vv;


	unordered_set< int  > us;

	vector<int> a = { 3, 5, 43, 2, 5, 2, 454 };

	//make_heap(a.begin(), a.end());
	//pop_heap(a.begin(), a.end());
	//a.push_back(10); push_heap(a.begin(), a.end());
	




	priority_queue<int, vector<int> > q(a.begin(), a.end()); 

	q.top();
	q.pop();
	q.push(6);






	//i = i | (i + 1)
	//i = (i & (i + 1)) - 1)

	/*std::string s = "Some people, when confronted with a problem, think "
		"\"I know, I'll use regular expressions.\" "
		"Now they have two problems.";

	std::regex long_word_regex("(\\w{7,})");
	std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
	std::cout << new_s << '\n';*/
}
