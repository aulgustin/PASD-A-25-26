#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int q[20],top=-1,front=-1,rear=-1,a[20][20],vis[20],stack[20];
int del();
void add(int item);
void bfs(int s, int n);
void dfs(int s, int n);
void push(int item);
int pop();

int main()
{
    int n,m,i,j,s,k;
    char sc;

    cout << "Masukkan jumlah simpul yang akan digunakan: "; cin >> n;
    cout << "Masukkan hubungan antar simpul:" << endl; cin >> m;
    for(k=1; k<=m; k++) {
        char ci, cj;
        cin >> ci >> cj;
        i = ci - 'A' + 1;
        j = cj - 'A' + 1;
        a[i][j] = 1;
        a[j][i] = 1;
    }

    cout << "Masukkan simpul awal yang akan dikunjungi: "; cin >> sc;
    s = sc - 'A' + 1;

    // BFS
    for(i=0;i<20;i++) vis[i]=0;
    front=-1; rear=-1;
    cout << "Hasil penelusuran menggunakan BFS:" << endl;
    bfs(s, n);
    cout << endl;

    // DFS
    for(i=0;i<20;i++) vis[i]=0;
    top=-1;
    cout << "Hasil penelusuran menggunakan DFS:" << endl;
    dfs(s, n);
    cout << endl;

    cout << "Jumlah simpul yang berhasil dikunjungi : " << n << endl;

    return 0;
}

void bfs(int s, int n)
{
    int p,i;
    add(s);
    vis[s]=1;
    p=del();
    if(p!=0)
        cout << (char)('A'+p-1) << "  ";
    while(p!=0)
    {
        for(i=1;i<=n;i++)
            if((a[p][i]!=0)&&(vis[i]==0))
            {
                add(i);
                vis[i]=1;
            }
        p=del();
        if(p!=0)
            cout << (char)('A'+p-1) << "  ";
    }
    for(i=1;i<=n;i++)
        if(vis[i]==0)
            bfs(i,n);
}

void dfs(int s, int n)
{
    int i,k;
    push(s);
    vis[s]=1;
    k=pop();
    if(k!=0)
        cout << (char)('A'+k-1) << "  ";
    while(k!=0)
    {
        for(i=1;i<=n;i++)
            if((a[k][i]!=0)&&(vis[i]==0))
            {
                push(i);
                vis[i]=1;
            }
        k=pop();
        if(k!=0)
            cout << (char)('A'+k-1) << "  ";
    }
    for(i=1;i<=n;i++)
        if(vis[i]==0)
            dfs(i,n);
}

void add(int item)
{
    if(rear==19)
        cout << "Antrian Penuh" << endl;
    else if(rear==-1)
    {
        q[++rear]=item;
        front++;
    }
    else
        q[++rear]=item;
}

int del()
{
    int k;
    if((front>rear)||(front==-1))
        return(0);
    else
    {
        k=q[front++];
        return(k);
    }
}

void push(int item)
{
    if(top==19)
        cout << "Stack Overflow" << endl;
    else
        stack[++top]=item;
}

int pop()
{
    int k;
    if(top==-1)
        return(0);
    else
    {
        k=stack[top--];
        return(k);
    }
}