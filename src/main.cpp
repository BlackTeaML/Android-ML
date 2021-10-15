#include <gd.h>
#include <dobby.h>
#include <dlfcn.h>
#include <cocos2d.h>

using namespace cocos2d;

namespace MenuLayerH
{
	bool(*init_o)(MenuLayer*);
	bool init(MenuLayer* self)
	{
		auto ret = init_o(self);

		auto sprite = CCSprite::createWithSpriteFrameName("GJ_playBtn_001.png");
		auto btn = CCMenuItemSprite::create(sprite, sprite, self, menu_selector(MenuLayer::onDaily));
		btn->setScale(0.5);
		auto menu = CCMenu::create();
		menu->addChild(btn, 100);
		menu->setPosition({CCDirector::sharedDirector()->getVisibleSize().width / 3, 100});
		self->addChild(menu, 100);

		return ret;
	}

	void applyHooks()
	{
		DobbyHook(dlsym(dlopen("libcocos2dcpp.so", RTLD_LAZY), "_ZN9MenuLayer4initEv"), (void*)init, (void**)&init_o);
	}
}

__attribute__((constructor))
void hyperdahs()
{
	MenuLayerH::applyHooks();
}
