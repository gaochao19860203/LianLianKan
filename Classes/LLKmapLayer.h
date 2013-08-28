#ifndef __LLKMAP_LAYER_H__
#define __LLKMAP_LAYER_H__
#include "BaseLayer.h"
#define picWidth 45
#define picHeight 51
class LLKmapLayer:public BaseLayer{
public:
	LLKmapLayer();
	~LLKmapLayer();
	static cocos2d::CCScene* scene();
	CREATE_FUNC(LLKmapLayer);
	virtual bool init();
	bool setUpdateView();
	virtual void onEnter();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

private:
	int row; // ������
	int cloum;// ������
	cocos2d::CCArray* llkArray;// ����Ǵ���ĵ�ͼ�е�ͼƬ
	cocos2d::CCArray* hitArray;// ����Ǵ�������ͼƬ 
	cocos2d::CCArray* totalArray;// ����Ǵ������еĵ�ͼ���� ��ʵ�����������ĵ�ͼ��Χ�ֲ�����һȦ�����������

};
#endif 