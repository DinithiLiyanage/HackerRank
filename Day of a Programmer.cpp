#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    vector<int> Days = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day_count = 0;
    if(year <= 1917){
       if(year % 4 == 0){
           Days[2] = 29;
       }
       else{
           Days[2] = 28;
       }
    }
    else if(year == 1918){
        Days[2] = 15;
    }
    else{
        if(year%400 == 0 || (year%4 ==0 && year%100 != 0)){
            Days[2] = 29;
        }
        else{
            Days[2] = 28;
        }
    }
    int i=1;
    while(i< 13){
       if(day_count + Days[i] <= 256){
           day_count += Days[i];
           i++;
       } 
       else{
           break;
       }
    }
    char date[25];
    int days = 256 - day_count;
    sprintf(date, "%02d.%02d.%04d", days, i, year);
    return date;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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
