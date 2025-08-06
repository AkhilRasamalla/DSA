#include<bits/stdc++.h>
using namespace std;

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
        if(a[s] != a[e]){
            return false;
        }
        

        else{
            s++;
            e--;

        }
        return true;

    }

}
int main(){
    char name[20];
    cout<<"enter your name: ";
    cout<<endl;
    cin>>name;

    //accessing the string 
    //name[0] = '\0';
    
    cout<<"your name is  " ;
    cout<<name<<endl;
    int len = getLength(name);
    cout<<"length is "<<len<<endl;
    reverse(name,len);
    cout<<"your name is ";
    cout<<name<<endl;


    cout<<"palindrome or not: "<<checkPalindrome(name,len)<<endl;


    //cout<<"length is "<<getLength(name)<<endl;





}

