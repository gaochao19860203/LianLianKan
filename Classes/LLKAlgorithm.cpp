#include "LLKAlgorithm.h"

USING_NS_CC;
// 这个是横向检测
CCArray* LLKAlgorithm::horizon(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray){
	CustomSprite* hit1=(CustomSprite*)hitArray->objectAtIndex(0);// 取出第一个
	CustomSprite* hit2=(CustomSprite*)hitArray->objectAtIndex(1);// 取出第二个
	int x1=hit1->getX(); // 得到第一个X 坐标
	int x2=hit2->getX(); // 得到第二个X 坐标
	bool isda=x1>x2?true:false;// 得出那个坐标肯后
	int temp=isda?x1-x2:x2-x1; // 获取两个两个点之间的 间隔
	CCArray* temparray=CCArray::create();// 记录两个点之间 所经过的点

	if (temp==1){// 表示两个是相邻的两个
		temparray->addObject(hit1);
		temparray->addObject(hit2);
	}else {    

		if (isda){
			temparray->addObject(hit1);
			temparray->addObject(hit2);
			for(int i=1;i<temp;i++){
				CustomSprite* hitteim=LLKAlgorithm::getCustByXandY(llkArray,x1-i,hit2->getY());
				// 如果是已经消除的那么 就可以继续查询
				if (!hitteim->getIsEliminate()){
					LLKAlgorithm::removeAllArray(temparray,false);
					break;
				}else {
					temparray->addObject(hitteim);
				}
			}

		}else {
			temparray->addObject(hit2);
			temparray->addObject(hit1);
			for(int i=1;i<temp;i++){
				CustomSprite* hitteim=LLKAlgorithm::getCustByXandY(llkArray,x2-i,hit2->getY());
				// 如果是已经消除的那么 就可以继续查询
				if (!hitteim->getIsEliminate()){
					LLKAlgorithm::removeAllArray(temparray,false);
					break;
				}else {
					temparray->addObject(hitteim);
				}
			}
		}

	}


	return temparray;

}
//这个是纵向检测
CCArray*  LLKAlgorithm::vertical(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray){
	CustomSprite* hit1=(CustomSprite*)hitArray->objectAtIndex(0);// 取出第一个
	CustomSprite* hit2=(CustomSprite*)hitArray->objectAtIndex(1);// 取出第二个
	int y1=hit1->getY(); // 得到第一个Y 坐标
	int y2=hit2->getY(); // 得到第二个Y 坐标
	bool isda=y1>y2?true:false;// 得出那个坐标肯后
	int temp=isda?y1-y2:y2-y1; // 获取两个两个点之间的 间隔
	CCArray* temparray=CCArray::create();// 记录两个点之间 所经过的点

	if (temp==1){// 表示两个是相邻的两个
		temparray->addObject(hit1);
		temparray->addObject(hit2);
	}else {    

		if (isda){
			temparray->addObject(hit1);
			temparray->addObject(hit2);
			for(int i=1;i<temp;i++){
				CustomSprite* hitteim=LLKAlgorithm::getCustByXandY(llkArray,hit2->getX(),y1-i);
				// 如果是已经消除的那么 就可以继续查询
				if (!hitteim->getIsEliminate()){
					LLKAlgorithm::removeAllArray(temparray,false);
					break;
				}else {
					temparray->addObject(hitteim);
				}
			}

		}else {
			temparray->addObject(hit2);
			temparray->addObject(hit1);
			for(int i=1;i<temp;i++){
				CustomSprite* hitteim=LLKAlgorithm::getCustByXandY(llkArray,hit2->getX(),y2-i);
				// 如果是已经消除的那么 就可以继续查询
				if (!hitteim->getIsEliminate()){
					LLKAlgorithm::removeAllArray(temparray,false);
					break;
				}else {
					temparray->addObject(hitteim);
				}
			}
		}

	}



	return temparray;
}

