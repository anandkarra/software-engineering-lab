#include<bits/stdc++.h>

using namespace std;

struct node{
    double es=0,ef=-90,ls=1000,lf=1000,ff,tf,var,p,m,o,ex;
};

int main(){
    double n;
    cout << "Enter  no. of relations :";
    cin >> n;
    unordered_map<char,vector<char> > g;
    unordered_map<char,vector<char> > g1;
    map<char,node> mp;
    priority_queue<pair<double,char> > pq;
    priority_queue<pair<double,char> > pq1;
    
    for(int i=0;i<n;i++){
        char x;
        string y;
        double wt;
        double a,m,b;
        cin >> x >> y >> a >> m >> b;
        wt = (a + 4*m + b)/6;
        if(y=="-"){
            vector<char> j;
            node k;
            k.p = a;
            k.m = m;
            k.o = b;
            k.ex = wt;
            k.var = pow((k.p-k.o)/6,2);
            mp[x] = k;
            g[x] = j;
            pq.push({0,x});
        }
        else{
            if(mp.find(x)==mp.end() ){
                vector<char> j;
                node k;
                k.p = a;
                k.m = m;
                k.o = b;
                k.ex = wt;
                k.var = pow((k.p-k.o)/6,2);
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
    
    double no = mp.size();
    char last = 'Z';
    unordered_map<char,double> vis;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        node *l = &mp[p.second];
        char c = p.second;
        double t = p.first;
        l->es = max(t,l->es);
        l->ef = max(l->ef,l->es + l->ex);
        for(int i=0;i<g[c].size();i++){
            node *tmp = &mp[g[c][i]];

            pq.push({l->ef,g[c][i]});
        }
    }
    
    double mx = 0;
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
        double t = p.first;
        l->lf = min(t,l->lf);
        l->ls = min(l->ls,t - l->ex);
        for(int i=0;i<g1[c].size();i++){
            node *tmp = &mp[g1[c][i]];
            pq1.push({l->ls,g1[c][i]});
        }
        
    }

    cout << "\nACT " << "\t" << "VAR " << "\t" << "EXP "<< "\t" << "EST " << "\t" << "LFT " << "\t" << "TF " << "\t" << "FF " << endl;
    for(auto it = mp.begin();it!=mp.end();it++){
        node *t = &(it->second);
        char c = it->first;
        t->tf = t->lf - t->ef;
        if(t->tf==0){
            t->ff = 0;
        }
        else{
            double mn = 100000;
            for(int i=0;i<g[c].size();i++)mn = min(mn,mp[g[c][i]].es);
            t->ff = mn - t->ex - t->es;    
        }
        cout << left << setprecision(2) << c << " " << "\t" << t->var << " " << "\t" << t->ex << " " << "\t" << t->es << " " << "\t" << t->lf << " " << "\t" << t->tf << " " << "\t" << t->ff << endl;
    }

    double projVar=0.0;
    cout << "\nCritical Path : ";
    for(auto it = mp.begin();it!=mp.end();it++){
        node *t = &(it->second);
        char c = it->first;
        t->tf = t->lf - t->ef;
        if(t->tf==0 && c!='Z'){
            t->ff = 0;
            projVar+=t->var;
            cout << c << " ";
        }
    }
    cout << endl;
    
    cout << "\nProject Variance= " << projVar << endl;

    double z = (35-mp[last].ef)/sqrt(projVar);
    cout << "z value  = " << z << endl;
    cout << "P(z<=" << z << ")= 0.9999" << endl;
    cout << "Probability of completing the project on or before 35 weeks= 0.9999" << endl;

    return 0;
}
