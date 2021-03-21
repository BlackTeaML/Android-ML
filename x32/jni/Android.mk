include $(CLEAR_VARS)
$(warning "${MAIN_LOCAL_PATH}")

LOCAL_PATH = .
LOCAL_MODULE := cocos2dcpp
LOCAL_EXPORT_C_INCLUDES := $(MAIN_LOCAL_PATH) \
	$(MAIN_LOCAL_PATH)/libs/cocos2d \
	$(MAIN_LOCAL_PATH)/libs/cocos2d/include \
	$(MAIN_LOCAL_PATH)/libs/cocos2d/platform \
	$(MAIN_LOCAL_PATH)/libs/cocos2d/platform/android \
	$(MAIN_LOCAL_PATH)/libs/cocos2d/kazmath/include
LOCAL_SRC_FILES := ${MAIN_LOCAL_PATH}/include/libcocos2dcpp.so
include $(PREBUILT_SHARED_LIBRARY)

LOCAL_PATH := ${MAIN_LOCAL_PATH}
include $(CLEAR_VARS)
LOCAL_MODULE := blacktea

LOCAL_CPPFLAGS := -std=c++14
LOCAL_CFLAGS := -Wno-error=format-security -fpermissive -Wc++14-extensions -Wno-absolute-value
LOCAL_CFLAGS += -fno-rtti -fno-exceptions

LOCAL_C_INCLUDES += $(MAIN_LOCAL_PATH) \
	$(MAIN_LOCAL_PATH)/libs/cocos2d \
	$(MAIN_LOCAL_PATH)/libs/cocos2d/include \
	$(MAIN_LOCAL_PATH)/libs/cocos2d/platform \
	$(MAIN_LOCAL_PATH)/libs/cocos2d/platform/android \
	$(MAIN_LOCAL_PATH)/libs/cocos2d/kazmath/include

LOCAL_SRC_FILES := src/main.cpp \
	libs/hook/inlineHook.c \
	libs/hook/relocate.c \

LOCAL_LDLIBS := -llog
LOCAL_SHARED_LIBRARIES = cocos2dcpp
include $(BUILD_SHARED_LIBRARY)