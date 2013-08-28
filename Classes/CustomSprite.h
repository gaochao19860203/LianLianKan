#ifndef __CUSTOM_SPRITE_H__
#define __CUSTOM_SPRITE_H__
#include "cocos2d.h"
// 此类是一个自定义的精灵类 主要用来存放我们连连看的每张图片
class CustomSprite:public cocos2d::CCNode{
public:
	CustomSprite();
	~CustomSprite();
	static CustomSprite* createWithSpritePicIndex(int index,const cocos2d::CCSize contentSize);//根据当前传递的 整型值来取出当前的所对应的的图片
	virtual bool init();
    bool setUpdateView(int i);
	CC_SYNTHESIZE(int,index,Index);
	void displayHitPic(int type);//1 表示显示点击后的样式 2 表示还原 原来的样式
	CC_SYNTHESIZE(int ,x,X);// 数组中坐标X 的值
	CC_SYNTHESIZE(int,y,Y);//  数组中坐标Y 的值
	CC_SYNTHESIZE(bool,isEliminate,IsEliminate);//  是否已被消除 true 表示已消除  false 表示没有被消除
	void displayCustome();  
	void displayLujing(float time);

};


#endif