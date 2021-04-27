#ifndef DOORS_INPUT_OUTPUT_H
#define DOORS_INPUT_OUTPUT_H



unsigned int Print(char *message, unsigned int line)
{
    char *vidmem = (char *) 0xb8000;
    unsigned int i=0;

    i=(line*80*2);

    while(*message!=0)
    {
        if(*message=='\n') // check for a new line
        {
            line++;
            i=(line*80*2);
            *message++;
        } else {
            vidmem[i]=*message;
            *message++;
            i++;
            vidmem[i]=0x07;
            i++;
        };
    };

    return(1);
}

#endif