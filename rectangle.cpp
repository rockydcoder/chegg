#include <string>
#include <iostream>
using namespace std;
    class Rectangle
    {
    public:
        float length, width, area, perimeter;
        Rectangle()
        {
            length = 0;
            width = 0;
        }
    public:
        void setLength()
        {
            cout << "please input length " << endl;
            cin >> length;
        }
        void setWidth()
        {
            cout << "please input width " << endl;
            cin >> width;
        }
        float getLength(float l)
        {
            return length;
        }
        float getWidth(float w)
        {
            return width;
        }
        float calcArea()
        {
            area = length * width;
            return area;
        }
        float calcPerimeter()
        {
            perimeter = 2 * (length + width);
            return perimeter; 
        }
        void showData()
        {
            float ar, peri;
            ar = calcArea();
            peri = calcPerimeter();
            cout << "The area is " << ar << endl;
            cout << "The perimeter is " << peri << endl;
        }
    };
    int main()
    {
        float ar, per;
        Rectangle rct;
        rct.setLength();
        rct.setWidth();
        rct.showData();
        
    }