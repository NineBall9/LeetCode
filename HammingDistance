//刚开始对x和y进行二进制转换，然后计算距离，很慢大概19ms
class Solution {
public:
    int hammingDistance(int x, int y) {
        int num = 0;
        int result = x xor y;
        while(result){
            int yushu = result % 2;
            num += yushu;
            result = result / 2;
        }
        return num;
    };
};
