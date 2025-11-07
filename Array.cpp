/*WEEK 1 story */
/* NAME - RAM AGARWAL*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

int theEfficientTraveler()
{
    int n, initialEnergy;

    cout << "Enter the number of cities (array size): ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter energy costs for each city: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << "Enter initial energy: ";
    cin >> initialEnergy;
    for (int i = 0; i < nums.size(); i++)
    {
        if (initialEnergy - nums[i] >= 0)
            initialEnergy -= nums[i];
        else
            return i;
    }
    return nums.size();
}
int theSumThatStandsOut()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int sum = 0;
    for (int number : nums)
        sum += number;

    int prefixsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int suffixsum = sum - prefixsum - nums[i];
        if (prefixsum == suffixsum)
            return i;
        prefixsum += nums[i];
    }
    return -1;
}
int flipTheSwitch()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array (0s and 1s only): ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int ZeroCount = 0, OneCount = 0;

    for (int number : nums)
    {
        if (number == 0)
            ZeroCount++;
        else if (number == 1)
            OneCount++;
        else
            cout << "Warning: Non-binary input detected (" << number << "). Ignoring.\n";
    }
    return min(ZeroCount, OneCount);
}
int theOddOneOut()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int result = 0;
    for (int number : nums)
        result ^= number;

    return result;
}
bool smartPairFinder()
{
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter the target sum: ";
    cin >> target;

    unordered_set<int> seenNumbers;

    for (int number : nums)
    {
        int complement = target - number;
        if (seenNumbers.find(complement) != seenNumbers.end())
            return true;
        seenNumbers.insert(number);
    }
    return false;
}

int theMinimalistPainter()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int maxValue = INT_MIN;
    for (int number : nums)
        maxValue = max(maxValue, number);

    int sum = 0;
    bool maxRemoved = false;

    for (int number : nums)
    {
        if (number == maxValue && !maxRemoved)
        {
            maxRemoved = true;
            continue;
        }
        sum += number;
    }

    return sum;
}
class Point
{
    float x, y;

public:
    Point(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    float distance(float x_point, float y_point)
    {
        float sq1 = float(x_point - x) * (x_point - x);
        float sq2 = float(y_point - y) * (y_point - y);
        return sqrt(sq1 + sq2);
    }

    void translate(float new_x, float new_y)
    {
        this->x = new_x;
        this->y = new_y;
    }

    void display()
    {
        cout << "(" << this->x << ", " << this->y << ")" << endl;
    }
};
class Shape : public Point
{
public:
    void get_area() {};
};

class Circle
{
    float radius;

public:
    Circle(float radius)
    {
        this->radius = radius;
    }

    float get_area()
    {
        float area = 3.14 * (this->radius) * (this->radius);
        return area;
    }
};
class Square
{
    float side;

public:
    Square(float side)
    {
        this->side = side;
    }

    float get_area()
    {
        return this->side * this->side;
    }
};
void GeometryOperations()
{
    float x1, x2, y1, y2, new_x, new_y;
    float side, radius;
    cout << "Enter co-ordinates of point-1(x1, y1):";
    cin >> x1 >> y1;
    cout << "Enter co-ordinates of point-2(x2, y2):";
    cin >> x2 >> y2;
    cout << "Enter radius of circle:";
    cin >> radius;
    cout << "Enter side of square:";
    cin >> side;
    cout << "Enter co-ordinates of translation point:";
    cin >> new_x >> new_y;

    Point point(x1, y1);
    Circle circle(radius);
    Square square(side);

    float distance = point.distance(x2, y2);
    float circleArea = circle.get_area();
    float squareArea = square.get_area();
    point.translate(new_x, new_y);

    cout << "Distance: " << distance << endl;
    cout << "Circle Area: " << circleArea << endl;
    cout << "Square Area: " << squareArea << endl;
    cout << "Translated Point1: ";
    point.display();
    cout << endl;
}

int main()

{
    int selectionofcode;

    do
    {
        cout << "PROBLEMS" << endl;
        cout << "1. cityTravel" << endl;
        cout << "2. theSumThatStandsOut" << endl;
        cout << "3. flipTheSwitch" << endl;
        cout << "4. theOddOneOut" << endl;
        cout << "5. smartPairFinder" << endl;
        cout << "6. theMinimalistPainter" << endl;
        cout << "7. geometryOperation" << endl;
        cout << "8. Exit" << endl;
        cout << "Select an option: ";

        while (!(cin >> selectionofcode))
        {
            cout << "Invalid input! Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (selectionofcode)
        {
        case 1:
        {
            cout << "Cities Visited: " << theEfficientTraveler() << "\n";
            break;
        }
        case 2:
        {
            cout << "Pivot Index: " << theSumThatStandsOut() << "\n";
            break;
        }

        case 3:
        {
            cout << "Minimum Flips: " << flipTheSwitch() << "\n";
            break;
        }

        case 4:
        {
            cout << "Unique Element: " << theOddOneOut() << "\n";
            break;
        }
        case 5:
        {
            cout << "Pair Exists: " << (smartPairFinder() ? "true" : "false") << "\n";
            break;
        }

        case 6:
        {
            cout << "Sum Except Max: " << theMinimalistPainter() << "\n";
            break;
        }
        case 7:
        {
            GeometryOperations();
            break;
        }

        case 8:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid Option! Please try again.\n";
            break;
        }

    } while (true);
    return 0;
};