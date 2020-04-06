#include "bin_tree.h"

#include "gtest/gtest.h"

namespace {
//
// Test binary tree traversal in pre-order
//
TEST(BinTreeTraversalPreOrder, EmptyTree) {
  std::vector<int> result;
  Tree *t = nullptr;
  traverse_pre_order(t, result);
  EXPECT_TRUE(result.empty());
}

TEST(BinTreeTraversalPreOrder, OneNodeTree) {
  Tree *t = new tree_node_t(0);
  std::vector<int> result;
  traverse_pre_order(t, result);
  ASSERT_EQ(1, result.size());
  EXPECT_EQ(0, result[0]);
}

// Input tree is as follows:
//   1
//  / \
// 2  3
TEST(BinTreeTraversalPreOrder, NormalTree) {
  Tree *t = build_tree("[1,2,3,4,5,null,6]");
  std::vector<int> x;
  std::vector<int> y{1, 2, 4, 5, 3, 6};
  traverse_pre_order(t, x);
  ASSERT_EQ(x.size(), y.size()) << "x and y are of unequal length";
  for (int i = 0; i != x.size(); i++) {
    EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
  }
}
//
// Test binary tree traversal in in-order
//
TEST(BinTreeTraversalInOrder, EmptyTree) {
  std::vector<int> result;
  Tree *t = nullptr;
  traverse_in_order(t, result);
  EXPECT_TRUE(result.empty());
}

TEST(BinTreeTraversalInOrder, OneNodeTree) {
  Tree *t = new tree_node_t(0);
  std::vector<int> result;
  traverse_in_order(t, result);
  ASSERT_EQ(1, result.size());
  EXPECT_EQ(0, result[0]);
}

// Input tree is as follows:
//      1
//    /  \
//   2   3
//  / \   \
// 4  5   6
TEST(BinTreeTraversalInOrder, NormalTree) {
  Tree *t = build_tree("[1,2,3,4,5,null,6]");
  std::vector<int> x;
  std::vector<int> y{4, 2, 5, 1, 3, 6};
  traverse_in_order(t, x);
  ASSERT_EQ(x.size(), y.size()) << "x and y are of unequal length";
  for (int i = 0; i != x.size(); i++) {
    EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
  }
}
//
// Test binary tree traversal in post-order
//
TEST(BinTreeTraversalPostOrder, EmptyTree) {
  std::vector<int> result;
  Tree *t = nullptr;
  traverse_post_order(t, result);
  EXPECT_TRUE(result.empty());
}

TEST(BinTreeTraversalPostOrder, OneNodeTree) {
  Tree *t = new tree_node_t(0);
  std::vector<int> result;
  traverse_post_order(t, result);
  ASSERT_EQ(1, result.size());
  EXPECT_EQ(0, result[0]);
}

// Input tree is as follows:
//      1
//    /  \
//   2   3
//  / \   \
// 4  5   6
TEST(BinTreeTraversalPostOrder, NormalTree) {
  Tree *t = build_tree("[1,2,3,4,5,null,6]");
  std::vector<int> x;
  std::vector<int> y{4, 5, 2, 6, 3, 1};
  traverse_post_order(t, x);
  ASSERT_EQ(x.size(), y.size()) << "x and y are of unequal length";
  for (int i = 0; i != x.size(); i++) {
    EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
  }
}
}  // namespace