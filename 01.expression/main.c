#include <stdio.h>

int main(int argc, const char * argv[]) {
    //赋值时，C系统会把int 的值转为int 类型，当值的范围过大时，C系统会转换一个int 的随机数 或 报错
    
    //scanf 函数：可以在程序运行的时候，让用户输入数据，然后将用户输入的数据赋值给指定的变量
    //scanf(格式控制符，如:%d，变量地址列表，如:&num). 它是一个阻塞式函数，不会往下面执行
    
    //1. 基本用法
   int num1 = 0;
   printf("请输入一个数字：");
   scanf("%d", &num1);
   printf("你输入的数字为：%d\n", num1);
    
    
    //2. 输入多位。输入多位数据时，可以用回车，空格，也可自定义分格符
   int num2 = 0, num3 = 0, sum = 0;
   printf("请分别输入二个数字，用回车或空格分开：");
   scanf("%d%d", &num2, &num3);
   //scanf("%d-%d", &num2, &num3);   //自定义分格符，输入时：2-3
   
   sum = num2 + num3;    //sum2, sum3 在缓存区
   printf("二个数分别为：%d,%d\n", num2, num3);
   printf("二个数相加为：%d\n", sum);
    
    
    //3. 当从缓存区拿数据时，空格，回车会被忽略，每次执行scanf 都会先到缓存区取数据，如：
   int num4 = 0;
   printf("请输入一个数字：");
   scanf("%d", &num4);
   printf("你输入的数字为：%d\n", num4);
   
   rewind(stdin);   //清空缓存区的所有数据
   
   char char1 = 0;
   printf("请输入一个字符：");
   scanf("%c", &char1);
   printf("你输入的字会为：%c\n", char1);
    //如输入数字 + 空格/回车：是第二个字符的输入会变成空格/回车，直接输出，处理：使用rewind(stdin) 清空缓存区的所有数据
    
    
    //4. 交换值
   int num5 = 500, num6 = 600;

    //方式1：中间变量
   int temp = 0;
   temp = num5;
   num5 = num6;
   num6 = temp;
    
    //方式2：两数相加再相减，减
   num5 = num5 + num6;
   num6 = num5 - num6;
   num5 = num5 - num6;
    
    //方式3：使用异或
   num5 = num5 ^ num6;
   num6 = num5 ^ num6;
   num5 = num5 ^ num6;
   printf("交换后数据为num5=%d,num6=%d\n", num5, num6);
    
    
    //5. 算术运算符（+-*/%），算术表达式(由算术运算符拼接成的表达式，表达式都有一个结果)
    //5.1 基本 - 执行顺序：（1.声明）float num7 ->（2.计算）12.12 + 12.35 -> （3)返回的结果赋值给1. 即num7
   float num7 = 12.12 + 12.35;
   printf("%f\n", num7);    //24.469999
   printf("%fl\n", num7);   //24.470000l
    
    //5.2 操作数是什么类型，返回即为什么类型： 10/4 返回整数：2, 解决：可以用强制转换
   int num8 = 10, num9 = 4;
   double sum1 = num8 / num9;
   printf("%fl\n", sum1);   //2.000000l

    //强制转换：
   double sum2 = num8 / (double)num9;
   printf("%fl\n", sum2);   //2.500000l
    
    //5.3 char
   char a = 'a';
   char A = 'A';
   int sum = a + A;
   printf("sum = %d\n", sum);  //162
    
    //大小写转相差32
   char up = 'a' - 32;          //转大写
   char down = 'A' + 32;
   printf("大写 = %c， 小写 = %c\n", up, down);
    
    
    //6. 复合赋值运算符（+=,-=,*=,/=）
   int num10 = 10;
   num10 += 5;
   printf("%d\n", num10);   //15
    
    
    //7. 自增/减运算符
   int num11 = 10, num12 = 10;
   num11++;
   ++num12;
   printf("%d\n%d\n", num11, num12);  // 11, 11
    
    //7.1 自增后赋值
   int i1 = 1;
   int k1 = i1++;
   printf("%d\n%d\n", i1,  k1);  //2，1
    
    //7.2 自增前赋值
   int i2 = 1;
   int k2 = ++i2;
   printf("%d\n%d\n", i2, k2);  //2，2
    
    //7.3 自增综合例子
   int i = 1;
   int j = 2;
   int sum = i++ + ++j + ++i;  // 1/2 + 3/3 + 2/3  = 6
   printf("%d\n", sum);   //6

    
    //8. 逗号运算符, 只计算最后一个表达式如：i+j+k, 前后的只做计算过程
   int i = 0, k = 1, j = 2;
   int sum1 = (i+1, k+1, j+1, i+j+k);  //3
   int sum2 = (i++, k++, j++, i+j+k);  //6
   printf("%d\n", sum1);
    
    
    //9. 比较表达式 <,>,=,<=,>=,!=,== 返回的值是bool值, 非0为真，用int的变量保存结果
    int num1 = 1, num2 = 2;
    int num3 = num1 > num2;
    printf("%d\n", num3);   //假：0,  条件反过来即为真：1
    
    int num4 = num1 + num2 > 3;  // 先计算 num1 + num2 计算出的结果，再与 3运算 结果：0
    printf("%d\n", num4);   //假：0
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;

}
