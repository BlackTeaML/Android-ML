#ifndef __CCMENUITEMSPRITEEXTRA_H__
#define __CCMENUITEMSPRITEEXTRA_H__

#include <gd.h>

	#pragma runtime_checks("s", off)
	class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite {
	protected:
		float m_fUnknown;
		float m_fUnknown2;

	public:
		static CCMenuItemSpriteExtra *create(CCNode *normalSprite, CCNode *selectedSprite, CCObject *target, cocos2d::SEL_MenuHandler selector);
		void setSizeMult(float mult);
	};
	#pragma runtime_checks("s", restore)


#endif