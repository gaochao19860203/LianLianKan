#include "CustomSprite.h"
USING_NS_CC;
CustomSprite::CustomSprite(){
	this->isEliminate=false;
}
CustomSprite::~CustomSprite(){

}
 
CustomSprite* CustomSprite::createWithSpritePicIndex( int index,const CCSize contentSize){
	CustomSprite * pRet = new CustomSprite();
	if (pRet)
	{
			pRet->setContentSize(contentSize);
	}
	
	if (pRet && pRet->init()&&pRet->setUpdateView(index))
	{
	
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}
 bool CustomSprite::init(){
	 bool isRet=false;
	 do 
	 {
	 CC_BREAK_IF(!CCNode::init());
	 isRet=true;
	 } while (0);
	 return isRet;
 }
 bool CustomSprite::setUpdateView(int i){
	 bool isRet=false;
	 do 
	 {
		 this->index=i;		
		 CCSprite* phit1=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("%s%d%s","point",i,".png")->getCString()));
		 CC_BREAK_IF(!phit1);
		 phit1->setAnchorPoint(ccp(0,0));
		 phit1->setPosition(ccp(0,0));
		 this->addChild(phit1,1,1);
		 CCSprite* phit2=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("%s%d%s","point_h_",i,".png")->getCString()));
		 CC_BREAK_IF(!phit2);
		 phit2->setAnchorPoint(ccp(0,0));
		 phit2->setPosition(ccp(0,0));
		 this->addChild(phit2,1,2);		 
		 phit2->setVisible(false);

		 CCSprite* hitbg=CCSprite::create("hint.png");
		 CC_BREAK_IF(!hitbg);
		 hitbg->setPosition(ccp(getContentSize().width/2,getContentSize().height/2));
		 this->addChild(hitbg,2,3);
		 hitbg->setVisible(false);

		 isRet=true;
	 } while (0);
	 return isRet;
	

 }
 void CustomSprite::displayHitPic(int type){
	CCSprite* phit2=(CCSprite*)this->getChildByTag(2);
	CCSprite* phit1=(CCSprite*)this->getChildByTag(1);
	 if(type==1){
	 phit2->setVisible(true);
	 phit1->setVisible(false);
	 }else {
	 phit2->setVisible(false);
	 phit1->setVisible(true);
	 }
 }


 void CustomSprite::displayCustome(){
	 this->displayHitPic(2);
	 CCSprite* phit1=(CCSprite*)this->getChildByTag(1);
	 phit1->setVisible(false);	 
	 this->setIsEliminate(true);
	  CCSprite* phit3=(CCSprite*)this->getChildByTag(3);
	  phit3->setVisible(true);
	  this->scheduleOnce(schedule_selector(CustomSprite::displayLujing),5);
 } 
 void CustomSprite::displayLujing(float time){
	 CCSprite* phit3=(CCSprite*)this->getChildByTag(3);
	 phit3->setVisible(false);
 }

