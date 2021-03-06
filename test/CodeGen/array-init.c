// RUN: %clang_cc1 %s -O0 -triple x86_64-unknown-linux-gnu -emit-llvm -o - | FileCheck %s

// CHECK: @{{.*}}.a1 = internal constant [5 x i32] [i32 0, i32 1, i32 2, i32 0, i32 0]
// CHECK: @{{.*}}.a2 = internal constant [5 x i32] zeroinitializer
// CHECK: @{{.*}}.a3 = internal constant [5 x i32] zeroinitializer

void testConstArrayInits(void)
{
  const int a1[5] = {0,1,2};
  const int a2[5] = {0,0,0};
  const int a3[5] = {0};
}
