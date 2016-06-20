/****************************************************************************************
主要的思路是先排序，然后计算0（大小王）的个数，剔除相邻的两张牌相等的情况（一定不能成为顺子），
统计非0的牌的间隔数是否小于等于0的个数，判断是否可组成顺子。
*****************************************************************************************/
class Solution {
public:
    bool IsContinuous( vector<int> numbers )
    {
        int length = numbers.size();
        if(length < 5)
            return false;
        sort(numbers.begin(),numbers.end());
        int numberOfZero = 0;
        int numberOfGap = 0;
        for(int i = 0; i < length; ++i)
        {
            if(numbers[i] == 0)
                numberOfZero++;
        }
        int small = numberOfZero;
        int big = small+1;
        while(big < length)
        {
            if(numbers[small] == numbers[big])
                return false;
            numberOfGap += numbers[big] - numbers[small] - 1;
            small = big;
            big++;
        }
        return (numberOfGap > numberOfZero) ? false : true;
    }
};
