#include "LLKGameLayer.h"
#include "LLKmapLayer.h"
USING_NS_CC;
CCScene* LLKGameLayer::scene(){
CCScene* scene=CCScene::create();
LLKGameLayer* layer=LLKGameLayer::create();
scene->addChild(layer);
return scene;

}
 bool LLKGameLayer::init(){
	 bool isRet=false;
	 do{
	 CC_BREAK_IF(!BaseLayer::init());
	 CC_BREAK_IF(!setUpdateView());
	 isRet=true;
	 } while (0);
	 return isRet;
 }
bool LLKGameLayer::setUpdateView(){
	bool isRet=false;
	do {
    LLKmapLayer* lLKmapLayer=LLKmapLayer::create();
	CC_BREAK_IF(!lLKmapLayer);
	CCSize mapsize= lLKmapLayer->getContentSize();
	lLKmapLayer->setPosition(ccp((getWinSize().width-mapsize.width)/2,(getWinSize().height-mapsize.height)/2));
	this->addChild(lLKmapLayer);
	 float minx=lLKmapLayer->boundingBox().getMinX();
	isRet=true;	
	} while (0);
	return isRet;
}

LLKGameLayer::LLKGameLayer(){

}
LLKGameLayer::~LLKGameLayer(){

}