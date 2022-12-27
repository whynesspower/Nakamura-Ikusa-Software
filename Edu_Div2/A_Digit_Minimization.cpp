// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


 // } Driver Code Ends
class Solution {
  public:
    int solve(int N, vector<int> &A) {
            map<long long,long long>mp;
            int maxi = INT_MIN;
            for (int i = 0; i < N; i++)
            {
                mp[A[i]]++;
                maxi = max(maxi, A[i]);
            }
            int breakpt=INT_MAX;
            for (int i = 1; i <= maxi; i++)
            {
                if (mp.find(i) == mp.end())
                {
                    breakpt = i;
                    break;
                }
            }

            long long ans = 0, prevans = 1;
            long long mod = 1e9 + 7;

            for (auto it = mp.begin(); it != mp.end(); it++)
            {
                if (it->first >= breakpt)
                    return ans;
                ans += ((it->second) % mod * (prevans) % mod) % mod;
                prevans = ((it->second) % mod * (prevans) % mod) % mod;
            }
            return ans;
        
    }
};


// { Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.solve(N, A);
        
        cout<<res<<endl;
        
    }
}
  // } Driver Code Ends