#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {

    //1 逻辑运算符-优先级是：！，&&，||， 注: 正数取反为（！）0
   int num1 = 10;
   int num2 = 20;
   int res = num1 > 0 && num2 > 10;
   printf("%d\n", res);   //1
    
    //逻辑短路
   int i = 1, j = 1, k = 1;
   int res1 = i++ > 10 && ++i < 0;  //i++ > 10 为假时(结果已明)，后面的不再执行，称为短路
   int res2 = j++ >  0 && ++j < 0;  //j++ > 0, 为真时，后面的要参与计算
   int res3 = k++ >  0 || ++k < 0;  //k++ > 0，为真时(结果已明)，后面的不再执行，称为短路
   printf("%d\n%d\n", res1, i);     //0,2
   printf("%d\n%d\n", res2, j);     //0,3
   printf("%d\n%d\n", res3, k);     //1,2
    
    
    
    //2 if, else
   int i = 1;
   if(i){
       printf("为真\n");    //为真：
   }else{
       printf("为假\n");
   }
    
    //作用域
   int k = 1;
   if(k > 0){
       k = 2;                       //在不同的作用域可以定义相同的变量
       printf("if里面的K=%d\n", k);  //2
   }//招待到这里if里面的k值被内存回收
   printf("if外面的K=%d\n", k);      //1 注：此k执行到外面大扩号也会被内存回收
    //注意：大扩号是一段代码块，下面的代码是会执行的。这样写法也可以提前释放回收
   {
       printf("10\n");
   }
    
    
    //3. if else if
   int j = 0;
   printf("请输入分数:");
   scanf("%d", &j);
   if(j >= 60 && j <= 80){
       printf("%d 及格\n", j);
   }else if(j > 80 && j <= 100){
       printf("%d 优秀\n", j);
   }else{
       printf("%d 不及格\n", j);
   }
    
    
    //4 三元表达式 _? 值1 : 值2; 为真时就是值1，否则为值2
   int num = 1;
   int res = num > 0 ? 100 : 200;
   printf("%d\n", res);   //100

    
    //随机数
   int random1 = arc4random_uniform(10);       //0-9的随机数
   int random2 = arc4random_uniform(11) + 10;  //10-20的随机数，规则：（20-10+1）+ 10
   
   printf("%d\n", random2);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
