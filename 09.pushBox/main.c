
#include <stdio.h>
#include <stdlib.h>
#define ROWS 10   //定义宏存储地图大小
#define COLS 11
/**
 *  存储地图数据的二维数组：路，人，箱子，墙
 *  多个函数都要访问这个地图数据，所以声明为全局变量
 */
char map[ROWS][COLS] = {
    "##########",
    "#  ####  #",
    "# X####  #",
    "# 0      #",
    "######   #",
    "#  ####  #",
    "#        #",
    "#   ######",
    "#         ",
    "##########"
};

//小人不前所在的行，列，默认在3行2列
int personCurrentRow = 3;
int personCurrentCol = 2;

/**
 *  根据map数组打印出地图
 */
void showMap();

/**
 *  接收输入小人的前进方向
 *  @return 前进方向
 */
char enterDirection();

/**
 *  根据当前坐标计算出下一个坐标
 *
 *  @param dir        方向
 *  @param currentRow 基准Row 坐标
 *  @param currentCol 基准Col 坐标
 *  @param pNextRow   下一个Row 坐标
 *  @param pNextCol   下一个Col 坐标
 */
void getNextPosition(char dir, int currentRow, int currentCol, int* pNextRow, int* pNextCol);

/**
 *  将小人向指定方向移动
 *  @param dir 指定的方向
 */
void movePerson(char dir);


int main(int argc, const char * argv[]) {
 
    while (1) {
        system("clear");
        // 1. 根据map数据打印出地图
        showMap();
        
        // 2. 接收输入小人的前进方向
        char dir = enterDirection();
        
        // 3. 根据小人前进的方向，来移动小人或者推箱子
        if(dir == 'q'){
            printf("Game Over ~ ");
            return 0;
        }else{
            movePerson(dir);
        }
    }
    
    return 0;
}




/**
 *  根据map数组打印出地图
 */
void showMap(){
    for (int i=0; i<COLS; i++) {
        printf("%s\n", map[i]);
    }
    
}

/**
 *  接收输入小人的前进方向
 *  @return 前进方向
 */
char enterDirection(){
    printf("请输入小人前进方向：a(左), w(上), d(右), s(下), q(退出)\n");
    char dir = 'a';
    rewind(stdin);   //清除缓存
    scanf("%c", &dir);
    return dir;
}


/**
 *  根据当前坐标计算出下一个坐标
 *
 *  @param dir        方向
 *  @param currentRow 基准Row 坐标
 *  @param currentCol 基准Col 坐标
 *  @param pNextRow   下一个Row 坐标
 *  @param pNextCol   下一个Col 坐标
 */
void getNextPosition(char dir, int currentRow, int currentCol, int* pNextRow, int* pNextCol){
    int nextRow = 0;
    int nextCol = 0;
    
    switch (dir) {
        case 'a':
        case 'A':
            nextRow = currentRow;
            nextCol = currentCol - 1;
            break;
        case 'w':
        case 'W':
            nextRow = currentRow - 1;
            nextCol = currentCol;
            break;
        case 'd':
        case 'D':
            nextRow = currentRow;
            nextCol = currentCol + 1;
            break;
        case 's':
        case 'S':
            nextRow = currentRow + 1;
            nextCol = currentCol;
            break;
    }
    
    //通过指针直接操作其坐标
    *pNextRow = nextRow;
    *pNextCol = nextCol;
}

/**
 *  将小人向指定方向移动
 *  @param dir 指定的方向
 */
void movePerson(char dir){
    // 1. 拿到小人的下1个坐标，根据小人的前进方向而不同，如：根据小人当前的坐标和前进方向计算出小人的下个坐标
    int personNextRow = 0;
    int personNextCol = 0;
    //基准坐标为:小人的坐标
    getNextPosition(dir, personCurrentRow, personCurrentCol, &personNextRow, &personNextCol);
    
    // 2. 判断小人的下1个坐标是1个什么物品, 如果是空格就移动小人
    if(map[personNextRow][personNextCol] == ' ')
    {
        map[personNextRow][personNextCol] = '0';        //移动后将当前1坐标设置为小人
        map[personCurrentRow][personCurrentCol] = ' ';  //移动后将小人之前1坐标设置为空
        
        //推完之后，改小人的位置
        personCurrentRow = personNextRow;
        personCurrentCol = personNextCol;
        
    }
    else if(map[personNextRow][personNextCol] == 'X')   //如果是箱子，就开始推箱子了
    {
        // 要判断箱子能不推，就要拿到这个箱子的下1个坐标，而箱子的坐标是personNextRow, personNextCol
        int boxNextRow = 0;
        int boxNextCol = 0;
        
        // 这段代码就是根据箱子现在的坐标，算出箱子下1个坐标: 基准坐标为：personNextRow, personNextCol
        getNextPosition(dir, personNextRow, personNextCol, &boxNextRow, &boxNextCol);
        
        // 继续判断箱子的下1个坐标是路
        if(map[boxNextRow][boxNextCol] == ' '){
            map[boxNextRow][boxNextCol] = 'X';
            
            // 把当有箱子的位置设置为小人
            map[personNextRow][personNextCol] = '0';
            
            // 把小人的位置设置为这空格
            map[personCurrentRow][personCurrentCol] = ' ';
            
            //推完之后，改小人的位置
            personCurrentRow = personNextRow;
            personCurrentCol = personNextCol;
        }
        
    }

}























