package com.snippets.jni;

public class HelloWorld {

    static {
        System.loadLibrary("native");
    }
    
    public static void main(String[] args) {
        new HelloWorld().hello();
    }

    private native void hello();
}
