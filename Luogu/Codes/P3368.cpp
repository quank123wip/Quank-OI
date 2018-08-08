// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
#define Lowbit(x) (x & -x)
const int maxn = 500000 + 10;
int n,m;
//#define Debug
typedef long long LL;
LL origin[maxn], input[maxn];
int bitree[maxn];
inline void update(int pos ,int val)
{
    int i=pos;
    while(pos<=n)
    {
        bitree[pos]+=val;
        pos+=Lowbit(pos);
    }
}
inline LL get_prefix(int pos)
{
    LL ans=0;
    while(pos)
    {
        ans+=bitree[pos];
        pos-=Lowbit(pos);
    }
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>origin[i];
    for(int i=2;i<=n;i++)input[i]=origin[i]-origin[i-1];
    for(int i=1;i<=n;i++)
    {
        update(i,input[i]);
    }
    while(m--)
    {
        int pd;
        cin>>pd;
        if(pd==1)
        {
            int a,b,c;
            cin>>a>>b>>c;
            update(a,c);
            update(b+1,-c);
        }
        else
        {
            int pos;
            cin>>pos;
            cout<<get_prefix(pos)<<endl;
        }
    }
}