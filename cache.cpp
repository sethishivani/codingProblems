class LRUCache {
public:
    list<pair<int,int> > cache;
    unordered_map<int, list< pair<int,int> >::iterator  > umap;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }

    int get(int key) {
        if(umap.find(key)==umap.end())
            return -1;
        auto it=umap[key];
        int v;
        v=(*it).second;
        cache.erase(it);
        cache.push_front({key,v});
        umap[key]=cache.begin();
        return v;
    }

    void put(int key, int value) {
        if(umap.find(key)!=umap.end())
        {
            auto it=umap[key];
            cache.erase(it);
            cache.push_front({key,value});
            umap[key]=cache.begin();
            return
        }
        int sz=cache.size();
        if(sz==cap)
        {
            pair<int,int> last=cache.back();
            cache.pop_back();
            umap.erase(last.first);
        }
        cache.push_front({key,value});
        umap[key]=cache.begin();
    }
};
