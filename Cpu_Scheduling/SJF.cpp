#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,i,j;

	cout<<"Enter the no of processes\n";
	cin>>n;

	vector<pair<int,int> >tim;
	int x;
	for(i=0;i<n;i++)
		{
			cin>>x;
			tim.push_back(make_pair(x,i+1));
		}
		sort(tim.begin(),tim.end());
	int t=0;
	for(i=0;i<n;i++){
		cout<<tim[i].second<<" :"<<t<<" "<<t+tim[i].first<<endl;
		t+=tim[i].first;
	}

}