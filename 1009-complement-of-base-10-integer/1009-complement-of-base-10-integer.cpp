class Solution {
public:
    int bitwiseComplement(int num) {
        if (num == 0) return 1;  // Special case for 0, as its complement is 1
        
        int mask = 0;
        int temp = num;
        
        // Create a mask with all bits set to 1 for the length of the number
        while (temp > 0) {
            temp = temp >> 1;
            mask = (mask << 1) | 1;
        }
        
        // XOR the number with the mask to get the complement
        return num ^ mask;
    }
};