/***
这个是一个拐角 的算法
一个转角连通：其实相当于两个图片划出一个矩形，这两个图片是一对对角顶点，另外两个顶点如果任意一个可以同时和这两个棋子直连，
那就说明可以 "一折连通" 其实就是把一个拐角的转化成 一个 横向联通和一个纵向联通的

*/

CCArray*  LLKAlgorithm::oneCorner(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray){
	CustomSprite* hit1=(CustomSprite*)hitArray->objectAtIndex(0);// 取出第一个
	CustomSprite* hit2=(CustomSprite*)hitArray->objectAtIndex(1);// 取出第二个
	int x1=hit1->getX();
	int x2=hit2->getX();
	int y1=hit1->getY();
	int y2=hit2->getY();
	bool isXg=x1>x2?true:false;//如果是true 表示hit1 在hit2 的后面
	bool isYg=y1>y2?true:false;//如果是true 表示hit1 在hit2 的上面
	// 下面我们计算出矩形的另外的两个重点
	// 先计算出  在矩形上面所对应的 
	int temx=0;
	int temy=0;	

	// 求取最上面的哪一个对应的坐标点

	if(isYg){
		temy=hit1->getY();
		temx=hit2->getX();
	}else {
		temy=hit2->getY();
		temx=hit1->getX();
	}
	CCArray* temparray=CCArray::create();// 记录两个点之间 所经过的点

	CustomSprite* hity=LLKAlgorithm::getCustByXandY(llkArray,temx,temy);// 得到最上面的那个对应的矩形顶点的 精灵图片
	CCArray* tempHit=CCArray::create();
	//顶点必须是已经消除的 要不肯定不能贯通
	if (hity->getIsEliminate()){
		tempHit->addObject(hity);
		tempHit->addObject(isYg?hit1:hit2);
		CCArray* temx=LLKAlgorithm::horizon(llkArray,tempHit);// 获取X 方向上是否可以连通
		if(temx->count()>0){// 表示可以连通
			temparray->addObjectsFromArray(temx);
			LLKAlgorithm::removeAllArray(tempHit,false);
			tempHit->addObject(hity);
			tempHit->addObject(isYg?hit2:hit1);
			CCArray* temy=LLKAlgorithm::vertical(llkArray,tempHit);
			if (temy->count()>0){
				temparray->removeObject(hity,false);
				temparray->addObjectsFromArray(temy);
			}else {
				LLKAlgorithm::removeAllArray(temparray,false);
			}
		}else {
			LLKAlgorithm::removeAllArray(tempHit,false);
		}
	}
	// 表示上面的路走不通
	if (temparray->count()==0){
		// 获取X 方向矩形所对应的的点		
		//temx=isXg?hit1->getX():hit2->getX();
		//temy=isXg?hit2->getY():hit1->getY();

		if (isYg){
			temy=hit2->getY();
			temx=hit1->getX();
		}else {
			temy=hit1->getY();
			temx=hit2->getX();		
		}

		CustomSprite* hitx=LLKAlgorithm::getCustByXandY(llkArray,temx,temy);// 得到最上面的那个对应的矩形顶点的 精灵图片
		if (hitx->getIsEliminate()){
			tempHit->addObject(hitx);
			tempHit->addObject(isYg?hit2:hit1);
			CCArray* temx=LLKAlgorithm::horizon(llkArray,tempHit);// 获取X 方向上是否可以连通
			if(temx->count()>0){// 表示可以连通
				temparray->addObjectsFromArray(temx);
				LLKAlgorithm::removeAllArray(tempHit,false);
				tempHit->addObject(hitx);
				tempHit->addObject(isYg?hit1:hit2);
				CCArray* temy=LLKAlgorithm::vertical(llkArray,tempHit);
				if (temy->count()>0){
					temparray->removeObject(hitx,false);
					temparray->addObjectsFromArray(temy);
				}else {
					LLKAlgorithm::removeAllArray(temparray,false);
				}
			}else {
				LLKAlgorithm::removeAllArray(tempHit,false);
			}
		}

	}

	return temparray;

}

