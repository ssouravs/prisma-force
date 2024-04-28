/*
    Inputs and declarations:
enemy:-> An array representing the powers of enemies in each circle.
power:-> Abhimanyu's initial power.
a:-> The number of times Abhimanyu can skip fighting an enemy.
b:-> The number of times Abhimanyu can recharge himself with power.

Algorithm: 
Initialize the index, i to 0.
While loop: Iterate through each circle of enemy line:
If I is equal to 3 or 7(as it is in the 4th and 8th level respectively), update the power of the enemy in that circle to regenerate itself once with half of its initial power of the previous levels(K3 and K7 namely) as it can attack from behind.
Check if Abhimanyu's power is greater than or equal to the power of the enemy in the current circle:
If true, reduce Abhimanyu's power by the enemy's power and move to the next circle (i++).
If false:
If Abhimanyu has remaining skips (a > 0), use one skip and move to the next circle (a-- and i++).
Otherwise, if Abhimanyu has remaining power recharges (b > 0), recharge his power by b and use one recharge (power += b and b--).
If both skips and recharges are exhausted, return false as Abhimanyu cannot defeat the current enemy.
Return true if Abhimanyu successfully crosses all circles without exhausting his power and skips/recharges.
*/



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