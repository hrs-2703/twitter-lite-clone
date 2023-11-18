class Twitter {
public:
int t;
    Twitter() {
         t=0;
    }
    map<int,vector<pair<int,int>>> mp1;
    map<int,set<int>> mp2;
    void postTweet(int userId, int tweetId) {
        mp1[userId].push_back({t,tweetId});
        t++;
    }
    
    vector<int> getNewsFeed(int userId) {
       priority_queue<pair<int, int>> maxHeap; 
    for (auto it=mp1[userId].begin();it!=mp1[userId].end();++it)
        maxHeap.push(*it);
    for (auto it1=mp2[userId].begin();it1!=mp2[userId].end();++it1){
        int usr = *it1; // get target user
        for (auto it2=mp1[usr].begin();it2!=mp1[usr].end();++it2)
            maxHeap.push(*it2);
    }   
    
    vector<int> res;
    while(maxHeap.size()>0) {
        res.push_back(maxHeap.top().second);
        if (res.size()==10) break;
        maxHeap.pop();
    }
    return res;    


    }
    
    void follow(int followerId, int followeeId) {
        mp2[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp2[followeeId].erase(followerId);
    }
};
