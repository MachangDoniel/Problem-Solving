class RandomizedSet {
public:
    vector<int>v;
    map<int,int>positionInV;
    RandomizedSet() {
        
    }
    bool setHas(int val){
        return positionInV.find(val)!=positionInV.end();
    }
    
    bool insert(int val) {
        if(setHas(val)) return false;
        else{
            positionInV[val]=v.size();
            v.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(setHas(val)){
            v[positionInV[val]]=v.back();
            positionInV[v.back()]=positionInV[val];
            v.pop_back();
            positionInV.erase(val);
            return true;
        }
        else return false;

    }
    
    int getRandom() {
        return v[(rand()%v.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */