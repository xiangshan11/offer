/*
请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
#include<iostream>
#include<string.h>
using namespace std;
void replace(char *str,int length)
{
    int space_num = 0;
    int old_length;
    for (old_length=0;str[old_length]!='\0';old_length++)
    {
        if(str[old_length] == ' ')
            space_num ++;
    }
    int new_length = old_length + space_num*2;
    if(new_length > length)
        return ;
    str[new_length] = '\0';

    int point1 = old_length-1;
    int point2 = new_length-1;
    while(point1 >= 0 && point2 > point1)
    {
        if(str[point1] == ' ')
        {
            str[point2--] = '0';
            str[point2--] = '2';
            str[point2--] = '%';
        }
        else
            str[point2--] = str[point1];

        point1--;
    }
}
int main()
{
    string str = "abc def gh";
    cout << str << endl;
    cout << strlen(str) << endl;
    replace(str,strlen(str));
    cout << str << endl;
    return 0;
}