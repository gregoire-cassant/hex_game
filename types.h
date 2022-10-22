#pragma once

enum color
{
    RED,
    BLUE,
    GREY
};
typedef enum color color;

typedef enum
{
    IA,
    HUMAN
} hIA;

color opp(color c);

typedef struct
{
    int x;
    int y;
} cords;

typedef struct linked
{
    void *item;
    struct linked *next;
} linked_t;



#define PURPLE_S "\033[0;35m"
#define PURPLE_E "\033[0m\n"

#define RED_S "\033[0;31m"
#define RED_E "\033[0m\n"

#define RED(str) RED_S str RED_E
#define PURPLE(str) PURPLE_S str PURPLE_E


