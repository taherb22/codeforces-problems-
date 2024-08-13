#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 2;
string s;
struct node
{
    int opening, closing, ans;
    node()
    {
        opening = 0;
        closing = 0;
        ans = 0;
    }
    node(int opening, int closing, int ans)
    {
        this->opening = opening;
        this->ans = ans;
        this->closing = closing;
    }
};

ll n, q, l, r;
node tree[4 * N];

node mrg(node &x, node &y)
{
    node z  ;
    z.opening = x.opening + y.opening;
    z.closing = x.closing + y.closing;
    z.ans = 2 * min(x.opening, y.closing);
    z.closing -= z.ans / 2;
    z.opening -= z.ans / 2;
    z.ans += x.ans + y.ans;
    return z;
}

void build(int id = 0, int ns = 0, int ne = n - 1)
{
    if (ns == ne)
    { 
        tree[id].opening=(s[ns]=='(') ; 
        tree[id].closing=(s[ns]==')') ; 
        return;
    }
    int l = 2 * id + 1;
    int r = l + 1;
    int md = ns + (ne - ns) / 2;
    build(l, ns, md);
    build(r, md + 1, ne);
    tree[id] = mrg(tree[l], tree[r]);
}

node query(int qs, int qe, int id = 0, int ns = 0, int ne = n - 1)
{
    if (ns > qe || qs > ne)
    {
        return node(); /// infnity
    }
    if (qs <= ns && qe >= ne)
    {
        return tree[id];
    }
    int l = 2 * id + 1;
    int r = l + 1;
    int md = ns + (ne - ns) / 2;
    node ndl = query(qs, qe, l, ns, md);
    node ndr = query(qs, qe, r, md + 1, ne);
    return mrg(ndl, ndr);
}

int main()
{

    cin >> s;
    n = (ll)s.size();
    build();
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        cout << query(--l, --r).ans << endl;
    }
    return 0;
}
