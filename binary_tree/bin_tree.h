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

#endif  // ALGOS_DS_01_BIN_TREE_H
