#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int s;
    int add;
    for (int  t = 1; t <= n; t++)
    {
        add = 0;
        s = 0;
        for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < t; j++)
            {
                
                bool d2= (t-1-i)>=2;
                bool g2= i>=2;
                bool h2=(t-1-j)>=2;
                bool b2= j>=2;
                bool d1 = (t-1-i)>=1;
                bool g1 = i>=1;
                bool h1 = (t-1-j)>=1;
                bool b1 = j>=1;
                if(d1 && h2)
                {
                    add+=1;
                }
                if(g1 && h2)
                {
                    add+=1;
                }
                if(d2 && h1)
                {
                    add+=1;
                }
                if(d2 && b1)
                {
                    add+=1;
                }
                if(g2 && h1);
                {
                    add+=1;
                }
        
                if(g2 && b1)
                {
                    add+=1;
                }
                if(b2 && g1)
                {
                   
                    add+=1;
                }
                if (b2 && d1)
                {
                    add+=1;
                }
                s+= t*t-1-add;
            }  
        }
        cout << s/2 << "\n";
    }
}