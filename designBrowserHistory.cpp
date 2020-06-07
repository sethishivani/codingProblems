//Link:  https://leetcode.com/problems/design-browser-history/

class BrowserHistory {
public:
    // vector<string> vec(5000);
    string vec[5000];
    int pos;
    int size;
    BrowserHistory(string homepage) {
        vec[0]=homepage;
        pos=0;
        size=0;
    }

    void visit(string url) {
        if(pos==size)
        {
            pos+=1;
            vec[pos]=url;
            size+=1;
        }
        else
        {
            pos+=1;
            vec[pos]=url;
            size=pos;
        }
    }

    string back(int steps) {
        if(pos-steps<0)
            pos=0;
        else
            pos=pos-steps;
        return vec[pos];
    }

    string forward(int steps) {
        if(steps+pos<=size)
            pos=steps+pos;
        else
            pos=size;
        return vec[pos];
    }
};
