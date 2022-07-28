#include <iostream>
#include <vector>

using namespace std;

void Output(vector<int> st, vector<int> mid, vector<int> fin);

int main()
{
    vector<int> goal{10,9,8,7,6,5,4,3,2,1};
    vector<int> rungA{10,9,8,7,6,5,4,3,2,1};
    vector<int> rungB;
    vector<int> rungC;

    int moveCount = 0;

    // Thank you https://en.wikipedia.org/wiki/Tower_of_Hanoi#Iterative_solution
    while (rungC != goal)
    {
        // Legal A to B
        if (!rungA.empty() && (rungB.size() == 0 || (rungA.back() < rungB.back())))
        {
            rungB.push_back(rungA.back());
            rungA.pop_back();
            moveCount++;
        }
        else
        {
            rungA.push_back(rungB.back());
            rungB.pop_back();
            moveCount++;
        }

        // Legal A to C
        if (rungC.size() == 0 || (rungA.back() < rungC.back()))
        {
            rungC.push_back(rungA.back());
            rungA.pop_back();
            moveCount++;
        }
        else
        {
            rungA.push_back(rungC.back());
            rungC.pop_back();
            moveCount++;
        }

        // Legal B to C
        if (rungC.size() == 0 || (rungB.back() < rungC.back()))
        {
            rungC.push_back(rungB.back());
            rungB.pop_back();
            moveCount++;
        }
        else
        {
            rungB.push_back(rungC.back());
            rungC.pop_back();
            moveCount++;
        }
        Output(rungA, rungB, rungC);
        cout << endl << "Move Count: " << moveCount << endl;
    }
    
  
}

void Output(vector<int> st, vector<int> mid, vector<int> fin)
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
