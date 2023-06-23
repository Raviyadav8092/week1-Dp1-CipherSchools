#include <iostream>
#include <stack>
using namespace std;

int minSwaps(string s) {
    string unpurified;
    for(int i =0;i<s.length();i++){
        if(s[i] == '[') unpurified.push_back(s[i]);
        else{
            if(!unpurified.empty() && unpurified.back() =='['){
                unpurified.pop_back();
            }
            else unpurified.push_back(s[i]);
        }
    }
    cout<<unpurified<<endl;
    int open = unpurified.size()/2;
    return ((open+1)/2);
}

int main() {
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    cout << minSwaps(s) << endl;
    return 0;
}