/***
其实两个拐角的算法就是，你找到一个点可以 其中一个直接连通，和另一个有一个拐角就可以连通 如果达到这样的要求就证明两个 图形
经过两个拐角可以直接连通 在上面的处理中我始终把行数小的放到最上面。那么现在的思路就是 以 first 出发向四个方向
检测，看看那个点复合这个要求 只要有一个点复合要求 就代表可以联通
*/

CCArray*  LLKAlgorithm::twoCorner(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray){

	bool isjiance=false; // 这个主要来表示是否走了 一个拐角的判断
	// 先获取 当前X 的最大是多少  y 的最大是多少
	CustomSprite* lastCutom=(CustomSprite*)llkArray->lastObject();
	int max=lastCutom->getX();
	int may=lastCutom->getY();
	CustomSprite* hit1=(CustomSprite*)hitArray->objectAtIndex(0);// 取出第一个
	CustomSprite* hit2=(CustomSprite*)hitArray->objectAtIndex(1);// 取出第二个

	// 随便拿出一个点  向他的四个方向出发 看看能否和另外一个变成一个拐角相连
	// 这里我们就拿出取出的第一个点吧 hit1

	CCArray* temparray=CCArray::create();// 记录两个点之间 所经过的点
	int x1=hit1->getX(); // 得到第一个X 坐标
	int y1=hit1->getY(); // 得到第1个Y坐标
	// 首先向左检测
	CCArray* temphit=CCArray::create(); 
	temphit->addObject(hit2);
	for(int i=(x1-1);i>=0;i--){
		CustomSprite* tepcou =LLKAlgorithm::getCustByXandY(llkArray, i, y1);
		if (tepcou->getIsEliminate()){
			// 判断看能否组成一个矩形
			temparray->addObject(tepcou);
			if(tepcou->getX()==hit2->getX()||hit2->getY()==tepcou->getY()){

				continue;
			}
			isjiance=true;
			temphit->addObject(tepcou);
			CCArray* temparr=LLKAlgorithm::oneCorner(llkArray,temphit);
			if (temparr->count()>0){
				temparray->addObjectsFromArray(temparr);
				break;
			}else {
				if(i==0){
					LLKAlgorithm::removeAllArray(temparray,false);
				}

				temphit->removeLastObject(false);
			}
		}else{
			LLKAlgorithm::removeAllArray(temparray,false);

			break;
		}

	}

	if (isjiance==false){
		LLKAlgorithm::removeAllArray(temparray,false);			
	}

	if(temparray->count()==0){
		bool isjiance=false; 
		// 向右检测
		for(int i=(x1+1);i<=max;i++){
			CustomSprite* tepcou =LLKAlgorithm::getCustByXandY(llkArray, i, y1);
			if (tepcou->getIsEliminate()){
				// 判断看能否组成一个矩形
				temparray->addObject(tepcou);
				if(tepcou->getX()==hit2->getX()||hit2->getY()==tepcou->getY()){
					continue;
				}
				isjiance=true; 
				temphit->addObject(tepcou);
				CCArray* temparr=LLKAlgorithm::oneCorner(llkArray,temphit);
				if (temparr->count()>0){
					temparray->addObjectsFromArray(temparr);
					break;
				}else {
					if(i==max){
						LLKAlgorithm::removeAllArray(temparray,false);
					}				
					temphit->removeLastObject(false);
				}
			}else{
				LLKAlgorithm::removeAllArray(temparray,false);			
				break;
			}
		}

		if (isjiance==false){
			LLKAlgorithm::removeAllArray(temparray,false);			
		}
	}

	if(temparray->count()==0){
		bool isjiance=false; 
		// 向下检测		
		for(int i=(y1-1);i>=0;i--){
			CustomSprite* tepcou =LLKAlgorithm::getCustByXandY(llkArray, x1, i);
			if (tepcou->getIsEliminate()){
				temparray->addObject(tepcou);
				// 判断看能否组成一个矩形
				if(tepcou->getX()==hit2->getX()||hit2->getY()==tepcou->getY()){				
					continue;
				}
				isjiance=true; 
				temphit->addObject(tepcou);
				CCArray* temparr=LLKAlgorithm::oneCorner(llkArray,temphit);
				if (temparr->count()>0){
					temparray->addObjectsFromArray(temparr);
					break;
				}else {
					if (i==0){
						LLKAlgorithm::removeAllArray(temparray,false);
					}					
					temphit->removeLastObject(false);
				}
			}else{
				LLKAlgorithm::removeAllArray(temparray,false);
				break;
			}
		}
		if (isjiance==false){
			LLKAlgorithm::removeAllArray(temparray,false);			
		}
	}


	if(temparray->count()==0){
		bool isjiance=false; 
		// 向上检测		
		for(int i=(y1+1);i<=may;i++){
			CustomSprite* tepcou =LLKAlgorithm::getCustByXandY(llkArray, x1, i);
			if (tepcou->getIsEliminate()){
				temparray->addObject(tepcou);
				// 判断看能否组成一个矩形
				if(tepcou->getX()==hit2->getX()||hit2->getY()==tepcou->getY()){
					continue;
				}
				isjiance=true; 
				temphit->addObject(tepcou);
				CCArray* temparr=LLKAlgorithm::oneCorner(llkArray,temphit);
				if (temparr->count()>0){
					temparray->addObjectsFromArray(temparr);	
					break;
				}else {
					if(i==may){
						LLKAlgorithm::removeAllArray(temparray,false);
					}

					temphit->removeLastObject(false);
				}
			}else{
				LLKAlgorithm::removeAllArray(temparray,false);

				break;
			}
		}
		if (isjiance==false){
			LLKAlgorithm::removeAllArray(temparray,false);			
		}
	}

	if (temparray->count()>0){
		temparray->addObject(hit1);
	}

	return temparray;
}




