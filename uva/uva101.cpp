#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<int> blocks[25];
int n;

vector<int>* posof(int x, int& h){
    for(int i=0; i<n; i++){
        for(int j=0; j<blocks[i].size(); j++){
            if(blocks[i][j]==x){
                h=j;
                return blocks+i;
            }
        }
    }
    assert(0);
}

vector<int>* pileof(int x){
    int t;
    return posof(x,t);
}

void pileover(int op1, int op2){
    int h1,h2;
    vector<int>* p1=posof(op1,h1), * p2=posof(op2,h2);
    for (int i = h1; i < p1->size(); i++) {
        p2->push_back((*p1)[i]);
    }
    int p1s=p1->size();
    for (int i = h1; i < p1s; i++) {
        p1->pop_back();
    }
}

void replace(int x){
    vector<int>* p = pileof(x);
    while(p->back() != x) {
        blocks[p->back()].push_back(p->back());
        p->pop_back();
    }
    blocks[p->back()].push_back(p->back());
    p->pop_back();
}

void print(){
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < blocks[i].size(); j++) {
            if (j!=0) {
                cout << " ";
            }
            cout << blocks[i][j];
        }
        cout << endl;
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        blocks[i].push_back(i);
    }
    while(1){
        string s1,s2;
        int op1,op2;
        cin >> s1;
        if (s1=="quit") {
            print();
            return 0;
        }
        cin >> op1 >> s2 >> op2;
        if (pileof(op1)==pileof(op2)){
            continue;
        }
        if (s1=="move" && s2=="onto"){
            replace(op1);
            replace(op2);
            pileof(op1)->pop_back();
            pileof(op2)->push_back(op1);
        }
        if (s1=="move" && s2=="over"){
            replace(op1);
            pileof(op1)->pop_back();
            pileof(op2)->push_back(op1);
        }
        if (s1=="pile" && s2=="onto"){
            replace(op2);
            pileover(op1,op2);
        }
        if (s1=="pile" && s2=="over"){
            pileover(op1,op2);
        }
#ifdef DEBUG
        print();
#endif
    }
}
