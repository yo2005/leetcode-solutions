class LRUCache {
    private:
    struct Node{
        int key ,value;
        Node* prev;
        Node* next;
        Node(int k,int v){
            key=k;
            value=v;
            prev=next=NULL;

        }
    };
    int cap;
    Node* head;
    Node* tail;
unordered_map<int,Node*>mp;
void deletenode(Node* node){
    Node* dprev=node->prev;
    Node* d=node->next;
    dprev->next=d;
    d->prev=dprev;
}
void addnode(Node* node){
    node->next=head->next;
    node->prev=head;
    head->next->prev=node;
    head->next=node;
}
 

public:
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;   
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* resnode=mp[key];
            int res=resnode->value;
            deletenode(resnode);
            addnode(resnode);
            return res;
        }
        return -1;       
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* zoo=mp[key];
            deletenode(zoo);
            mp.erase(key);
        }
        if(mp.size()==cap){
            Node* lr=tail->prev;
            mp.erase(lr->key);
            deletenode(lr);
        }
        Node* node= new Node(key,value);
        addnode(node);
        mp[key]=node;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
