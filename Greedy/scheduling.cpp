#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp (pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}

// start time, end time = pair
vector<pair<int, int>> selectMostEventsToAttend(vector<pair<int, int>> events) {
    sort(events.begin(), events.end(), cmp);
    int currTime = 0;
    vector<pair<int, int>> res;
    for (int i = 0; i < events.size(); i++) {
        if (events[i].first >= currTime) {
            res.push_back(events[i]);
            currTime += (events[i].first + events[i].second);
        }
    }
    return res;
}