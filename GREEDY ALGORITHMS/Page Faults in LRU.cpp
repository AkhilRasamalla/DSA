// User function Template for C++

class Solution {
  public:
    int pageFaults(int N, int C, int pages[]) {
        unordered_set<int> s;  // to store pages in memory
        list<int> lru;         // to maintain LRU order
        int faults = 0;

        for (int i = 0; i < N; i++) {
            int page = pages[i];

            // Case 1: Page already in memory (hit)
            if (s.find(page) != s.end()) {
                // Move this page to front (most recent)
                lru.remove(page);
                lru.push_front(page);
            }
            else {
                // Page fault occurs
                faults++;

                // If memory is full, remove LRU page
                if ((int)s.size() == C) {
                    int lruPage = lru.back(); 
                    lru.pop_back();
                    s.erase(lruPage);
                }

                // Insert new page
                s.insert(page);
                lru.push_front(page);
            }
        }

        return faults;
    }
};
