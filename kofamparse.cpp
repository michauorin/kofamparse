#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>

using namespace std;

struct kofam_hit
{
  bool is_above_threshold{false};
  string gene_name;
  string KO_number;
  double threshold;
  double score;
  string e_value;
  string KO_definition;

  string print()
  {
    stringstream buffer;
    buffer << is_above_threshold << ","
           << gene_name << ","
           << KO_number << ","
           << threshold << ","
           << score << ","
           << e_value << ","
           << KO_definition << "\n";
    return buffer.str();
  }
};

int main(int argc, char* argv[])
{
        if (argc < 3)
        {
        cerr << "USAGE: kofamparse [SOURCE_FILE] [RESULT_FILE]";
        return -1;
        }

  ifstream input_file;
  input_file.open(argv[1]);
  if(!input_file.is_open()) cerr << "Input file could not be opened!";

  ofstream output_file;
  output_file.open(argv[2]);
  if(!output_file.is_open()) cerr << "Output file could not be opened!";

  string parsed_line;
  auto process_kofam_line = [&]()
  {
    if(parsed_line[0]=='#') return string{""};
    kofam_hit result;
    stringstream tmp{parsed_line};
    if(parsed_line[0]=='*') result.is_above_threshold = true;
    tmp.get();
    //Make get eat * if it exists and then proceed through other fields.
    tmp >> result.gene_name;
    tmp >> result.KO_number;
    tmp >> result.threshold;
    tmp >> result.score;
    tmp >> result.e_value;
    getline(tmp,result.KO_definition);
    //KO definition contains commas which break CSV parsing, gotta get rid of em
    replace(result.KO_definition.begin(),result.KO_definition.end(), ',', ';');
    return result.print();
  };

  stringstream output_buffer;
  while(getline(input_file,parsed_line))
    {
      output_buffer << process_kofam_line();
    }

  input_file.close();

  output_file << "Above threshold, Gene name, KO number, threshold, "
              << "score, e-value, KO definition\n";
  output_file << output_buffer.str();
  output_file.close();

return 0;
}
