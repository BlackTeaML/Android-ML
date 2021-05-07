#ifndef CREATORLAYER_H
#define CREATORLAYER_H
#include <cocos2d.h>

class CreatorLayer : public cocos2d::CCNode {
public:
	static cocos2d::CCScene* scene();
	static cocos2d::CCLayer* create();
	void onTreasureRoom(cocos2d::CCObject* pSender);
	void onSecretVault(cocos2d::CCObject* pSender);
	void onChallenge(cocos2d::CCObject* pSender);
	void onWeeklyLevel(cocos2d::CCObject* pSender);
	void onGauntlets(cocos2d::CCObject* pSender);
	void onMapPacks(cocos2d::CCObject* pSender);
	void onFameLevels(cocos2d::CCObject* pSender);
	void onOnlineLevels(cocos2d::CCObject* pSender);
	void onLeaderboards(cocos2d::CCObject* pSender);
	void onSavedLevels(cocos2d::CCObject* pSender);
	void onMyLevels(cocos2d::CCObject* pSender);
	void onDailyLevel(cocos2d::CCObject* pSender);
	void onFeaturedLevels(cocos2d::CCObject* pSender);
	bool init();
};
#endif