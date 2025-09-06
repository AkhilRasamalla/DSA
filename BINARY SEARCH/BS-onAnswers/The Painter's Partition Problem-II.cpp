class Solution {
private:
    int CountStudents(vector<int>& arr, int pages) {
        int students = 1;
        long long pagesStudent = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (pagesStudent + arr[i] <= pages) {
                pagesStudent += arr[i];

            } else {
                students += 1;
                pagesStudent = arr[i];
            }
        }
        return students;
    }

public:
    int findPages(vector<int>& arr, int k) {
        // code here
        // edge case
        if (k > arr.size())
            return -1;

        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        while (low <= high) {
            long long mid = (low + high) / 2;
            int students = CountStudents(arr, mid);
            if (students > k) {
                low = mid + 1;

            } else {
                high = mid - 1;
            }
        }
        return low;
    }
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        return findPages(arr,k);
        
    }
};