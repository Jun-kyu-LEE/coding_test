#include <iostream>
#include<vector>

using namespace std;

int n;
int arr[100];

//dp[i][j] i번째까지 있을때 
int main() {
    cin >> n;
    int sum=0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum+=arr[i];
    }
    vector<bool>v(sum+1,0);
    // Please write your code here.
    //total-2*만들수있는 값이 가장 큰값을 찾으면 된다
    v[0]=true;
    
    for(int i=0; i<n; i++){
        int x=arr[i];
        for(int j=sum; j>=x; j--){
            if(v[j-x])v[j]=true;
        }
    }    
    
    int answer=1e9+1;
    for(int s=1; s<=sum; s++){
        if(v[s])answer=min(answer,abs(sum-2*s));
    }
    cout<<answer;
    return 0;
}
