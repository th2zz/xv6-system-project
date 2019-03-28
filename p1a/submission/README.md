my-cat.c
	buffer size is set to be 512
	will exit when num_files is 0 with exit code 0;
	otherwise read each provided files sequentially and will exit when file not found with exit code 1;
	

my-sed.c
	if find_term is empty (""), the program will regard it as string "\"\"" (two quotes) and try to find it.
	if replace_term is empty, the find_term will be deleted.
	the process is: read from stream - store in memory & do the operation - prints result to stdout
		for each operation, the program tries to find the substring before find_term, after find_term and then do the corresponding concatenation.
	when reading multiple files, it will exit(1) when file not found
my-uniq.c
	the program finds repeated adjacent lines in a stream and deletes them (in memory), and only prints unique lines to stdout.
	when reading multiple files, it will exit(1) when file not found
	the basic process is:
		read first line and store it in temp char* then rewind the stream
		read line by line from the stream and compare it with previous line read using char* temp as a placeholder
			if same do nothing and continue to nextline
			if different print to stdout
