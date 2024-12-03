#include <bits/stdc++.h>
using namespace std;

// Reads two integers and prints their sum
void solve(int &t,int &T) {
    char ch1,ch2; cin>>ch1>>ch2;
    int x=ch1,y=ch2;
    cout<<x<<" "<<y<<endl;
    cout<<"Case "<<t<<":"<<endl;
    for(int i=1;i<=94;i++){
        int col1=-1,col2=-1;
        for(int j=1;j<=i;j++){
            for(int k=0;k<94/i;k++){
                if(k+33==x) col1=j;
                if(k+33==y) col2=j;
            }
        }
        cout<<col1<<" = "<<col2<<endl;
        if(col1==col2){
            int row=i;
            int col=94/i;
            if(94%i) col++;
            cout<<row<<" "<<col<<endl;
        }
    }
}

main() {
    int T=1;
    cin>>T;
    for(int t=1;t<=T;t++){
        solve(t,T);
    }
    return 0;
}
