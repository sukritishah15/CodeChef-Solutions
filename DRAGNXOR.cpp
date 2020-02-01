#include <iostream>
using namespace std;
int ones(int x){
    if(x==0)
        return 0;
    return (1 +ones(x&(x-1)));
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,a,b;
	    cin>>n>>a>>b;
	    int a1=ones(a);
	    int a0=n-a1;
	    int b1 = ones(b);
        int b0 = n-b1;
        int p = min(a1,b0)+min(b1,a0);
        //we need to make maximum number of (1,0) or (0,1) pairs
        //to make the result maximum, we want all the ones towards the most significant side (left)
        //We will calculate no. of 1's and no. of 0's
        //Whichever will be min., shall govern the no. of pairs
        //x = minimum _ of( number of 1s in A, number of 0s in B)
        //y = minimum _ of( number of 1s in B, number of 0s in A)
        //number of ones in the result is at max P = x + y. 
        //The answer is (1111…) : P times followed by (…000) : N-P times, 
        //which is nothing but the integer 
        //     ( ((1<<P)-1) << (N-P) ).
        cout<<(((1<<p)-1)<<(n-p))<<endl;
	}
	return 0;
}
