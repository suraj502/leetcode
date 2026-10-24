class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int month[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};

        string arr, lv;

        if (arriveAlice >= arriveBob)
            arr = arriveAlice;
        else
            arr = arriveBob;

        if (leaveAlice <= leaveBob)
            lv = leaveAlice;
        else
            lv = leaveBob;

        if (arr > lv)
            return 0;

        int m1 = stoi(arr.substr(0, 2));
        int d1 = stoi(arr.substr(3, 2));

        int m2 = stoi(lv.substr(0, 2));
        int d2 = stoi(lv.substr(3, 2));

        int start = d1, end = d2;

        for (int i = 0; i < m1 - 1; i++)
            start += month[i];

        for (int i = 0; i < m2 - 1; i++)
            end += month[i];

        return end - start + 1;
    }
};