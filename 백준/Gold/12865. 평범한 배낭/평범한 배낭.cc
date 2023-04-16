#include <iostream>

int n,k;
using namespace std;

typedef struct node
{
    int w;
    int v;
    int r=0;
}node;

int max_value=0;
node h[102];
node m[102][100002];
node g[100002];

void sorting()
{
    node temp;
     for(int i=n-1; i>0; i--)
     {
        for(int j=0; j<i; j++)
        {

        if(h[j].w>h[j+1].w)
            {
                temp = h[j];
                h[j] = h[j+1];
                h[j+1] = temp;
            }
        }
     }
     for(int i=0; i<n; i++)
     {
         g[h[i].w].r=i;
     }

}

int main()
{

    int a,b;
    cin>>n>>k;
     for(int i=0;i<n;i++)
     {
         cin>>a>>b;
         h[i].w=a;
         h[i].v=b;
     }
     sorting();
    for(int i=h[0].w;i<=k;i++)
    {
        if(m[0][i].v<h[0].v)
            m[0][i].v=h[0].v;
        max_value=max(max_value,m[0][i].v);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j>=h[i].w&&m[i-1][j-h[i].w].w+h[i].w<=k&&m[i-1][j-h[i].w].v+h[i].v>m[i-1][j].v)
            {
                m[i][j].v = m[i-1][j-h[i].w].v+h[i].v;
            }
            else
                m[i][j].v=m[i-1][j].v;
            m[i][j].w=j;
            max_value=max(max_value,m[i][j].v);
        }

    }
    cout<<max_value;
}
