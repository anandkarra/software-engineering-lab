#include <bits/stdc++.h>

using namespace std;

vector<int> pa,ca;

// 2
void merge(vector<int> &a,int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    vector<int> L(n1),R(n2);

    int i,j,k;
    for(i=0;i<n1;i++){
        // 3
        ca.push_back(3);

        L[i]=a[l+i];
    }
    for(j=0;j<n2;j++){
        // 4
        ca.push_back(4);

        R[j]=a[mid+j+1];
    }

    i=0;
    j=0;
    k=l;

    // 5
    while(i<n1 && j<n2){
        // 6

        if(L[i]<=R[j]){
            // 7
            pa.push_back(7);

            a[k]=L[i];
            
            ca.push_back(7);
            
            i++;
        }
        // 8
        else{
            // 9
            pa.push_back(9);

            a[k]=R[j];

            ca.push_back(9);

            j++;
        }
        k++;
    }
    
    // 10
    while(i<n1){
        ca.push_back(10);

        a[k]=L[i];
        i++;
        k++;
    }

    // 11
    while(j<n2){
        ca.push_back(11);

        a[k]=R[j];
        j++;
        k++;
    }
}

// 1
void mergeSort(vector<int> &a,int l,int r){
    if(l<r){
        pa.push_back(1);

        int mid=l+(r-l)/2;
        
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);

        merge(a,l,mid,r);
    }
}

int main(){
    
    vector<int> a={14,3,33,2,5,36,73};
    
    mergeSort(a,0,a.size()-1);

    // 12
    ca.push_back(12);

    cout << "Sorted array: ";
    for(auto i:a)
        cout << i << " ";
    cout << endl;

    cout << "p-use of input array:" << endl;
    for(auto i:pa)
        cout << i << " ";
    cout << endl;

    cout << "c-use of input array:" << endl;
    for(auto i:ca)
        cout << i << " ";
    cout << endl;
    
    return 0;
}