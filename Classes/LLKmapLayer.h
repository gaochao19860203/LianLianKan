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
	int row; // 多少行
	int cloum;// 多少列
	cocos2d::CCArray* llkArray;// 这个是储存的地图中的图片
	cocos2d::CCArray* hitArray;// 这个是储存点击的图片 
	cocos2d::CCArray* totalArray;// 这个是储存所有的地图布局 其实就是在真正的地图周围又部署了一圈方便用来检测

};
#endif 