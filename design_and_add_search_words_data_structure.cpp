struct Node{
    Node* links[26];
    bool flag=false;
    bool containskey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool setend(){
        return flag=true;
    }
    bool isend(){
        return flag;
    }


    };
class WordDictionary {
private:Node* root;
public:
    WordDictionary() {
        root=new Node();
        
    }
    
    void addWord(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);

        }
        node->setend();

        
    }
        bool dfs(string &word,int i,Node* node){
        if(i==word.length()){
            return node->flag;
        }
        if(word[i]=='.'){
            for(int j=0;j<26;j++){
                if(node->links[j]!=NULL){
                    if(dfs(word,i+1,node->links[j])){
                        return true;
                    }
                }
            }
            return false;
        }
        else{
            if(!node->containskey(word[i])){
                return false;
            }
            return dfs(word,i+1,node->get(word[i]));
        }
    }
    
    bool search(string word) {
        return dfs(word,0,root);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
