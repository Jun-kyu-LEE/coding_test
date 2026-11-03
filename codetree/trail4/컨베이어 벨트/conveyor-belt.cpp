#include <iostream>

using namespace std;

int n, t;
int u[200];
int d[200];
int arr[401];


int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> u[i];

    for (int i = 0; i < n; i++) cin >> d[i];
 //n n-1
 //n+1 n-2 
 //n+2 n-3
 //2n-1 0

    for(int i=0; i<n; i++)arr[i]=u[i];
    for(int i=n; i<2*n; i++)arr[i]=d[i-n];
    

    while(t--){
        int temp=arr[2*n-1];
        for(int i=2*n-1; i>=1; i--){
            arr[i]=arr[i-1];
        }
        arr[0]=temp;
    }
    for(int i=0; i<n; i++)cout<<arr[i]<<" ";
    cout<<"\n";
    for(int i=n; i<2*n; i++)cout<<arr[i]<<" ";

    return 0;
}
