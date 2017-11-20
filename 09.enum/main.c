
#include <stdio.h>
#include <stdlib.h>

int* test1(){
    int arr[] = {10, 20, 30};
    return arr;
}

int* test2(){
    int* arr = calloc(3, sizeof(int));
    *arr = 10;
    *(arr+1) = 20;
    *(arr+2) = 30;
    return arr;
}

void test3(){
    printf("指向函数的指针-调用\n");
}

//结构体与函数1-作参数-按值传递,
struct Student{
    char* name;
    int age;
    int score;
};
void isPost(struct Student stu){
    if(stu.score > 60){
        printf("%s及格了\n", stu.name);
    }else{
        printf("%s不及格\n", stu.name);
    }
}
//使用指针, 这样就可改值了
void isPost(struct Student* stu){
 stu.score  = 100;
}


//结构体与函数1-作返回值
struct Student getOneStuden(){
    struct Student stu1 = {"Tom", 24, 98};
    return stu1;
}



int main(int argc, const char * argv[]) {
    /*
    1. 指针作为函数的参数。
            效果：在函数的内部可以通过函数去修改实参的值。
            使用：当函数的参数有多个时
            用只不修改：在这个参数的指针加上coust 修饰
    2. 指针作为函数的返回值
       如果你要返回一个指针，那么你就要保证这个指针指向的空间在函数结束后仍然存在
       解决：可以将空间申请在堆区, 如：callor... 使用完要free
       如果返回值是字符串/int数组，返回类型就为：char*, int*
    
    3. 返回值可以返回局部的值，但地址是返回不了
     
    4. 指向函数的指针
       代码及代码中的函数是存储在代码段的，也就存在一个存储地址。 这样就可以申请一个指针，指向这个地址，就可以调用这个函数
       调用函数就有2种方式：1是函数名调用，2是使用指针间接调用
     声明函数指针：
        a. 要求指向的函数的返回值类型和参数描述必须要与指针的描述一样
        b. 声明语法：如：void (*pFunction)();
        c. 初始化：取到符合条件的函数的地址（函数名），将地址赋值给指针变量。void (*pFunc)() = test2;
        d. 调用：(*pFunc)() 或 pFunc();  有参数就给，有返回值就接
     
     */
    
   int* arr = test1();      //10, 0, 0  局部被回收，可以找到地址，但数据只能找到低字节
   int* arr = test2();      //10, 20, 30
   for (int i=0; i<3; i++) {
       printf("%d\n", arr[i]);
   }
   free(arr);  //使用完calloc(）要free
    
    
    //指向函数的指针-赋值
   void (*pTest3)() = test3;
    //指向函数的指针-调用。 有2种方式
   pTest3();     //方式1
   (*pTest3)();  //方式2
    
    
    
    /*
     数组类型要求类型一致
     结构体---就是创建一个自定义的数据类型
     a. 结构体类型变量语法：struct Student{ 类型 变量的名； };  代表创建了一个新的数据类型
     b. 结构体声明：struct Student stu;可以批量声明 struct Student stu1, stu2;
     c. 初始化：为结构中的小变量赋值
     
     可以简化一步：struct Student{ ... } stu;
     
     注：匿名结构体：指没有指定名，用的较少
     
     作用域：定义在函数内部，只能在函数内使用，（一般情况下，让所有函数用）定义在函数外部，就相当于全局结构体
     相互赋值：相同结构体的变量是可以相互赋值的。
     
     */
    
   //1. 只创建了一个Student 的数据类型，存在内存的代码段
   struct Student{
       char* name;
       int age;
       float height;
   };
   //2. 数据类型的声明
   struct Student stu;   //就会在内存中开空间， 类型为：struct Student
   //3. 初始化  是值传递
   stu.name = "Tom";
   stu.age = 25;
   stu.height = 17.8;
    
      //合并第2，3项, 要按顺序
   struct Student stu = {"Tom", 25, 17.8};                    //方式1
   struct Student stu = {.name="Tom", .age=25, .height=17.8}; //方式2
    
   //4. 输出
   printf("name=%s age=%d, height=%.2f\n", stu.name, stu.age, stu.height);
   
   //可以自定义这个类型
   struct Student json;
   json.name = "CC";
   json.age  = 27;
   json.height = 18.2;
    
    
    /**
     结构体数组。语法 struct Student students[2];
     结构体数组。长度：sizeof(students)/sizeof(struct Student);
     */
   struct Student{
       char* name;
       int age;
       float height;
   };
    //初始化1
   struct Student students[2];
   struct Student stu1 = {"Tom", 25, 17.8};
   struct Student stu2 = {"jack", 23, 18.2};
   students[0] = stu1;
   students[1] = stu2;
    
    //初始化2
   struct Student students[2];
   students[0] = (struct Student){"Tom", 25, 17.8};
   students[1] = (struct Student){"jack", 23, 18.2};
    
    //初始化3. 长度可以省掉
   struct Student students[] =
   {
       {"Tom", 25, 17.8},
       {"jack", 23, 18.2}
   };
    
    
    //输出
   for (int i=0; i<2; i++) {
       printf("姓名：%s, 年龄：%d, 身高：%.2f\n",
              students[i].name,
              students[i].age,
              students[i].height);
   }
    
    //结构体长度
   int len = sizeof(students)/sizeof(struct Student);
   printf("长度为：%d\n", len);   //2
    
    
    //结构体嵌套
   struct Date{
       int year;
       int month;
       int day;
   };
   struct Person{
       char* name;
       int age;
       float height;
       struct Date birthday;   //嵌套结构体
   };
   //初始化
   struct Person stu = {"tom", 24, 18.3, {2016, 07, 12}};
   printf("姓名:%s, 年龄:%d, 身高:%.2f, 出身年月日:%d-%d-%d\n",
          stu.name,
          stu.age,
          stu.height,
          stu.birthday.year,
          stu.birthday.month,
          stu.birthday.day);
    //姓名:tom, 年龄:24, 身高:18.30, 出身年月日:2016-7-12
    
    
    //结构体与函数1-作参数-是按值传递
   struct Student stu1 = {"Tom", 20, 65};
   isPost(stu1);   //Tom及格了
    
    //结构体与函数2-作返回值
   struct Student s1 = getOneStuden();
   printf("name:%s, age:%d, score:%d\n",
          s1.name,
          s1.age,
          s1.score);
    //name:Tom, age:24, score:98
    
    
    
    /* 结构体指针
       初始化:使用结构体变量的地址使用&,将地址赋值给指针变量
     */
   struct Student tom = {"tom", 24, 18.1};
   struct Student* pStu = &tom;
    //第一种方式
    (*pStu).name = "Jack";   //扩起来是因为优先级问题
    
    //第二种方式
   pStu->name = "Jack";
    
    //打印出
   printf("name:%s, age:%d, score:%d\n",
                     tom.name,
                     tom.age,
                     tom.score);
    //name:Jack, age:24, score:18
    
    
    
    
    /**
     *  枚举 可以让程序员新创建1个数据类型，这个数据类型的变量的取值被限定
     作用域:定义在函数内为局部,定义在函数外为全局
     1. 创建一个枚举类型
     enum 新类型
        { 
          枚举值1，枚举值2....
        };
        
     2. 声明变量：enum 新类型 变量名；
     3. 初始化：变量值只能存储枚举中已定义的枚举值
     每1个枚举值都有一个对应数值，默认从0开始，依次的递增。类似为数组
     使用场景：如：按钮的状态（可用，不可用）
     长度: 无论是什么类型的枚举变量,都占4个字节
     存储: 枚举变量中真正存储的是 枚举值所对应的整型的数
     
     取枚举值要使用比较
     
     规范:
       1. 名 与 值首字母都要大写
       2. 值命名: 名 + 值
     
*/
   enum Direction
   {
       DirectionEast,    //0   //East = 10  即对应整型数为10,可以指定
       DirectionSouth,   //1
       DirectionWest,    //2
       DirectionNorth    //3
   };
   
   //enum Direction dir = 0;    //可以这么写,可读行差
   enum Direction dir = DirectionSouth;
   printf("%d\n", dir);  //1
   
   int len = sizeof(dir);
   printf("%d\n", len);    //4个字节
    
    
    /*
     typedef  类型定义, 作用:为一个已经存在的数据类型取1 个别名
     语法: typedef int nums;    //别名为 nums
     
     系统中"size_t" 就是 自定义类型, 其实就是unsigned long
     
     使用场景: 
         1. 数据类型过长.
        unsigned long long int num = 100;
        //取别名
        typedef unsigned long long int nums;
        nums = 100;
     
         2. 结构体也可以取别名,不过名子最好一样
         方式1:
         struct Student{
             char* name;
             int age;
             int score;
         };
         typedef struct Student Student;
         Student stu1;
         
         //方式2 声明同时
        typedef struct Student{
             char* name;
             int age;
             int score;
         } Student;
        Student stu1;
     
        //方式3 最常用: 声明匿名结构体的同时,就使用typedof 来为结构体类型取1 个别名
         typedef struct {
             char* name;
             int age;
             int score;
         } Student;
         Student stu1;
     
        3. 枚举取别名
        //方式1
         enum Direction
         {
             DirectionEast,    
             DirectionSouth,
             DirectionWest,
             DirectionNorth
         };
         typedef enum Direction Direction;
     
        //方式2 声明同时
         typedef enum Direction
         {
             DirectionEast,
             DirectionSouth,
             DirectionWest,
             DirectionNorth
         } Direction;
     
        //方式3: 最常用: 声明匿名结构体的同时,就使用typedof 来为结构体类型取1 个别名
         typedef enum Direction
         {
             DirectionEast,
             DirectionSouth,
             DirectionWest,
             DirectionNorth
         } Direction;
     */
    typedef int nums;
    nums num1 = 10;
    printf("%d\n", num1);
    
    //自定义一个string 类型, 就可以使用sting 代替 char*
    typedef char* string;
    string name = "jack";
    printf("%s\n", name);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
