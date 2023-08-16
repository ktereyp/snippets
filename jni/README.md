### generate .h file

```java
javac -h . com/snippets/jni/HelloWorld.java
```

this will generate a file `com_snippets_jni_HelloWorld.h`

### compile jni

```
pushd .
# compile
mkdir -p ../build && cd ../build && cmake .. && make native
# return this directory
popd

# compile java
javac com/snippets/jni/HelloWorld.java
```

### run

```bash
java -cp .  -Djava.library.path=../build/jni/ com.snippets.jni.HelloWorld
```
