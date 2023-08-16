#include "com_snippets_jni_HelloWorld.h"

#include <iostream>

void JNICALL Java_com_snippets_jni_HelloWorld_hello
(JNIEnv *, jobject) {
    std::cout << "hello" << std::endl;
}

