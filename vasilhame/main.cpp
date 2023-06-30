#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pxy;
void imprimirCaminho(map<pxy, pxy> mp, pxy u)
{
	if (u.first == 0 && u.second == 0) {
		cout << 0 << " " << 0 << endl;
		return;
	}
	imprimirCaminho(mp, mp[u]);
	cout << u.first << " " << u.second << endl;
}
void BFS(int jarro1, int jarro2, int alvo)
{
	map<pxy, int> m;
	bool podeResolver = false;
	map<pxy, pxy> mp;

	queue<pxy> q;

	q.push(make_pair(0, 0));
	while (!q.empty()) {

		auto u = q.front();
		// cout<<u.first<<" "<<u.second<<endl;
		q.pop();
		if (m[u] == 1)
			continue;

		if ((u.first > jarro1 || u.second > jarro2 || u.first < 0
			|| u.second < 0))
			continue;
		// cout<<u.first<<" "<<u.second<<endl;

		m[{ u.first, u.second }] = 1;

		if (u.first == alvo) {
			podeResolver = true;

			imprimirCaminho(mp, u);
			if (u.first == alvo) {
				if (u.second != 0)
					cout << u.first << " " << 0 << endl;
			}
			else {
				if (u.first != 0)
					cout << 0 << " " << u.second << endl;
			}
			return;
		}
		// encher jarro 2
		if (m[{ u.first, jarro2 }] != 1) {
			q.push({ u.first, jarro2 });
			mp[{ u.first, jarro2 }] = u;
		}

		// encher jarro 1
		if (m[{ jarro1, u.second }] != 1) {
			q.push({ jarro1, u.second });
			mp[{ jarro1, u.second }] = u;
		}

		// encher jarro 2 usando jarro 1
		int d = jarro2 - u.second;
		if (u.first >= d) {
			int c = u.first - d;
			if (m[{ c, jarro2 }] != 1) {
				q.push({ c, jarro2 });
				mp[{ c, jarro2 }] = u;
			}
		}
		else {
			int c = u.first + u.second;
			if (m[{ 0, c }] != 1) {
				q.push({ 0, c });
				mp[{ 0, c }] = u;
			}
		}
		// encher jarro 1 usando jarro 2
		d = jarro1 - u.first;
		if (u.second >= d) {
			int c = u.second - d;
			if (m[{ jarro1, c }] != 1) {
				q.push({ jarro1, c });
				mp[{ jarro1, c }] = u;
			}
		}
		else {
			int c = u.first + u.second;
			if (m[{ c, 0 }] != 1) {
				q.push({ c, 0 });
				mp[{ c, 0 }] = u;
			}
		}

		// esvaziar jarro 2
		if (m[{ u.first, 0 }] != 1) {
			q.push({ u.first, 0 });
			mp[{ u.first, 0 }] = u;
		}

		// esvaziar jarro 1
		if (m[{ 0, u.second }] != 1) {
			q.push({ 0, u.second });
			mp[{ 0, u.second }] = u;
		}
	}
	if (!podeResolver)
		cout << "Sem solucao";
}

int main()
{
	int jarro1 = 4, jarro2 = 3, alvo = 2;
	cout << "Caminho do estado inicial para o estado final ::\n";
	BFS(jarro1, jarro2, alvo);
	return 0;
}
