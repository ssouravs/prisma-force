#include <bits/stdc++.h>
using namespace std;

bool chakravyuh(vector<int>& enemy,int power,int a, int b){
    int i=0;
    while(i<enemy.size()){
        if(i==3 || i==7){
            enemy[i]=enemy[i]+enemy[i-1]/2; //Previous enemy's (namely k3 and k7) power gets added to the next iteration circle so that they cn attack from behind 
        }
        
        if (power >= enemy[i]) { // Check if Abhimanyu's power is greater than or equal to the enemy's power
            power -= enemy[i]; // Reduce Abhimanyu's power after battling the enemy
            i++;
        } else {
            if (a > 0) { // Use boons if available
                a--;
                i++;
            } else if (b > 0) { // Recharge power if available
                power += b;
                b--;
            } else {
                return false; // Abhimanyu cannot defeat the current enemy and lose the battle in the chakrabvyuh
                
            }
        }
        
        
    }
    return true;
}
int main() {
    // Write C++ code here
    vector<int> enemy{1,2,8,4,12,16,7,8,9,1,1};
    int p1=45;
    int p2=40;
    int a=2;
    int b=3;

    //The algorithm gets tested on two sets of test cases
    // WHere different power values return different answer
    cout<<chakravyuh(enemy,p1,a,b)<<endl; //return true
    cout<<chakravyuh(enemy,p2,a,b)<<endl; //return false

    return 0;
}