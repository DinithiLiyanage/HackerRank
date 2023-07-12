#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Function to remove white spaces
vector<string> split(string &txt, char ch)
{
    vector<string> result;
    int len = txt.length();
    //cout<<"len: "<<len<<endl;
    string strs = "";
    for(int i=0; i<len; i++){
        //cout<<"char"<<txt[i]<<endl;
        if(txt[i]!= ' '){
            strs += txt[i];
        }
        else{
            //cout<<"strs"<<strs<<endl;
            result.push_back(strs);
            strs = "";
        }
    }
    result.push_back(strs);
    return result;
}

struct Node{
    int size = 1;
    struct Node *parent = NULL;
};

struct Node *findParent(Node nodes[], int i){
    Node *root = &nodes[i];
    while (root->parent != NULL) {
        root = root->parent;    
    }
    if(root != &nodes[i]){
        nodes[i].parent = root; 
    }
    return root;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string input;
    getline(cin, input);
    vector<string> details = split(input, ' ');
    int n = stoi(details[0]);
    int q = stoi(details[1]);
    
    Node tree[n+1];
    
    string operation;
    for(int i=0; i<q; i++){
        getline(cin, operation);
        vector<string> query = split(operation, ' ');
        
        if(query[0] == "Q"){
            Node *parent = findParent(tree, stoi(query[1]));
            cout<<parent->size<<endl;
        }
        else{
            //get the 2 communities
            Node *parentA = findParent(tree, stoi(query[1]));
            Node *parentB = findParent(tree, stoi(query[2]));
            if(parentA != parentB){
                parentA -> parent = parentB;
                parentB -> size += parentA ->size;
            }
        }
    }
    return 0;
}
