class SpecialQueue {

  public:
queue<int>q;
deque<int>mn,mx;
    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        while(!mn.empty() &&mn.back()>x) mn.pop_back();
        mn.push_back(x);
        while(!mx.empty() && mx.back()<x) mx.pop_back();
        mx.push_back(x);
        
    }

    void dequeue() {
        // Remove element from the queue
        int a=q.front();
        q.pop();
        if(mx.front()==a) mx.pop_front();
        if(mn.front()==a) mn.pop_front();
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        return mn.front();
    }

    int getMax() {
        // Get maximum element
        return mx .front();
    }
};