class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int count=0;
        int left=0 , right=n-1;
        while(left<right){
            char c = tolower(s[left]);
            if(c=='a'|| c=='e'|| c=='i' ||c=='o'||c=='u'){
                count++;
            }
            char d = tolower(s[right]);
            if(d=='a'||d=='e'|| d=='i' ||d=='o'||d=='u'){
                count--;
            }
            left++;
            right--;
        }
        return count==0;
    }
};