#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */
struct Node{
    int data;
    struct Node *left, *right;
    int level;
};

Node* createNode(int data, int level){
    Node *node = new Node();
    node->left = node->right = NULL;
    node->data = data;
    node->level = level;
    return node;
}

void swap(Node *root, int level){
    if(root != NULL && root->level == level){
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
        return;
    }
    if(root->left != NULL){
        swap(root->left, level);
    }
    if(root->right != NULL){
        swap(root->right, level);
    }
}

void inorder(Node *root, vector<int> &arr){
    if(root == NULL){
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

int buildTree(vector<vector<int>> indexes, Node *root){
    queue<Node*> q;
    int maxLevel = 1;
    q.push(root);
    for(vector<int> index: indexes){
        Node *current = q.front();
        if(index[0] != -1){
            Node *leftNode = createNode(index[0], (current->level + 1));
            q.push(leftNode);
            //cout<<"leftNode->level"<<leftNode->level<<endl;
            current->left = leftNode;
        }
        if(index[1] != -1){
            Node *rightNode = createNode(index[1], (current->level + 1));
            q.push(rightNode);
            //cout<<"rightNode->level"<<rightNode->level<<endl;
            current->right = rightNode;
        }
        maxLevel = current->level;
        q.pop();
        
    }
    //cout<<"max level"<<maxLevel<<endl;
    return maxLevel;
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    Node *root = createNode(1,1);
    vector<vector<int>> inorder_traversal;
    int maxLevel = buildTree(indexes, root);
    for(int k: queries){
        for(int i=1; i<= maxLevel; i++){
            if(i%k == 0){
                swap(root, i);
            }
        }
        vector<int> k_traversal;
        inorder(root, k_traversal);
        inorder_traversal.push_back(k_traversal);
    }
    return inorder_traversal;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
