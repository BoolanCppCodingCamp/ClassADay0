# ClassADay0

实战课提到的几个资料：

1. Scott Meyers 的演讲：

https://youtu.be/smqT9Io_bKo

2. Tensorflow 中 variant 的使用：

```cpp
namespace tensorflow {

// Allow Tensors to be stored inside Variants with automatic
// encoding/decoding when those Variants are themselves being decoded
// in a Tensor's FromProto.
//
// NOTE(mrry): The corresponding "copy function" registrations can be found in
// ../common_runtime/copy_tensor.cc (due to dependencies on other common_runtime
// code).
```
https://github.com/tensorflow/tensorflow/blob/master/tensorflow/core/framework/tensor.cc
