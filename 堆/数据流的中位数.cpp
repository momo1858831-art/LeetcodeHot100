#include<iostream>
using namespace std;

class MedianFinder {
public:

    //大根堆保存最小的N/2个数
    priority_queue<int,vector<int>,less<int>>pmin;
    //小根堆保存最大的N/2个数
    priority_queue<int,vector<int>,greater<int>>pmax;


    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // 向pmin插入
        if(pmin.size()==pmax.size()){
            pmax.push(num);
            pmin.push(pmax.top());
            pmax.pop();
            return;
        }
        // 向pmax插入
        pmin.push(num);
        pmax.push(pmin.top());
        pmin.pop();
    }
    
    double findMedian() {
        if(pmin.size()==pmax.size()){
            return (pmin.top()+pmax.top())*1.0/2;
        }
        return pmin.top();
    }
};