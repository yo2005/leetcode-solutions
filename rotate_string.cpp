class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(s==goal){
            return true;
        }
            char z=s[0];
            s.erase(s.begin());
            s.push_back(z);
        
        }
        return false;
    }
};
