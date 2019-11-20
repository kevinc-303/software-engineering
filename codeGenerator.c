#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *infile, *outfile;
    char c[100]; /* or other suitable maximum line size */
    int result;
    char loadint[100] = "LOADINT ";
    char loadfloat[100] = "LOADFLOAT ";

    infile = fopen("postfix.txt", "r");
    outfile = fopen("instructions.txt", "w+");

    if(infile == NULL)
    {
        printf("ERROR: Unable To Access Postfix File\n");
        exit(1);
    }
    
    while ( fgets ( c, sizeof c, infile ) != NULL ) 
    {
        strtok(c, "\n");

        result = strcmp(c, "+");
        if (result == 0) {
            fputs("ADD,\n", outfile); 
        } else { 
            result = strcmp(c, "-");
            if (result == 0) {
                fputs("SUB,\n", outfile);
            } else {
                result = strcmp(c, "*");
                if (result == 0) {
                    fputs("MUL,\n", outfile);
                } else {
                    result = strcmp(c, "/");
                    if (result == 0) {
                        fputs("DIV,\n", outfile);
                    } else {
                        result = strcmp(c, "^");
                        if (result == 0) {
                            fputs("EXP,\n", outfile);
                        } else {
                            result = strcmp(c, "%");
                            if (result == 0) {
                                fputs("MOD,\n", outfile);
                            } else {
                                result = strcmp(c, "\n");
                                if (result == 0) {
                                    fputs("", outfile);
                                } else {
                                    result = strcmp(c, "");
                                    if (result == 0) {
                                        fputs("", outfile);
                                    } else {
                                        if (strchr(c, '.') != NULL) {
                                            strcat(loadfloat, c);
                                            strcat(loadfloat, ",\n");
                                            fputs(loadfloat, outfile);
                                            strcpy(loadfloat, "LOADFLOAT ");
                                        } else {
                                            strcat(loadint, c);
                                            strcat(loadint, ",\n");
                                            fputs(loadint, outfile);
                                            strcpy(loadint, "LOADINT ");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    }

    fputs("HLT", outfile);

    fclose(infile);
    fclose(outfile);

}
