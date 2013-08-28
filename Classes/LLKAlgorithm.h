#ifndef __LLKALGORITHM_H__
#define __LLKALGORITHM_H__
#include "cocos2d.h";
#include "CustomSprite.h"
class LLKAlgorithm{

public:

static cocos2d::CCArray* algorithm(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray);

	// 这个是横向检测
static cocos2d::CCArray* horizon(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray);
//这个是纵向检测
static cocos2d::CCArray* vertical(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray);





/***
 这个是一个拐角 的算法
 一个转角连通：其实相当于两个图片划出一个矩形，这两个图片是一对对角顶点，另外两个顶点如果任意一个可以同时和这两个棋子直连，
 那就说明可以 "一折连通" 其实就是把一个拐角的转化成 一个 横向联通和一个纵向联通的

*/

static cocos2d::CCArray* oneCorner(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray);

/***
 其实两个拐角的算法就是，你找到一个点可以 其中一个直接连通，和另一个有一个拐角就可以连通 如果达到这样的要求就证明两个 图形
 经过两个拐角可以直接连通 在上面的处理中我始终把行数小的放到最上面。那么现在的思路就是 以 first 出发向四个方向
 检测，看看那个点复合这个要求 只要有一个点复合要求 就代表可以联通
 */

static cocos2d::CCArray* twoCorner(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray);

// 通过XY 获取 响应的 元素
static CustomSprite* getCustByXandY(cocos2d::CCArray* llkArray,int x,int y);

static void removeAllArray(cocos2d::CCArray* array,bool isrel);


};
#endif