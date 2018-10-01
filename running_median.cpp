#include <bits/stdc++.h>
using namespace std;
void buildmax(int p[], int n);
void heapmaxify(int p[], int i, int heapnze);
void buildmin(int p[],int heapnze);
void heapminify(int p[], int i, int heapnze);
void buildmax(int p[], int n) {
        int  h= (n-1)/2;
        for (long long int i=h;i>=0;i--) 
        {
            heapmaxify(p,i,n);
        }
    }
void buildmin(int p[], int n) {
        int g=(n-1)/2;
        for (long long int i=g;i>=0;i--)
        {
            heapminify(p,i,n);
        }
    }
void heapminify(int p[], int i, int n) {
        int left=2*i+1;
        int right=2*i+2;
        int s=i;

        if (left<n&&p[left]<p[s]) 
        {
            s= left;
        }
        if (right<n&&p[right]<p[s]) 
        {
            s= right;
        }

        if (s!=i) 
        {
           
            int t=p[i];
            p[i]=p[s];
            p[s]=t;
            heapminify(p,s,n);
        }
    }    
int main() 
{
        int n;
        cin>>n;
        int a[n],heapmax[n],heapmin[n],minn=0,maxn=0,t=0;
        double  median = 0;
        for (int i=0;i<n;i++) 
        {
            int x;
            cin>>x;
            a[i]=x;
            if (a[i]<median) {
                heapmax[maxn]=a[i];
                maxn=maxn+1;
                // if (heapmax[maxn-1]>heapmax[0]) 
                // {
                //     t= heapmax[maxn-1];
                //     heapmax[maxn-1]=heapmax[0];
                //     heapmax[0]=t;
                // }
            } 
            else 
            {
                heapmin[minn]=a[i];
                minn=minn+1;
                // if (heapmin[minn-1]<heapmin[0]) 
                // {
                //     t= heapmin[minn-1];
                //     heapmin[minn-1]=heapmin[0];
                //     heapmin[0]=t;
                // }
            }
            if(abs(maxn-minn)>1) {
                if (maxn>minn) {
                    t= heapmax[maxn-1];
                    heapmax[maxn-1]=heapmax[0];
                    heapmax[0]=t;
                    heapmin[minn]=heapmax[--maxn];
                    minn++;
                    t=heapmin[minn-1];
                    heapmin[minn-1]=heapmin[0];
                    heapmin[0]=t;
                    buildmax(heapmax,maxn);
                } 
                else 
                {
                    t= heapmin[minn-1];
                    heapmin[minn-1]=heapmin[0];
                    heapmin[0]=t;
                    heapmax[maxn]=heapmin[--minn];
                    maxn++;
                    t= heapmax[maxn-1];
                    heapmax[maxn-1]=heapmax[0];
                    heapmax[0]=t;
                    buildmin(heapmin, minn);
                }
            }
            if (maxn>minn) {
                median=heapmax[0];
                
            } else if(maxn<minn) {
                median=heapmin[0];
            } else {
               median=heapmin[0]+heapmax[0];
               median=median/2;
            }

           printf("%.1lf\n",median);

        }

    }

   

   void heapmaxify(int p[], int i, int n) 
   {
        int left=2*i+1;
        int right=2*i+2;
        int l=i;
        if (left<n&&p[left]>p[l]) {
            l=left;
        }
        if (right<n&&p[right]>p[l]) {
            l=right;
        }
        if (l!=i) {
            
            int t=p[l];
            p[l]=p[i];
            p[i]=t;
            heapmaxify(p,l,n);
        }
    }

    
    

