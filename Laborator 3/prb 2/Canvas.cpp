#include <iostream>
using namespace std;
#include "Canvas.h"

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    m[x][y]=ch;
    m[x+ray][y]=ch;
    m[x][y+ray]=ch;
    m[x-ray][y]=ch;
    m[x][y-ray]=ch;
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    m[x][y]=ch;
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    m[top][left]=ch;
    m[bottom][right]=ch;
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for(int i=top;i<=bottom;i++)
        for(int j=left;j<=right;j++)
        m[i][j]=ch;
}
void Canvas::SetPoint(int x, int y, char ch)
{
    m[x][y]=ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    m[x1][y1]=ch;
    m[x2][y2]=ch;
    while(x1<=x2)
    {
        x1++;
        m[x1][y1]=ch;
    }
    while(y1<=y2)
    {
        y1++;
        m[x1][y1]=ch;
    }
}
void Canvas::Print()
{
    for(int i=1;i<=width;i++)
    {
        for(int j=1;j<=height;j++)
        cout<<m[i][j]<<" ";
        cout<<endl;
    }
}
void Canvas::Clear()
{
    for(int i=1;i<=width;i++)
        for(int j=1;j<=height;j++)
    m[i][j]=' ';
}

