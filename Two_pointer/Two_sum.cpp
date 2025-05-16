// Pair with Target Sum (easy)
#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> vect1{2,5,9,11};
	int target=6;
	


	//Main code
	vector<int> vect2;
	int j=vect1.size()-1;
	int sum=0;
	int i=0;
	while(i<j){
		sum=vect1[i]+vect1[j];
		if(sum==target){
			vect2.push_back(i);
			vect2.push_back(j);
			break;
		}
		else if (sum>target){
			sum-=vect1[j];
			j--;
		}
		else{
			sum+=vect1[i];
			i++;
		}
	}
	if(vect2.size()==0){
		cout<<"No possible output";
	}
	for(i=0;i<vect2.size();i++){
		cout<<vect2[i]<<" ";
	}
	return 0;
	
}