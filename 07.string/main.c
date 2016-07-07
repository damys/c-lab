

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    //原理：将字符串数据的每1个字符存储在字符数组中，并在后面追加1个’\0’ 代表字符串存储完毕
    char name1[] = {'t','o','m','\0'};
    char name2[] = {"tom"}; //会是最后追加\0
    char name3[] = "tom";   //会是最后追加\0

    //用调用的方式查看：
    for (int i=0; i<3; i++) {
        printf("%c", name3[i]);
    }

    char ch1[2] = "abcd"; //ab
    char ch2[]  = "abcd"; //abcd
    //循环输出
    for (int i=0; i<3; i++) {
        printf("%c\n", ch1[i]);
    }
    //%s 占位符
    printf("%s\n", ch2);

    char str1[]="abc";
    char str2[3]="def";  //\0不会存在此数组中，直到\0才结束
    printf("%s\n",str2);  //defabc


    //接收用户输入,注意使用scanf %s时：如果输入字符长度超过10个就会报错；输入空格会认为是结束
    char str[10];
    printf("你的名子叫：");
    scanf("%s", str); //不需要取地址符&
    printf("hello：%s\n", str);


    //字符串的长度
    char name[]="abcd";
    int len = sizeof(name)-1;
    //注意：不能使用sizeof 计算长度，因为有可能字符串数据存储在字符数组中占了1部分
    //应该：从第1个字符开始记数，直到’\0’为止
    int lens = 0;
    while (name[lens] != '\0') {
        lens++;
    }
    printf("长度为：%d\n", lens);



    //1. puts() 函数。作用输出字符串，优点：自动换行。缺点：只能输出字符串，不安全，超过长度会报错
    char name[] = "abcd";
    puts(name);


    //2. gets() 函数。作用从控制台接收用户输入1个字符串数据; 优点：输出空格也会照样输出。缺点：与puts 不安全，超过长度会报错
    char name[20];
    printf("请输入你的名子：");
    gets(name); //接收
    puts(name); //输出


    //3. strlen() 函数：库：string.h
    char name[] = "aaaa";
    unsigned long len = strlen(name);
    printf("len:%lu\n", len);  //4


    //4. strcmp() 函数。compare 字符串比较
    char str1[] = "aa";
    char str2[] = "bb";
    int res = strcmp(str1, str2);
    printf("res:%d\n", res);  //-1   比ascii码,如返回负数，str1 < str2


    //5. strcpy() 函数 copy
    char str1[] = "aa";
    char str2[] = "bb";
    strcpy(str1, str2);   //将str2 copy 到str1中， 要注意长度问题
    printf("%s\n", str1);  //bb


    //6. strcat() 函数 concat 连接
    char str1[10] = "aa";
    char str2[] = "bb";
    strcat(str1, str2);
    printf("%s\n", str1);  //aabb 注意：str1 长度要够长才可以，否则不会连接
    
    
    
    
    
    
    
    
    return 0;
}
