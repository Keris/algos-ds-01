#ifndef ALGOS_DS_01_BIN_TREE_H
#define ALGOS_DS_01_BIN_TREE_H

#include <string>
#include <vector>

struct tree_node_t {
  int val;
  tree_node_t *left, *right;

  explicit tree_node_t(int x) : val{x}, left{nullptr}, right{nullptr} {}
};

using Tree = tree_node_t;

// Build a tree from a json string of array of numbers
Tree *build_tree(const std::string &j_str);

// Traverse a tree in pre-order
void traverse_pre_order(Tree *t, std::vector<int> &out);

// Traverse a tree in pre-order iteratively
std::vector<int> traverse_pre_order_iter(Tree *t);

// Traverse a tree in in-order
void traverse_in_order(Tree *t, std::vector<int> &out);

// Traverse a tree in in-order iteratively
std::vector<int> traverse_in_order_iter(Tree *t);

// Traverse a tree in post-order
void traverse_post_order(Tree *t, std::vector<int> &out);

// Traverse a tree in post-order iteratively
std::vector<int> traverse_post_order_iter(Tree *t);

// Traverse a tree by level
std::vector<std::vector<int>> traverse_by_level(Tree *t);

// Get max depth of a tree
// The max depth is the number of nodes along the path from root node
// down to the farthest leaf node
int max_depth(Tree *t);

// Get the sum of all left leaves in a given binary tree
int sum_of_left_leaves(Tree *t);

#endif  // ALGOS_DS_01_BIN_TREE_H
