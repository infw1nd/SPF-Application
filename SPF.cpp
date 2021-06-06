// SHORTED PATH FINDER ON MATRIX
// Author : Nguyen Anh Quan
#include <bits/stdc++.h>
#include <windows.h>
#include <cstdlib>
#define ll long long
#define LIM 1000000
using namespace std;
typedef pair<int,int> ii;
queue <ii> q;
int r,c,sx,sy,tx,ty,nb,step;
ii vs[300][300];
ii b[90005];
char M[300][300];
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
void cl() //clear
{
    system("cls");
}
void pr() //print
{
    for (int i=1;i<=r;i++)
    {
        for (int j=1;j<=c;j++) cout<<M[i][j]<<" ";
        cout<<"\n";
    }
}
void init()
{
   for (int i=1;i<=r;i++)
     for (int j=1;j<=c;j++) M[i][j]='\'';
}
void Menu()
{
    cout<<"     _______     ______       _______  \n";
    cout<<"    /       |   |   _  \\     |   ____| \n";
    cout<<"   |   (----`   |  |_)  |    |  |__    \n";
    cout<<"    \\   \\       |   ___/     |   __|   \n";
    cout<<".----)   |      |  |         |  |      \n";
    cout<<"|_______/       | _|         |__|      \n";
    cout<<"   SHORTED PATH FINDER ON MATRIX\n \n";
    cout<<"version : 1.5.21 \nauthor : Nguyen Anh Quan ";
    cout<<"";
    cout<<"\n\n\nPress Enter to start >>";
    cin.get();
    cl();
}
void Input()
{
    cout<<"Enter the index of the Matrix \n";
    cout<<"> number of rows : ";cin>>r;
    cout<<"> number of columns : ";cin>>c;
    init();
    cl();pr();
    cout<<"Position of the Starting Point : ";cin>>sx>>sy;
    M[sx][sy]='S';cl();pr();
    cout<<"Position of the Target : ";cin>>tx>>ty;
    M[tx][ty]='T';cl();pr();
    while (true)
    {
        cout<<"Number of Barriers : ";cin>>nb;
        if (nb<=r*c-2) break;
        else {
        cout<<"wrong input [x] ";
        Sleep(500);
        cl();pr();
        }
    }
    if (nb!=0)
    {
        cout<<"Position of Barriers : \n";
        for (int i=1;i<=nb;i++)
            while (true)
            {
              cin>>b[i].first>>b[i].second;
              if (!((b[i].first==sx&&b[i].second==sy)||(b[i].first==tx&&b[i].second==ty)))
              {
                M[b[i].first][b[i].second]='B';
                cl();pr();
                cout<<"Number of Barriers : "<<nb<<"\n";
                cout<<"Position of Barriers : \n";
                for (int j=1;j<=i;j++) cout<<b[j].first<<" "<<b[j].second<<"\n";
                break;
              }
              cout<<"wrong input [x] ";
              Sleep(500);
              cl();pr();
              cout<<"Number of Barriers : "<<nb<<"\n";
              cout<<"Position of Barriers : \n";
              for (int j=1;j<=i-1;j++) cout<<b[j].first<<" "<<b[j].second<<"\n";
            }
     }
     Sleep(300);cl();
}
void SolveUI()
{
   for (int i=1;i<=2;i++)
   {
       cout<<"Solve";
       for (int j=1;j<=3;j++) {Sleep(250);cout<<".";}
       Sleep(250);cl();
   }
}
void BFS(ii u)
{
   q.push(u);vs[u.first][u.second]=u;
   while (!q.empty())
   {
       ii u=q.front();
       int x=u.first,y=u.second;
       q.pop();
       for (int i=0;i<8;i++)
       {
           int row=x+dx[i],col=y+dy[i];
           if (row>=1&&row<=r&&col>=1&&col<=c)
              if (!vs[row][col].first&&!vs[row][col].second&&M[row][col]!='B')
              {
                 q.push(ii(row,col));
                 vs[row][col].first=x;
                 vs[row][col].second=y;
              }
       }
   }
}
void Trace()
{
     int x=tx,y=ty;
     do
     {
        int xn=vs[x][y].first;
        int yn=vs[x][y].second;
        x=xn;y=yn;
        M[x][y]=char(254);
        step++;
     }
     while (!(x==sx&&y==sy));
     M[x][y]='S';
}
void NoRes()
{
    cout<<"No result [!]\n\n";
}
int Result()
{
    BFS(ii(sx,sy));
    if (vs[tx][ty].first!=0&&vs[tx][ty].second!=0) Trace();
    else {NoRes();return 0;}
    cout<<"Successfully Completed [v]";
    Sleep(600);cl();
    cout<<"This is the shortest path from S to T on a "<<r<<"x"<<c<<" matrix\n";
    pr();
    cout<<"Number of steps : "<<step<<"\n\n";
    return 1;
}
int main()
{
    Menu();
    Input();
    SolveUI();
    Result();
    system("pause");
    return 0;
}
