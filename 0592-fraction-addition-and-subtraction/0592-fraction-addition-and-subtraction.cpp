class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1;

        int len = expression.length();
        int i = 0;

        while (i < len) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                sign = (expression[i] == '-') ? -1 : 1;
                i++;
            }

            int num = 0;
            while (i < len && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');  // convert char into int
                i++;
            }

            // Skip the '/' 
            i++;

            int denom = 0;
            while (i < len && isdigit(expression[i])) {
                denom = denom * 10 + (expression[i] - '0');
                i++;
            }

            num *= sign;

            numerator = numerator * denom + num * denominator;
            denominator *= denom;

            int gcdVal = gcd(abs(numerator), abs(denominator));
            numerator /= gcdVal;
            denominator /= gcdVal;
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        return to_string(numerator) + "/" + to_string(denominator);
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};