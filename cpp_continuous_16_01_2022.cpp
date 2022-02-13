#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
		answer[4] = v[4].first - v[3].first + rect(2);
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

	//return answer[n] = min(v[n].first - v[n - 1].first + rect(n - 2),
	//	v[n].first - v[n - 2].first + rect(n - 3));
}



int main()
{

#ifdef _DEBUG
	FILE* IN, * OUT;
	freopen_s(&IN, "input.txt", "r", stdin);
	freopen_s(&OUT, "output.txt", "w", stdout);
#endif



	int n;
	cin >> n;
	v.resize(n);
	answer.resize(n + 1);

	int i = 0;
	for (auto& it : v)
	{
		cin >> it.first;
		it.second = i++;
	}

	sort(v.begin(), v.end());
	v.push_front({ 0, -1 });


	cout << rect(n);


	return 0;





	answer[2] = v[2] - v[1];

	// Условие ? Если верно : Если ложь;

	answer[2] *= ((answer[2] < 0) ? -1 : 1);
	answer[3] = v[3] - v[1];
	answer[4] = v[4] - v[3] + answer[2];

	for (int i = 5; i <= n; ++i)// Мин Макс
	{
		answer[i] = min(v[i] - v[i - 1] + answer[i - 2], v[i] - v[i - 1] + v[i - 1] - v[i - 2] + answer[i - 3]);
	}


	cout << answer[n];

}
