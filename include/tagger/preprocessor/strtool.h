//
// Created by 王鹏飞 on 16/1/19.
//

#ifndef CRF_STRTOOL_H
#define CRF_STRTOOL_H

#endif //CRF_STRTOOL_H

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

    namespace strtool {
        string trim(const string &str) {
            string::size_type pos = str.find_first_not_of(" \n\r");
            if (pos == string::npos) {
                return str;
            }
            string::size_type pos2 = str.find_last_not_of(" \n\r");
            if (pos2 != string::npos) {
                return str.substr(pos, pos2 - pos + 1);
            }
            return str.substr(pos);
        }

        int split(const string &str, vector<string> &ret_, string sep = ",") {
            ret_.clear();
            if (str.empty()) {
                return 0;
            }

            string tmp;
            string::size_type pos_begin = str.find_first_not_of(sep);
            string::size_type comma_pos = 0;

            while (pos_begin != string::npos) {
                comma_pos = str.find(sep, pos_begin);
                if (comma_pos != string::npos) {
                    tmp = str.substr(pos_begin, comma_pos - pos_begin);
                    pos_begin = comma_pos + sep.length();
                }
                else {
                    tmp = str.substr(pos_begin);
                    pos_begin = comma_pos;
                }

                if (!tmp.empty()) {
                    ret_.push_back(tmp);
                    tmp.clear();
                }
            }
            return 0;
        }

        string replace(const string &str, const string &src, const string &dest) {
            string ret;

            string::size_type pos_begin = 0;
            string::size_type pos = str.find(src);
            while (pos != string::npos) {
                cout << "replacexxx:" << pos_begin << " " << pos << "\n";
                ret.append(str.data() + pos_begin, pos - pos_begin);
                ret += dest;
                pos_begin = pos + 1;
                pos = str.find(src, pos_begin);
            }
            if (pos_begin < str.length()) {
                ret.append(str.begin() + pos_begin, str.end());
            }
            return ret;
        }

        u32string join(std::vector<std::u32string> const &words, char32_t delim) {
            basic_ostringstream<char32_t> oss;
            for (auto iter = words.cbegin(); iter != words.cend(); ++iter) {
                if (iter != words.cbegin())
                    oss << delim;
                oss << *iter;
            }
            return oss.str();
        }

    }

