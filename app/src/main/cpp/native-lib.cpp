#include <jni.h>
#include <string>
#include <dlfcn.h>
#include "OboeDebug.h"

extern "C" JNIEXPORT jstring JNICALL
Java_general_code_jnilibsprebuilt_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
//    LOGV("attempting to open %s", "avcodec");
//    void * avcodec = dlopen("avcodec", RTLD_NOW);
//    if (avcodec == nullptr) {
//        LOGV("%s could not be opened: %s", "avcodec", dlerror());
//    } else {
//        LOGV("%s opened successfully", "avcodec");
//    }
    return env->NewStringUTF(hello.c_str());
}
