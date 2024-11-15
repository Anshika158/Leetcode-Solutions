class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int size=arr.size();
        if(is_sorted(arr.begin(),arr.end())) return 0;
        // if(is_sorted(arr.rbegin(),arr.rend())) return size-1;

        int left = 0 , right = size-1;
        while(left+1<size && arr[left]<=arr[left+1]){
            left++;
        }
        while(right>0 && arr[right-1]<=arr[right]){
            right--;
        }
        int minRemoval=min(size-left-1,right);
        int i=0, j=right;
        while(i<=left && j<size){
        if(arr[i]<=arr[j]){
            minRemoval=min(minRemoval , j-i-1);
            i++;
        }else{
            j++;
        }
        }
        return minRemoval;
    }
};