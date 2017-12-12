
#include <android/log.h>

#define TAG "update"
#define LOGD(tag,fmt,...)  __android_log_print(ANDROID_LOG_DEBUG,tag,fmt,__VA_ARGS__) // 定义LOGD类型
#define LOGI(tag,fmt,...)  __android_log_print(ANDROID_LOG_INFO,tag,fmt,__VA_ARGS__) // 定义LOGI类型
#define LOGW(tag,fmt,...)  __android_log_print(ANDROID_LOG_WARN,tag,fmt,__VA_ARGS__) // 定义LOGW类型
#define LOGE(tag,fmt,...)  __android_log_print(ANDROID_LOG_ERROR,tag,fmt,__VA_ARGS__) // 定义LOGE类型
#define LOGF(tag,fmt,...)  __android_log_print(ANDROID_LOG_FATAL,tag,fmt,__VA_ARGS__) // 定义LOGF类型