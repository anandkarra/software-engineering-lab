#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<vector<int> > a = {{19,19,19,19},{63,59,55,51},{18,22,26,30}};
    int kloc;
    cout << "Enter KLOC: ";
    cin >> kloc;
    float a1,b;
    a1 = 3.2;
    b = 1.05;
    float c,d;
    c = 2.5;
    d = 0.38;
    float ei = a1*pow(kloc,b);
    float eaf = 1.29*0.95;
    float e = ei*eaf;
    float tdev = c*pow(e,d);
    vector<float> est;    
    if(kloc>=2 && kloc<8){
        float xdif,ydif;
        for(int i=0;i<3;i++){
            xdif = (kloc - 2)/6;
            ydif = a[i][1] - a[i][0];
            float m = a[i][0] + ydif*xdif;
            est.push_back(m*tdev/100);
        }
    }
    else if(kloc>=8 && kloc<32){
        float xdif,ydif;
        for(int i=0;i<3;i++){
            xdif = (kloc - 8)/24;
            ydif = a[i][2] - a[i][1];
            float m = a[i][1] + ydif*xdif;
            est.push_back(m*tdev/100);
        }
    }
    else if(kloc>=32 && kloc<128){
        float xdif,ydif;
        for(int i=0;i<3;i++){
            xdif = (kloc - 32)/96;
            ydif = a[i][3] - a[i][2];
            float m = a[i][2] + ydif*xdif;
            est.push_back(m*tdev/100);
        }
    }
    else if(kloc==128)
        for(int i=0;i<3;i++)est.push_back(a[i][3]*tdev);
    
    cout << "Total Development Time: " << tdev << endl;
    cout << "\nDevelopement Times\n";
    cout << "------------------\n";
    cout << "Product Design                : ";
    cout << est[0] << endl;
    cout << "Programming                   : ";
    cout << est[1] << endl;
    cout << "Integration and System Design : ";
    cout << est[2] << endl;
    cout << "Average Staff Size            : " << e/tdev << endl;
    return 0;
}     