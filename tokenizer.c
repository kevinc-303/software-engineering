#include <stdio.h>
#include <stdlib.h>
main()
{
    FILE *infile, *outfile;
    infile = fopen("input.txt","r");
    outfile = fopen("tokenizer.txt", "w+");
    char line[1024];


    fgets( line ,1024, infile); // reads in first line fom input file
        for(int i = 0; line[i]; i++){
            if (line[i] == '+'
                || line[i] == '-'
                || line[i] == '/'
                || line[i] == '*'
                || line[i] == '%'
                || line[i] == '^'
                || line[i] == '('
                || line[i] == ')'
                || line[i] == '\n'
                || line[i] == '\r'
                )
                    {
                        char c = '\n';
                        fputc(c, outfile);
                        fputc(line[i], outfile);
                        fputc(c, outfile);
                    }
            else if ( (isdigit(line[i])) || (line[i] == '.') ) {
				fputc(line[i], outfile);
			}
        }


}
