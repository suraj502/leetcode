class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10)return false;
        bool person=true;
        int counter=9;
        n=n-10;
        while(counter>0){
             if(counter>n){
                return person;
             }
             n=n-counter;
             counter--;
             person=!person;
        }
        return true;
    }
};