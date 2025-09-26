// class Solution {
// public:
//     double myPow(double x, int n) {
//         long long N = n;
//         if(N < 0){
//             x = 1 / x;
//             N = -N;
//         }

//         //BRUTE FORCE

//         // double result  = 1.0;
//         // for(long long i=0;i<N;i++){
//         //     result *= x;
//         // }
//         // return result;

//         //OPTIMAL
//         double result = 1.0;
//         while(N > 0){
//             if(N % 2 == 1){
//                 result *= x;
//             }
//             x *= x;
//             N /= 2;
//         }
//         return result;
//     }
// };

//RECUIRSIVE APPROACH
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0){
            x = 1 / x;
            N = -N;
        }

        //BRUTE FORCE

        // double result  = 1.0;
        // for(long long i=0;i<N;i++){
        //     result *= x;
        // }
        // return result;

        //OPTIMAL
        double result = 1.0;
        while(N > 0){
            if(N % 2 == 1){
                result *= x;
            }
            x *= x;
            N /= 2;
        }
        return result;
    }
};