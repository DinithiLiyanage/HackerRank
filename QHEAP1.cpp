#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

void heapify(vector<int> arr, int i){
    int smallest = i;
    int L = 2*i+1;
    int R = 2*i+2;
    int len = arr.size();
    if(L<len && arr[smallest] > arr[L]){
        smallest = L;
    }
    if(R<len && arr[smallest] > arr[R]){
        smallest = R;
    }
    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr, smallest);
    }
}

    

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int operation, operand, q_count, pos, len, i;
    set<int> heap;
    cin>>q_count;
        
    while(q_count>0){
        q_count--;
        cin>>operation;
        switch(operation){
            case 1: //insert
               cin>>operand; 
               heap.insert(operand); 
               break; 
            case 2: // delete
                cin>>operand;
                heap.erase(heap.find(operand));
                break;
            case 3: // print min
                cout<<*heap.begin()<<endl;
                break;
            default:
                cout<<"No such operation defined."<<endl;
                return 0;
        }
            
    }
    return 0;
}
