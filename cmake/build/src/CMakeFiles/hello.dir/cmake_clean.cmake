FILE(REMOVE_RECURSE
  "CMakeFiles/hello.dir/main.c.o"
  "../bin/hello.pdb"
  "../bin/hello"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang C)
  INCLUDE(CMakeFiles/hello.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
