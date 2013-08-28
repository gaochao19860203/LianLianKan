#ifndef __LLKGAME_LAYER_H__
#define __LLKGAME_LAYER_H__
#include "BaseLayer.h"
#include "CustomSprite.h"
class LLKGameLayer:public BaseLayer{
public:
	LLKGameLayer();
	~LLKGameLayer();
	static cocos2d::CCScene* scene();
	CREATE_FUNC(LLKGameLayer);
	virtual bool init();
	bool setUpdateView();
};
#endif 