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
// 2   3
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
//     1
//    / \
//   2   3
//  / \   \
// 4   5   6
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
//     1
//    / \
//   2   3
//  / \   \
// 4   5   6
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

// Tests binary tree traversal by level
TEST(BinTreeTraversalByLevel, NormalTree) {
  Tree *t = build_tree("[1,2,3,4,5,null,6]");
  auto x = traverse_by_level(t);
  std::vector<std::vector<int>> y{{1}, {2, 3}, {4, 5, 6}};
  ASSERT_EQ(x.size(), y.size()) << "x and y are of unequal length";
  for (int i = 0; i != x.size(); i++) {
    ASSERT_EQ(x[i].size(), y[i].size())
        << "x[i] and y[i] are of unequal length at index " << i;
    for (int j = 0; j != x[i].size(); j++) {
      EXPECT_EQ(x[i][j], y[i][j])
          << "Vectors x[i] and y[i] differ at index " << j;
    }
  }
}

// Tests binary tree traversal in preorder iterately
TEST(BinTreeTraversalPreOrderIter, NormalTree) {
  Tree *t = build_tree("[1,2,3,4,5,null,6]");
  auto x = traverse_pre_order_iter(t);
  std::vector<int> y;
  traverse_pre_order(t, y);
  ASSERT_EQ(x.size(), y.size()) << "x and y are of unequal length";
  for (int i = 0; i != x.size(); i++) {
    EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
  }
}

// Tests binary tree traversal in inorder iterately
TEST(BinTreeTraversalInOrderIter, NormalTree) {
  Tree *t = build_tree("[1,2,3,4,5,null,6]");
  auto x = traverse_in_order_iter(t);
  std::vector<int> y;
  traverse_in_order(t, y);
  ASSERT_EQ(x.size(), y.size()) << "x and y are of unequal length";
  for (int i = 0; i != x.size(); i++) {
    EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
  }
}

TEST(BinTreeTraversalInOrderIter, EmptyTree) {
  Tree *t = build_tree("[]");
  auto x = traverse_in_order_iter(t);
  ASSERT_EQ(x.size(), 0) << "Empty tree should have zero elements";
}

TEST(BinTreeTraversalPostOrderIter, EmptyTree) {
  Tree *t = build_tree("[]");
  auto x = traverse_post_order_iter(t);
  ASSERT_EQ(x.size(), 0) << "Empty tree should have zero elements";
}

TEST(BinTreeTraversalPostOrderIter, NormalTree) {
  Tree *t = build_tree("[1,2,3,4,5,null,6]");
  std::vector<int> x;
  traverse_post_order(t, x);
  auto y = traverse_post_order_iter(t);
  ASSERT_EQ(x.size(), y.size()) << "x and y are of unequal length";
  for (int i = 0; i != x.size(); i++) {
    EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
  }
}

TEST(TreeMaxDepth, EmptyTree) {
  Tree *t{nullptr};
  auto h = max_depth(t);
  ASSERT_EQ(h, 0) << "The height of empty tree is not 0";
}

TEST(TreeMaxDepth, SingleNodeTree) {
  Tree *t = build_tree("[1]");
  auto h = max_depth(t);
  ASSERT_EQ(h, 1) << "The height of tree with only one node is not 1";
}

TEST(TreeMaxDepth, TreeOfDepth2) {
  Tree *t = build_tree("[1,2,3]");
  auto h = max_depth(t);
  ASSERT_EQ(h, 2);
}

TEST(TreeMaxDepth, TreeOfDepth3) {
  Tree *t = build_tree("[1,2,3,null,4]");
  ASSERT_EQ(max_depth(t), 3);
}
}  // namespace