CustomSprite* LLKAlgorithm::getCustByXandY(cocos2d::CCArray* llkArray,int x,int y){
	for (int i=0;i<llkArray->count();i++){
		CustomSprite* hit1=(CustomSprite*)llkArray->objectAtIndex(i);
		if (hit1->getX()==x&&hit1->getY()==y){
			return hit1;
		}else {
			continue;
		}
	}
}

void LLKAlgorithm::removeAllArray(CCArray* myarray,bool isrel){
	for(int i=0;i<myarray->count();i++){
		myarray->removeObjectAtIndex(0,isrel);
		i--;
	}

}

CCArray* LLKAlgorithm::algorithm(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray){
	CustomSprite* hit1=(CustomSprite*)hitArray->objectAtIndex(0);// 取出第一个
	CustomSprite* hit2=(CustomSprite*)hitArray->objectAtIndex(1);// 取出第二个
	CCArray* temparr=NULL;
	// 表示在一行
	if (hit1->getX()==hit2->getX()){	

		temparr=LLKAlgorithm::vertical(llkArray, hitArray);
		if (temparr->count()>0){
			CCLOG("vertical");
		}

	}else if (hit1->getY()==hit2->getY()){ // 表示在一列
		temparr=LLKAlgorithm::horizon (llkArray, hitArray);	
		if (temparr->count()>0){
			CCLOG("horizon");
		}
	}else{
		// 表示不再一行 也不在一列
		temparr=LLKAlgorithm::oneCorner(llkArray, hitArray);	
		if (temparr->count()>0){
			CCLOG("oneCorner");
		}
	}

	if (temparr->count()==0){
		temparr=LLKAlgorithm::twoCorner(llkArray,hitArray);
		if (temparr->count()>0){
			CCLOG("twoCorner");
		}
	}

	return temparr;
}