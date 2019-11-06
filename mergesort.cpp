#include <bits/stdc++.h>

using namespace std;

void Merge(vector<int> &a,int l,int mid,int r){
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
    }

    while(j<n2){
        a[k]=R[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int> &a,int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        
        MergeSort(a,l,mid);
        MergeSort(a,mid+1,r);

        Merge(a,l,mid,r);
    }
}

int main(){  
    vector<int> a={14,3,2,5,36,33,67,34,23,73};
    
    MergeSort(a,0,a.size()-1);
    
    for(int i=0;i<a.size();i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}