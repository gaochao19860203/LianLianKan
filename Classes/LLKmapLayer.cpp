#include "LLKmapLayer.h"
#include "CustomSprite.h"
#include "LLKAlgorithm.h"
USING_NS_CC;
LLKmapLayer::LLKmapLayer(){
	this->row=8;
	this->cloum=14;
	llkArray=CCArray::create();
	llkArray->retain();

	totalArray=CCArray::create();
	totalArray->retain();

	hitArray=CCArray::create();
	hitArray->retain();


}
LLKmapLayer::~LLKmapLayer(){
	if (llkArray)
	{
		llkArray->autorelease();
	}

	if (totalArray)
	{
		totalArray->autorelease();
	}

	if (hitArray)
	{
		hitArray->autorelease();
	}

}
CCScene* LLKmapLayer::scene(){
	CCScene* scene=CCScene::create();
	LLKmapLayer* layer=LLKmapLayer::create();
	scene->addChild(layer);
	return scene;

}
bool LLKmapLayer::init(){
	bool isRet=false;
	do{
		CC_BREAK_IF(!BaseLayer::init());
		this->setContentSize(CCSize(picWidth*cloum,picHeight*row));
		CC_BREAK_IF(!setUpdateView());
		isRet=true;
	} while (0);
	return isRet;
}
bool LLKmapLayer::setUpdateView(){
	bool isRet=false;
	do {
		//得到需要的总张数  // 一定要是偶数
		int totalcout=this->row*this->cloum;
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("point.plist","point.png");
		CCArray* temparry=CCArray::create();
		// 一次生成两张一样的
		for (int i=0;i<totalcout/2;i++){
			int num=CCRANDOM_0_1()*35;//因为是图片的张数是从0到36张 所以随机从0 到35
			CustomSprite*  phit1=  CustomSprite::createWithSpritePicIndex(num,CCSize(picWidth,picHeight));		
			CustomSprite*  phit2=  CustomSprite::createWithSpritePicIndex(num,CCSize(picWidth,picHeight));		
			temparry->addObject(phit1);
			temparry->addObject(phit2);
		}

		for(int i=0;i<row+2;i++){
			for(int j=0;j<this->cloum+2;j++){

				if ((i==0)||(j==0)||(j==cloum+1)||(i==row+1)){
					CustomSprite*  temp=  CustomSprite::createWithSpritePicIndex(0,CCSize(picWidth,picHeight));
					temp->displayCustome();
					temp->setX(j);
					temp->setY(i);

					temp->setAnchorPoint(ccp(0,0));
					temp->setPosition(ccp(45*(j-1),51*(i-1)));
						this->addChild(temp);
					this->totalArray->addObject(temp);

				}else {
					CustomSprite* phit=(CustomSprite*)temparry->randomObject();
					temparry->removeObject(phit,false);
					phit->setAnchorPoint(ccp(0,0));
					phit->setPosition(ccp(45*(j-1),51*(i-1)));
					this->addChild(phit);
					llkArray->addObject(phit);
					phit->setX(j);
					phit->setY(i);
					this->totalArray->addObject(phit);
				}
			}
		}
		isRet=true;	
	} while (0);
	return isRet;
}
void LLKmapLayer::onEnter(){
	BaseLayer::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(  
		this,//在那个类中实现触屏回调函数  
		0, //优先级  
		true);//触摸时间是否被该目标截获  
}
bool LLKmapLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
	CCPoint ponti= pTouch->getLocation();
	CCSize mapsize= this->getContentSize();
	float x=ponti.x-(getWinSize().width-mapsize.width)/2;
	float y=ponti.y-(getWinSize().height-mapsize.height)/2;
	if(llkArray){
		for(int i=0;i<llkArray->count();i++){
			CustomSprite* phit=(CustomSprite*)llkArray->objectAtIndex(i);
			if(phit->boundingBox().containsPoint(CCPoint(x,y))){



				//表示这个没有被删除掉
				if (phit->getIsEliminate()==false){
					if(hitArray->count()==0){
						hitArray->addObject(phit);
						phit->displayHitPic(1);
					}else {
						CustomSprite* temp=(CustomSprite*) hitArray->objectAtIndex(0);

						if (temp->getX()==phit->getX()&&temp->getY()==phit->getY()){
						break;
						}

						if(temp->getIndex()==phit->getIndex()){
							hitArray->addObject(phit);
							phit->displayHitPic(1);
						}else {
							hitArray->removeObjectAtIndex(0,false);
							temp->displayHitPic(2);
							hitArray->addObject(phit);
							phit->displayHitPic(1);
						}

					} 
				}

				break;
			}
		}

	}
	if(hitArray->count()==2){
		CCArray* temparr= LLKAlgorithm::algorithm(totalArray,hitArray);
		if (temparr){
			if (temparr->count()>0){
				for(int i=0;i<temparr->count();i++){
					CustomSprite* temp=(CustomSprite*) temparr->objectAtIndex(i);				
					temp->displayCustome();					
				}
				hitArray->removeObjectAtIndex(0,false); 
				hitArray->removeObjectAtIndex(0,false);
			}else {
				CustomSprite* temp=(CustomSprite*) hitArray->objectAtIndex(0);
				temp->displayHitPic(2);
				hitArray->removeObjectAtIndex(0,false); 
			}

		}
	}



	return true;
}
void LLKmapLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){

}
void LLKmapLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent){

}
void LLKmapLayer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent){

}