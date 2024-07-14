class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int ones = 0;
        int z = 0;
        for(auto ele : arr){
            if(ele == 1) ones++;
            else z++;
        }
        
        for(int i = 0; i<arr.size() ;i++){
            if(z > 0){
              arr[i] = 0;
              z--;
            } 
            else arr[i] = 1;
        }
    }
};

// dutch flag algorithm

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int i = 0;
        int j = arr.size() - 1;
        
        while(i < j){
            if(arr[i] == 0)  i++;
            else if(arr[j] == 1)  j--;
            else{
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        
    }
};

