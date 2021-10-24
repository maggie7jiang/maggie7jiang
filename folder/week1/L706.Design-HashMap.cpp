class MyHashMap {
         vector<vector<pair<int, int>>> map;
        const int size = 10000;   
public:
    MyHashMap() {
        map.resize(size);
    }
    
    void put(int key, int value) {
        int index = key % size;
        vector<pair<int, int>> &row = map[index];
        for (auto iterator = row.begin(); iterator != row.end(); iterator++)
        {
            if (iterator->first == key)
            {
                iterator->second = value;
                return;
            }
        }
        row.push_back(make_pair(key, value));
    }
    /*returns the value to which the specified key is mapped,
    or -1 if this map contains no mapping for the key*/
    int get(int key) {
        int index = key % size;
        vector<pair<int, int>> &row = map[index];
        for (auto iterator = row.begin(); iterator != row.end(); iterator++)
        {
            if (iterator->first == key)
            {
                return iterator->second;
            }
        }
        return -1;
    }
    /*return the maping of the specified value key if this map
    contains a mapping for the key*/
    void remove(int key) {
        int index = key % size;
        vector<pair<int, int>> &row = map[index];
        for (auto iterator = row.begin(); iterator != row.end(); iterator++)
        {
            if (iterator->first == key)
            {
                row.erase(iterator);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
