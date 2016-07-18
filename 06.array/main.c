
#include <stdio.h>
#include <stdlib.h>
#define LEN 10     //数组的长度可以定义为宏

void testArray(int arr[], int len){   //当函数的参数为数组.并不会创建数组，而是声明一个变量用来存储数组地址的，也做指针变量
    //在函数的内部，sizeof返回的长度为8，因为当数组作为参数传递时就会丢失的
    //int len=sizeof(arr)/sizeof(arr[0]);
    //解决：把长度传递给我，也就是增加一个参数：长度    
    for (int i=0; i<len; i++) {
       printf("%d\n", arr[i]);
    }    
}

/**
 *  判断一个数组中是否包含另一个数据
 *
 *  @param redBalls 数组
 *  @param 6        长度
 *  @param num      被测试的数据
 *
 *  @return 是否包含：0不包含，否则为包含
 */
int isContains(int redBalls[], int len, int num)
{
    for(int i=0; i<len; i++){
        if(redBalls[i] == num){
            return 1;
        }
    }
    return 0;
}

/**
 *  根据行，列，设置二维数组的值
 *
 *  @param cols 列数
 *  @param rows 行数
 *  @param arr  传入数组
 */
void setValue(int cols, int rows, int arr[][cols]){
    for(int i = 0; i<rows; i++){
        for( int j = 0; j<cols; j++){
            arr[i][j] = (i*j)+10;
        }
    }
}

/**
 *  遍历输出二维数组
 *
 *  @param cols 列数
 *  @param rows 行数
 *  @param arr  传入数组
 */
