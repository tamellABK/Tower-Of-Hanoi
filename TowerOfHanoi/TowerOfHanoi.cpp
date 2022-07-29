#include <iostream>
#include <vector>

using namespace std;

void Output(vector<int>& st, vector<int>& mid, vector<int>& fin);
void MoveRing(vector<int>& rung1, vector<int>& rung2);

int main()
{
    vector<int> rungA{10,9,8,7,6,5,4,3,2,1};
    vector<int> rungB;
    vector<int> rungC;

    int moveCount = 0;

    // Thank you https://en.wikipedia.org/wiki/Tower_of_Hanoi#Iterative_solution
    while (rungC != vector<int>{10,9,8,7,6,5,4,3,2,1})
    {
        // Legal A to B
        MoveRing(rungA, rungB);

        // Legal A to C
        MoveRing(rungA, rungC);

        // Legal B to C
        MoveRing(rungB, rungC);
        moveCount += 3;
 
        Output(rungA, rungB, rungC);
        cout << endl << "Move Count: " << moveCount << endl;
    }
}

void MoveRing(vector<int>& rung1, vector<int>& rung2)
{
    if (!rung1.empty() && (rung2.empty() || (rung1.back() < rung2.back())))
    {
        rung2.push_back(rung1.back());
        rung1.pop_back();
    }
    else
    {
        rung1.push_back(rung2.back());
        rung2.pop_back();
    }
}

void Output(vector<int>& st, vector<int>& mid, vector<int>& fin)
{
    system("cls");
    for (int i : st)
    {
        cout << i << " ";
    }

    cout << endl;

    for (int i : mid)
    {
        cout << i << " ";
    }

    cout << endl;

    for (int i : fin)
    {
        cout << i << " ";
    }
}