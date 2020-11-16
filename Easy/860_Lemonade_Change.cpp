class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill_5 = 0, bill_10 = 0;
        for(int& pay : bills) {
            switch(pay) {
                case 5:
                    bill_5++;
                    break;
                case 10:
                    if(bill_5 < 1)   return false;
                    bill_5--;
                    bill_10++;
                    break;
                case 20:
                    if(bill_5 >= 1 && bill_10 >= 1) {
                        bill_5--;
                        bill_10--;
                        break;
                    }
                    if(bill_5 >= 3) {
                        bill_5 -= 3;
                        break;
                    }
                    return false;
                    
                default:
                    break;
            }
        }
        return true;
    }
};