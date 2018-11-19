#include <bits/stdc++.h>
using namespace std;
struct process{
	int ind;
	int arr;
	int burstrem;
};
struct mycomp{
bool operator()(process &p1,process &p2){
return p1.burstrem>p2.burstrem;
}
};

int main(){
	int n,i,j;

	cout<<"Enter the no of processes\n";
	cin>>n;
	process p[n];
	int x,y;
	priority_queue<process,vector<process>,mycomp> pq;
	int mx=0;
	for(i=0;i<n;i++)
		{
			cin>>x>>y;
			p[i].ind=i+1;
			p[i].arr=x;
			p[i].burstrem=y;
			mx+=p[i].burstrem;
		}

	i=0;
	int cnt=0;
	process pt;
	while(cnt<=mx){
		if(p[i].arr==cnt){
			pq.push(p[i]);
			i++;
		}
		if(!pq.empty()){
		pt=pq.top();
		pq.pop();

		cout<<cnt<<" P"<<pt.ind<<" "<<pt.burstrem<<endl;
		//cnt++;
		pt.burstrem--;
		if(pt.burstrem)
			pq.push(pt);
	}
	else
		cout<<cnt<<" Idle\n";
	cnt++;
}
}