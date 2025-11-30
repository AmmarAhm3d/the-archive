#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string* a = new string[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	string* t = new string[m], * s = new string[m];
	int* age = new int[m];

	for (int i = 0; i < m; i++)
		cin >> t[i] >> s[i] >> age[i];

	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;

		vector<pair<int, string>> v;

		for (int j = 0; j < m; j++) 
			if (a[i] == t[j])
				v.push_back(make_pair( age[j],s[j] ));
		
		sort(v.begin(), v.end());

		for (auto it = v.begin(); it != v.end(); it++)
			cout << it->second << " " << it->first << endl;
	}
	return 0;

}