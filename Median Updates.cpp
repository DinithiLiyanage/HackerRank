#include <map>
#include <set>
#include <list>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */


void median(vector<char> s,vector<int> X) {
    multiset<int> arrLeft, arrRight;
    int len = s.size();
    double Median = 0;
    for(int i=0; i<len; i++){
        if(s[i] == 'a'){
            if(arrLeft.empty() && arrRight.empty()){
                arrLeft.insert(X[i]);
            }
            else if(arrLeft.size() > arrRight.size()){
                if(X[i] >= Median){
                    arrRight.insert(X[i]);
                }
                else{
                    arrRight.insert(*(--arrLeft.end()));
                    arrLeft.erase(--arrLeft.end());
                    arrLeft.insert(X[i]);
                }
            }
            else if(arrLeft.size() < arrRight.size()){
                if(X[i] <= Median){
                    arrLeft.insert(X[i]);
                }
                else{
                    arrLeft.insert(*arrRight.begin());
                    arrRight.erase(arrRight.begin());
                    arrRight.insert(X[i]);
                }
            }
            else{
                if(X[i] < Median){
                    arrLeft.insert(X[i]);
                }
                else{
                    arrRight.insert(X[i]);
                }
            }
        }
        else{
            multiset<int>::iterator itLeft = arrLeft.find(X[i]);
            multiset<int>::iterator itRight = arrRight.find(X[i]);
            if(itLeft != arrLeft.end() || itRight != arrRight.end()){
                if(itLeft != arrLeft.end()){
                    arrLeft.erase(itLeft);
                }
                else{
                    arrRight.erase(itRight);
                }
                
                if(!arrLeft.empty() || !arrRight.empty()){
                    if(arrLeft.size() > arrRight.size()){
                          //cout<<"Im here at 106"<<endl;
                          arrRight.insert(*(--arrLeft.end()));
                          arrLeft.erase(--arrLeft.end());
                    }
                    else if(arrLeft.size() < arrRight.size()){
                          arrLeft.insert(*arrRight.begin());
                          arrRight.erase(arrRight.begin());
                    }
                }
                else{
                    cout<<"Wrong!"<<endl;
                    continue;
                }
            }
            else{
               cout<<"Wrong!"<<endl;
               continue;
            }
        }
        
        int lenLeft = arrLeft.size();
        int lenRight = arrRight.size();
        if(lenLeft == lenRight){
              Median = ((long long int)*(--arrLeft.end()) + (long long int)*arrRight.begin())/2.0;
        }
        else if(lenLeft > lenRight){
            Median = *(--arrLeft.end());
        }
        else{
            Median = *arrRight.begin();
        }
        if(fmod(Median, 1.0) == 0){
            cout<<(int)Median<<endl;
        }
        else{
            cout<<fixed<<setprecision(1)<<Median<<endl;
        }
                
    }
}
int main(void){

//Helpers for input and output

	int N;
	cin >> N;
	
	vector<char> s;
    vector<int> X;
	char temp;
    int tempint;
	for(int i = 0; i < N; i++){
		cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
	}
	
	median(s,X);
	return 0;
}
