class Node{
public:
    int key,val;
    Node* prev;
    Node* next;

    Node(int k,int v){
        key=k;
        val=v;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
public:

    unordered_map<int,Node*> mp;

    Node* head;
    Node* tail;

    int cap;

    LRUCache(int capacity) {

        cap=capacity;

        head=new Node(-1,-1);
        tail=new Node(-1,-1);

        head->next=tail;
        tail->prev=head;
    }

    void deleteNode(Node* node){

        Node* p=node->prev;
        Node* n=node->next;

        p->next=n;
        n->prev=p;
    }

    void insertAfterHead(Node* node){

        Node* temp=head->next;

        head->next=node;
        node->prev=head;

        node->next=temp;
        temp->prev=node;
    }

    int get(int key) {

        if(mp.find(key)==mp.end())
            return -1;

        Node* node=mp[key];

        deleteNode(node);
        insertAfterHead(node);

        return node->val;
    }

    void put(int key, int value) {

        if(mp.find(key)!=mp.end()){

            Node* node=mp[key];

            node->val=value;

            deleteNode(node);
            insertAfterHead(node);

            return;
        }

        if(mp.size()==cap){

            Node* lru=tail->prev;

            mp.erase(lru->key);

            deleteNode(lru);

            delete lru;
        }

        Node* node=new Node(key,value);

        insertAfterHead(node);

        mp[key]=node;
    }
};