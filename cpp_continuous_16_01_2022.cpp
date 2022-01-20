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

double f(double x)
{
	return x * 126 + 342.5f + PI;
}


__int64 GCD(__int64 a, __int64 b)
{
	//while (a && b)
	// a == 0 - > false
	// 
	// 0000000000000000 - > 0
	// 0000000000000001 - > 1
	// 1111111111111111 -> 
	// 1000000000000000 -> -(011111111111111)+1 -> -(011111111111110) -2^64 + 1 
	// 1111111111111111 -> -1

	while ((a != 0) && (b != 0))
	{
		if (a > b) a = a % b;
		else b = b % a;
	}
	return a + b;
}

int main()
{
	std::set<int> s;

	map<int, int> m; // O(log2 N)      log2 (2^100) = 100  (10^33)
	int a[1000];


	//FILE* IN, * OUT;
	//freopen_s(&IN, "input.txt", "r", stdin);
	//freopen_s(&OUT, "output.txt", "w", stdout);

	ifstream cin("input.txt");
	ofstream cout("output.txt");

	//unordered_map<int, int> um; // O(1) ~ 100

	vector< string > st;
	queue<int> q;
	priority_queue<int> pq;
	list < vector<int>> l;
	forward_list< int > fl;
	bitset<100> b;

	__int64 L, R, N;

	cin >> N;

	cin >> L >> R;

	// [L R)

	__int64 C;

	// 1 .. 5			6..10
	// 
	// 	   6 7 8 9 10
	// 
	// 	   [6			7			8) 9 10
	//           < 6
	//           <=5


	while (R - L > 1)
	{
		C = (R + L) / 2;

		C = L + (R - L) / 2;

		if (N > C) // [L  C   R)
			//		  [   L   R)
		{
			L = C;
		}
		else
		{
			R = C;
		}

		cout << L << " " << R << "\n";
		//cout << L << " " << R << endl;// "\n";
	}

	// A = 5^3 * 2^ 3
	// B = 5 * 2^5
	int A = 1000; int B = 160;

	// 2 4 5 8 32 125 

	{
		vector<int> v = { 4, 5, 2, 32, 8, 125 };

		for (int i = 0; i < v.size(); ++i)
			for (int j = 0; j < v.size() - 1; ++j)
				if (v[j] > v[j + 1])
					v[j] ^= v[j + 1] ^= v[j] ^= v[j + 1];




		// O(n * log n)  
		//  std::sort

		int l = 0;
		int r = v.size(); // [l .. r)


		{
			while (r - l > 1)
			{
				int c = (r - l) / 2 + l;

				if ((A % v[c] == 0) && (B % v[c] == 0))
				{
					l = c;   // [l  c  r) ->  [0   l..r)
					// [l c r) <-   [l..r  0)

					// [l r)
				}
				else
				{
					r = c;
				}
			}

		}

		cout << "\n" << v[l];



		l = -1;

		// 0 1 2 3 4 5
		r = v.size() - 1; // (l  r]


		{
			while (r - l > 1)
			{


				int c = (r + l) / 2;


				if ((A % v[c + 1] != 0) || (B % v[c + 1] != 0))
				{
					r = c;
				}
				else
				{
					l = c;
				}
			}

		}


		cout << "\n" << v[r];

	}



	{
		vector<int> v;

		//srand(  time(0)  );
		std::mt19937 gen(time(0));
		int N;
		cin >> N;

		//v.resize(N);

		for (int i = 0; i < N; ++i)
		{
			int r = gen();
			v.push_back(r % 1000);
		}


		// 142321 / 1000 = 142
		// 142321 % 1000 = 142321 - (142321/1000) * 1000 = 142321 - 142*1000 = 321;



		sort(v.begin(), v.end());

	}



	{
		double pi = PI;

		//int y = f(x);



		cout << "\n" << pi;


		double l = -1e6;
		double r = 1e6;

		int it = 100;

		double m = 3.49;

		for (int i = 0; i < it; ++i)
		{
			m = (r + l) / 2;

			if (f(m) < 0)
			{
				l = m;
			}
			else
			{
				r = m;
			}
		}


		cout << "\n" << m << "\n";


		{
			__int64 a, b;

			cin >> a >> b;


			cout << GCD(600, 9);
		}


		int a = -1; // 1111111111111111
		//cout<<"-" << 00000000000000+1 


		--a; // 1111111111111110
		--a; // 1111111111111101
		--a; // 1111111111111100
		--a;
		--a;
		--a;



	}



	{
		int n;
		//cin >> n;
		n = 100;
		vector<int> v(n);



		//for (auto it = v.begin(); it != v.end(); ++it)

		mt19937 gen(time(0));


		for (auto& it : v)
		{
			it = gen() % n;
		}

		v = { 1, 2, 3 , 8,  14, 14, 14, 15, 15, 20 };

		sort(v.begin(), v.end());


		//bin_search(v, x);

		{
			vector<int>::iterator it = lower_bound(v.begin(), v.end(), 14); //	>=

			cout << "\n" << *(it - 1) << " " << *(it) << " " << *(it + 1); 
		}

		{
			vector<int>::iterator it = upper_bound(v.begin(), v.end(), 14); //	>

			cout << "\n" << *(it - 1) << " " << *(it) << " " << *(it + 1);
		}




		{
			vector<int>::iterator it = lower_bound(v.begin(), v.end(), 20);  // [l   r)

			int a = *(it - 1);
			int b = *(it);


			//int c = *(it + 1);


			//cout << "\n" << *(it - 1) << " " << *(it) << " " << *(it + 1);
		}

		{
			vector<int>::iterator it = upper_bound(v.begin(), v.end(), 30);

			if (it == v.end()) return 0;


			int a = *(it - 1);

			cout << "\n" << *(it - 1) << " " << *(it) << " " << *(it + 1);
		}
	}
}