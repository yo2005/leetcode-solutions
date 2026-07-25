class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);//this is not main its just used for being able to use >> on s
        vector<string>z;
        string word;//temperory holder
        while(iss >> word){
            z.push_back(word);
        }
        reverse(z.begin(),z.end());
        string result;
        for(int i=0;i<z.size();i++){
            result+=z[i];
            if(i!=z.size()-1){
                result+=" ";
            }
        }
        return result;


        
    }
};
