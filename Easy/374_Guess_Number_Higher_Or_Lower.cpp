// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);
class Solution {
public:
    int guessNumber(int n) {
        return play_game(1, n);
    }
    int play_game(int low, int high) {
        int m = low + (high-low)/2;
        return guess(m) == 0 ? m : (guess(m) == -1 ? play_game(low, m-1) : play_game(m+1, high));
    }
};