#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int n;
int camein[maxn];
struct node
{
    int head, tail;
    vector<int> son;
} point[maxn];
vector<int> sons[30];
vector<pair<int, int>> path;
inline void build_edge(int from, int to)
{
    point[from].son.push_back(to);
}
inline void reset(void)
{
    memset(camein, 0, sizeof(camein));
    for (int i = 0; i < 30; i++)
        sons[i].clear();
    path.clear();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string cache;
        cin >> cache;
        point[i].head = cache[0];
        point[i].tail = cache[cache.length() - 1];
        point[i].son.clear();
        sons[point[i].head - 'a'].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sons[point[i].tail - 'a'].size(); j++)
        {
            build_edge(i, sons[point[i].tail - 'a'][j]);
            camein[sons[point[i].tail - 'a'][j]]++;
        }
    }
}
inline void solve(void)
{
    bool in, out;
    reset();
    for (int i = 0; i < n; i++)
    {
        if(camein[i]==0&&point[i].son.size()==0)
        {
            cout << "The door cannot be opened." << endl;
            return;
        }
        if (camein[i] != point[i].son.size())
        {
            if (in == false && camein[i] == point[i].son.size() - 1)
                in = true;
            else if (out == false && camein[i] - 1 == point[i].son.size())
                out = true;
            else
            {
                cout << "The door cannot be opened." << endl;
                return;
            }
        }
    }
    if(in==out)cout << "Ordering is possible." << endl;
    else cout << "The door cannot be opened." << endl;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        solve();
    return 0;
}