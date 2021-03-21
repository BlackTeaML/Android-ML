#include <cstdio>
#include <cstdlib>
#include <dlfcn.h>
#include <cocos2d.h>
#include "libs/hook/inlineHook.h"

using namespace cocos2d;

CCNode* (*old_PlayerObject_create)(CCNode*, int, int, CCLayer*);
CCNode* playerObject_create(CCNode* self, int int1, int int2, CCLayer* layer) {
	if(self != nullptr) {
		CCNode* ret = old_PlayerObject_create(self, int1, int2, layer);
		// idk why bit i like it
		ret->setScale(2);
		return ret;
	}
	return old_PlayerObject_create(self, int1, int2, layer);
}

__attribute__((constructor))
void libblacktea_main() {

	hook("_ZN12PlayerObject6createEiiPN7cocos2d7CCLayerE", playerObject_create, old_PlayerObject_create);
	inlineHookAll();
}
