
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    /*
     字符串数据在C语言中的存储
     1. 使用字符数组来存储：将每个字符串都所加到数组，后加\0。
         char name[3] = {'a', 'b', '\0'};
         char name[]  = {'a', 'b', '\0'};
         char name[]  = {'abc'};  //系统会自动添加\0, 前提是字符数组的长度够
         char name[]  = 'abc';    //一般是这样使用
     
     2. 使用字符指针来存储
     char* name = "abc";   //注意要使用双引号
     
     3. 区别
         a. 当他们都是局部变量的时候
            char name1[]  = "aaa";  //申请在栈区 长度为4，因后要加\0
            char* name2[] = 'bbb';  //局面变量指针指向常量区，在栈区; ”def”是字符串数组存储在常量区，长度为4
         b. 存储的结构不同，可变与不可变
     
     4. 字符串数组有2种：1. 字符的二维数组，2. 字符指针数组
    */
    
    char name1[]  = "aaa";
    char* name2   = "bbb";    //bbb 是存储在常量区
    printf("name1[]的地址：%p\n", name1);  //0x7fff5fbff7dc 栈区
    printf("* name2的地址：%p\n", name2);  //0x100000f7a    说明两个变量不要同一个区域

    name1[0] = 'j';  //注意要使用单引号
    *name2 = 'j';    //注意：不能修改指针指向的字符串数据， 常量区的值是不能修改的
    printf("name1[]的值为：%s\n", name1);  //jaa


    char* name = "abc";
    printf("name=%s\n", name);  //abc

    
    
    //字符串的恒定性：以字符指针形式存储字符串，其字符串数据是在常量区，指针变量是栈区
    char* name1 = "abc";
    char* name2 = "abc";
    char* name3 = "abc";

    //存储在常量区的值前，内存会检测是否存在，存在就进行存储，直接把地址赋给它
    printf("*name1指向的地址：%p\n", name1);  //0x100000f56
    printf("*name2指向的地址：%p\n", name2);  //0x100000f56
    printf("*name3指向的地址：%p\n", name3);  //0x100000f56

    name3 = "ccc";  //这样是可以重新初始化的，为新的地址. 注意：只能是指针
    printf("*name3指向的地址：%p\n", name3);  //0x100000fae
    
    
    
    //例题：求一个字符出现的次数。思路：遍历 判断直接结束\0
    char* str = "aaabbcc";
    int count = 0;  //计数器

    int i=0;
    while(*(str+i)){
        if(*(str+i) == 'a'){
            count++;
        }
        i++;
    }


    printf("a出现的次数:%d\n", count);  //3
    
    //普通字符数组存储的长度有限制，字符指针的长度方面有优势
    
    
    
    //字符串数组：使用一个二维字符数组，来存储多个字符串，每1行就是1个字符串
    char names[][10] = {
            "aa","bb","ccc"
        };
    for (int i=0; i<3; i++) {
        printf("%s\n", names[i]);  //aa, bb, cc
    }
    //上面这个使用有个缺点：第一个字符串的长度不能超过长度为9。9=10-1
    
    //这样就要使用指针, 长度就不限制
    char* names[4] = {"aa", "bb", "ccccccc"}; // 这样值就会存在常量区
    for(int i=0; i<4; i++){
        //printf("%s\n", *(names+i));   //aa, bb, ccccccc
        printf("%s\n", names[i]);   //aa, bb, ccccccc
    }
    
    
    //字符串的排序-冒泡排序-选择排序
    //1. 冒泡排序-按字符
    char* str[] = {"cc", "aa", "dd", "bb"};
    int len = sizeof(str)/sizeof(str[0]);    //如写8；指针长度都是占8个字节

    for(int i=0; i<len-1; i++){
        for(int j=0; j<len-1-i; j++){
            //比较两个字符串的ASCII码大小，大返1，小返-1， 等于返0。  要引用<string.h> 库
            int res = strcmp(str[j], str[j+1]);
            //交换位子
            if(res > 0){
                char* temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
    //打印结果
    for(int i=0; i<len; i++){
        printf("排序后为：%s\n", str[i]);
    }
    
    
    //2. 选择排序-按长度
    char* str[] = {"ccc", "aa", "d", "bbbb"};
    int len = sizeof(str)/sizeof(str[0]);    //如写8；指针长度都是占8个字节

    for(int i=0; i<len-1; i++){
        for (int j=i+1; j<len; j++) {  //二 二
            
            unsigned long len1 = strlen(str[i]);
            unsigned long len2 = strlen(str[j]);
            
            if(len1 < len2){
                char* temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    //打印结果
    for(int i=0; i<len; i++){
        printf("排序后为：%s\n", str[i]);  //bbbb, ccc, aa, b
    }
    
    
    /*
     fputs() 将字符串输出到 指定流中（标准输出流：控制台; 文件流：磁盘上的文件）
     fgets() 将这符串输入到 批定流中，安全，空间也会接收。以\n结束
                    scanf 不全安，输入空格会被认为结束。
                    gets 不安全
          解决：超过长度不会被显示, 也没有换行符. 即要判断最后一个字符是不是为\n, 如果是将\n 替换为\0
     
     fopen() 可以创建1个指同文件的指针:(url, w[r,a])
     fclose() 关闭
     */
    char* name = "hello world";
    fputs(name, stdout);   //控制台输出
    
    //写入的文件
    FILE* pFile = fopen("/Users/Damys/c/program/base/08 pointer 02/file.txt", "a");  //w, a
    char* name = "hello world\n";
    fputs(name, pFile);
    fclose(pFile);
    
    //读取文件fgets(*, len, )  //注意第二个参数长度是len-1个，有\0
    char inputs[5];
    printf("请输入：");          //输入：123456
    fgets(inputs, 5, stdin);   //控制台：stdin 键盘流
    printf("%s\n", inputs);    //输出：1234    长度：len - 1
    
    //处理：判断最后一个字符是不是为\n, 如果是将\n 替换为\0
    char inputs[5];
    printf("请输入：");
    fgets(inputs, 5, stdin);
    unsigned long len = strlen(inputs);

    if(inputs[len - 1] == '\n'){
        inputs[len - 1] = '\0';
    }
    printf("%s\n", inputs);

    //fgets 读取文件
    FILE* pFile = fopen("/Users/Damys/c/program/base/08 pointer 02/file.txt", "r"); //r,a,w
    char content[32];
    fgets(content, 32, pFile);
    printf("读取的内容：%s\n", content);
    fclose(pFile);
    
    
    //const 是一个关键字，定义常量,即不可变性， 一般修饰基本数据类型：int,double,float,char
    const int num1 = 10; //写法1
    int const num2 = 20; //写法2
    
    //const 修饰数组的值是不能被修改的
    const int arr[4] = {1,2,3};
    arr[0] = 100;  //编译错误。是不能修改的
    
    /* 
        const 修饰指针，同样不能修改的
        写法1： const int* p1 = num;       *p1 是不能修改指向的值
        写法2： int* const p1 = num;       *p1 是能修改指赂的值
        写法3： const int* const p1 = num; *p1 是不能修改指向的值
     */
    int num1 = 10;
    const int* p1 = &num1;
    //*p1 = 100;  //编译错误。是不能修改的
    num1 = 100;   //这样是可以修改的

    int num2 = 20;
    int* const p2 = &num2;  //这样写下面的可可赋值，下面编译不会出错
    *p2 = 200;    //这样是可以修改的
    
    //const 使用场景，其值是不被修改的，只读
    /**
     *  在函数的参数是一个指针的时候，函数的内部是有可能会修改实参变量的值
     *  可以给参数加一个const, 指针也一样: void printArray(const arr[], int len){...}
     */
    
    
    /**
     *  内存管理:内存5大区域
     1. 栈区域： 存储局部变量  如：int num=10, int* p=&num。 num 与 p 都存储在栈区域
     2. 堆区域： 允许程序员手动的从堆申请空间来使用，要主动释放。除非程序结束  如：int 4, float 4....
     3. BSS段区域：   存储未初始化的全局变量/静态变量，因程序运行时其全局/静态变量都没有初始化
     4. 数据段/常量区：存储已初始化的全局变量/静态变量，与常量数据， 在main 外定义的变量
     5. 代码段区域：   存储程序代码/指令
     
     在堆区申请指定字节数的字节空间：<stdlib.h> 库
     malloc() 在堆内存中申请连续的参数个字节空间
        1. 参数只有一个(size_t 也就是unsigned long 类型),
        2. 返回的类型是：void *，代表没有类型的指针
        3. 返回的值是：第一个字节的地址
        4. 使用任意类型的指针变量存储。 类型可根据实际操作的申请空间
        如果要使用1个字节的操作，使用char
                4               int
                8               double
     注意：这们申请的地址是由低到高分配的（与常规相反）
          每次申请都是由0开始，每一次分配的地址不一定挨在一起
          单个申请的地址是依次分配的。如:malloc(4)
          如果申请失败就返回NULL,所以最好先判断一下：int* p1 = malloc(4); if(p1){ 申请成功 }
     使用完要释放堆空间：free(指针)
     
     calloc(int，sizeof(int))   向堆区申请指定的字节空间. 申请完系统会自动清零。几个 sizeof(类型)
     realloc()  向堆区申请指定的字节空间, 作用：扩容
     */
    int* p1 = malloc(4); //申请4个连续的字节空间, 如没有初始化分配就是垃圾值
    int* p2 = malloc(12); //相当于在堆中创建了1个长度为3的整型数组

    *p2 = 100;        //依次为每个地址赋值
    *(p2+1) = 200;
    *(p2+2) = 300;
    for (int i=0; i<3; i++) {
        printf("%d\n", p2[i]);  //100,200,300
    }
    free(p2);   //释放堆空间
    
    //calloc
    int* p1 = calloc(4, sizeof(int));  // 4 个 int 类型的数组
    if(p1){
        //赋值
        for (int i=0; i<3; i++) {
            p1[i] = i*10;
        }
        //打印
        for (int j=0; j<3; j++) {
            printf("%d\n", p1[j]);   //0,10,20
        }
        free(p1);
    }
    

    int* p2 = calloc(3, sizeof(int));
    *(p2+3) = 200;
    printf("%d\n", *(p2+3));   //200
    
    //realloc() 如果原来的空间有剩余空间不够扩容，就重新找1块足够的空间，将原来的数据拷贝过来，原来的空间被自动释放
    int* arr1 = calloc(5, sizeof(int));
    //int* p1 = calloc(10, sizeof(double));   //如果中间添加这句，arr1, arr2的地址就不一样了
    //给数组赋值，可以常用于数组
    for(int i=0; i<5; i++){
        arr1[i] = (i+1)*10;
    }
    //扩容
    int* arr2 = realloc(arr1, 100);
    //打印
    for (int j=0; j<5; j++) {
        printf("%d\n", arr1[j]);  //10,20,30,40,50
    }
    //对比两个扩容后的地址
    printf("arr1=%p\n", arr1);   //0x100200310
    printf("arr2=%p\n", arr2);   //0x100200310

    
    
    
    return 0;
}
