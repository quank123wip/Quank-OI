#include <bits/stdc++.h>
using namespace std;

class SegTree
{
  private:
    vector<long long> Original_data;
    struct Node
    {
        long long l, r;
        long long sum;
        long long lazy;
        Node *left = nullptr, *right = nullptr;
        Node()
        {
            lazy = 0;
            l = 0;
            r = 0;
            sum = 0;
            left = nullptr;
            right = nullptr;
        }
        ~Node()
        {
            if (left != nullptr)
                delete left;
            if (right != nullptr)
                delete right;
        }
    };
    Node *root = nullptr;
    inline void built(long long l, long long r, Node *now)
    {
        if (l == r)
            now->sum = Original_data[l];

        now->l = l;
        now->r = r;
        /*更新节点区间*/

        if (l != r)
        {
            now->left = new Node;
            now->right = new Node;
            built(l, (l + r) / 2, now->left);
            built((l + r) / 2 + 1, r, now->right);
        }
        if (now->left != nullptr)
            now->sum += now->left->sum;
        if (now->right != nullptr)
            now->sum += now->right->sum;
    }

    inline long long __query(long long l, long long r, Node *now)
    {
        if (l == now->l && r == now->r)
        {
            if (now->lazy >= 0)
            {
                __update(now->left->l, now->left->r, now->lazy, now->left);
                __update(now->right->l, now->right->r, now->lazy, now->right);
                now->sum += (now->r - now->l + 1) * now->lazy;
                now->lazy = 0;
                return now->sum;
            }
            else
            {
                if (r <= now->left->r)
                {
                    return __query(l,r,now->left);
                    
                }
                if (l >= now->right->l)
                {
                    return __query(l,r,now->right);
                }
                if (l <= now->left->r && r >= now->right->l)
                {
                    return __query(l,now->left->r,now->left)+__query(now->right->l,r,now->right);
                }
            }
        }
    }
    inline void __update(long long l, long long r, long long value, Node *now)
    {
        if (l == now->l && r == now->r)
        {
            now->lazy += value;
            return;
        }
        else
        {
            now->sum += (r - l + 1) * value;
            if (r <= now->left->r)
            {
                __update(l, r, value, now->left);
                return;
            }
            if (l >= now->right->l)
            {
                __update(l, r, value, now->right);
                return;
            }
            if (l <= now->left->r && r >= now->right->l)
            {
                __update(l, now->left->r, value, now->left);
                __update(now->right->l, r, value, now->right);
                return;
            }
        }
    }

  public:
    SegTree(vector<long long> data)
    {
        Original_data = data;
        root = new Node;
        built(0, data.size() - 1, root);
    }
    ~SegTree(void)
    {
        delete root;
    }
    inline long long query(long long l, long long r)
    {
        return __query(l, r, root);
    }
    inline void update(long long l, long long r, long long value)
    {
        __update(l, r, value, root);
        return;
    }
};
long long n,m;
vector<long long>arr;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        long long cache;
        cin>>cache;
        arr.push_back(cache);
    }
    SegTree st(arr);
    for(int i=0;i<m;i++)
    {
        int pd;
        long long a,b,c;
        cin>>pd>>a>>b;
        if(pd==1)
        {
            cin>>c;
            st.update(a,b,c);
        }
        else{
            cout<<st.query(a,b)<<endl;
        }
    }
}