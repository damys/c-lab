
#include <stdio.h>

//1. 按值传递
void test1(int num)
{
    num++;
}

//2. 数组参数按址传递
void test2(int arr[], int len)
{
    arr[0]=20;
}

//3. 指针按址传递
void test3(int* p)
{
    *p = 30;
}

//返回1个数组中最大值与最小值，注：函数只能返回一个值。
//方式2：可以不返回值，声明两个指针，max, min，将数的结果最后赋值给两个指针：*min = min; *max = max;
int getMaxAndMin(int arr[], int len, int* min)
{
    int max = INT32_MIN;
//    int min = INT32_MAX;
    *min = INT32_MAX;
    
    for(int i=0; i<len; i++){
        if(arr[i] > max){
            max = arr[i];
        }else if(arr[i] < *min){
            *min = arr[i];
        }
    }
    
    return max;
}


int main(int argc, const char * argv[]) {
    /**
        *  变量的值：存储在变量中的数据
        *  变量的地址：1个变量是由1个或者多个字节组成的，组成这个变量的低字节的地址，就是这个变量的地址
        *  变量的地址就叫做指针，指针就是地址
        
        *  int* p1  p1 只能存储int变量的地址，否则就会出现其它问题
        *  char* p2
        *  double* p3
        *  float* p4
        *  写法三种：int* p1(推荐写法);int * p1; int *p1;
        */

    int num = 100;   //如地址：0x11001
    int* p1 = &num;   //他存的是地址0x11001，他指向num变量。他本身也有地址：0x21001

    printf("变量num的地址：%p\n", &num);  //0x7fff5fbff83c
    printf("指针p1中存的地址：%p\n", p1);  //0x7fff5fbff83c
    printf("指针p1的地址：%p\n", &p1);    //0x7fff5fbff830

    printf("%d\n", num);    //100
    printf("%d\n", *p1);    //100  num = *p
    *p1 = 200; //间接操作（赋值，取值）num变量
    printf("%d\n", num);    //200

    //批量声明指针：int* p1, *p2, *p3
    //野指针：声明一个指针，如果没有初始化，其指针变量中存的地址是随机值，垃圾址，就有可能会指向其它地址, 这样相当危险了
    //指针初始化可以为：NULL。 NULL 等价于 0

    //多个指针指向一个变量，都可以操作指向变量的值


    //使用指针
    //1. 参数是按值传递
    int num = 0;
    int sum = test1(num);
    printf("%d\n", sum);    //0

    //2. 参数数组是按地传递
    int arr[]={2,3,4};
    test2(arr, 3);
    printf("%d\n", arr[0]);  //20

    //3. 参数指针是按地传递
    int num = 0;
    test3(&num);
    printf("%d\n", num);     //30


    //函数只能返回一个值，可以增加一个指针参数，如：int* p1， *p = 可以当变量名来操作
    int arr[] = {2,13,4,15,7,3,5};
    int min = 0;
    int max = getMaxAndMin(arr, sizeof(arr)/sizeof(arr[0]), &min);

    printf("min:%d, max:%d\n", min, max);   //min:3, max:15


    //名种类型的指针的大小都是占8个字节
    char* name = NULL;
    printf("%d\n", sizeof(name));

    //p1指针变量中存储的是num变量的地下，也就是num变量的低字节地址，通过这个p1指针只能找到这个地址的低字节地址
    //通过指针操作变量赋值时，是要根据其相同变量的类型来操作多少个字节
    int num = 0;
    int* p1 = &num;
    *p1 = 50;

    //指针的类型
    int num = 300;
    char* p1 = &num;
    *p1 = 97;
    printf("%d\n", num);   //353   只会修改第一个字节，第二个到第四个字节不会被修改
    printf("%c\n", *p1);   //a
    
    
    //多级指针及级别
    /**
     *  声明一级指针：数据类型*   指针名   注：只能存储普通变量的地址
     *  声明二级指针：数据类型**  指针名
     *  声明三级指针：数据类型*** 指镇名
     */
    int num =  10;
    int*   p1 = &num;  //存储的是普通变量的地址
    int**  p2 = &p1;
    int*** p3 = &p2;

    *p1 = 15;   //num = 15

    printf("num 的地址：%p\n", &num); //0x7fff5fbff7dc
    printf("p1 的值：%p\n", p1);      //0x7fff5fbff7dc
    printf("p1 的地址：%p\n", &p1);   //0x7fff5fbff7d0
    printf("p2 的值：%p\n", p2);      //0x7fff5fbff7d0
    printf("p2 的地址：%p\n", &p2);   //0x7fff5fbff7c8
    printf("p3 的值：%p\n", p3);      //0x7fff5fbff7c8
    printf("p3 的地址：%p\n", &p3);   //0x7fff5fbff7c0


    //使用指针的时候，有几个*就要转几个弯
    int num1 = 10;
    int*  p1 = &num1;
    int** p2 = &p1;

    *p1 = 200;
    printf("num:%d\n", num1);  //200

    int num2 = 100;
    *p2 = &num2;
    printf("num1:%d\n", num1);  //200
    printf("num2:%d\n", num2);  //100
    printf("*p1:%d\n", *p1);    //100


    int num =  10;
    int*   p1 = &num;
    int**  p2 = &p1;
    int*** p3 = &p2;
    /**
        *p1   代表num
        **p2  代表num
        ***p3 代表num
     */
    printf("*p1:%d\n",*p1);      //10
    printf("**p2:%d\n",**p2);    //10
    printf("***p3:%d\n",***p3);  //10
    
     /**
       *p2  代表p1
       *p3  代表p2
       **p3 代表p1
     */
    printf("*p2:%p\n",*p2);    //0x7fff5fbff7dc  与&p1 的地址一样
    printf("*p3:%p\n",*p3);    //0x7fff5fbff7d0  与&p3 的地址一样
    printf("**p3:%p\n",**p3);  //0x7fff5fbff7dc  与&p1 的地址一样

    printf("p1 的值：%p\n", p1);      //0x7fff5fbff7dc
    printf("p1 的地址：%p\n", &p1);   //0x7fff5fbff7d0
    printf("p2 的值：%p\n", p2);      //0x7fff5fbff7d0
    printf("p2 的地址：%p\n", &p2);   //0x7fff5fbff7c8
    printf("p3 的值：%p\n", p3);      //0x7fff5fbff7c8
    printf("p3 的地址：%p\n", &p3);   //0x7fff5fbff7c0
    
    
    /**
     *  指针加减:加一个单位类型变量所占的地址。如：*int:4, *double:8
     */
    int num1 = 10;
    int num2 = 20;
    int* p1 = &num1;
    int* p2 = p1 + 1;
    int* p3 = p1 - 1;
    printf("p1=%p\n", p1);       //0x7fff5fbff7dc
    printf("p2=%p\n", p2);       //0x7fff5fbff7e0  可以看出+4（int）

    printf("p3=%p\n", p3);       //0x7fff5fbff7d8
    printf("num2=%p\n", &num2);  //0x7fff5fbff7d8
    printf("*p2=%d\n", *p2);//垃圾值
    printf("*p3=%d\n", *p3);//20  内存是的地址是由高到低连续分配的
    
    //数组元素与指针
    int arr[3]={10, 20, 30};
    int* pa0 = &arr[0];
    int* pa1 = &arr[1];
    int* pa2 = &arr[2];

    *pa0 = 100;
    *pa1 = 200;
    *pa2 = 300;
    //这个数组值就为：100，200，300
    
   int* p1 = arr;  //==&arr[0]  从最低位开始分配，arr 代表数据的地址，也是第0个元素地址
    //*p1 代表数组中的第0个元素
    //*(p1+1) 数组中的第1
   printf("*p1=%d\n", *p1);          //100
   printf("*(p1+1)=%d\n",*(p1+1));   //200 为相邻的地址。+1 为int 4 长度
    
    //使用指针第1种：
    for(int i=0; i<3; i++){
        printf("%d\n", *(p1+i));  //100, 200, 300
    }
    
    //使用指针第2种：
    for(int i=0; i<3; i++){
        printf("%d\n", *(arr+i));  //100, 200, 300 //注意 不能写：arr++， 不能给数组名赋值，因为数组名代表数组，而数组一创建地址就不会变，是一个变量
    }
    
    //使用指针第3种：注意：第2次遍历会变化，因最后一次执行就会执行到外面了，因此要重新指定： p1 = arr
    p1 = arr;
    for(int i=0; i<3; i++){
        printf("%d\n", *(p1++));  //100, 200, 300
    }
    
    
    /**
     *  在声明数组作为参数时，是按地址传递的，实际上是一个指针。指向第一个元素的地址
     *  所以，可以直接写指针，代替写数组，更高效： 
     *  test(int arr[], int len {...}
     *  test(int* arr, int len) {...}  苹果的类库也是采用这种方式写的
     */
    
    /**
     *  索引
     *  p1[n] == *(p1+n), 只要是指针都可以使用中括弧[]
     */
    
    int num1 = 10;
    int num2 = 20;
    int* p1 = &num2;    //当为&num1 是，num1=100, num2=20

    p1[0] = 100;   // ==*(p1 + 0)
    p1[1] = 200;   // ==*(p1 + 1)
    printf("num1=%d\n", num1);   //200
    printf("num2=%d\n", num2);   //100
    
    
    /**
     *  数组存储指针：int* arr[3];
     */
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;

    int* p1 = &num1;
    int* p2 = &num2;
    int* p3 = &num3;

    int* arr[3] = {p1, p2, p3};  //也可以写： int* arr[3] = {&num1, &num2, &num3}
    for (int i=0; i<3; i++) {
        printf("arr[%d]=%p\n", i, arr[i]);
    }
    printf("%p\n", &num1);  //0x7fff5fbff7bc
    /*
     这三个数的地址
     arr[0]=0x7fff5fbff7bc
     arr[1]=0x7fff5fbff7b8
     arr[2]=0x7fff5fbff7b4
     */
    
    //数组扩展
    int arr[3] = {10, 20, 30};
    int* pArr[3] = {arr, &arr[1], &arr[2]};

    for (int i=0; i<3; i++) {
        printf("arr[%d]=%p\n", i, pArr[i]);
    }
    printf("arr[0]=%p\n", &arr[0]);
    /*
     arr[0]=0x7fff5fbff7dc
     arr[1]=0x7fff5fbff7e0
     arr[2]=0x7fff5fbff7e4
     
     arr[0]=0x7fff5fbff7dc
     */
    
    //指针与指针之间的减法（只能做减法运算）,用于判断两个元素之间相差多少个元素,注意要为相同的类型，一般都为数组，即跟类型有关
    //先求出两个指针的差 / 每1个指针变量对应的普通变量占有的字节数
    int arr[]={10,20,30,40,50};
    int* p1 = &arr[1];
    int* p2 = &arr[2];
    int* p3 = &arr[4];

    long res = p1 - p2;  //-1
    long res = p2 - p1;  //1
    long res = p3 - p1;    //3
    printf("p1-p2=%ld\n", res);
    
    
    //指针与指针之间可以做比较运算：>,>=,<,<=,==,!=..., 比较字节的高地址与低地址，先声明变量为高地址
    int num1 = 10;
    int num2 = 20;

    int* p1 = &num1;    //*p1  指向的变量，可以直接赋值
    int* p2 = &num2;

    // int res = p2 > p1;  //p2的值是否大于p1的值  == 0
    int res = p1 > p2;    //变量分配字节空间地址是由高到低分配  == 1
    printf("p1 > p2:%d\n", res);
    
    
    
    return 0;
}
