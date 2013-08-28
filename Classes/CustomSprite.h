#ifndef __CUSTOM_SPRITE_H__
#define __CUSTOM_SPRITE_H__
#include "cocos2d.h"
// ������һ���Զ���ľ����� ��Ҫ�������������������ÿ��ͼƬ
class CustomSprite:public cocos2d::CCNode{
public:
	CustomSprite();
	~CustomSprite();
	static CustomSprite* createWithSpritePicIndex(int index,const cocos2d::CCSize contentSize);//���ݵ�ǰ���ݵ� ����ֵ��ȡ����ǰ������Ӧ�ĵ�ͼƬ
	virtual bool init();
    bool setUpdateView(int i);
	CC_SYNTHESIZE(int,index,Index);
	void displayHitPic(int type);//1 ��ʾ��ʾ��������ʽ 2 ��ʾ��ԭ ԭ������ʽ
	CC_SYNTHESIZE(int ,x,X);// ����������X ��ֵ
	CC_SYNTHESIZE(int,y,Y);//  ����������Y ��ֵ
	CC_SYNTHESIZE(bool,isEliminate,IsEliminate);//  �Ƿ��ѱ����� true ��ʾ������  false ��ʾû�б�����
	void displayCustome();  
	void displayLujing(float time);

};


#endif