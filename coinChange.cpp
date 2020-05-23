//Link:  https://practice.geeksforgeeks.org/problems/coin-change-minimum-number-of-coins/1/?track=amazon-dynamic-programming&batchId=192

long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
{
    long long mini[value+1]={0};
    //The above array holds the minimum number of coins for every amount from 0 to value
    mini[0]=0;
    for(int i=1;i<value+1;i++)
        mini[i]=INT_MAX;
        //We fill all array with inifinty as intially we need infinite coins to make the value
    vector<int> coinsSet;
    for(int i=0;i<numberOfCoins;i++)
        coinsSet.push_back(coins[i]);
    // Either let the mini[i] be the number of coins needed or if mini[i-coin]+1 i.e
    // considering coin in your collection gives you lesser coins update  mini[i] with
    // mini[i-coin]+1
    for(auto coin:coinsSet) //Iterating over each coin
    {
        for(int i=1;i<value+1;i++)
        {
            if(i>=coin) //No use in checking for values that are smaller than the current coin
            {
                if(mini[i-coin]!=INT_MAX)
                    mini[i]=min(mini[i-coin]+1,mini[i]);
            }
        }
    }
    return mini[value];
}
