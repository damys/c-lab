#include <stdio.h>
#include <stdlib.h>


/**
 *  show_name
 */
void show_name(){
    printf("this is function\n");
}

/**
 *  计算二个数的和
 *
 *  @param num1 操作数1
 *  @param num2 操作数2
 *
 *  @return 一个结果
 */

//int sum();  //处理函数声明要在main函数前面问题；位子要求：要在调用函数的前面（也可以在main里面）

int sum(int num1, int num2)
{
    int result = 0;
    result = num1 + num2;
    return result;
}

int main(int argc, const char * argv[]) {
    
    //goto 可以将cup的执行跳转到指定的地方，可以前后跳转，只参在当前函数中跳转，跳转的地不能在声明变量（重复定义）的前面
    //下面程序会出现死循环
   int num = 0;
loop://标签名，随意
   //int num = 0;   //报错，跳转的地不能在声明变量的前面
   printf("aaa%d\n", num);
   printf("bbb\n");
   printf("ccc\n");
   printf("ddd\n");
   goto loop;
    
    /*
     返回值 函数名（参数）{
        函数体；
     }
     
     */
    
    show_name();
    
    printf("%d\n", sum(2,3));

    
    return 0;
}


