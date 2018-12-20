//
//  main.c
//  AlgrithmByCDemo
//
//  Created by Heeron on 2018/12/19.
//  Copyright © 2018 HeeronChang. All rights reserved.
//

#include <stdio.h>
/// 给定一个整形数组和一个目标值，判断数组中是否有两个数之和等于目标值
int twoSum(int nums[], int target) {
    
    return 0;
}

/// 深度优先搜索
int m, n, p, q, min = 99999999;
int a[51][51], book[51][51];

void dfs(int x, int y, int step) {
    // 定一个方向数组 next
    int next[4][2] = {
        {0, 1}, // 向右
        {1, 0}, // 向下
        {0, -1}, // 向左
        {-1, 0} // 向上
    };
    
    // 判断是否找到
    if (x == p && y == q) {
        if (step < min) min = step;
        return;
    }
    
    // 使用循环获取下一步的坐标，tx：下一步的横坐标，ty：下一步的纵坐标
    int tx = 0, ty = 0;
    for (int k = 0; k <= 3; k++) {
        tx = x + next[k][0];
        ty = y + next[k][1];
        
        // 判断越界
        if (tx < 0 || tx > n || ty < 0 || ty > m) {
            continue;
        }
        
        // 判断该点是否为障碍物或者已经在路径中
        if (a[tx][ty] == 0 && book[tx][ty] == 0) {
            book[tx][ty] = 1; // 标记点已经走过
            dfs(tx, ty, step + 1); // 开始尝试下一个点
            book[tx][ty] = 0; // 尝试结束，取消这个点的标记
        }
    }
    
    return;
}

/// 调用深度优先搜索
void callDfs() {
    int startx = 0, starty = 0;
    printf("设置格子");
    scanf("%d %d", &n, &m); // n 为行，m 为列
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //            printf("设置障碍物");
            //            scanf("%d", &a[i][j]);
            a[i][i] = 0;
        }
    }
    a[0][2] = 1;
    
    printf("设置起点坐标，终点坐标");
    // 起点坐标和终点坐标
    scanf("%d %d %d %d", &startx, &starty, &p, &q);
    
    // 从起点开始搜索
    book[startx][starty] = 1; // 标记起点已经在路径中
    dfs(startx, starty, 0);
    printf("%d", min);
    getchar(); getchar();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    // 深度优先搜索
    callDfs();
    
    return 0;
}

