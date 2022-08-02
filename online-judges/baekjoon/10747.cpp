#include "bits/stdc++.h"
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	string t;
	cin >> s >> t;

	string censored;
	// Add each character to the censored string
	for (int i = 0; i < s.size(); i++) {
		censored += s[i];
		// If the end of the string is t, we remove t from the end
		if (censored.size() > t.size()
				&& censored.substr(censored.size() - t.size()) == t) {
			censored.resize(censored.size() - t.size());
		}
	}
	cout << censored << endl;
}
