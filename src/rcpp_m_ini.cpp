#include "mini/ini.h"
#include <Rcpp.h>
using namespace Rcpp;

//' @useDynLib M.ini _M_ini_rcpp_mini_reader
//' @importFrom Rcpp evalCpp
// [[Rcpp::export]]
List rcpp_mini_reader(CharacterVector filename)
{
  std::string file_path = Rcpp::as<std::string>(filename);
  List ini_list = List::create();

  // first, create a file instance
  mINI::INIFile file(file_path);

  // next, create a structure that will hold data
  mINI::INIStructure ini;

  // now we can read the file
  file.read(ini);

  // Convert ini to Rcpp List
  for (auto const &it : ini)
  {
    auto const &section = it.first;
    auto const &collection = it.second;
    // size_t n_keys = section.size();
    List ini_section = List::create();
    for (auto const &it2 : collection)
    {
      auto const &key = it2.first;
      auto const &value = it2.second;
      ini_section[key] = value;
    }

    ini_list[section] = ini_section;
  }

  return ini_list;
}
