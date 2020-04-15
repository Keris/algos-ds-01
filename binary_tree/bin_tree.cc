#include "bin_tree.h"

#include <algorithm>
#include <queue>
#include <stack>

#include "../json/json.hpp"

using json = nlohmann::json;

Tree *_internal_build(const json &j_array, int idx) {
  if (idx < j_array.size() && j_array.at(idx) != nullptr) {
    auto t_node = new TreeNode(j_array.at(idx));
    auto l_idx = 2 * idx + 1, r_idx = 2 * idx + 2;
    t_node->left = _internal_build(j_array, l_idx);
    t_node->right = _internal_build(j_array, r_idx);
    return t_node;
  }
  return nullptr;
}

Tree *build_tree(const std::string &j_str) {
  auto js = json::parse(j_str);
  if (js.empty()) return nullptr;
  return _internal_build(js, 0);
}

void traverse_pre_order(Tree *t, std::vector<int> &out) {
  if (t) {
    out.push_back(t->val);
    traverse_pre_order(t->left, out);
    traverse_pre_order(t->right, out);
  }
}

std::vector<int> traverse_pre_order_iter(Tree *t) {
  if (!t) return {};

  std::vector<int> result;
  std::stack<Tree *> st;
  st.push(t);
  while (!st.empty()) {
    auto n = st.top();  // visit a tree node
    result.push_back(n->val);
    st.pop();
    if (n->right) st.push(n->right);
    if (n->left) st.push(n->left);
  }
  return result;
}

void traverse_in_order(Tree *t, std::vector<int> &out) {
  if (t) {
    traverse_in_order(t->left, out);
    out.push_back(t->val);
    traverse_in_order(t->right, out);
  }
}

std::vector<int> traverse_in_order_iter(Tree *t) {
  if (!t) return {};

  std::stack<Tree *> st;
  std::vector<int> result;
  auto curr = t;
  while (!st.empty() || curr) {
    if (curr) {
      st.push(curr);
      curr = curr->left;
    } else {
      curr = st.top();
      st.pop();
      result.push_back(curr->val);
      curr = curr->right;
    }
  }
  return result;
}

void traverse_post_order(Tree *t, std::vector<int> &out) {
  if (t) {
    traverse_post_order(t->left, out);
    traverse_post_order(t->right, out);
    out.push_back(t->val);
  }
}

std::vector<int> traverse_post_order_iter(Tree *t) {
  if (!t) return {};

  std::stack<Tree *> st;
  std::vector<int> result;
  TreeNode *last_node = nullptr;
  auto curr = t;
  while (!st.empty() || curr) {
    if (curr) {
      st.push(curr);
      curr = curr->left;
    } else {
      curr = st.top();
      if (curr->right && curr->right != last_node)
        curr = curr->right;
      else {
        result.push_back(curr->val);
        st.pop();
        last_node = curr;
        curr = nullptr;
      }
    }
  }
  return result;
}

std::vector<std::vector<int>> traverse_by_level(Tree *t) {
  if (!t) return {};
  std::queue<Tree *> q;
  std::vector<std::vector<int>> res;
  q.push(t);
  while (!q.empty()) {
    int sz = q.size();
    std::vector<int> v;
    for (int i = 0; i != sz; i++) {
      auto node = q.front();
      v.push_back(node->val);
      q.pop();
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
    res.push_back(v);
  }
  return res;
}

int max_depth(Tree *t) {
  if (!t) return 0;

  auto h1 = max_depth(t->left);
  auto h2 = max_depth(t->right);
  return 1 + std::max(h1, h2);
}

int sum_of_left_leaves(Tree *t) {
  if (!t) return 0;
  std::stack<Tree *> st;
  int res{0};
  st.push(t);
  TreeNode *parent = nullptr;
  while (!st.empty()) {
    auto tn = st.top();
    st.pop();
    // visit node if it's a left leaf
    if (parent && parent->left == tn && !tn->left && !tn->right) res += tn->val;
    parent = tn;
    if (tn->right) st.push(tn->right);
    if (tn->left) st.push(tn->left);
  }
  return res;
}

bool is_identical_tree(TreeNode *s, TreeNode *t) {
  if (!s && !t) return true;
  if (s && !t) return false;
  if (!s && t) return false;
  return s->val == t->val && is_identical_tree(s->left, t->left) &&
         is_identical_tree(s->right, t->right);
}

bool is_subtree(TreeNode *s, TreeNode *t) {
  if (is_identical_tree(s, t)) return true;
  if (s) return is_subtree(s->left, t) || is_subtree(s->right, t);
  return false;
}