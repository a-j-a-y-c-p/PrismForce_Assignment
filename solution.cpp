#include <bits/stdc++.h>

using namespace std;

const int enemies = 11;

int p;

bool canAbhimanyuCross(vector<int>& enemyPower, int enemy, int cur_power, int behind, int a, int b)
{
    if (enemy == enemies)
        return true;

    bool flag = false;

    if (b > 0 && cur_power < p)
        flag |= canAbhimanyuCross(enemyPower, enemy, p, behind, a, b - 1);

    if (cur_power >= behind)
    {
        cur_power -= behind;
        behind = 0;
    }
    else
        return false;

    if (a > 0)
        flag |= canAbhimanyuCross(enemyPower, enemy + 1, cur_power, behind, a - 1, b);

    if (cur_power >= enemyPower[enemy])
    {
        if (enemy == 2 || enemy == 6)
            behind = enemyPower[enemy] / 2;

        flag |= canAbhimanyuCross(enemyPower, enemy + 1, cur_power - enemyPower[enemy], behind, a, b);
    }

    return flag;
}

int main()
{
    vector<int> enemyPower(enemies);

    for (int i = 0; i < enemies; i++)
        cin >> enemyPower[i];

    int a, b;
    cin >> p >> a >> b;
    a = min(a, enemies);
    b = min(b, enemies);

    int behind = 0;

    if (canAbhimanyuCross(enemyPower, 0, p, behind, a, b))
        cout << "Abhimanyu can cross the Chakrvyuha" << endl;
    else
        cout << "Abhimanyu cannot cross the Chakrvyuha" << endl;

    return 0;
}

//Test case: 1 

// enemyPower = [30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130]
// p = 100
// a = 2
// b = 3
// Expected Output: Abhimanyu can cross the Chakravyuha

// Test case: 2

// enemyPower = [30, 40, 90, 60, 70, 80, 130, 100, 110, 120, 130]
// p = 100
// a = 1
// b = 2
// Expected Output:
// Abhimanyu cannot cross the Chakravyuha