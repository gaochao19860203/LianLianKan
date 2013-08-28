#ifndef __LLKALGORITHM_H__
#define __LLKALGORITHM_H__
#include "cocos2d.h";
#include "CustomSprite.h"
class LLKAlgorithm{

public:

static cocos2d::CCArray* algorithm(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray);

	// ����Ǻ�����
static cocos2d::CCArray* horizon(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray);
//�����������
static cocos2d::CCArray* vertical(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray);





/***
 �����һ���ս� ���㷨
 һ��ת����ͨ����ʵ�൱������ͼƬ����һ�����Σ�������ͼƬ��һ�ԶԽǶ��㣬�������������������һ������ͬʱ������������ֱ����
 �Ǿ�˵������ "һ����ͨ" ��ʵ���ǰ�һ���սǵ�ת���� һ�� ������ͨ��һ��������ͨ��

*/

static cocos2d::CCArray* oneCorner(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray);

/***
 ��ʵ�����սǵ��㷨���ǣ����ҵ�һ������� ����һ��ֱ����ͨ������һ����һ���սǾͿ�����ͨ ����ﵽ������Ҫ���֤������ ͼ��
 ���������սǿ���ֱ����ͨ ������Ĵ�������ʼ�հ�����С�ķŵ������档��ô���ڵ�˼·���� �� first �������ĸ�����
 ��⣬�����Ǹ��㸴�����Ҫ�� ֻҪ��һ���㸴��Ҫ�� �ʹ��������ͨ
 */

static cocos2d::CCArray* twoCorner(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray);

// ͨ��XY ��ȡ ��Ӧ�� Ԫ��
static CustomSprite* getCustByXandY(cocos2d::CCArray* llkArray,int x,int y);

static void removeAllArray(cocos2d::CCArray* array,bool isrel);


};
#endif