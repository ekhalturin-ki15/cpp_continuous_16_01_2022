#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <regex>
#include <set>
#include <map>
#include <unordered_set>
#include <cmath>

using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


#ifdef _DEBUG
	FILE* IN, * OUT;
	freopen_s(&IN, "input.txt", "r", stdin);
	freopen_s(&OUT, "output.txt", "w", stdout);
#endif
	int n, win;
	cin >> n >> win;

	vector<int> v(n);

	for (auto& it : v) cin >> it;

	//O(n * log(n))  Max
	vector<vector<int>> sparse_table(n, vector<int>(ceil(log2(n+1)) ));
	vector<int> my_pow;

	for (int k = 1, j = 0; k < n; k *= 2, ++j)
	{
		my_pow.push_back(k);
		for (int i = 0; i < n; ++i)
		{
			if (j == 0)
				sparse_table[i][j] = v[i];
			else
			{
				if ((i + k / 2) < n)
					sparse_table[i][j] = min(sparse_table[i][j - 1], sparse_table[i + k/2][j - 1]);// j-1 высоты размер группы равен k/2
			}
		}
	}

	// 10^6 * sqrt(10^3) = 10^9


	// 10^6 * log(10^6) = 18*10^6

	//int request; cin >> request;
	for (int i = 0; i < n - win + 1; ++i)
	{
		int l = i;
		int r = l + win;
		int ans = v[l];
		int h = 0;
		h = sparse_table.at(0).size() - 1;
		while (l < r)
		{
			if (l + my_pow[h] <= r)
			{
				ans = min(ans, sparse_table[l][h]);
				l += my_pow[h];
			}
			else
				--h;
		}
		// O (log N)
		cout << ans << "\n";
	}


	//i = i | (i + 1)
	//i = (i & (i + 1)) - 1)

	/*std::string s = "Some people, when confronted with a problem, think "
		"\"I know, I'll use regular expressions.\" "
		"Now they have two problems.";

	std::regex long_word_regex("(\\w{7,})");
	std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
	std::cout << new_s << '\n';*/
}