#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main() {
	fast;
	long long N, M;
	cin >> N >> M;
	vector<long long> Tree;
	long long a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		Tree.push_back(a);
	}
	long long min=1;
	long long max = *max_element(Tree.begin(), Tree.end());
	long long mid;
	long long search=0;
	while (min <= max) {
		mid = (min + max) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (Tree[i] - mid >= 0) sum += Tree[i] - mid;
			else continue;
		}
		if (sum < M) max = mid - 1;
		else {
			min = mid + 1;
			if(search<mid) search = mid;
		}
	}
	cout << search;
}