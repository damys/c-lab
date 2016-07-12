#include <stdio.h>

int main(int argc, const char * argv[])
{
    printf("hello XCode~\n");
    
    int int1 = 123456.12345678;
    printf("%d\n", int1);   //123456
    
    printf("%7d\n", int1);  // 123456 小于7位时前面有空格补齐
    printf("%07d\n", int1); //0123456 以0补齐
    printf("%5d\n", int1);  //123456  大于5位时，按原位输出
    
    
    float float1 = 12.123456789f;   //12.123457 建议这样写+f
    float float2 = 12.123456789;  //12.123457
    float float3 = 12.2f;         //12.200000 默认输出小数点后6位
    float float4 = 12.2;          //12.200000
    printf("%f\n",float1);          //12.123457
    
    //位数float, double %.2f, $.2lf 是一样的用法
    printf("%.2f\n", float1);       //12.12
    printf("%2.f\n", float1);       //12
    
    double double1 = 12.123456789;
    printf("%lf\n", double1);        //12.123457 保留后6位小数,小数不足6位以0补充
    
    char char1 = 'c';
    char char2 = "c";       //双引号内容不能正确输出
    char char3 = "北京";     //不支持中文，会输出一个ASCII码, 赋值时可以直接赋ASCII: 'A':65, 'a':97 '0':48
    char char4 = "abcd";    //d 只能存储一个字符，且为最一个字符
    
    printf("%c\n", char1);
    
    printf("%d, %f, %fl, %c\n", int1, float1, double1, char1); //123456, 12.123457, 12.123457l, c
    //printf("%d, %f, %fl, %c\n", float1, double1, char1);     //99, 12.123457, 12.123457l, 缺少匹配的值时，系统会随机数分配值
    
    //return 0;
}
