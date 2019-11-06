#include <bits/stdc++.h>

using namespace std;

bool flag1=0,flag2=0;

void merge(vector<int> &a,int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    vector<int> L(n1),R(n2);

    int i,j,k;
    for(i=0;i<n1;i++)
        L[i]=a[l+i];
    for(j=0;j<n2;j++)
        R[j]=a[mid+j+1];

    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        a[k]=L[i];
        i++;
        k++;
        flag1=1;
    }

    while(j<n2){
        a[k]=R[j];
        j++;
        k++;
        flag2=1;
    }
}

void mergeSort(vector<int> &a,int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);

        merge(a,l,mid,r);
    }
}

vector<int> generateRandomVector(){
    srand(time(0));

    int n=rand()%10;

    vector<int> a;
    for(int i=0;i<n;i++)
        a.push_back(rand()%1000);
    
    return a;
}

int main(){

    vector<int> a=generateRandomVector();
    vector<int> orig=a;

    mergeSort(a,0,a.size()-1);

    while(!(flag1 && flag2)){
        vector<int> a=generateRandomVector();
        orig=a;
        mergeSort(a,0,a.size()-1);
    }

    for(auto i:orig)
            cout << i << " ";
    cout << endl;

    return 0;
}