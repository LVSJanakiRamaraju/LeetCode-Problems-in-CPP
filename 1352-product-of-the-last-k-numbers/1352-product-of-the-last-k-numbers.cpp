class ProductOfNumbers {
private:
    vector<int> products;
    int size =0;

public:
    ProductOfNumbers() {
        products.push_back(1);
        size =0;

        
    }
    
    void add(int num) {
       if(num == 0){
        products = {1};
        size =0;
       }
       else{
        products.push_back(products[size]*num);
        size++;
       }
    }
    
    int getProduct(int k) {
        if(k > size)    return 0;
        return products[size]/products[size-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */