class Bank {
public:
    vector<long long> balances;
    int n;
    Bank(vector<long long>& balance) {
        balances = balance;
        n = balances.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1<=0 or account1>n) return false;
        if(account2<=0 or account2>n) return false;
        if(balances[account1-1]<money) return false;
        balances[account1-1]-=money;
        balances[account2-1]+=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account<=0 or account>n) return false;
        balances[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account<=0 or account>n) return false;
        if(balances[account-1]<money) return false;
        balances[account-1]-=money;
        return true;
    }
};
