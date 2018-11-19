#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,i,j;

	cout<<"Enter the no of processes\n";
	cin>>n;

	int tim[n];
	for(i=0;i<n;i++)
		cin>>tim[i];

	int t=0;
	for(i=0;i<n;i++){
		cout<<i+1<<" :"<<t<<" "<<t+tim[i]<<endl;
		t+=tim[i];
	}

}