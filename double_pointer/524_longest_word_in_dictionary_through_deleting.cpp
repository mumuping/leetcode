//
// Created by lp on 2022/9/21.
//

#include "string"
#include "vector"

std::string findLongestWord(std::string s, std::vector<std::string> &dictionary) {
  int index_pointer_to_s = 0, index_pointer_to_word = 0;
  int size_s = s.size(), size_dictionary = dictionary.size();
  int length_word_in_dictionary = 0;

  int result_index = 0;
  int result_length = 0;

  for (int i = 0; i < size_dictionary; ++i) {
	index_pointer_to_s = 0;
	index_pointer_to_word = 0;
	length_word_in_dictionary = dictionary[i].size();

	while (index_pointer_to_s < size_s) {
	  if (s[index_pointer_to_s]==dictionary[i][index_pointer_to_word])
		++index_pointer_to_word;
	  if (index_pointer_to_word==length_word_in_dictionary) {
		if (result_length < length_word_in_dictionary) {
		  result_index = i;
		  result_length = length_word_in_dictionary;
		}
		if (result_length==length_word_in_dictionary) {
		  result_index = std::lexicographical_compare(dictionary[result_index].begin(),
													  dictionary[result_index].end(),
													  dictionary[i].begin(),
													  dictionary[i].end()) ? result_index : i;
		  result_length = dictionary[result_index].size();
		}
		break;
	  }
	  ++index_pointer_to_s;
	}
  }

  if (result_length!=0)return dictionary[result_index];
  else return "";
}
