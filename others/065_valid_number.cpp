//
// Created by lp on 2023/2/28.
//
#include "string"
#include "regex"
#include "unordered_map"

bool isNumber(std::string s) {
  static const std::regex pattern("[+-]?(?:\\d+\\.?\\d*|\\.\\d+)(?:[Ee][+-]?\\d+)?");
  return std::regex_match(s, pattern);
}

enum class State {
  STATE_INITIAL,
  STATE_INT_SIGN,
  STATE_INTEGER,
  STATE_POINT,
  STATE_POINT_WITHOUT_INT,
  STATE_FRACTION,
  STATE_EXP,
  STATE_EXP_SIGN,
  STATE_EXP_NUMBER,
  STATE_END
};

enum class CharType {
  CHAR_NUMBER,
  CHAR_EXP,
  CHAR_POINT,
  CHAR_SIGN,
  CHAR_ILLEGAL
};

CharType toCharType(char ch) {
  if (ch >= '0' && ch <= '9') return CharType::CHAR_NUMBER;
  else if (ch=='e' || ch=='E') return CharType::CHAR_EXP;
  else if (ch=='.') return CharType::CHAR_POINT;
  else if (ch=='+' || ch=='-') return CharType::CHAR_SIGN;
  else return CharType::CHAR_ILLEGAL;
}

bool isNumber_(std::string s) {
  std::unordered_map<State, std::unordered_map<CharType, State>> transfer{
	  {
		  State::STATE_INITIAL, {
		  {CharType::CHAR_NUMBER, State::STATE_INTEGER},
		  {CharType::CHAR_POINT, State::STATE_POINT_WITHOUT_INT},
		  {CharType::CHAR_SIGN, State::STATE_INT_SIGN}
	  }
	  }, {
		  State::STATE_INT_SIGN, {
			  {CharType::CHAR_NUMBER, State::STATE_INTEGER},
			  {CharType::CHAR_POINT, State::STATE_POINT_WITHOUT_INT}
		  }
	  }, {
		  State::STATE_INTEGER, {
			  {CharType::CHAR_NUMBER, State::STATE_INTEGER},
			  {CharType::CHAR_EXP, State::STATE_EXP},
			  {CharType::CHAR_POINT, State::STATE_POINT}
		  }
	  }, {
		  State::STATE_POINT, {
			  {CharType::CHAR_NUMBER, State::STATE_FRACTION},
			  {CharType::CHAR_EXP, State::STATE_EXP}
		  }
	  }, {
		  State::STATE_POINT_WITHOUT_INT, {
			  {CharType::CHAR_NUMBER, State::STATE_FRACTION}
		  }
	  }, {
		  State::STATE_FRACTION,
		  {
			  {CharType::CHAR_NUMBER, State::STATE_FRACTION},
			  {CharType::CHAR_EXP, State::STATE_EXP}
		  }
	  }, {
		  State::STATE_EXP,
		  {
			  {CharType::CHAR_NUMBER, State::STATE_EXP_NUMBER},
			  {CharType::CHAR_SIGN, State::STATE_EXP_SIGN}
		  }
	  }, {
		  State::STATE_EXP_SIGN, {
			  {CharType::CHAR_NUMBER, State::STATE_EXP_NUMBER}
		  }
	  }, {
		  State::STATE_EXP_NUMBER, {
			  {CharType::CHAR_NUMBER, State::STATE_EXP_NUMBER}
		  }
	  }
  };

  int len = s.length();
  State st = State::STATE_INITIAL;
  for (int i = 0; i < len; ++i) {
	CharType tp = toCharType(s[i]);
	if (transfer[st].find(tp)==transfer[st].end()) return false;
	else st = transfer[st][tp];
  }
  return st==State::STATE_INTEGER || st==State::STATE_POINT
	  || st==State::STATE_FRACTION || st==State::STATE_EXP_NUMBER
	  || st==State::STATE_END;
}