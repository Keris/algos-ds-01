#include "bin_tree.h"
#include "../json/json.hpp"

using json = nlohmann::json;

Tree *_internal_build(const json &j_array, int idx) {
  if (idx < j_array.size() && j_array.at(idx) != nullptr) {
    auto t_node = new tree_node_t(j_array.at(idx));
    auto l_idx = 2 * idx + 1, r_idx = 2 * idx + 2;
    t_node->left = _internal_build(j_array, l_idx);
    t_node->right = _internal_build(j_array, r_idx);
    return t_node;
  }
  return nullptr;
}

Tree *build_tree(const std::string &j_str) {
  auto js = json::parse(j_str);
  if (js.empty())
    return nullptr;
  return _internal_build(js, 0);
}

void traverse_pre_order(Tree *t, std::vector<int> &out) {
  if (t) {
    out.push_back(t->val);
    traverse_pre_order(t->left, out);
    traverse_pre_order(t->right, out);
  }
}

void traverse_in_order(Tree *t, std::vector<int> &out) {
  if (t) {
    traverse_in_order(t->left, out);
    out.push_back(t->val);
    traverse_in_order(t->right, out);
  }
}

void traverse_post_order(Tree *t, std::vector<int> &out) {
  if (t) {
    traverse_post_order(t->left, out);
    traverse_post_order(t->right, out);
    out.push_back(t->val);
  }
}