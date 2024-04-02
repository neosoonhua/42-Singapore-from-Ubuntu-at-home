# norminette -R CheckForbiddenSourceHeader
# norminette -R CheckDefine
# ./pipex infile "ls -l" "wc -l" 
./pipex infile "ls -l" "wc -l" outfile
# valgrind --leak-check=full --show-leak-kinds=all -s ./pipex infile "ls -l" "wc -l"
# valgrind --leak-check=full --show-leak-kinds=all -s ./pipex infile "ls -l" "wc -l" outfile
# valgrind -s ./pipex infile "ls -l" "wc -l" outfile
# valgrind --leak-check=full --show-leak-kinds=all -s ./pipex infile ls wc outfile
