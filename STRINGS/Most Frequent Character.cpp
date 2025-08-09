class Solution {
public:
    char getMaxOccuringChar(string& s) {
        //  code here
        int arr[26]={0};

    //create an array of count of characters 
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        //lower case
        int number = 0;
        // if(ch>='a' && ch<='z'){
        //     number = ch - 'a';

        // }
        // else{//upper case
        //     number = ch-'A';
        // }
        number = ch - 'a';
        arr[number]++;
    }
    int maxi = -1 , ans =0;
    for(int i=0;i<26;i++){
        if(maxi<arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }
    return 'a'+ans;
    }
};