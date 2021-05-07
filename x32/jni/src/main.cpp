#include <cstdio>
#include <cstdlib>
#include <dlfcn.h>
#include <cocos2d.h>
#include <gd.h>
#include "libs/hook/inlineHook.h"

using namespace cocos2d;

namespace h_menuLayer {
	void* (*o_init)(CCLayer*);
	void* init(CCLayer* self) {
		auto ret = o_init(self);
		auto sprite = CCSprite::createWithSpriteFrameName("GJ_playBtn_001.png");
		auto btn = CCMenuItemSprite::create(sprite, sprite, self, menu_selector(CreatorLayer::onDailyLevel));
		btn->setScale(0.5);
		auto menu = CCMenu::create();
		menu->addChild(btn, 100);
		menu->setPosition({CCDirector::sharedDirector()->getVisibleSize().width / 2, 100});
		self->addChild(menu, 100);
		return ret;
	}
}

// https://github.com/FlairyDash/rgb-icons-mod/blob/main/main.cpp
namespace h_playerObject {
	CCNode* (*o_create)(CCNode*, int, int, CCLayer*);
	CCNode* create(CCNode* self, int i1, int i2, CCLayer* layer) {
		if(self != nullptr) {
			CCNode* ret = o_create(self, i1, i2, layer);
			ret->runAction(CCRepeatForever::create(CCSequence::create(
				CCTintTo::create(0.5, 255,   0,	  0), 
				CCTintTo::create(0.5, 255, 255,   0), 
				CCTintTo::create(0.5, 0  , 255,   0),
				CCTintTo::create(0.5, 0  , 255, 255), 
				CCTintTo::create(0.5, 0  ,   0, 255), 
				CCTintTo::create(0.5, 255,   0, 255), 
				nullptr)));
			CCNode* a = (CCNode*)ret;
			CCNode* b = (CCNode*)a->getChildren()->objectAtIndex(0);
			CCNode* c = (CCNode*)b->getChildren()->objectAtIndex(0);
			c->runAction(CCRepeatForever::create(CCSequence::create(
				CCTintTo::create(0.5, 0  , 255, 255), 
				CCTintTo::create(0.5, 0  ,   0, 255), 
				CCTintTo::create(0.5, 255,   0, 255), 
				CCTintTo::create(0.5, 255,   0,	  0), 
				CCTintTo::create(0.5, 255, 255,   0), 
				CCTintTo::create(0.5, 0  , 255,   0),
				nullptr)));
			return ret;
		}
		return o_create(self, i1, i2, layer);
	}
}


__attribute__((constructor))
void fdml_init() {
	hook("_ZN9MenuLayer4initEv", h_menuLayer, init, o_init);
	hook("_ZN12PlayerObject6createEiiPN7cocos2d7CCLayerE", h_playerObject, create, o_create);	inlineHookAll();
}
