#ifndef MENULAYER_H
#define MENULAYER_H
#include <cocos2d.h>

class MenuLayer : public cocos2d::CCNode {
public:
  void endGame();
  void onYouTube(cocos2d::CCObject*);
  void onTwitter(cocos2d::CCObject*);
  void onFacebook(cocos2d::CCObject*);
  void onRobTop(cocos2d::CCObject*);
  void onNewgrounds(cocos2d::CCObject*);
  void onStats(cocos2d::CCObject*);
  void onEveryplay(cocos2d::CCObject*);
  void syncPlatformAchievements(float);
  void onAchievements(cocos2d::CCObject*);
  void onMoreGames(cocos2d::CCObject*);
  void onDaily(cocos2d::CCObject*);
  void onMyProfile(cocos2d::CCObject*);
  static cocos2d::CCNode* node(void);
  static cocos2d::CCScene* scene(bool);
  void updateUserProfileButton(void);
  bool init();
  void onGameCenter(cocos2d::CCObject*);
  void openOptions(bool);
  void onOptionsInstant();
  void onOptions(cocos2d::CCObject*);
  void onQuit(cocos2d::CCObject*);
  void onGarage(cocos2d::CCObject*);
  void onCreator(cocos2d::CCObject*);
  void onPlay(cocos2d::CCObject*);
};
#endif