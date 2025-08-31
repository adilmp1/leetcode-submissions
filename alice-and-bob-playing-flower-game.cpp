    long long flowerGame(int n, int m) {
        if(n<=1 and m<=1) return 0;

        long long left_odd,left_even,right_odd,right_even;

        left_even = n/2;
        right_even = m/2;

        left_odd = (n+1)/2;
        right_odd = (m+1)/2;

        long long ans = left_even*right_odd + left_odd*right_even;

        return ans;
    }
