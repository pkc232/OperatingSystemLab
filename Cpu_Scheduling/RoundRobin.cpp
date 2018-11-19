#include <bits/stdc++.h>
using namespace std;

int main(){
	int quant=3,i,x,n;
	cout<<"Enter the no of processes\n";
	cin>>n;

	queue<pair<int,int> > Q;
	for(i=0;i<n;i++)
	{
		cin>>x;
		Q.push(make_pair(i+1,x));
	}

	int c=0,cnt=0,tim=0;
	pair<int,int>  p;

	while(!Q.empty()){
		p=Q.front();Q.pop();
		
		if(p.second<quant)
		{
			cout<<tim<<"--"<<tim+p.second<<":"<<p.first<<endl;
			tim+=p.second;
		}
		else
		{
			cout<<tim<<"--"<<tim+quant<<":"<<p.first<<endl;
			p.second-=quant;
			if(p.second>0)
				Q.push(p);

			tim+=quant;
		}
	}
}