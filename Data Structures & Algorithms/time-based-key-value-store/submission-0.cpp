class TimeMap {
    // key is name like alice
    // value is a vector of key value pairs, timestamp, value
    // so if you get(name, timestamp), it grabs the timestamp: value within name
private:
    // map keeps timestamps sorted automatically
    std::unordered_map<std::string, std::map<int, std::string>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) {
            return "";
        }

        const auto& keyMap = store[key];
        // first element > timestamp
        auto it = keyMap.upper_bound(timestamp);

        if (it == keyMap.begin()) {
            return "";
        }

        --it;
        return it->second;
    }
};
