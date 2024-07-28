import java.util.*;

class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int maxC = 0;
        for (int i = 0; i < candies.length; i++) {
            if (candies[i] > maxC) {
                maxC = candies[i];
            }
        }
        List<Boolean> ans = new ArrayList<Boolean>(candies.length);
        for (int i = 0; i < candies.length; i++) {
            ans.add(extraCandies >= maxC - candies[i] ? true : false);
        }
        return ans;
    }
}