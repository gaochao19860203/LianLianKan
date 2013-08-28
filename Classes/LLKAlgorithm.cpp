#include "LLKAlgorithm.h"

USING_NS_CC;
// ����Ǻ�����
CCArray* LLKAlgorithm::horizon(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray){
	CustomSprite* hit1=(CustomSprite*)hitArray->objectAtIndex(0);// ȡ����һ��
	CustomSprite* hit2=(CustomSprite*)hitArray->objectAtIndex(1);// ȡ���ڶ���
	int x1=hit1->getX(); // �õ���һ��X ����
	int x2=hit2->getX(); // �õ��ڶ���X ����
	bool isda=x1>x2?true:false;// �ó��Ǹ�����Ϻ�
	int temp=isda?x1-x2:x2-x1; // ��ȡ����������֮��� ���
	CCArray* temparray=CCArray::create();// ��¼������֮�� �������ĵ�

	if (temp==1){// ��ʾ���������ڵ�����
		temparray->addObject(hit1);
		temparray->addObject(hit2);
	}else {    

		if (isda){
			temparray->addObject(hit1);
			temparray->addObject(hit2);
			for(int i=1;i<temp;i++){
				CustomSprite* hitteim=LLKAlgorithm::getCustByXandY(llkArray,x1-i,hit2->getY());
				// ������Ѿ���������ô �Ϳ��Լ�����ѯ
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
				// ������Ѿ���������ô �Ϳ��Լ�����ѯ
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
//�����������
CCArray*  LLKAlgorithm::vertical(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray){
	CustomSprite* hit1=(CustomSprite*)hitArray->objectAtIndex(0);// ȡ����һ��
	CustomSprite* hit2=(CustomSprite*)hitArray->objectAtIndex(1);// ȡ���ڶ���
	int y1=hit1->getY(); // �õ���һ��Y ����
	int y2=hit2->getY(); // �õ��ڶ���Y ����
	bool isda=y1>y2?true:false;// �ó��Ǹ�����Ϻ�
	int temp=isda?y1-y2:y2-y1; // ��ȡ����������֮��� ���
	CCArray* temparray=CCArray::create();// ��¼������֮�� �������ĵ�

	if (temp==1){// ��ʾ���������ڵ�����
		temparray->addObject(hit1);
		temparray->addObject(hit2);
	}else {    

		if (isda){
			temparray->addObject(hit1);
			temparray->addObject(hit2);
			for(int i=1;i<temp;i++){
				CustomSprite* hitteim=LLKAlgorithm::getCustByXandY(llkArray,hit2->getX(),y1-i);
				// ������Ѿ���������ô �Ϳ��Լ�����ѯ
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
				// ������Ѿ���������ô �Ϳ��Լ�����ѯ
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
�����һ���ս� ���㷨
һ��ת����ͨ����ʵ�൱������ͼƬ����һ�����Σ�������ͼƬ��һ�ԶԽǶ��㣬�������������������һ������ͬʱ������������ֱ����
�Ǿ�˵������ "һ����ͨ" ��ʵ���ǰ�һ���սǵ�ת���� һ�� ������ͨ��һ��������ͨ��

*/

CCArray*  LLKAlgorithm::oneCorner(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray){
	CustomSprite* hit1=(CustomSprite*)hitArray->objectAtIndex(0);// ȡ����һ��
	CustomSprite* hit2=(CustomSprite*)hitArray->objectAtIndex(1);// ȡ���ڶ���
	int x1=hit1->getX();
	int x2=hit2->getX();
	int y1=hit1->getY();
	int y2=hit2->getY();
	bool isXg=x1>x2?true:false;//�����true ��ʾhit1 ��hit2 �ĺ���
	bool isYg=y1>y2?true:false;//�����true ��ʾhit1 ��hit2 ������
	// �������Ǽ�������ε�����������ص�
	// �ȼ����  �ھ�����������Ӧ�� 
	int temx=0;
	int temy=0;	

	// ��ȡ���������һ����Ӧ�������

	if(isYg){
		temy=hit1->getY();
		temx=hit2->getX();
	}else {
		temy=hit2->getY();
		temx=hit1->getX();
	}
	CCArray* temparray=CCArray::create();// ��¼������֮�� �������ĵ�

	CustomSprite* hity=LLKAlgorithm::getCustByXandY(llkArray,temx,temy);// �õ���������Ǹ���Ӧ�ľ��ζ���� ����ͼƬ
	CCArray* tempHit=CCArray::create();
	//����������Ѿ������� Ҫ���϶����ܹ�ͨ
	if (hity->getIsEliminate()){
		tempHit->addObject(hity);
		tempHit->addObject(isYg?hit1:hit2);
		CCArray* temx=LLKAlgorithm::horizon(llkArray,tempHit);// ��ȡX �������Ƿ������ͨ
		if(temx->count()>0){// ��ʾ������ͨ
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
	// ��ʾ�����·�߲�ͨ
	if (temparray->count()==0){
		// ��ȡX �����������Ӧ�ĵĵ�		
		//temx=isXg?hit1->getX():hit2->getX();
		//temy=isXg?hit2->getY():hit1->getY();

		if (isYg){
			temy=hit2->getY();
			temx=hit1->getX();
		}else {
			temy=hit1->getY();
			temx=hit2->getX();		
		}

		CustomSprite* hitx=LLKAlgorithm::getCustByXandY(llkArray,temx,temy);// �õ���������Ǹ���Ӧ�ľ��ζ���� ����ͼƬ
		if (hitx->getIsEliminate()){
			tempHit->addObject(hitx);
			tempHit->addObject(isYg?hit2:hit1);
			CCArray* temx=LLKAlgorithm::horizon(llkArray,tempHit);// ��ȡX �������Ƿ������ͨ
			if(temx->count()>0){// ��ʾ������ͨ
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
��ʵ�����սǵ��㷨���ǣ����ҵ�һ������� ����һ��ֱ����ͨ������һ����һ���սǾͿ�����ͨ ����ﵽ������Ҫ���֤������ ͼ��
���������սǿ���ֱ����ͨ ������Ĵ�������ʼ�հ�����С�ķŵ������档��ô���ڵ�˼·���� �� first �������ĸ�����
��⣬�����Ǹ��㸴�����Ҫ�� ֻҪ��һ���㸴��Ҫ�� �ʹ��������ͨ
*/

CCArray*  LLKAlgorithm::twoCorner(cocos2d::CCArray* llkArray,cocos2d::CCArray* hitArray){

	bool isjiance=false; // �����Ҫ����ʾ�Ƿ����� һ���սǵ��ж�
	// �Ȼ�ȡ ��ǰX ������Ƕ���  y ������Ƕ���
	CustomSprite* lastCutom=(CustomSprite*)llkArray->lastObject();
	int max=lastCutom->getX();
	int may=lastCutom->getY();
	CustomSprite* hit1=(CustomSprite*)hitArray->objectAtIndex(0);// ȡ����һ��
	CustomSprite* hit2=(CustomSprite*)hitArray->objectAtIndex(1);// ȡ���ڶ���

	// ����ó�һ����  �������ĸ�������� �����ܷ������һ�����һ���ս�����
	// �������Ǿ��ó�ȡ���ĵ�һ����� hit1

	CCArray* temparray=CCArray::create();// ��¼������֮�� �������ĵ�
	int x1=hit1->getX(); // �õ���һ��X ����
	int y1=hit1->getY(); // �õ���1��Y����
	// ����������
	CCArray* temphit=CCArray::create(); 
	temphit->addObject(hit2);
	for(int i=(x1-1);i>=0;i--){
		CustomSprite* tepcou =LLKAlgorithm::getCustByXandY(llkArray, i, y1);
		if (tepcou->getIsEliminate()){
			// �жϿ��ܷ����һ������
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
		// ���Ҽ��
		for(int i=(x1+1);i<=max;i++){
			CustomSprite* tepcou =LLKAlgorithm::getCustByXandY(llkArray, i, y1);
			if (tepcou->getIsEliminate()){
				// �жϿ��ܷ����һ������
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
		// ���¼��		
		for(int i=(y1-1);i>=0;i--){
			CustomSprite* tepcou =LLKAlgorithm::getCustByXandY(llkArray, x1, i);
			if (tepcou->getIsEliminate()){
				temparray->addObject(tepcou);
				// �жϿ��ܷ����һ������
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
		// ���ϼ��		
		for(int i=(y1+1);i<=may;i++){
			CustomSprite* tepcou =LLKAlgorithm::getCustByXandY(llkArray, x1, i);
			if (tepcou->getIsEliminate()){
				temparray->addObject(tepcou);
				// �жϿ��ܷ����һ������
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
	CustomSprite* hit1=(CustomSprite*)hitArray->objectAtIndex(0);// ȡ����һ��
	CustomSprite* hit2=(CustomSprite*)hitArray->objectAtIndex(1);// ȡ���ڶ���
	CCArray* temparr=NULL;
	// ��ʾ��һ��
	if (hit1->getX()==hit2->getX()){	

		temparr=LLKAlgorithm::vertical(llkArray, hitArray);
		if (temparr->count()>0){
			CCLOG("vertical");
		}

	}else if (hit1->getY()==hit2->getY()){ // ��ʾ��һ��
		temparr=LLKAlgorithm::horizon (llkArray, hitArray);	
		if (temparr->count()>0){
			CCLOG("horizon");
		}
	}else{
		// ��ʾ����һ�� Ҳ����һ��
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