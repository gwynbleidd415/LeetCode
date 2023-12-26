class Solution {
private:
    int divideHelperPositive(int dividend, int divisor) {
        if(dividend == INT32_MIN && divisor == -1) return INT32_MAX;
        if(divisor == INT32_MIN){
            if(dividend == INT32_MIN) return 1;
            return 0;
        }
        bool isNeg = (dividend ^ divisor) < 0;
        bool isMin = false;
        if(dividend == INT32_MIN){
            isMin = true;
            dividend += 1;
        }
        dividend = abs(dividend);
        divisor = abs(divisor);
        int temp = divisor, temp1;
        int ans{0}, itr{1};
        while(dividend >= temp){
            dividend -= temp;
            ans += itr;
            temp1 = temp << 1;
            if(temp1 < 0){
                break;
            }
            temp = temp1;
            itr <<= 1;
        }
        while(temp >= divisor && dividend > 0){
            while(dividend < temp){
                temp >>= 1;
                itr >>= 1;
            }
            if(temp < divisor) break;
            dividend -= temp;
            ans += itr;
        }
        if(isMin && dividend + 1 == divisor) {
            if(ans == INT32_MAX) return INT32_MIN;
            ++ans;
        }
        return isNeg?-ans:ans;
    }
    int divideHelperNegative(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(dividend == INT32_MIN && divisor == -1) return INT32_MAX;

        bool isNeg = (dividend ^ divisor) < 0;
        if(dividend > 0) dividend = -dividend;
        if(divisor > 0) divisor = -divisor;
        int temp = divisor, itr{1}, ans{0}, temp1;
        while(dividend <= temp){
            dividend -= temp;
            ans -= itr;
            temp1 = temp << 1;
            if(temp1 == INT_MIN) break;
            temp = temp1;
            itr <<= 1;
        }
        while(dividend < 0){
            while(temp < dividend){
                temp >>= 1;
                itr >>= 1;
            }
            if(temp > divisor) break;
            ans -= itr;
            dividend -= temp;
        }
        return isNeg?ans:-ans;
    }
public:
    int divide(int dividend, int divisor) {
        return divideHelperNegative(dividend, divisor);
    }
};