class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<char> has_box(n), has_key(n), opened(n);
        deque<int> queue;
        for(int b: initialBoxes){
            has_box[b] = 1;
            if(status[b] == 1) queue.push_back(b);
        }
        int total = 0;
        while(!queue.empty()){
            int box = queue.front(); 
            queue.pop_front();
            if(opened[box]) continue;
            opened[box] = 1;
            total += candies[box];
            for(int k: keys[box]){
                if(!has_key[k]){
                    has_key[k] = 1;
                    if(has_box[k] && !opened[k]) queue.push_back(k);
                }
            }
            for(int inner: containedBoxes[box]){
                if(!has_box[inner]){
                    has_box[inner] = 1;
                    if((status[inner] == 1 || has_key[inner]) && !opened[inner]) queue.push_back(inner);
                }
            }
        }
        return total;
    }
};