class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // int l ;
        // int r;
        // int n = fruits.size();
        // int maxFruits = 0;
        
        // // for(l=0;l<n;l++){
        // //     unordered_map<int,int> Count;
        //     int currentFruits = 0;
        //     for(r=l;r<n;r++){
        //         Count[fruits[r]]++;
        //         if(Count.size() > 2){
        //             break;
        //         }
        //         currentFruits++;
        //     }
        //     maxFruits = max(maxFruits,currentFruits);
            
        
        // }
        // return maxFruits;
        // int currentFruits = 0;

        // unordered_map<int,int> Count;
        // while(r < n){
        //     Count[fruits[r]]++;
        //     if(Count.size() > 2){
        //         l++;

        //     }   
        //     currentFruits++;
        //     maxFruits = max(maxFruits, currentFruits);
        //     r++;
        // }
        // return maxFruits;

        int l = 0 ;
        int maxFruits =0;
        int n = fruits.size();
        unordered_map<int,int> Count;
        for(int r=0;r<n;r++){
            Count[fruits[r]]++;

            while(Count.size() > 2){
                Count[fruits[l]]--;
                if(Count[fruits[l]]==0){
                    Count.erase(fruits[l]);
                }
                l++;

                
            }
            maxFruits= max(maxFruits,r-l+1);

        }
        return maxFruits;

    }
};