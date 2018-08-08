#include <bits/stdc++.h>
using namespace std;
int n, m, q, u, v, t, cc, cnt1, cnt2, h1 = 1, h2 = 1, h = 1;
long double p;


int cut1[8000000], cut2[8000000];
int now[8000000];
priority_queue<int> answerset;
bool cmp(int a, int b) { return a > b; }
int main()
{
    //freopen("earthworm.in","r",stdin);
    //freopen("earthworm.out","w",stdout);
    cin >> n >> m >> q >> u >> v >> t;
    p = (long double)u / (long double)v;
    for (int i = 1; i <= n; i++)
    {
        int e;
        cin >> e;
        now[i] = e;
    }
    sort(now + 1, now + 1 + n, cmp);
    for (int i = 1; i <= m; i++)

    {
        int nowdo;
        if (h > n)
        {
            if (cut1[h1] > cut2[h2])
                nowdo = cut1[h1++];
            else
                nowdo = cut2[h2++];
        }
        else if (now[h] >= cut1[h1] && now[h] >= cut2[h2])
            nowdo = now[h], ++h;
        else if (cut1[h1] >= cut2[h2] && now[h] <= cut1[h1])
            nowdo = cut1[h1], ++h1;
        else
            nowdo = cut2[h2], ++h2;
        int a, b;
        nowdo += cc;
        a = floor(p * nowdo);
        b = nowdo - a;
        cc += q;
        a -= cc;
        b -= cc;
        cut1[++cnt1] = a;
        cut2[++cnt2] = b;
        if (i % t==0)
            cout << nowdo << " ";
    }
    cout << endl;
    for (int i = h; i <= n; i++)
        answerset.push(now[i]);
    for (int i = h1; i <= cnt1; i++)
        answerset.push(cut1[i]);
    for (int i = h2; i <= cnt2; i++)
        answerset.push(cut2[i]);
    int counts = 1;
    while (!answerset.empty())
    {

        if (counts % t == 0)
            cout << answerset.top() + cc<<" ";
        answerset.pop();
        counts++;
    }
}