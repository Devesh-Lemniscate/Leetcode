/*
 * Problem 2409: Count Days Spent Together (POTD)
 * Language: Java
 */
class Solution {
    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int startAlice = getNum(arriveAlice);
        int endAlice = getNum(leaveAlice);
        int startBob = getNum(arriveBob);
        int endBob = getNum(leaveBob);
        System.out.println(startAlice + " " + endAlice + " " + startBob + " " + endBob);
        return Math.max(0, Math.min(endAlice, endBob) - Math.max(startAlice, startBob) + 1);
    }

    private int getNum(String date){
        int []days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = 1; i < days.length; i++)
            days[i] += days[i-1];
        int month = Integer.parseInt(date.substring(0, 2));
        int day = Integer.parseInt(date.substring(3, 5));
        month-=2;
        return (month >= 0 ? days[month] : 0) + day;
    }
}