void enumrate(int cols, int rows, int arr[][cols]){
    for(int i = 0; i<rows; i++){
        for( int j = 0; j<cols; j++){
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
}


int main(int argc, const char * argv[]) {
    
    //初始化写法1：声明再初始化
    //int arr1[LEN];
    int arr1[3];
    arr1[0] = 2;
    arr1[1] = 3;
    arr1[2] = 4;
    printf("%d\n", arr1[1]);

    //初始化写法2：直接初始化
   int arr2[3] = {1, 3, 5};   //编译的时候会换成上面的形式, 先声明，再初始化。不能使用变量做为长度。
    
    //初始化写法3：长度可以省掉
   int arr3[] = {1,2,3,4,5,6};  //由大括弧的个数来确认的

    //初始化写法4：
   int arr4[3] = {1,2};    //只为数组前面的元素赋值，后面赋值的元素会自动初始化为0
    //初始化所有的元素为0： int arr[]={0};

    //初始化写法5：
   int arr5[] = {[1]=2,[2]=3};  //0,2,3
    
    //输出
   for (int i=0; i<3; i++) {
       printf("%d\n", arr5[i]);
   }
    
    
    //数组的地址：数组中最低字节的地址；数组中下标为0的元素的地址
   int arr[] = {2,3};
   printf("%d\n", arr[0]); //2
   printf("%p\n", arr);   //0x7fff5fbff7e0  数组名存储的是数组的地址
   printf("%p\n", &arr);  //0x7fff5fbff7e0
    
    
    //数组的长度：占用的字节数是一样的； 长度计算：sizeof(arr) / sizeof(数据类型)
    //例1：
    int arr[] = {2,3,4,5,6};
    int num = sizeof(arr);  //可以计算出数组占用总的字节数
    printf("总的字节数%d\n", num);            //20
    printf("数组的长度为：%d\n", num/sizeof(int));  //5
    
    //例2：
    int arr[] = {2,8,6,4,1};
    int min = INT32_MAX;
    int max = INT32_MIN;
    int temp = 0;

    for(int i=0, len = sizeof(arr)/sizeof(arr[0]); i<len; i++){
        if(arr[i] < min){
            min = arr[i];
            
        }else if(arr[i] > max){
            max = arr[i];
        }
        
        if(arr[i] < arr[i+1]){
            temp = arr[i];
        }
    }
    printf("最小值：%d\n", min);
    printf("最大值：%d\n", max);
    printf("最小值：%d\n", temp);
    
    
    //函数-数组为参数是作为地址传递
    int a[] = {1,2,3,4,5,6,7,8,9,10,11};
    testArray(a, sizeof(a)/sizeof(a[0]));  //此处的第一个参数a 为数组的地址
  
    

    //例子：数组随机：例子：生成双色球，红：33，兰：16 中随机出红：6，兰：1
    //1. 准备一个红色数组装6,兰色数组装1
    int redBalls[6]={0};

    //2. 随机出6个红色球
    for(int i=0; i<6;){
    //loop:  //2种
        printf("");
        int num = arc4random_uniform(33)+1;
        
        int res = isContains(redBalls, 6, num);
        if(res == 0){
            //不包含
            redBalls[i]=num;
            i++;        //3种:将循环体的i++ 去掉
        }else{
            //包含,重新回复执行
            printf("产生的随机数%d重复\n", num);
            //goto loop;  //1种：这样会产生0
            //i--;  //2种：将goto 去掉
        }
        
    }
    
    //3. 打印数组中随机产生的红色球
    printf("本期红色球：");
    for(int i=0; i<6; i++){
        printf("%d ",redBalls[i]);
    }
    printf("\n");
    
    
    //1. 选择排序：
    int arr[] = {2,5,21,4,6};
    int len = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<len-1; i++) {
        //拿下标0 跟后面的每个元素比较
        for(int j = i+1; j<len; j++){
            //如果下标0的值大于后面的每个元素值，就交换
            if(arr[i] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    //输出从小到大的排序后的数组
    for (int i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    
    //2. 冒泡排序
    int arr[] = {2,5,21,4,6};
    int len = sizeof(arr)/sizeof(arr[0]);

    //外层循环控制轮数，每循环1次，要完成1轮的比较
    for (int i=0; i<len-1; i++) {
        //内层循环，循环次数：len - i -1;
        for(int j=0; j<len-i-1; j++){
            
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    //输出从小大的排序后的数组
    for (int i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    
    //3. 二分法查找：中间数
    int arr[] = {2,5,8,14,16};
    int len = sizeof(arr)/sizeof(arr[0]);

    int min = 0;
    int max = len - 1;
    int mid = len / 2;
    int key = 14;

    //判断要找的数与中间数对比
    while (key != arr[mid]) {
        //判断大小关系
        if(arr[mid] > key){
            //说明在左边
            max = mid -1;
        }else if(arr[mid] < key){
            //说明在右边
            min = mid + 1;
        }
        mid = (max + min)/2;
    }
    printf("找到的这个数下标为:%d\n",mid);
    
    
    //4. 倒序,反转
    int arr[] = {2,5,8,14,16};
    int len = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<len/2; i++) {
        int temp = 0;
        //交换开始
        temp = arr[i];
        arr[i] = arr[len-i-1];  //最左边所最右边交换
        arr[len-i-1] = temp;
    }
    for (int i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    
    
    //二维数组：数组的元素需要2个下标来确认。组（行，列）
    //1.初始化
    int arr[2][3];   //所占的内存空间:2*3*4=24
    arr[0][0]=1;
    arr[0][1]=2;
    arr[0][2]=3;
    arr[1][0]=4;

    //2. 初始化：根据大括弧的个数自动识别行数
    int arr[][3] = {{1,1,1},{2,2,2},{3,3,3}};

    //3. 初始化:依个数向后推出，没有初始化的为0
    int arr[3][3] = {1,1,1,2,2,2,3,3};

    //4. 初始化。部分, 没有初始化的为0
    int arr[3][3] = {{1},{2},{3}};

    //5. 初始化：未指定行数
    int arr[][3] = {1,1,1,2,2,2,3,3};

    //6. 初始化：循环
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            arr[i][j]=1;
        }
    }

    for (int i=0; i<3; i++) {       //行
        for (int j=0; j<3; j++) {   //列
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
   
    
    //每组的平均成绩
   int arr[2][3]={
       {2,3,4},
       {3,4,5}
   };
   for (int i=0; i<2; i++) {
       int sum = 0;
       for (int j=0; j<3; j++) {
           sum += arr[i][j];
       }
       printf("第%d组的平均数是：%d\n",i+1,sum/3);
   }
    
    //地址：二维数组名也是二维数组的地址
    int arr[2][3];
    printf("%d\n", arr[0]);

    //长度：行，列，元素的个数
    int arr[2][3]={
                {2,3,4},
                {3,4,5}
            };
    int len = sizeof(arr);   //24
    int rows = sizeof(arr)/sizeof(arr[0]); //2
    int cols = sizeof(arr[0])/sizeof(int);
    printf("元素的长度：%d。元素的行：%d\。元素的列：%d\n", len, rows, cols);
    
    //二维数组可以做为参数传递, 同时也要声明第二,三个参数：行数，列数
    /** 写参数的时候：先写行，列，数组的列数用参数指定，这个行，列数就任一指定了
     *  int test(int rows, int cols, int arr[][cols]){
     *  for(int i=0; i<rows, i++){
     *      for(int j=0; j<cols, j++){}
     *  }
     *  }
     *  调用：
     *  int num = test(arr, rows, cols);
     */
    
    //案例：用户输入行，列，赋值行*列+10，并打印出值
    int rows = 0, cols = 0;
    printf("请分别输入行，列数");
    scanf("%d%d", &rows, &cols);
    int arr[rows][cols];

    setValue(cols, rows, arr);
    enumrate(cols, rows, arr);

    
    //字符数组：
    char chs[3] = {'a'};   //其它元素初始化为：\0，此字符是不可见的
    int arr[3]  = {'5'};   //其它元素初始化为：0
    
    char chs[] = {'a','b', 'c'};
    
    for (int i=0; i<sizeof(chs); i++) {
        printf("%c", chs[i]);   //abc
    }
    printf("\n");
    
    
    return 0;
}
