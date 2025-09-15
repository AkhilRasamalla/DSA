class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        long long total = accumulate(cardPoints.begin(),cardPoints.end(),0);
        // int minSum = INT_MAX;
        // for(int i=0;i <= n-(n-k);i++){
        //     int sum =0;
        //     for(int j=i;j<i+(n-k);j++){
        //         sum += cardPoints[j];
               
        //     }
        //      minSum = min(minSum,sum);

        // }
        // return total-minSum;

        if(k==n) return total;
        
        int windowsize = n-k;
        long long windowsum = 0;
        for(int i=0;i<windowsize;i++){
            windowsum += cardPoints[i];
        }
        long long  minsum  = windowsum;
        for(int i=windowsize;i<n;i++){
            windowsum += cardPoints[i];
            windowsum -= cardPoints[i-windowsize];
            minsum = min(minsum,windowsum);

        }
        return total - minsum;



    }
};