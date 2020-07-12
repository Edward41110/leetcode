package LeetCode;

class diffDays {

    private static int daysFrom1971(String date) {
        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8, 10));
        int[]dayBeforeMonths = new int[]{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int ret = (year - 1971) * 365 + dayBeforeMonths[month - 1] + day - 1;
        int leap = year >= 1972 ? (year - 1968) / 4 : 0;
        ret += leap;
        if (year % 4 == 0 && month < 3) {
            ret--;
        }
        return ret;
    }

    public static int daysBetweenDates(String date1, String date2) {
        if (date1.compareTo(date2) > 0) {
            String temp = date1;
            date1 = date2;
            date2 = temp;
        }
        return daysFrom1971(date2) - daysFrom1971(date1);
    }
}