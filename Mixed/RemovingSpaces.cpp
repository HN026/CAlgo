#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
#include<string>

using namespace std;

string RemoveSpaces(string s, int n){
    string newstring = "";
    int j = 0;

    for(int i = 0; i<n; i++){
        if(s[i]==' ' && s[i-1]==' '){
            continue;
        }
        else {
            newstring += s[i];
            j += 1;
        }
    }
    if(newstring[--j]==' '){
        newstring.pop_back();
    }
    return newstring;
}


string ReverseWords(string s, int n){
    string k = RemoveSpaces(s,n);
    
    string newstring = "";
    for(int i = 0; i<k.size(); i++){
       newstring += k[k.size()-1-i];
    }

    int s1 = 0;
    newstring += " ";
    for(int i = 0; i<newstring.size(); i++){
        if(newstring[i]==' '){
            int e = i-1;
            while(s1<=e){
               char temp = newstring[s1];
               newstring[s1] = newstring[e];
               newstring[e] = temp;
               s1++;
               e--;
            }
            s1 = i+1;
        }
    }
    newstring.pop_back();
    return newstring;
}

int main(){
    string s = "       hello world ";
    while(s[0]==' '){
        s.erase(0,1);
    }
    int n = s.size();
    cout<<ReverseWords(s,n)<<endl;
    return 0;
}