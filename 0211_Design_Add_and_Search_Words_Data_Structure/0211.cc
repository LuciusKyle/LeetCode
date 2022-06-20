
#include <assert.h>
#include <re2/re2.h>

#include <chrono>
#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

constexpr size_t kFileSizeLimit = 16 * 1024 * 1024;

class WordDictionary {
 public:
  WordDictionary() {
    for (int i = 0; i < 25; ++i) root_.push_back(new Node);
  }
  ~WordDictionary() {
    for (auto ptr : root_) delete ptr;
  }

  void addWord(const string word) {
    Node *temp_node_ptr = root_[word.size() - 1];
    for (const char ch : word) {
      if (temp_node_ptr->child_nodes[ch - 'a'] == nullptr)
        temp_node_ptr->child_nodes[ch - 'a'] = new Node;

      temp_node_ptr = temp_node_ptr->child_nodes[ch - 'a'];
    }
    temp_node_ptr->end_of_word = true;
  }

  bool search(const string target) {
    return search(target, 0, root_[target.size() - 1]);
  }

 private:
  struct Node;
  bool search(const string &target, size_t start_index, const Node *temp_root_ptr) const;
  struct Node {
    Node() : end_of_word(false), child_nodes{nullptr} {};
    ~Node() {
      for (auto ptr : child_nodes) delete ptr; // delete nullptr is OK;
    }
    bool end_of_word;
    Node *child_nodes[26];
  };
  vector<Node *> root_;
};

bool WordDictionary::search(const string &target, size_t start_index, const Node *temp_root_ptr) const {
  for (size_t i = start_index; i < target.size(); ++i) {
    if (target[i] == '.') {
      bool one_possible_answer = false;
      for (size_t j = 0; j < 26; ++j)
        if (temp_root_ptr->child_nodes[j] != nullptr && search(target, i + 1, temp_root_ptr->child_nodes[j])) {
          one_possible_answer = true;
          break;
        }

      return one_possible_answer;
    }
    if (temp_root_ptr->child_nodes[target[i] - 'a'] == nullptr)
      return false;

    temp_root_ptr = temp_root_ptr->child_nodes[target[i] - 'a'];
  }
  return temp_root_ptr->end_of_word;
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(int argc, char *argv[]) {
  char *abc = nullptr;
  delete abc;
  auto start = std::chrono::high_resolution_clock::now();
  auto duration = start - start;

  char *buf = new char[kFileSizeLimit];
  FILE *fp = nullptr;
  const re2::RE2 line_break_regex = R"reg(([[:graph:]]+?)[[:space:]]([[:graph:]]+?)[[:space:]]+)reg";
  const re2::RE2 extract_element = R"reg(\"(.+?)\")reg";
  for (int i = 1; i < argc; ++i) {
    fp = fopen(argv[i], "rb");
    if (fp == nullptr) continue;
    const size_t file_size = fread(buf, 1, kFileSizeLimit, fp);
    if (kFileSizeLimit <= file_size) {
      fclose(fp);
      continue;
    }
    fclose(fp);
    string first_line, second_line;
    const re2::StringPiece file_content(buf, file_size);
    bool result = re2::RE2::FullMatch(file_content, line_break_regex, &first_line, &second_line);
    assert(result);
    re2::StringPiece actions(first_line), parameters(second_line);
    string action, parameter;
    result = re2::RE2::FindAndConsume(&actions, extract_element, &action);
    assert(result);
    assert(action == "WordDictionary");
    WordDictionary word_dict;
    size_t add_word_count = 0, search_word_count = 0;
    while (re2::RE2::FindAndConsume(&actions, extract_element, &action)) {
      bool param_result = re2::RE2::FindAndConsume(&parameters, extract_element, &parameter);
      assert(param_result);
      if (action == "addWord") {
        start = std::chrono::high_resolution_clock::now();
        word_dict.addWord(parameter);
        duration += std::chrono::high_resolution_clock::now() - start;
        ++add_word_count;
      } else if (action == "search") {
        start = std::chrono::high_resolution_clock::now();
        word_dict.search(parameter);
        duration += std::chrono::high_resolution_clock::now() - start;
        ++search_word_count;
      } else
        abort();
    }
    cout << "time in " << argv[i] << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << " milliseconds\n";
    cout << "add count: " << add_word_count << "\tsearch count: " << search_word_count << "\n\n";
    duration = start - start;
  }
  delete[] buf;
  cout << endl;
  return 0;
}