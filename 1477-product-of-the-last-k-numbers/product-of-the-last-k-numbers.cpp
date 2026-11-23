class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    vector<int>st;
    void add(int num) {
        st.push_back(num);
    }
    
    int getProduct(int k) {
        int pro=1;
        int n=st.size();
        int j=n-1;
        while(k>=1){
            int a=st[j];
            pro=pro*a;
            j--;
            k--;

        }
        return pro;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */