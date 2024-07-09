    double myPow(double x, int n) 
    {
        double ans=1;
        double val=x;
        bool isNegative=(n<0);
        n=abs(n);
        while(n)
        {
            if(n%2==1)
            {
                ans*=val;
            }
            val*=val;
            n/=2;
        }    
        if(isNegative) ans=(double)(1/ans);
        return ans;
    }
