/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/


void decode_huff(node * root, string s) {
    string decode = "";
    int len = s.length();
    struct node* temp = root;
    int i = 0;
    while(i<len){
        if(s[i] == '1'){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
        if(temp->left == NULL && temp->right == NULL){
            decode += temp->data;
            temp = root;
        }
        i += 1;
     }
    cout<<decode;
}
