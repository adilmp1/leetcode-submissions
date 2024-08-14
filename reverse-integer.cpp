    int reverse(int x) {
        bool isNegative = x < 0;
        x = abs(x);
        long long int ans = 0;
        int count = 0;
        while (x) {
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0; 
            }
            ans *= 10;
            ans += x % 10;
            x /= 10;
            count++;
        }
        if (isNegative)
            return (-1 * ans);
        return ans;
    }
