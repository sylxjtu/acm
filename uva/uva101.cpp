#include <iostream>
#include <vector>
using namespace std;

struct BlockPile{
    vector<int> data;
    void print(){
        for (int i = 0; i < data.size(); ++i)
        {
            cout << " " << data[i];
        }
    }
    int find(int target, int& retOffset){
        for (int i = 0; i < data.size(); ++i)
        {
            if (data[i] == target)
            {
                retOffset = i;
                return 1;
            }
        }
        return 0;
    }
};

struct BlockWorld{
    BlockPile* s;
    int size;
    BlockWorld(int sz){
        size=sz;
        s = new BlockPile[sz];
        for (int i = 0; i < sz; ++i)
        {
            s[i].data.push_back(i);
        }
    }
    ~BlockWorld(){
        delete []s;
    }
    void print(){
        for (int i = 0; i < size; ++i)
        {
            cout << i << ":";
            s[i].print();
            cout << endl;
        }
    }
    void find(int target, int& retPile, int& retOffset){
        for (int i = 0; i < size; ++i)
        {
            if (s[i].find(target, retOffset))
            {
                retPile = i;
                return;
            }
        }
    }
    void clearPos(int pile, int offset){
        for (int i = offset+1; i < s[pile].data.size(); ++i)
        {
            s[s[pile].data[i]].data.push_back(s[pile].data[i]);
        }
        s[pile].data.resize(offset+1);
    }
    void clearValue(int target){
        int pile, offset;
        find(target, pile, offset);
        clearPos(pile, offset);
    }
    void moveTo(int src, int dest){
        int srcPile, destPile, devNull;
        find(src, srcPile, devNull);
        find(dest, destPile, devNull);
        s[destPile].data.push_back(s[srcPile].data.back());
        s[srcPile].data.pop_back();
    }
    void pileTo(int src, int dest){
        int srcPile, destPile, srcOffset, destOffset;
        find(src, srcPile, srcOffset);
        find(dest, destPile, destOffset);
        for (int i = srcOffset; i < s[srcPile].data.size(); ++i)
        {
            s[destPile].data.push_back(s[srcPile].data[i]);
        }
        s[srcPile].data.resize(srcOffset);
    }
};

int main(){
    int sz;
    cin >> sz;
    BlockWorld bw(sz);
    while(1){
        string s1;
        cin >> s1;
        if (s1 == "quit")
        {
            bw.print();
            return 0;
        }
        else
        {
            int src, dest;
            string s2;
            cin >> src >> s2 >> dest;

            int srcPile, destPile, devNull;
            bw.find(src, srcPile, devNull);
            bw.find(dest, destPile, devNull);
            if (srcPile == destPile)
            {
                continue;
            }

            if (s2 == "onto")
            {
                bw.clearValue(dest);
            }
            if (s1 == "move")
            {
                bw.clearValue(src);
                bw.moveTo(src, dest);
            }
            else
            {
                bw.pileTo(src, dest);
            }
        }
    }
}
