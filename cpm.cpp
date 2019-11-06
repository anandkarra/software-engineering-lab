#include<bits/stdc++.h>

using namespace std;

struct node{
    int es=0,ef=-90,ls=1000,dur,lf=1000,ff,tf;
};

int main(){
    int n;
    cout << "Enter  no. of relations :";
    cin >> n;
    unordered_map<char,vector<char> > g;
    unordered_map<char,vector<char> > g1;
    map<char,node> mp;
    priority_queue<pair<int,char> > pq;
    priority_queue<pair<int,char> > pq1;
    
    for(int i=0;i<n;i++){
        char x;
        string y;
        int wt;
        cin >> x >> y >> wt;
        if(y=="-"){
            vector<char> j;
            node k;
            k.dur = wt;
            mp[x] = k;
            g[x] = j;
            pq.push({0,x});
        }
        else{
            if(mp.find(x)==mp.end()){
                vector<char> j;
                node k;
                k.dur = wt;
                mp[x] = k;
                g[x] = j;
            }
            for(int j=0;j<y.length();j++){
                g[y[j]].push_back(x);
                g1[x].push_back(y[j]);
            }
        }
    }

    vector<char> xe={};
    for(auto it = mp.begin();it!=mp.end();it++){
        if(g[it->first].size()==0)
        xe.push_back(it->first);
    }
    for(int j=0;j<xe.size();j++){
            g[xe[j]].push_back('Z');
            g1['Z'].push_back(xe[j]);
    }

    int no = mp.size();
    char last = 'Z';
    unordered_map<char,int> vis;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        node *l = &mp[p.second];
        char c = p.second;
        int t = p.first;
        l->es = max(t,l->es);
        l->ef = max(l->ef,t + l->dur);
        for(int i=0;i<g[c].size();i++){
            node *tmp = &mp[g[c][i]];

            pq.push({l->ef,g[c][i]});
        }
    }

    int mx = 0;
    for(auto it = mp.begin();it!=mp.end();it++){
        node *t = &(it->second);
        char c = it->first;
        mx = max(mx,t->ef);
        if(g[c].size()==0){
            pq1.push({t->ef,c});
        }
    }

    cout << "\nCompletion Time : " << mp[last].ef << endl;

    while(!pq1.empty()){
        auto p = pq1.top();
        pq1.pop();
        node *l = &mp[p.second];
        char c = p.second;
        int t = p.first;
        l->lf = min(t,l->lf);
        l->ls = min(l->ls,t - l->dur);
        for(int i=0;i<g1[c].size();i++)
        {
            node *tmp = &mp[g1[c][i]];
            pq1.push({l->ls,g1[c][i]});
        }
        
    }

    cout << "\nACT " << setw(3) << "EST " << setw(3) << "EFT " << setw(3) << "LST " << setw(3) << "LFT " << setw(3) << "TF  " << setw(3) << "FF " << endl;
    for(auto it = mp.begin();it!=mp.end();it++){
        node *t = &(it->second);
        char c = it->first;
        t->tf = t->lf - t->ef;
        if(c=='Z')continue;
        if(t->tf==0){
            t->ff = 0;
        }
        else{
            int mn = 100000;
            for(int i=0;i<g[c].size();i++)mn = min(mn,mp[g[c][i]].es);
            t->ff = mn - t->dur - t->es;    
        }
        cout << c << right << " " << setw(3) << t->es << " " << setw(3) << t->ef << " " << setw(3) << t->ls << " " << setw(3) << t->lf << " " << setw(3) << t->tf << " " << setw(3) << t->ff << endl;
    }

    cout << "\nCritical Path : ";
    for(auto it = mp.begin();it!=mp.end();it++){
        node *t = &(it->second);
        char c = it->first;
        if(t->tf==0 && c!='Z')
        {
            t->ff = 0;
            cout << c << " ";
        }
    }
    cout << endl;

    return 0;
}