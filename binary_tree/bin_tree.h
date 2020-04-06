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

// Traverse a tree in in-order
void traverse_in_order(Tree *t, std::vector<int> &out);

// Traverse a tree in post-order
void traverse_post_order(Tree *t, std::vector<int> &out);

#endif  // ALGOS_DS_01_BIN_TREE_H
