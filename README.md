# kofamparse
[![Built with Spacemacs](https://cdn.rawgit.com/syl20bnr/spacemacs/442d025779da2f62fc86c2082703697714db6514/assets/spacemacs-badge.svg)](http://spacemacs.org)  

A simple parser that takes the text output from the [KofamScan tool](https://www.genome.jp/tools/kofamkoala/), and transforms it into a fully formed CSV file.  

The spaces are aggregated and replaced with commas, while commas in KO annotation description are replaced with semicolons.  
## Instalation  

The code should not be platform specific, any modern c++ compiler should accept the makefile. The std flag can probably be dropped to c++14 safely [it compliles], but i only tested it with 17.


```
git clone https://github.com/michauorin/kofamparse
cd kofamparse
make
```
## Usage  

```
path/to/kofamparse/dir/kofamparse source_file output_file

#source_file as in kofamscan output in default [detail] format
```

If the need to transform between detail and mapper format will arise i'll consider adding such functionality. Same goes for filtering to only output KO calls above threshold.
