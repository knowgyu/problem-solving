#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    int ans = 0;
    for (int k = 1; k * (k - 1) / 2 < N; k++){
        int num = N - k * (k - 1) / 2;
        if(num % k == 0 && num / k > 0) {
            ans++;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
