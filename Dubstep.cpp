/**
 *author:Abu Jafar Shiddik
 *created:05-03-2023(16:59:57)
**/
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int flag = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='W' and s[i+1]=='U' and s[i+2]=='B'){
            i+=2;
            if(!flag)
                cout<<" ";
        }
        else{
            flag = 0;
            cout<<s[i];
        }
    }
    
return 0;
}
// #include <iostream>
// using namespace std;

// int main() {
// 	string s;
// 	int flag=1;
// 	cin>>s;
// 	for(int i=0;i<s.size();i++){
// 	    if(s[i]=='W'&& s[i+1]=='U' && s[i+2]=='B'){
//             cout<<"i = "<<i<<"\n";
// 	        i+=2;
// 	        if(!flag){
// 	            cout<<" ";
// 	        }
// 	        continue;
// 	    }else {
// 	        flag=0;
// 	        cout<<s[i];
// 	    }
// 	}
// 	return 0;
// }