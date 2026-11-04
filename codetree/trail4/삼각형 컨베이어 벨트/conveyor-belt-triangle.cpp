#include <iostream>

using namespace std;

int n, t;
int l[200];
int r[200];
int d[200];
int arr[600];
int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> l[i];

    for (int i = 0; i < n; i++) cin >> r[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    // Please write your code here.
    for(int i=0; i<n; i++)arr[i]=l[i];
    for(int i=n; i<2*n; i++)arr[i]=r[i-n];
    for(int i=2*n; i<3*n; i++)arr[i]=d[i-2*n];

    while(t--){
        int temp=arr[3*n-1];
        for(int i=3*n-1; i>=1; i--){
            arr[i]=arr[i-1];
        }
        arr[0]=temp;
    }
    for(int i=0; i<n; i++)cout<<arr[i]<<" ";
    cout<<"\n";
    for(int i=n; i<2*n; i++)cout<<arr[i]<<" ";
    cout<<"\n";
    for(int i=2*n; i<3*n; i++)cout<<arr[i]<<" ";
    return 0;
}
