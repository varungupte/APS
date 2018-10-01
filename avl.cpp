#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long int data;
    struct node *left,*right;
    long long int h;
    long long int n;
};
long long int xsmall(struct node* ,long long int b);
long long int cou=0,va;
long long int number_elements(struct node* NN);
long long int balfac(struct node *NN);
void inorder(struct node *NN);
struct node* insert(struct node *NN,long long int x);
struct node* del(struct node *NN,long long int x);
struct node* rotateright(struct node *x);
struct node* rotateleft(struct node *x);
long long int height(struct node *NN);
void search(struct node *NN,long long int b)
{
    if(NN!=NULL)
    {
        if(NN->data==b)
        {
            cout<<"1"<<endl;
        }
        else if(NN->data>b)
        {
            search(NN->left,b);
        }
        else if(NN->data<b)
        {
            search(NN->right,b);
        }
    }
    else
    {
        cout<<"0"<<endl;
    }
    
}
void inorder(struct node *NN)
{
    if(NN!=NULL)
    {
        inorder(NN->left);
        cout<<NN->data<<" "<<NN->n<<endl;
        inorder(NN->right);
    }
}
struct node* insert(struct node *NN,long long int x)
{
    if(NN==NULL)
    {
        NN=(struct node*)malloc(sizeof(struct node));
        NN->left=NULL;
        NN->right=NULL;
        NN->data=x;
        //NN->n=1;     
    }
    else
       {if(x>(NN->data))      
        {
            NN->right=insert(NN->right,x);
            if(balfac(NN)==-2)
                if(x>NN->right->data)
                    NN=rotateleft(NN);
                else
                    {
                        NN->right=rotateright(NN->right);
                        NN=rotateleft(NN);
                    }
        }
        else
            if(x<NN->data)
            {
                NN->left=insert(NN->left,x);
                if(balfac(NN)==2)
                    if(x < NN->left->data)
                        NN=rotateright(NN);
                    else
                       {NN->left=rotateleft(NN->left);
                       NN=rotateright(NN);}
            }}
    NN->h=height(NN);
    NN->n=number_elements(NN);
    //NN->n=number_elements(NN->left)+number_elements(NN->right)+1;
        return(NN);
}
 
struct node* del(struct node *NN,long long int x)
{
    struct node *p;
    if(NN==NULL)
    {
        return NULL;
    }
    else
        if(x>NN->data)    
        {
            NN->right=del(NN->right,x);
            if(balfac(NN)==2)
                if(balfac(NN->left)>=0)
                    NN=rotateright(NN);
                else
                  {NN->left=rotateleft(NN->left);
                       NN=rotateright(NN);}
        }
        else
            if(x<NN->data)
            {
                NN->left=del(NN->left,x);
                if(balfac(NN)==-2)   
                    if(balfac(NN->right)<=0)
                        NN=rotateleft(NN);
                    else
                        {NN->right=rotateright(NN->right);
                    NN=rotateleft(NN);}
            }
            else
            {
               
                if(NN->right!=NULL)
                {   
                    p=NN->right;
                    while(p->left!= NULL)
                        p=p->left;
                    NN->data=p->data;
                    NN->right=del(NN->right,p->data);
                    
                    if(balfac(NN)==2)
                        if(balfac(NN->left)>=0)
                            NN=rotateright(NN);
                        else
                          {NN->left=rotateleft(NN->left);
                       NN=rotateright(NN);}
                }
                else
                    return(NN->left);
            }
    NN->h=height(NN);
    NN->n=number_elements(NN);
    //NN->n=number_elements(NN->left)+number_elements(NN->right)+1;
    return(NN);
}
 
long long int height(struct node *NN)
{
    long long int lh,rh;
    if(NN==NULL)
        return(0);
    
    lh=(NN->left==NULL)?0:1+(NN->left->h);
    rh=(NN->right==NULL)?0:1+(NN->right->h);
    if(lh>rh)
        return(lh);
    return(rh);
}
 
struct node* rotateright(struct node *x)
{
    struct node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->h=height(x);
    x->n=number_elements(x);
    y->h=height(y);
    y->n=number_elements(y);
    return(y);
}
 
struct node * rotateleft(struct node *x)
{
    struct node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->h=height(x);
    x->n=number_elements(x);
    y->h=height(y);
     y->n=number_elements(y);
    return(y);
}

long long int balfac(struct node *NN)
{
    long long int lh,rh;
    if(NN==NULL)
        return(0);
    lh=(NN->left==NULL)?0:1+(NN->left->h);
    rh=(NN->right==NULL)?0:1+(NN->right->h);
    return(lh-rh);
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct node *root=NULL;
    long long int n,m,a,b;
    cin>>n>>m;
    long long int t=n,val;
    while(t--)
    {
        cin>>val;
        root=insert(root,val);
    }
    long long int p=0;
    while(m--)
    {
        cin>>a>>b;
         switch(a)
        {
            case 1: root=insert(root,b);
                    //cout<<root->data<<endl;
                    break;
            case 2: search(root,b);
                    //cout<<p<<endl;
                    break;
            case 3: 
                    p=xsmall(root,b);
                    cout<<p<<endl;
                    root=del(root,p);
                    cou=0;
                    break;
            case 4: inorder(root);
                    break;     
        }
    }
    return 0;
}
long long int xsmall(struct node* NN,long long int b)
{
    
    long long int n=number_elements(NN->left);
    if((n+1)==b)
        { 
        return NN->data;}
     else if(n+1<b)
     {
       return xsmall(NN->right,b-n-1);

     }  
     else 
       return xsmall(NN->left,b);  
}
long long int number_elements(struct node *NN)
{
    long long int lh,rh;
    if(NN==NULL)
        return(0);
    
    lh=(NN->left==NULL)?0:(NN->left->n);
    rh=(NN->right==NULL)?0:(NN->right->n);
    return (rh+lh+1);
}
// long long int xsmall(struct node* T,long long int b)
// {
    
//     if(T!=NULL)
//     {   
        
//         xsmall(T->left,b);
//         cou=cou+1;
//         if(cou==b)
//         {    va=T->data;
            
//         }
//         xsmall(T->right,b);
//     }
//     return va;
// }
