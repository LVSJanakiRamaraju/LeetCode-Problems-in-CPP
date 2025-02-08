class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexToNum.find(index) != indexToNum.end()){
            int prev = indexToNum[index];
            numToIndex[prev].erase(index);
            if(numToIndex[prev].empty())    numToIndex.erase(prev);
        }
        indexToNum[index] = number;
        numToIndex[number].insert(index);
    }
    
    int find(int number) {
        if(numToIndex.find(number) != numToIndex.end())     return *numToIndex[number].begin();
        return -1;
        
    }
private:
    unordered_map<int, set<int>> numToIndex;
    unordered_map<int, int> indexToNum;


};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */