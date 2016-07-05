#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    //1. switch case
   int num1 = 0, num2 = 0, res = 0;
   char ch = 0;
   
   printf("请输入第一个操作数：");
   scanf("%d", &num1);
   printf("请输入第二个操作数：");
   scanf("%d", &num2);
   
   rewind(stdin);  //清除缓存中的数据，包括：回车，空格， 或者这么输入： scanf("%d%c%d", &num1,&ch,&num2);
   printf("请输入操作符:");
   scanf("%c", &ch);

   printf("num1=%d ch=%c num2=%d\n", num1, ch, num2);

   switch ( ch ) {  //可以是表达式，变量，常量
       case '+':
           res = num1 + num2;
           break;
       case '-':
           res = num1 - num2;
           break;
       case '*':
           res = num1 * num2;
           break;
       case '/':
           res = num1 / num2;
           break;
           
       default:
           printf("输入错误！");
           break;
   }
   printf("结果为：%d\n", res);
    
    
    //2. 调试
   int num = 0;  //调试模式时：将鼠标放在num上，可以查看当前的值
   num++;
   ++num;
   num += 5;
   printf("num=%d\n", num);
    
    
    //2. while
    //产生10个随机数，每产生1个，就显示他是偶数还是奇数
   int i = 0;
   while (i < 10)
   {
       int num = arc4random_uniform(100)+1;
       if(num % 2 == 0){
           printf("这个数%d是偶数\n", num);
       }else{
           printf("这个数%d是奇数\n", num);
       }
       i++;
   }
    
    //判断密码输入直到正确
   int pwd = 0;
   while (pwd != 123456) {
       printf("请输入正确密码:");
       scanf("%d", &pwd);
   }
   printf("输入密码正确\n");
    
    //1000 到 5000 的各位数相加等于5
   int i = 1000;
   while (i <= 5000) {
       int qw = i /1000;
       int bw = i % 1000 /100;
       int sw = i % 1000 % 100 /10;
       int gw = i % 10;
       
       if(qw + bw + sw + gw == 5){
           printf("%d\n", i);
       }
       i++;
   }
    
    
    //3. break, continue 在循环体内结束循环
   int i = 1;
   while (i <= 4) {
       printf("%d\n", i);
       i++;
       
       if( i == 3){
           continue;  //后面的continue exe 不会被执行到
       }
       printf("continue exe\n");
       //i++;  //在此处为死循环
   }
    /* 输出：
     1
     continue exe
     2
     3
     continue exe
     4
     continue exe
     */
    
    //计算二个随机数的结果，并打分
   int i = 0;
   int score = 10;
   
   while (i < 3) {
       int num1 = arc4random_uniform(90)+10;
       int num2 = arc4random_uniform(90)+10;

       printf("请听第%d题：%d + %d = \n", i+1,num1, num2);
       int sum = 0;
       printf("请输入结棍:");
       scanf("%d", &sum);
       if(num1 + num2 == sum){
           printf("计算正确\n");
           score++;
       }else{
           printf("计算不正确\n");
           score--;
       }
       printf("你的得分是：%d\n",score);
       
       i++;
   }
   
    //猜随机数-随机条件不确认
   int num = arc4random_uniform(100)+1; // 随机数：1-100
   int guess = 0;
   
   while (guess != num) {
       printf("请输入你猜的1-100的猜数数:");
       scanf("%d", &guess);
       if(guess > num){
           printf("猜的数过大\n");
       }else if(guess < num){
           printf("猜的数过小\n");
       }
   }
   printf("猜正确\n");
    
    //求5个数的最小数
   int max = INT32_MIN;
   int num = 0;
   int i = 1;
   
   while(i <= 5){
       printf("请输入5个数的第%d个数:", i);
       scanf("%d", &num);
       
       if(num > max){
           max = num;
       }
       
       i++;
   }
   printf("五个数的最小数为：%d\n", max);
    
    //随机产生10个3-200的随机数，求最大数
   int max = INT32_MIN;
   for (int i=1; i<=10; i++) {
       int num = arc4random_uniform(198) + 3;
       printf("随机数是%d\n", num);
       
       if(num > max){
           max = num;
       }
   }
   printf("随机数的最大值是：%d\n", max);
    
    //本金10000元存入银行，年利率是千分之3，每过一年，将本金与利息相加作为新的本金，计算5年后，获得的本金是多少？
    /*
    第1年  10030
      2   10030 * 1.003
      3   10030 * 1.003 * 1.003
     */
   double money = 10000;
   for (int i=1; i<=5; i++) {
       money *=1.003;
   }
   printf("5年后获得的本多是%.2f\n", money);
    
    
    
    //求输入5个学生年龄的平均值，如者年龄为负数， 大于100结束输入，并给出提示
   int age = 0;
   int total_age = 0;
   int i = 0;
   int flag = 0;   //第二个种处理，定义一个标识符
   
   while (i < 5) {
       printf("请输入5个学生的第%d个人年龄：", i+1);
       scanf("%d", &age);
       
       if(age < 0 || age > 100){
           printf("输入的年龄有误，结束输入\n");
           flag = 1;
           break;
       }
       
       total_age += age;
       
       i++;
   }
    
   if(i == 5){
       printf("这5个学生的年龄的平均值是：%.2f\n", total_age * 1.0 / 5);
   }
   if(flag == 0){
       printf("这5个学生的年龄的平均值是：%.2f\n", total_age * 1.0 / 5);
   }
    
    
    //穷举
    // 如：有100多个人排队，3个人1组，多1， 4个人1组，多4， 5个人1组，多5
   int i = 100;
   
   while (i < 200) {
       if(i % 3 == 1 || i % 4 == 4 || i % 5 == 5){
           printf("这个队有%d人\n", i);
       }
       
       i++;
   }
    
    
    //do while
   int i = 1;
   
   do{
       printf("%d\n", i);
       i++;
   }while(i <= 5);
    
    
    //for
    //如：计算100-199的水仙花数（各个位的立方相加等于这个数的本身））
   for(int i = 100; i<=199; i++){
       int bw = i / 100;
       int sw = i % 100 / 10;
       int gw = i % 10;
       
       int sum = bw * bw * bw + sw * sw * sw + gw * gw * gw;
       if(sum == i){
           printf("水仙花数有：%d\n", i);
       }
   }
    
    /*
     打印出：
     *
     **
     ***
     ****
     *****
     第1行 打1个
     2      2
     3      3
     4      4
     5      5
     i      i
     */
   for(int i = 1; i<=5; i++){
       for(int j = 1; j<=i; j++){
           printf("*");
       }
       printf("\n");
   }
    
    
     /*
      打印出
     *
     **
     ***
     ****
     *****
     ****
     ***
     **
     *
     下半部分分析：
     第1行  4
       2   3
       3   2
       4   1
       i   5-i
     */
    //上半部分
   for(int i = 1; i<=5; i++){
       for(int j = 1; j<=i; j++){
           printf("*");
       }
       printf("\n");
   }
    //下半部分
   for(int i = 1; i<=5; i++){
       for(int j = 1; j<=5-i; j++){
           printf("*");
       }
       printf("\n");
   }
    
    /*
     打印出：
         *
        **
       ***
      ****
     *****
     第1行 空格4 星1
       2     3   2
       3     2   3
       4     1   4
       5     0   5
       i     5-i i
     */
   for (int i=1; i<=5; i++) {
       for(int j=1; j<=5-i; j++){
           printf(" ");
       }
       for (int k=1; k<=i; k++) {
           printf("*");
       }
       printf("\n");
   }
    
    //九九乘法口决
    /*
     第1行 1个
       2   2
       3   3
       i   i
     */
    
   for (int i=1; i<=9; i++) {
       for (int j=1; j<=i; j++) {
           printf("%d * %d = %d \t", i, j, i*j);
       }
       printf("\n");
   }
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
