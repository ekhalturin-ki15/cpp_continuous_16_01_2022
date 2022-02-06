#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

#define ALL(x) x.begin(), x.end()


#pragma comment(linker, "/STACK:36777216")


bool cmp( pair <pair<int, int>, int> l, pair <pair<int, int>, int> r)
{
	if (l.first.first != r.first.first) return (l.first.first < r.first.first);
	if (l.first.second != r.first.second) return (l.first.second < r.first.second);
	return (l.second < r.second);

}



bool cmp2(int l, int r)
{
	return l < r;
}

vector<int> color;
vector< pair <pair<int, int>, int>> rib; // 3 == 3     
vector<vector< pair<int, int> >> ss;
vector<vector< int >> ms;

int step;
void dfs(int now)
{
	cout << now << "\n";
	++step;

	color[now] = true;

	for (int i = 0; i < ss[now].size(); ++i)
	{
		int wher = ss[now][i].first;

		//dfs(ss[now][i].first);
		if (color[wher] == false)
			dfs(wher);
	}
}


void main()
{
#ifdef _DEBUG
	FILE* IN, * OUT;
	freopen_s(&IN, "input.txt", "r", stdin);
	freopen_s(&OUT, "output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	ss.resize(n);
	ms.assign(n, vector< int >(n, 999));

	for (int i = 0; i < k; ++i)
	{
		int l, r, len;
		cin >> l >> r >> len;
		//rib.push_back({ {l, r},  len});

		rib.push_back(make_pair(make_pair(l, r), len));
		rib.push_back(make_pair(make_pair(r, l), len));

		ss[l].push_back({ r, len });
		ss[r].push_back({ l, len });

		ms[l][r] = len;
		ms[r][l] = len; // Неориентированный

	}

	//sort(rib.begin(), rib.end());
	sort(ALL(rib));

	int m;
	cin >> m;

	//vector< pair <pair<int, int>, int>>::iterator
	//cmp(rib[0], rib[1]);

	vector<int> v = { 2, 4, 5, 6, 6, 7, 8, 9, 10, 11 };

	lower_bound(ALL(v), m, cmp2);

	lower_bound(ALL(rib), make_pair(make_pair(m, -1), 0));

	for (auto it = lower_bound(ALL(rib), make_pair(make_pair(m, -1), 0));
		it != rib.end(); ++it)
	{
		if (it->first.first != m) break; // Боимся разыменовать end

		cout << it->first.first << " " << it->first.second << "\n";
	}
	//shuffle



	for (int i = 0; i < n; ++i)
	{
		cout << i << " : ";
		for (int j = 0; j < ss[i].size(); ++j)
		{
			cout << ss[i][j].first << " ";
		}
		cout << "\n";
	}


	cout << "\t";
	for (int i = 0; i < n; ++i)
	{
		cout << i << "\t";
	}
	cout << "\n";
	for (int i = 0; i < n; ++i)
	{
		cout << i << "\t";
		for (int j = 0; j < n; ++j)
		{
			cout << ms[i][j] << "\t";


		}
		cout << "\n";
	}


	cout << "--- через рекурсию ----\n";
	color.resize(n);
	dfs(m);
	cout << "--- через стек dfs----\n";
	{
		stack<int> qq;
		qq.push(m);
		color.assign(n, 0);
		color[m] = true;

		while (!qq.empty())
		{
			int now = qq.top();

			cout << now << "\n";
			qq.pop();

			for (int i = ss[now].size() - 1; i >= 0; --i)
			{
				int wher = ss[now][i].first;

				//dfs(ss[now][i].first);
				if (color[wher] == false)
				{
					qq.push(wher);
					color[wher] = true;
				}
			}

		}
	}

	cout << "--- через очередь----\n";
	{
		queue<int> q;
		q.push(m);
		color.assign(n, 0);
		color[m] = true;

		while (!q.empty())
		{
			int now = q.front();

			cout << now << "\n";
			q.pop();

			for (int i = 0; i < ss[now].size(); ++i)
			{
				int wher = ss[now][i].first;

				//dfs(ss[now][i].first);
				if (color[wher] == false)
				{
					q.push(wher);
					color[wher] = true;
				}
			}

		}
	}


	string s;
	vector< vector < int >> _map_buf;
	vector< vector < int >> _map;



	pair <int, int> start, finish;

	int x, y = 0;
	while (cin >> s)
	{
		vector < int > buf;
		for (x =0; x < s.size(); ++x)
		{
			auto it = s[x];
			buf.push_back(it == '#');
			if (it == 'S')
				start = { x,y };
			if (it == 'F')
				finish = { x,y };

		}

		_map_buf.push_back(buf);
		++y;
	}

	_map.assign(x, vector<int>(y));
	vector<vector<int>> dis(x, vector<int>(y, -1));
	for (x = 0; x < _map_buf[0].size(); ++x)
	{
		for (y = 0; y < _map_buf.size(); ++y)
		{
			_map[x][y] = _map_buf[y][x];
		}
	}



	cout << "--- Выход из лабиринта----\n";
	cout << "--- через очередь----\n";



	vector<pair<int, int>>  WASD{ {0, -1}, {-1, 0}, {0,1}, {1,0} };

	
		queue< pair< int , int> > q;
		q.push( start);

		int start_dis = 5;

		dis[start.first][start.second] = start_dis; // Растояния

		while (!q.empty())
		{
			int now_x = q.front().first;
			int now_y = q.front().second;

			q.pop();

			for (auto it : WASD)
			{
				x = now_x + it.first;
				y = now_y + it.second;

				if (_map[x][y]) continue;

				if (dis[x][y] == -1)
				{
					q.push({ x,y });
					dis[x][y] = dis[now_x][now_y] + 1;
				}
			}
				

		}

		vector <vector<int>> ans(dis.size(), vector<int>(dis[0].size()));
		// 1 ^   2 <   3 V    4 >

		int len_wher = dis[finish.first][finish.second];

		int now_x = finish.first;
		int now_y = finish.second;

		while (len_wher != start_dis)
		{
			for (int i = 0; i < 4; ++i)
			{
				auto it = WASD[i];
				x = now_x + it.first;
				y = now_y + it.second;

				if (_map[x][y]) continue;

				if (dis[x][y] == len_wher - 1)
				{
					now_x = x;
					now_y = y;
					ans[now_x][now_y] = i + 1;
					len_wher = dis[x][y];


					break;
				}
			}




		}



		cout << "\n";
		for (int i = 0; i < dis[0].size(); ++i)
		{
			for (int j = 0; j < dis.size(); ++j)
			{
				cout << dis[j][i] << "\t";


			}
			cout << "\n";
		}
	

		cout << "\n";
		for (int i = 0; i < dis[0].size(); ++i)
		{
			for (int j = 0; j < dis.size(); ++j)
			{
				switch (ans[j][i])
				{
				case 1: 
					cout << "V"; break;
				case 2:
					cout << ">"; break;
				case 3:
					cout << "^"; break;
				case 4:
					cout << "<"; break;
				default:
					cout << (_map[j][i]) ? "#" : ".";
				}
				//cout << ans[j][i] << "\t";


			}
			cout << "\n";
		}


		//Алг Флойда
		for (int k = 0; k < n; ++k) //Посредник
		{
			for (int l = 0; l < n; ++l)
			{
				for (int r = 0; r < n; ++r) // Неориентированый
				{
					if (l == r) continue;
					if (ms[l][r] > ms[l][k] + ms[k][r])
					{
						ms[l][r] = ms[l][k] + ms[k][r];
					}
				}
			}

		}

		cout << "\n";
		for (int i = 0; i < n; ++i)
		{
			cout << i << "\t";
			for (int j = 0; j < n; ++j)
			{
				cout << ms[i][j] << "\t";


			}
			cout << "\n";
		}



}
