#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static char *words[] = {
    "admit", "agony", "alarm", "anger", "arena", "azure", "basin",
    "baton", "belle", "bevel", "bleat", "blood", "bogus", "boots",
    "broil", "bully", "cadet", "camel", "cedar", "chief", "comic",
    "corps", "crawl", "crest", "crude", "dance", "decal", "dirge",
    "donor", "dozed", "drawn", "droll", "dwarf", "edict", "eject",
    "elide", "empty", "exert", "faith", "feast", "femur", "fiery",
    "fizzy", "forum", "frank", "glued", "grail", "graze", "hello",
    "honor", "humor", "hutch", "idiot", "jolly", "kayak", "logic",
    "lousy", "mines", "motto", "novel", "orbit", "pagan", "plaid",
    "posse", "pulse", "purge", "quiet", "quota", "raven", "rigor",
    "risky", "rusty", "shaft", "sheep", "skate", "slate", "slimy",
    "smoky", "snaps", "snuff", "softy", "space", "spilt", "squaw",
    "stalk", "stays", "swarm", "swift", "sworn", "tenth", "testy",
    "throw", "tonic", "twist", "unity", "vivid", "wrist", "write",
    "yeast", "weave"
};

void print_red(char c)
{
    printf("\033[31;1m%c\033[0m", c);
}

void print_blue(char c)
{
    printf("\033[34;1m%c\033[0m", c);
}

void print_yellow(char c)
{
    printf("\033[93;1m%c\033[0m", c);
}

void genword(char* word)
{
    int numwords = sizeof(words)/sizeof(words[0]);

    time_t t = time(NULL);
    srandom(t);
    int i = random() % numwords;

    strcpy(word, words[i]);
}

