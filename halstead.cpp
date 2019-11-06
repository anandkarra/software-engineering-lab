#include<bits/stdc++.h>
#include<fstream>

using namespace std;

int main(){
    string str="";
    char x;
    ifstream inFile;
    inFile.open("mergesort.cpp");
    int opr=0,opd=0;
    int uopr=0,uopd=0;
    unordered_map<string,int> opts;
    unordered_map<string,int> opnds;
    opts["int"] = 0;    opts["void"] = 0;       opts["while("] = 0;
    opts[","] = 0;      opts[";"] = 0;          opts["++"] = 0;
    opts["=+"] = 0;     opts["<"] = 0;          opts[">"] = 0;
    opts["<="] = 0;     opts[">="] = 0;         opts["="] = 0;
    opts["+"] = 0;      opts["-"] = 0;          opts["=="] = 0;
    opts["if("] = 0;    opts["else"] = 0;       opts["for("] = 0;
    opts["return"] = 0; opts["("] = 0;          opts["{"] = 0;
    opts["["] = 0;      opts["cin"] = 0;        opts["cout"] = 0;
    opts["using"] = 0;  opts["namespace"] = 0;  opts["std"] = 0;
    opts["endl"] = 0;   opts["continue"] = 0;   opts["break"] = 0;
    opts["main("] = 0;  opts[" << "] = 0;       opts[" >> "] = 0;
    opts["&&"] = 0;     opts["--"] = 0;         opts["Merge("] = 0;
    opts["MergeSort("] = 0;
    
    if(!inFile){
        cerr << "Unable to open file\n";
        exit(1);
    }
    while(inFile >> noskipws >> x){
        if(x=='\n')str.push_back(' ');
        else str.push_back(x);
    }
    
    string s = "";
    for(int i=0;i<str.size();i++){
        if(!isspace(str[i]))s.push_back(str[i]); 
        if(str[i]==' '){
            if(s=="#include<iostream>" || s==")" || s=="]" || s=="}"){
                s="";
                continue;
            }
            if(opts.find(s)!=opts.end()){
                //cout << s << endl;
                if(opts[s]==0)uopr++;
                opts[s]++;
                opr++;
                s="";
            }
            else{
                //cout << s << endl;
                opnds[s]++;
                opd++;
                s="";
            }
        }
    }
    uopd = opnds.size();
    cout << "Operators and operands in merge sort:\n";
    cout << "Total operators : " << opr << endl;
    cout << "Total operands : " << opd << endl;
    cout << "Unique operators : " << uopr << endl;
    cout << "Unique operands : " << uopd << endl;
    int N = opr + opd;
    int eta = uopr + uopd;
    float V = N*log(eta);
    float Vs = (2+uopd)*log(2+uopd);
    float Eff = V*V/Vs;
    float tdev = Eff/18;
    cout << "Effort : " << Eff << "\n";
    cout << "Time of Developement : " << tdev << "\n";
    inFile.close();
    return 0;
}
//sahadeepjyoti01@gmail.com