#include<bits/stdc++.h>
using namespace std;


char tolowerCase(char ch){
    if(ch >= 'a' && ch<='z'){
        return ch;

    }
    else{
        char temp = ch-'A'+'a';
        return temp; 
    }
}

void reverse(char name[],int n){
    int s=0;
    int e = n-1;
    while(s<e){
        swap(name[s++],name[e--]);

    }
}

int  getLength(char name[]){
    int count =0;
    for(int i=0;i<name[i] != '\0';i++){
        count++;
    }
    return count;

    
}

bool checkPalindrome(char a[],int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        if(tolowerCase(a[s]) != tolowerCase(a[e])){
            return false;
        }
        

        else{
            s++;
            e--;

        }
        //return true;

    }
    return true;

}

char getMaxOccCharacter(string s){
    int arr[26]={0};

    //create an array of count of characters 
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        //lower case
        int number = 0;
// all the inputs are given in lower case only
        
        // if(ch>='a' && ch<='z'){
        //     number = ch - 'a';

        // }
        // else{//upper case
        //     number = ch-'A';
        // }
        number = ch - 'a';
        arr[number]++;
    }
 //find maximum occurences in the character   
    int maxi = -1 , ans =0;
    for(int i=0;i<26;i++){
        if(maxi<arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }
    char finalAns = 'a'+ans;
    return finalAns;
}
int main(){
    // char name[20];
    // cout<<"enter your name: ";
    // cout<<endl;
    // cin>>name;

    // //accessing the string 
    // //name[0] = '\0';
    
    // cout<<"your name is  " ;
    // cout<<name<<endl;
    // int len = getLength(name);
    // cout<<"length is "<<len<<endl;
    // reverse(name,len);
    // cout<<"your name is ";
    // cout<<name<<endl;


    // cout<<"palindrome or not: "<<checkPalindrome(name,len)<<endl;

    // cout<<"CHARACTER IS "<<tolowerCase('a')<<endl;
    // cout<<"CHARACTER IS "<<tolowerCase('S');
    


    //cout<<"length is "<<getLength(name)<<endl;
    string s;
    cin>>s;
    cout<<getMaxOccCharacter(s)<<endl;







}

