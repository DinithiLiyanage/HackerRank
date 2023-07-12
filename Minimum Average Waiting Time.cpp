#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumAverage' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY customers as parameter.
 */

//The return type was changed to long long int for larger input values.

//Function to sort the 2D vector using first column
bool sortCol(const vector<int>& v1, const vector<int>& v2){
    return v1[0] > v2[0];
}


long long int minimumAverage(vector<vector<int>> &customers) {
    sort(customers.begin(), customers.end(), sortCol);
    int cust_count = customers.size();
    
    //Initiate current time to the first order placement time
    long long int cur_time = customers[cust_count-1][0];
    long long int total_wait = 0;
    
    //Store the orders in the increasing order of the cooking time
    priority_queue<vector<int>> orderQ;
    
    while(!orderQ.empty() || !customers.empty()){
        
        /*
        If the next customer hasn't placed order yet and all previous orders are done, 
        set the current time to the next customer's ordering time
        */
        if(orderQ.empty() && !customers.empty() && customers.back()[0] > cur_time){
            cur_time = customers.back()[0];
        }
        
        /*
        If customers came in while you were preparing an order, once the order is complete, 
        add those new orders to priority queue
        */
        while(!customers.empty() && customers.back()[0] <= cur_time){
            vector<int> new_order = customers.back();
            customers.pop_back();
            new_order[0] *= -1;
            new_order[1] *= -1;
            swap(new_order[0], new_order[1]);
            orderQ.push(new_order);
        }
        
        /*
        Remove the last element from the queue (i.e. the next pizza with the lowest cooking time) and prepare
        */
        vector<int> cur_order = orderQ.top();
        orderQ.pop();
        cur_time += (-1*cur_order[0]);
        total_wait += cur_time - (-1*cur_order[1]);
    }
    return total_wait/cust_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> customers(n);

    for (int i = 0; i < n; i++) {
        customers[i].resize(2);

        string customers_row_temp_temp;
        getline(cin, customers_row_temp_temp);

        vector<string> customers_row_temp = split(rtrim(customers_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int customers_row_item = stoi(customers_row_temp[j]);

            customers[i][j] = customers_row_item;
        }
    }

    long long int result = minimumAverage(customers);

    fout << result << "\n";

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
