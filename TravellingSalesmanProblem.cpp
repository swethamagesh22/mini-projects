#include<iostream>
#include<fstream>
#include<cstdlib>
#include<limits>
#include<vector>

#define CityNum 5

using namespace std;

vector<vector<int> > jour(CityNum,vector<int>(CityNum));
vector<int> path(CityNum);
vector<int> bestpath(CityNum);
int bestcost=numeric_limits<int>::max();
int cost=0;


void backtrack(int t)
{
	int i,j;
	if(t==CityNum-1)   
    {
        if(jour[path[t-1]][path[t]]!=0&&jour[path[t]][0]!=0)
		{
			if(cost+jour[path[t]][0]<bestcost&&jour[path[t]][0]!=0)
			{
				bestcost=cost+jour[path[t]][0];
				for(j=0; j<=CityNum-1; j++)  
					bestpath[j]=path[j];
			}								
		}		
    }	
	else
	{
		for(j=t-1;j<=CityNum-1;j++)
		{
			if(jour[path[t-1]][path[j]]!=0&&cost+jour[path[t-1]][path[j]]<bestcost)
			{
				swap(path[t],path[j]);//加入第i个城市
                cost+=jour[path[t-1]][path[t]];//更新扩展后的路径的代价
				backtrack(t+1);//递归搜索以x[i]为根的后续子树
                cost-=jour[path[t-1]][path[t]];//搜索失败，回溯，回到
                swap(path[t],path[j]);
			}
		}		
	}
}
int ary[10][10],completed[10],n; 
void takeInput()
{
int i,j;
 
cout<<"Enter the number of cities: ";
cin>>n;
 
cout<<"\nEnter the Cost Matrix\n";
 
for(i=0;i < n;i++)
{
cout<<"\nEnter Elements of Row: "<<i+1<<"\n";
 
for( j=0;j < n;j++)
cin>>ary[i][j];
 
completed[i]=0;

}
 
cout<<"\n\nThe cost list is:";
 
for( i=0;i < n;i++)
{
cout<<"\n";
 
for(j=0;j < n;j++)
cout<<"\t"<<ary[i][j];
}
}
 
int least(int c)
{
int i,nc=999;
int min=999,kmin;
 
for(i=0;i < n;i++)
{
if((ary[c][i]!=0)&&(completed[i]==0))
if(ary[c][i]+ary[i][c] < min)
{
min=ary[i][c]+ary[c][i];
kmin=ary[c][i];
nc=i;
}
}
 
if(min!=999)
cost+=kmin;
 
return nc;
}
 
void mincost(int city)
{
int i,ncity;
 
completed[city]=1;
 
cout<<city+1<<"--->";
ncity=least(city);
 
if(ncity==999)
{
ncity=0;
cout<<ncity+1;
cost+=ary[city][ncity];
 
return;
}
 
mincost(ncity);
}
 
int main()
{
takeInput();
 
cout<<"\n\nThe Path is:\n";
mincost(0); 
 
cout<<"\n\nMinimum cost is "<<cost;
 
return 0;
}